#ifndef CLASS_FREQNOTE_H
#define CLASS_FREQNOTE_H

#include <string>

namespace freq{

	class FreqNote
	{
		int calcHalfStepOffset(std::string note);

		public:
			float calcFreq(std::string note);
	};

}

#endif