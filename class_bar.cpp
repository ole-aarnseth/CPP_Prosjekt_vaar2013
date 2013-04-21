#include "class_bar.h"
#include <iostream>

using namespace music_n;

bar::bar(){timeleft = 0;}

bool bar::addTone(tone myTone){

	if(timeleft + (1/myTone.getLength()) <= 1){
	tones.push_back(myTone);
	timeleft +=(1/myTone.getLength());
	return true;
	}
}

tone bar::getTone(int i){
if((i) < tones.size())
	return tones[i];
}

int bar::getAntT(){
return tones.size();
}


