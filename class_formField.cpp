#include "class_formField.h"
#include <iostream>
using namespace music;

formField::formField(int l, int y, int x) :
length(l),
ypos(y),
xpos(x),
cpos(0),
buffer("")
{}

int formField::getLength()
{
	return length;
}

int formField::getBLength()
{
	return buffer.length();
}

int formField::getYpos()
{
	return ypos;
}

int formField::getXpos()
{
	return xpos;
}

int formField::getCpos()
{
	return cpos;
}

void formField::moveLeft()
{
	if (cpos > 0)
	cpos--;
}

void formField::moveRight()
{
	if (cpos < buffer.length())
	cpos++;
}

void formField::addToBuffer(char c)
{
	if (buffer.length() < length)
	{
		buffer += c;
		cpos++;
	}
}

void formField::delFromBuffer()
{
	if (cpos == 0)
	return;

	std::string nbuff = "";
	unsigned int delpos = cpos - 1;

	for (unsigned int i = 0; i < buffer.length(); i++)
	{
		if (i != delpos)
		nbuff += buffer.at(i);
	}

	buffer = nbuff;
	cpos--;
}

std::string formField::getBuffer()
{
	return buffer;
}

char* formField::getCBuffer()
{
	return (char*)buffer.c_str();
}

void formField::resetBuffer()
{
	buffer = "";
	cpos = 0;
}
