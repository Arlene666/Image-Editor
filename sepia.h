#ifndef SEPIA_H
#define SEPIA_H

#include "image.h"
#include "decorator.h"
#include "ppmArray.h"


class Sepia: public Decorator {
    public:
        Sepia(Image *comp);
        void setSource(std::istream *inp) override;
        void render(PpmArray &ppm) override;
};


#endif

