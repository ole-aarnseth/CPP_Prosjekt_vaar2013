#ifndef CLASS_NOTE_H
#define CLASS_NOTE_H

#include <string>

namespace music{

	class note
	{
	std::string key;
	int length;
		public:
			note(std::string c_key, int c_length);
			int getLength();
			std::string getKey();
	};

}

#endif
