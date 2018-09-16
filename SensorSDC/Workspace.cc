
#include <iostream> 
#include <vector>
#include "Sensor.h"
// #include "../MapSDC/Map.h"
#include "../Factory/Factory.h"
#include "../CoreSDC/Constants.h"
#include "../CoreSDC/ComputationMath.h"


int main(){
    //create a map 
    Map::LandmarkMap map1 = Factory::GetLandmarkMapForSensorTest("landmarks1.txt");
    // create a sensor 
    Sensor::LandmarkSensor sensor1; 
    // set the map 
    sensor1.SetMap(map1);
    // set the max range
    Core::Range max_range;
    max_range.distance = 100;
    max_range.bearing = Core::Orientation{Constant::CIRCLE_ANGLE};
    sensor1.SetMaximumRange(max_range);
    // show information on the sensor 
    sensor1.ShowInformation();
    // sense
    Sensor::SensorMeasurement sensor_measurement;
    Core::Pose pose;
    pose.position = Core::Position{47, 40};
    pose.orientation = Core::Orientation{Math::DegToRad(0)};

    sensor1.Sense(pose,sensor_measurement);
    // display the sense Result
    Factory::DisplaySensorRangeMeasurement(sensor_measurement);


    return 0; 
}