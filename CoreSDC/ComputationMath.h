
#include <cmath> 
#include "Constants.h"
#include "Units.h"


#ifndef COMPUTATIONMATH_H
#define COMPUTATIONMATH_H

namespace Math{

Unit::Degree RadToDeg(Unit::Radian radian){
    return (radian * 180.0 / Constant::PI);
}

Unit::Radian DegToRad(Unit::Degree degree){
    return (degree * Constant::PI/ 180.0);
}


}


#endif 