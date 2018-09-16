/*
This file defines the state objects. 

State consists of position, orientation (heading direction: picth, yaw, roll)
For this 2D Codebase, the yaw angle would be used only.
*/

#include "Units.h"

#ifndef POSE_H
#define POSE_H

namespace Core{

typedef int ID ; 

struct Position{
    Unit::Meter x;
    Unit::Meter y; 
};

struct Orientation{
    Unit::Radian yaw;  // yaw angle. in radian
};

struct Pose{
    Position position; 
    Orientation orientation; 
};

}


#endif 