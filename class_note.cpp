#include "class_note.h"
#include "class_tools.h"
#include <sstream>

using namespace music;

//konstruktør 
note::note(std::string c_key, int c_length){	
key = c_key;
length = c_length;
}

//getfunksjon for key.
std::string note::getKey(){
return key;
}

//getfunksjon for length.
int note::getLength(){
return length;
}

//toStringfunksjon som skriver ut key og length.
std::string note::toString(){
tools myTools;
std::string output;
  output.append(key);
  output.append(", ");
  output.append(myTools.int2string(length));
  output.append("\n");
return output;
}
