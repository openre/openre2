#include <iostream>
#include "openre.hpp"

using namespace std;
using namespace openre;
/*
 *  OpenRE - several instances (TBD - right now only one is supported) that
 *           runs whole network
 *      Domain - several domains - one domain -> one device/instance
 *          Neurons - layers neurons relater to current Domain
 *          Synapses - synapses that connects neurons
 *          Device (one Domain - one Device (CPU, GPU or something else))
 *  Layer - layers of the network
 *      Shape - area of the Layer that run on the current Domain. Shapes
 *              can overlap each other. Neurons in layers are connected with
 *              help of shapes (from the group of layer neurons in first shape
 *              to the group of layer neurons in the second). Layer can connect
 *              to itself.
 *
 * */

int main() {
    cout << "do stuff" << endl;
    int x = 4;
    cout << x << endl;
    independentMethod(x);
    cout << x << endl;
    OpenRE p;
    p.foo(x);
    cout << x << endl;
}
