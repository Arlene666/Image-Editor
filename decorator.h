#ifndef DEC_H
#define DEC_H
#include "image.h"

class Decorator: public Image {
    protected:
        Image *comp;
    public:
        Decorator(Image *comp);
        void setSource(std::istream *inp) override;
        virtual ~Decorator();
};

#endif

