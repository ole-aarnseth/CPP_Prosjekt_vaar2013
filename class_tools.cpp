#include "class_tools.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace music;

//Tar imot en *charArr og et nummer. Returnerer en pointer til mottat charrArr.
const char* tools::int2char(char *src, int number) {
std::stringstream strs;
strs << number;
std::string temp_str = strs.str();
src = (char*) temp_str.c_str();
return src;
}

//Gjør om fra double to char*.
void tools::dbl2char(double d, char* c){
    sprintf(c , "%lf" , d);
}

//Gjør om fra int til string
std::string tools::int2string(int number){
std::string s;
std::stringstream out;
out << number;
s = out.str();
return s;
}

//Gjør om den første bokstaven i s fra lower til upper case. 
//Funksjonen brukes kun til noter da resten av programmet er avhengig av 
//at notene er i upper case.
std::string tools::convertLetter(std::string s)
{  
if(s[0]>90)
    s[0]-=32;
return s;
}

//Gjør om en chararr til en int. 
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
