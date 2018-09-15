#include <iostream> 
#include <vector> 
#include <istream> 
#include "../CoreSDC/Pose.h"

#ifndef LandMarkMap_H
#define LandMarkMap_H

namespace Map{

class GlobalMap{

public:
    GlobalMap(){;}
    ~GlobalMap(){}

};

struct Landmark {
    Core::Position location;

};

class LandmarkMap : public GlobalMap {
public:
    std::vector<Landmark> pLandmarks;

    // constructor 
    LandmarkMap();
    // destructor 
    ~LandmarkMap();

    // read landmarks from file 
    bool ReadLandmarkFromFile(std::fstream& input_file);

    // print the landmarks 
    void PrintMap();

};





}

#endif 