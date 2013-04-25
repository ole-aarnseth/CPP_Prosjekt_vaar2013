#include "class_song.h"

using namespace music;

song::song(std::string c_title, int c_bpm)
{
  title = c_title;
  bpm = c_bpm;
}

int song::getBpm(){
  return bpm;
}

std::string song::getTitle(){
  return title;
}

void song::rename(std::string newtitle){
  title = newtitle;
}

void song::setBpm(int newbpm){
  bpm = newbpm;
}

bool song::addNotes(note myNote, int barindeks){
  if(barindeks < bars.size()){
    bars[barindeks].addNote(myNote);
    return true;
  }

  return false;
}

bool song::addBar(){
  bar newbar;
  bars.push_back(newbar);
}

int song::barCount(){
  return bars.size()-1;
}