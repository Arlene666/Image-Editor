#include "exception.h"
#include <string>
using std::string;

string PpmArrayInputFormatException::getErrorMessage(){
  return s;
}

PpmArrayInputFormatException::PpmArrayInputFormatException(std::string s) 
  : s{s} {}

