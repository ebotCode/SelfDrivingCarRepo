#include <cmath>
#include "Pose.h"
#include "Measurement.h"
#include "Constants.h"
#include "Units.h"



#ifndef GEOMETRICMATH_H
#define GEOMETRICMATH_H


namespace GeometricMath{

Core::Distance ComputeDistanceBetweenPosition(Core::Position p1, Core::Position p2){

    Core::Distance distance = std::sqrt(std::pow(p2.x - p1.x,2) + std::pow(p2.y - p1.y,2)); 
    return distance; 
}

Core::Orientation ComputeBearingOfPointWithRespectToPose(Core::Pose pose,Core::Position p1){
    /* returns the bearing angle of the point located at p1, with respect to the pose */
    Unit::Meter x2 = p1.x;
    Unit::Meter y2 = p1.y;
    Unit::Meter x1 = pose.position.x;
    Unit::Meter y1 = pose.position.y;
    
    Core::Orientation bearing; 
    // Rotate and translate to pose coordinate.
    Unit::Meter xnew =  x2 * std::cos(pose.orientation.yaw) + y2 * std::sin(pose.orientation.yaw) + (-x1);
    Unit::Meter ynew = -x2 * std::sin(pose.orientation.yaw) + y2 * std::cos(pose.orientation.yaw) + (-y1);

    // now find the angle wrt to this new 
    Unit::Radian angle = std::atan2(ynew , xnew); //atan2 gives (0,pi) if y > 0, and (0,pi) if y < 0
    bearing.yaw = angle;
    if (angle < 0){

        bearing.yaw = Constant::CIRCLE_ANGLE + angle; 
    
    }
    
    return bearing;    

}



}



#endif 



