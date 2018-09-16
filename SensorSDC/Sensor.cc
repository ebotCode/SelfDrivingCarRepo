

#include <iostream>
#include "Sensor.h"
#include <string> 
#include "../MapSDC/Map.h"
#include "../CoreSDC/Pose.h"
#include "../CoreSDC/Measurement.h"
#include "../CoreSDC/GeometricMath.h"
#include "../CoreSDC/Units.h"


namespace Sensor{

int LandmarkSensor::landmarkSensorCount_ = 0;
Core::ID LandmarkSensor::uniqueIdCount_ = 0;

LandmarkSensor::LandmarkSensor(){

    id_ = uniqueIdCount_; 
    landmarkSensorCount_++;
    uniqueIdCount_++;   

}

LandmarkSensor::LandmarkSensor(Core::Range max_range_in)
{
    id_ = uniqueIdCount_; 
    landmarkSensorCount_++;
    uniqueIdCount_++;

    SetMaximumRange(max_range_in);
}

LandmarkSensor::~LandmarkSensor(){
    landmarkSensorCount_-=1;
}

void LandmarkSensor::Initialise(){
    mapPtr_ = nullptr; 
}
// Speed CalculateSpeed(Meters distance, Seconds time) 
void LandmarkSensor::Sense(Core::Pose pose,SensorMeasurement& ranges_out){
    /* fills in the ranges_out with ranges of landmarks that the sensor 
        can reach.
        For now, it is assumed that the max sensor angle range is 2*pi (360)
    */
    /*
    int nlandmarks = 5; 
    ranges_out.resize(nlandmarks);
    
    Core::Range range ; 
    for (size_t i = 0; i < ranges_out.size(); i++){

        range.distance = 0.1;     
        range.bearing = Core::Orientation{0.3}; 
        ranges_out.at(i) = range;
    }
    */
    // compute the distances to all the landmarks. any landmark that falls within 
    // the maxrange distance 
    int nlandmarks = mapPtr_->pLandmarks.size();
    
    ranges_out.resize(0);
    Core::Range range;
    for (int i = 0; i < nlandmarks; i++){
        Core::Position landmark_location = mapPtr_->pLandmarks.at(i).location;

        Core::Distance distance = GeometricMath::ComputeDistanceBetweenPosition(pose.position,landmark_location);
        Core::Orientation bearing  = GeometricMath::ComputeBearingOfPointWithRespectToPose(pose,landmark_location);
        if (distance <= maxRange_.distance){
            range.distance = distance;
            range.bearing  = bearing;
            ranges_out.push_back(range);
        }
    }
    
}

void LandmarkSensor::SetMaximumRange(Core::Range max_range_in){
    maxRange_ = max_range_in; 
}

void LandmarkSensor::SetMap(Map::LandmarkMap& map_in){
    mapPtr_ = &map_in;
}

void LandmarkSensor::ShowInformation(){
    /* displays information about the sensor */
    std::cout << "Sensor_"<<id_<<" : maxrange (distance : "<<maxRange_.distance 
              << " , bearing : " << maxRange_.bearing.yaw << " ) "<<std::endl;
    
}

}