#include "sepia.h"
using namespace std;


Sepia::Sepia(Image *comp):Decorator{comp} {}

void Sepia::setSource(std::istream *inp) {
    comp->setSource(inp);
}

static int min(int a, int b) {
    if (a < b) return a;
    return b;
}

static void sep(struct Pixel &p) {
    int r = min(255, p.r*.393+p.g*.769+p.b*.189);
    int g = min(255, p.r*.349+p.g*.686+p.b*.168);
    int b = min(255, p.r*.272+p.g*.534+p.b*.131);
    p.r = r;
    p.g = g;
    p.b = b;
}
    

void Sepia::render(PpmArray &ppm) {
    comp->render(ppm);
    int size = ppm.getSize();
    for (int i = 0; i < size; ++i) {
        sep(ppm.getPixels()[i]);
    }
}


