#ifndef CLASS_FREQNOTE_H
#define CLASS_FREQNOTE_H

#include <string>

#define A 1.0594630943592952 // Konstant benyttet i utregning

namespace freq{

	class FreqNote // Klasse for omregning av note til freq (frekvens)
	{
		// Funksjon som blir benyttet av algoritmen, regner ut hvor mange "halfsteps" unna A4 noten befinner seg
		int calcHalfStepOffset(std::string note);

		public:
			float calcFreq(std::string note); // Algoritme som regner ut frekvens basert på tone
	};

}

#endif