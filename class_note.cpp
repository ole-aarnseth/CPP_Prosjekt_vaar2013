#include "class_note.h"
#include <sstream>

using namespace music;

note::note(std::string c_key, int c_length){	
key = c_key;
length = c_length;
}

std::string note::getKey(){
return key;
}

int note::getLength(){
return length;
}
