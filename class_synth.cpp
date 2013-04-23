#include "class_synth.h"
#include <iostream>

using namespace music_n;

void synth::playSequence(std::vector<tone_t> param){
  	int fd = open("/dev/console", O_WRONLY);

	for(int i = 0; i < param.size(); i++)
	{
  	ioctl(fd, KIOCSOUND, (int)(1193180/param[i].tone));
  	usleep(1000*param[i].length);
	}

  	ioctl(fd, KIOCSOUND, 0);
  	close(fd);
}

std::vector<tone_t> synth::parse(std::vector<bar> bars, int bpm){ //Gjør om til data synthen forstår. Spytter ut en vector av tone structer som kan mates inn i playSequence(). 
std::vector<tone_t> output;
std::cout << "line 21!" << std::endl;

	for(int i = 0; i < bars.size(); i++){
	
		for(int x = 0; x < bars[i].getAntT(); x++){
		std::cout << "line 26!" << std::endl;
		tone_t myTone;
		myTone.tone = f_note.calcFreq((bars[i].getTone(x).getKey()));
		myTone.length = calculateLength(bars[i].getTone(x).getLength(), bpm);
		output.push_back(myTone);
		std::cout << "line 32!" << std::endl;
		}
	std::cout << "line 33!" << std::endl;
	}
std::cout << "line 35!" << std::endl;
return output;
}

int synth::calculateLength(double length, int bpm){
int tonelength = bpm*((4+2)/(length/4));
return tonelength; 
}
