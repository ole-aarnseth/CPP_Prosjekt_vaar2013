#ifndef CLASS_FORMFIELD_H
#define CLASS_FORMFIELD_H

#include <string>

namespace music{

	class formField
	{
		int length, ypos, xpos, cpos;
		std::string buffer;

		public:
			formField(int l, int y, int x);
			int getLength();
			int getBLength();
			int getYpos();
			int getXpos();
			int getCpos();
			void moveLeft();
			void moveRight();
			void addToBuffer(char c);
			void delFromBuffer();
			std::string getBuffer();
			char* getCBuffer();
			void resetBuffer();
	};



}

#endif