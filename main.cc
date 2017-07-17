#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ppmArray.h"
#include "image.h"
#include "basic.h"
#include "exception.h"
#include "flip.h"
#include "rotate.h"
#include "sepia.h"

//You may need to include headers for classes you create

using namespace std;

/*
 * The harness is not very robust. Failure to follow requirements
 * might cause it to (a) crash (b) throw uncaught exceptions 
 * (c) behave in an undefined manner
 */
int main(){
  cin.exceptions(ios::failbit|ios::eofbit|ios::badbit);
  string s;

  try {
    while(1) {
      getline(cin,s);

      istringstream iss{s};
      string fname;

      //input image file
      iss >> fname;
      istream *in = new ifstream(fname.c_str());
      if (in->fail()) {
        cerr << "Something bad happened: perhaps incorrect filename." << endl;
        exit(1);
      }
      //output image file
      iss >> fname;
      ostream *out = new ofstream(fname.c_str());
      if (out->fail()) {
        cerr << "Something bad happened." << endl;
        delete in;
        exit(1);
      }
    
      PpmArray ppmArray;
      Image *img = new BasicImage();



      // YOU SHOULD NOT NEED TO EDIT CODE ABOVE THIS LINE

      string dec;
      while (iss >> dec) {
        if (dec == "rotate") {
            img = new Rotate(img);
        }
        else if (dec == "flip") {
            img = new Flip(img);
        } 
        else if (dec == "sepia") {
            img = new Sepia(img);
        }
        else {
          cerr << "Invalid transformation (ignored)" << dec << endl;
          break;
        }
      }//end reading input line 

      // YOU SHOULD NOT NEED TO EDIT CODE BELOW THIS LINE



      //set the source
      img->setSource(in);

      try {
        //read image and apply any transformations
        img->render(ppmArray); 

        //write out the transformed image to destination file
        *out << ppmArray; 

      } catch (PpmArrayInputFormatException &e){
        cerr << e.getErrorMessage();    
      }

      delete in; delete out; delete img;
    }//end while(1)
  } //end try
  catch (ios::failure) {}
}
