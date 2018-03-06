#pragma once

#include <iostream> // IO access
namespace openre {

class OpenRE {

    public:
        // why only detected if implemented here?
        // void foo(int &i) {
        // 	i = 1;
        // }
        void foo(int &i);

};

void independentMethod(int &i);

} /* namespace openre */

