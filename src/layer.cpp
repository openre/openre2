/*
 * layer.cpp
 *
 *  Created on: 08.06.2017
 *      Author: Dmitrii Boiarshinov
 */

#include "layer.hpp"
#include "types.hpp"
#include <stdexcept>
#include <string>
#include "shape.hpp"

namespace openre {

address from_percent(percent p, address from, address to){
    return from + (1.0*p/100)*(to-from);
}

Layer::Layer(string name, address width, address height):
    name(name),
    width(width),
    height(height)
{
    // TODO Auto-generated constructor stub
}

Layer::Layer():
    name(""),
    width(0),
    height(0)
{
    // TODO Auto-generated constructor stub
}

Layer::~Layer() {
    while (!shapes.empty()){
        Shape *s = shapes.back();
        shapes.pop_back();
        delete s; // created in addShape
    }
}

void Layer::addShape(address a_x, address a_y, address a_width, address a_height){
    if (a_x >= width || a_y >= height || a_x + a_width > width || a_y + a_height > height){
        throw invalid_argument(
            string("Layer(\"") + name + "\", "
            + to_string(width) + ", " + to_string(height) + ")"
            + " does not fit Shape("
            + to_string(a_x) + ", " + to_string(a_y) + ", "
            + to_string(a_width) + ", " + to_string(a_height) + ")"
        );
    }
    if (!a_width || !a_height){
        throw invalid_argument("Shapes width and height should be non-zero");
    }
    shapes.push_back(new Shape(a_x, a_y, a_width, a_height));
}

} /* namespace openre */
