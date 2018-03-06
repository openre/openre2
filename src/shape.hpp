/*
 * shape.h
 *
 *  Created on: 08.06.2017
 *      Author: Dmitrii Boiarshinov
 */

#pragma once
#include <string>
#include "types.hpp"

using namespace std;

namespace openre {

class Shape {
public:
    Shape(address x, address y, address width, address height);
    virtual ~Shape();
    address x;
    address y;
    address width;
    address height;

};

} /* namespace openre */

