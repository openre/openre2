/*
 * layer.h
 *
 *  Created on: 08.06.2017
 *      Author: Dmitrii Boiarshinov
 */

#pragma once
#include <string>
#include <vector>
#include "types.hpp"
#include "shape.hpp"

using namespace std;

namespace openre {

address from_percent(percent p, address from, address to);

class Layer {
public:
    Layer();
    Layer(string name, address width, address height);
    virtual ~Layer();
    void addShape(address a_x, address a_y, address a_width, address a_height);
    string name;
    address width;
    address height;
    vector<Shape *> shapes;

};

} /* namespace openre */

