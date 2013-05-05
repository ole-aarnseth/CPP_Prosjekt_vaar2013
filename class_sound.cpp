#include <iostream>
#include "class_sound.h"


using namespace music;

//spiller av en hel vector med noter.
void sound::playSequence(std::vector<note_t> param){
  	int fd = open("/dev/console", O_WRONLY);

	for(int i = 0; i < param.size(); i++)
	{
  	ioctl(fd, KIOCSOUND, (int)(1193180/param[i].note));
  	usleep(1000*param[i].length);
	}

  	ioctl(fd, KIOCSOUND, 0);
  	close(fd);
}

std::vector<note_t> sound::parse(std::vector<bar> bars, int bpm){ //Gjør om til data synthen forstår. Spytter ut en vector av note structer som kan mates inn i playSequence(). 
std::vector<note_t> output;

	for(int i = 0; i < bars.size(); i++){
	
		for(int x = 0; x < bars[i].getAntT(); x++){
		note_t myNote;
		myNote.note = f_note.calcFreq((bars[i].getNote(x).getKey()));
		myNote.length = calculateLength(bars[i].getNote(x).getLength(), bpm);
		output.push_back(myNote);
		}
	}
return output;
}

//regner ut hvor lenge tonen skal spille i millisekunder.
int sound::calculateLength(double length, int bpm){
int notelength = ((60 * 1000)/bpm)*(4/length);
return notelength; 
}

//spiller av en enkelt tone, med mulighet for å spille av tonen konstant.
void sound::makeSound(int l, int h, bool cont)
{
	int fd = open("/dev/console", O_WRONLY);
  	ioctl(fd, KIOCSOUND, (int)(1193180/h));
	if(!cont){
	  usleep(1000*l);
	  ioctl(fd, KIOCSOUND, 0);
	  close(fd);
	}
}
