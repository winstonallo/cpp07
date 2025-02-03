#include "whatever.hpp"
#include <cassert>
#include <iostream>

void testSwap() {
    std::string a = "Hello", b = "World";
    mod::swap(a, b);
    assert(a == "World");
    assert(b == "Hello");
}

int main() { testSwap(); }
