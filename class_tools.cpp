#include "class_tools.h"
#include <sstream>
#include <iostream>

using namespace music;

int tools::getNumber(){
std::string input = "";
int myNumber = 0;

	while (true) 
	{
	std::getline(std::cin, input);
	std::stringstream myStream(input);
	if (myStream >> myNumber)
		break;
	}
	 	
return myNumber;
}	

std::string tools::getString(){
std::string input = "";
std::getline(std::cin, input);
return input;
}

const char* tools::int2char(char *src, int number) {//Tar imot en pointer til en chararr og returnerer pointer besudlet.
std::stringstream strs;
strs << number;
std::string temp_str = strs.str();
src = (char*) temp_str.c_str();  
return src;
}

