/*
This file defines the state objects. 

State consists of position, orientation (heading direction: picth, yaw, roll)
For this 2D Codebase, the yaw angle would be used only.
*/

#ifndef LOCATIONSTATE_H
#define LOCATIONSTATE_H

namespace Core{

struct Position{
    double x;
    double y; 
};

struct Orientation{
    double yaw;  // yaw angle. in radian
};


struct LocationState{ // defines the State based on location. 
    Position position;
    Orientation orienation;
};



}


#endif 