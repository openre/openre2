#include "openre.hpp"
#include "types.hpp"

namespace openre {

void OpenRE::foo(int &i) {
    i = 1;
}


void independentMethod(int &i) {
    i = 0;
}

} /* namespace openre */

