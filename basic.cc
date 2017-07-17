#include "basic.h"  

void BasicImage::setSource(std::istream *inp) { 
  source = inp;
}

// A Base Image simply reads the image format and
// constructs the PpmArray
void BasicImage::render(PpmArray &ppm) {
  *source >> ppm; //use input operator
}

