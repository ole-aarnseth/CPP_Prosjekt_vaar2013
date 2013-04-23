#ifndef CLASS_SYNTH_H
#define CLASS_SYNTH_H

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

namespace music_n{

struct tone_t{
	float tone;
	int length;
	};

	class synth
	{
		freq::FreqNote f_note;
	
		public:
			void playSequence(std::vector<tone_t> param);
			std::vector<tone_t> parse(std::vector<bar> bars, int bpm);
			int calculateLength(double length, int pbm);
			
	};

}

#endif
