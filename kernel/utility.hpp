#pragma once

#include "chardev/uart.hpp"
#include "../ktl/array.hpp"
#include "../ktl/memory.hpp"

namespace kt::utility {
    extern "C" void printk(char* s);
}