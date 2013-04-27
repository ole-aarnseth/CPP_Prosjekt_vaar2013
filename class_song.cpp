#include "class_song.h"
#include "class_sound.h"

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
    if(bars[barindeks].addNote(myNote))
    {
    return true;
    }
  return false;
  }

  return false;
}

bool song::validateNote(note myNote){
  
}

bool song::addBar(){
  bar newbar;
  bars.push_back(newbar);
}

int song::barCount(){
  return bars.size();
}

void song::play(){
  sound mySound;
  mySound.playSequence(mySound.parse(bars,bpm));
}

