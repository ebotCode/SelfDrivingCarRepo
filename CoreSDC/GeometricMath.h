#include <cmath>
#include "Pose.h"
#include "Measurement.h"
#include "Constants.h"
#include "Units.h"



#ifndef GEOMETRICMATH_H
#define GEOMETRICMATH_H


namespace GeometricMath{

Core::Distance ComputeDistanceBetweenPosition(Core::Position p1, Core::Position p2);

Core::Orientation ComputeBearingOfPointWithRespectToPose(Core::Pose pose,Core::Position p1);

}



#endif 



