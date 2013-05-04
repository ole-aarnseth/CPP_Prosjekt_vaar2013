#ifndef CLASS_FREQNOTE_H
#define CLASS_FREQNOTE_H

#include <string>

#define A 1.0594630943592952

namespace freq{

	class FreqNote
	{
		int calcHalfStepOffset(std::string note);

		public:
			float calcFreq(std::string note);
	};

}

#endif