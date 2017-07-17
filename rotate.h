#ifndef ROTATE_H
#define ROTATE_H

#include "image.h"
#include "decorator.h"
#include "ppmArray.h"

class Rotate: public Decorator {
    public:
        Rotate(Image *comp);
        void setSource(std::istream *inp) override;
        void render(PpmArray &ppm) override;
};

#endif

