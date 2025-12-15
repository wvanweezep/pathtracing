#include <iostream>

#include "image.h"

int main() {
    std::cout << "Hello, World!\n";

    Image img(800, 800);
    for (int y = 0; y < 800; y++) {
        for (int x = 0; x < 800; x++) {
            img.setPixel(x, y, Color(x / 800.f, y / 800.f, 1));
        }
    }
    img.writeToPPM("_results/test.ppm");

    return 0;
}
