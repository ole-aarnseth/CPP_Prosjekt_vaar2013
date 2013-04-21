#ifndef CLASS_BAR_H
#define CLASS_BAR_H

#include <string>
#include <vector>
#include "class_tone.h"


namespace music_n{

	class bar
	{
	std::vector<tone> tones;
	int ant_toner;	//Used for iteration
	double timeleft;		
		public:
			bar();
			bool addTone(tone myTone);
			bool removeTone(int i);
			bool checkSpace(tone myTone);
			tone getTone(int i);
			int getAntT();
	};

}

#endif
