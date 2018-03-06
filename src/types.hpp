#pragma once
#include <cstdint>

using namespace std;

namespace openre {

typedef int32_t threshold;
typedef int32_t neuron_level;
typedef uint8_t neuron_flags;
typedef uint8_t index_flags;
typedef int16_t synapse_level_level;
typedef uint8_t synapse_flags;
typedef uint16_t medium_address;
typedef uint32_t address;
typedef uint32_t tick;
typedef uint32_t vitality;
typedef uint8_t output;
typedef address percent;

const address undef = UINT32_MAX;

} /* namespace openre */

