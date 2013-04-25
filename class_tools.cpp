#include "class_tools.h"
#include <sstream>
#include <iostream>

using namespace tools_n;

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

std::string tools::getString()
{
std::string input = "";
std::getline(std::cin, input);
return input;
}
