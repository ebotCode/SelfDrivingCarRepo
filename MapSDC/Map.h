#include <iostream> 
#include <vector> 
#include <istream> 
#include "../CoreSDC/Pose.h"

#ifndef Map_H
#define Map_H

namespace Map{

class GlobalMap{

public:
    GlobalMap(){;}
    ~GlobalMap(){}
    virtual void ShowInformation() = 0;

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

    void  ShowInformation();
    // print the landmarks 
    void PrintMap();

};





}

#endif 