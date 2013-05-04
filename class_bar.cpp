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
if((i) < notes.size()){
  return notes.at(i);
  }
}

std::vector<note> bar::getNotes(){
  return notes;
}

int bar::getAntT(){
return notes.size();
}

double bar::getTimeleft(){
  return timeleft;
}

bool bar::deleteNote(int i)
{
  if(i == 0)
  {
    return false;
  }

  if(i <= notes.size())
  {
    notes.erase(notes.begin() + i-1);
    return true;
  }

  else
  {
    return false;
  }
}
