#include "include/macos.h"
#include <iostream>
// https://github.com/amengede/getIntoMetalDev/tree/main/cpp/01%20hello%20metal
int main() {
    auto pool = NS::AutoreleasePool::alloc()->init();
    std::cout << "Hello, World!" << std::endl;
    pool->drain();
    return 0;
}
