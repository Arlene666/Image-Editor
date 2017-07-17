#include "flip.h"
using namespace std;

Flip::Flip(Image *comp):Decorator{comp} {}

void Flip::setSource(istream *inp) {
    comp->setSource(inp);
}

static void swap_pixel(Pixel &p1, Pixel &p2) {
    int temp_r = p1.r;
    int temp_g = p1.g;
    int temp_b = p1.b;
    p1.r = p2.r;
    p1.g = p2.g;
    p1.b = p2.b;
    p2.r = temp_r;
    p2.g = temp_g;
    p2.b = temp_b;
}

void Flip::render(PpmArray &ppm) {
    comp->render(ppm);
    int width = ppm.getWidth();
    int height = ppm.getHeight();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width / 2; ++j) {
            swap_pixel(ppm.getPixels()[i*width+j],
                    ppm.getPixels()[(i+1)*width-j - 1]);
        }
    }
}
