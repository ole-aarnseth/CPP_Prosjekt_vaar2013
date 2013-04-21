#include "class_tone.h"

using namespace tone_n;

tone::tone(std::string c_key, int c_length){	
key = c_key;
length = c_length;
}

std::string tone::getKey(){
return key;
}

int tone::getLength(){
return length;
}
