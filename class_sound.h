#ifndef CLASS_SOUND_H
#define CLASS_SOUND_H

#include <iostream>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "class_bar.h"
#include "class_freqnote.h"
#include <unistd.h>

namespace music{

struct note_t{
	float note;
	int length;
	};

	class sound
	{
		freq::FreqNote f_note;
	
		public:
			void playSequence(std::vector<note_t> param);
			std::vector<note_t> parse(std::vector<bar> bars, int bpm);
			int calculateLength(double length, int pbm);
			
	};

}

#endif
