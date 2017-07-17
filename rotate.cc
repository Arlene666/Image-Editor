#include "rotate.h"
#include <vector>
using namespace std;

Rotate::Rotate(Image *comp):Decorator{comp} {}

void Rotate::setSource(istream *inp) {
    comp->setSource(inp);
}

void Rotate::render(PpmArray &ppm) {
    comp->render(ppm);
    int size = ppm.getSize();
    int &width = ppm.getWidth();
    int &height = ppm.getHeight();
    vector <Pixel> vecs;
    for (int i = 0; i < size; ++i) {
        vecs.emplace_back(ppm.getPixels()[i]);
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            ppm.getPixels()[i*height+j] = vecs[width*(height-j-1)+i];
        }
    }
    int temp = width;
    width = height;
    height = temp;
}

