#ifndef CLASS_UTILITY_H
#define CLASS_UTILITY_H

#include <string>

namespace music{

	class tools//Enkel klasse for å samle alle verktøy som ellers mangler hjem.
	{
		public:
		      std::string getString();
		      int getNumber();
		      const char* int2char(char *src, int number);
	};

}

#endif
