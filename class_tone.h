#ifndef CLASS_TONE_H
#define CLASS_TONE_H

#include <string>

namespace tone_n{

	class tone
	{
	std::string key;
	int length;		
		public:
			tone(std::string c_key, int c_length);
			int getLength();
			std::string getKey();
	};

}

#endif
