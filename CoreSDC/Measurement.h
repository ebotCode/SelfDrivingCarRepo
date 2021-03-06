/*  Definition of measurement information */


#include "Pose.h"
#include "Units.h"

#ifndef MEASUREMENT_H
#define MEASUREMENT_H

namespace Core{

using Distance = Unit::Meter ;

struct Range{
    /*
    Range is measured relative to the reference vehicle
    */
    Distance distance; // distance 
    Orientation bearing; // orientation  
};


}

#endif 