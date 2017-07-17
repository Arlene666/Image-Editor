#include "decorator.h"
using namespace std;


Decorator::Decorator(Image *comp):comp{comp} {}

void Decorator::setSource(istream *inp) {
    comp->setSource(inp);
}


Decorator::~Decorator() {
    delete comp;
}


