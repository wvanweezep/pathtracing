#include <iostream>

#include "image.h"

int main() {
    std::cout << "Hello, World!\n";

    Image img(800, 800);
    img.writeToPPM("_results/test.ppm");

    return 0;
}
