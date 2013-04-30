#include "class_tools.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

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

int tools::char2int(char str[])
{
	int p_tens = 1, r = 0;

	if (str[0] == '\0')
	{
		std::cout << "Error! Empty string.\n";
		return 0;
	}

	if (str[0] == '-')
	{
		if (str[1] == '\0')
		{
			std::cout << "Error! Empty string.\n";
			return 0;
		}

		for (int i = 2; str[i] != '\0'; i++)
		{
			p_tens *= 10;
		}

		for (int i = 1; str[i] != '\0'; i++)
		{
			r += (str[i] - '0') * p_tens;
			p_tens /= 10;
		}

		r *= -1;
	}

	else
	{
		for (int i = 1; str[i] != '\0'; i++)
		{
			p_tens *= 10;
		}

		for (int i = 0; str[i] != '\0'; i++)
		{
			r += (str[i] - '0') * p_tens;
			p_tens /= 10;
		}
	}

	return r;
}

void tools::dbl2char(double d, char* c){
    sprintf(c , "%lf" , d);
}

std::string tools::int2string(int number){
std::string s;
std::stringstream out;
out << number;
s = out.str();
return s;
}
