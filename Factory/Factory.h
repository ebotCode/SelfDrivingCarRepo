#include "../MapSDC/Map.h"
#include "../SensorSDC/Sensor.h"
#include "../CoreSDC/ComputationMath.h"
#include <fstream>


#ifndef FACTORY_H
#define FACTORY_H

namespace Factory{


Map::LandmarkMap GetLandmarkMapForSensorTest(std::string input_filename){
    // create a map 
    Map::LandmarkMap map1; 
    //
    std::fstream landmarkfile; 
    landmarkfile.open(input_filename,std::ios::in);
    map1.ReadLandmarkFromFile(landmarkfile);

    return map1 ;      
}

void DisplaySensorRangeMeasurement(Sensor::SensorMeasurement& sensor_measurement){
    std::cout << "number of measurements = " << sensor_measurement.size() << std::endl; 
    if (sensor_measurement.size() == 0){
        std::cout <<" No landmarks detected " << std::endl;
    }
    for (size_t i = 0; i < sensor_measurement.size(); i++){
            std::cout << "range ("<<i<<") = "<<"( distance : "<<sensor_measurement.at(i).distance<< " , " <<
                    "bearing : "<<Math::RadToDeg(sensor_measurement.at(i).bearing.yaw )<<" )"<< std::endl; 
        }    
    }


}
#endif 