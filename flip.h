#ifndef FLIP_H
#define FLIP_H
#include "image.h"
#include "decorator.h"
#include "ppmArray.h"
#include <iostream>


class Flip: public Decorator {
    public:
        Flip(Image *comp);
        void setSource(std::istream *inp) override;
        void render(PpmArray &ppm) override;
};


#endif

