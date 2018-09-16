

#include <iostream>
#include <vector> 
#include <string>
#include "../CoreSDC/Pose.h"
#include "../CoreSDC/Measurement.h"
#include "../MapSDC/Map.h"

#ifndef SENSOR_H
#define SENSOR_H


namespace Sensor{

typedef std::vector<Core::Range> SensorMeasurement;

class RangeSensor{
public:
    RangeSensor(){}
    ~RangeSensor(){}
    virtual void Sense(Core::Pose, SensorMeasurement& ranges_out) =0;
    virtual void ShowInformation() = 0;
};

class LandmarkSensor : RangeSensor{
public:
    
    LandmarkSensor();
    LandmarkSensor(Core::Range max_range_in);
    ~LandmarkSensor();
    // Sense: takes in a pose and the output, and popoulates the ranges_out with 
    // the Range (distance, bearing) detected. 
    void Sense(Core::Pose,SensorMeasurement& ranges_out);
    void SetMaximumRange(Core::Range max_range_in);
    void SetMap(Map::LandmarkMap& map_in);
    void ShowInformation();

private: 
    void Initialise();
    // void setName(std::string name_in);

private: 
    static Core::ID uniqueIdCount_;
    static int landmarkSensorCount_;
    Core::Range maxRange_; // maximum range that can be detected
    Core::ID id_;
    Map::LandmarkMap* mapPtr_; // non-owning pointer 


};



}


#endif 