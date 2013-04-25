#include "class_bar.h"
#include <iostream>

using namespace music;

bar::bar(){timeleft = 0;}

bool bar::addNote(note myNote){

	if(timeleft + (1/myNote.getLength()) <= 1){
	notes.push_back(myNote);
	timeleft +=(1/myNote.getLength());
	return true;
	}
	else{
	return false;
	}
}

note bar::getNote(int i){
if((i) < notes.size())
	return notes[i];
}

int bar::getAntT(){
return notes.size();
}
