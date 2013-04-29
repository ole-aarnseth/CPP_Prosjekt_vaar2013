#include "class_bar.h"
#include <iostream>

using namespace music;

bar::bar(){timeleft = 0;}

bool bar::addNote(note myNote){
double one = 1;

	if(timeleft + (one/(double)myNote.getLength()) <= 1){
	notes.push_back(myNote);
	timeleft = timeleft + (one/(double)myNote.getLength());
	return true;
	}

return false;
}

note bar::getNote(int i){
if((i) < notes.size())
	return notes[i];
}

int bar::getAntT(){
return notes.size();
}

double bar::getTimeleft(){
  return timeleft;
}
