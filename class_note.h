#ifndef CLASS_NOTE_H
#define CLASS_NOTE_H

#include <string>

namespace music{

	class note
	{
	std::string key;
	double length;
		public:
			note(std::string c_key, double c_length);
			double getLength();
			std::string getKey();
	};

}

#endif
