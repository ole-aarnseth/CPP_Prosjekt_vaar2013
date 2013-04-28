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

bool song::validateNote(std::string note)
{
  int wrongCount = 0;

  if(note.length() > 3 || note.length() < 2)
  {
    
    wrongCount++;
  }

  
  
  if(note.length() == 2)
  {

    char c = note.at(0);

    if(c == 'C' || c == 'D'|| c == 'E' || c == 'F' || c == 'G' || c == 'B')
    {

   
    }

    else
    {
  wrongCount++;
    }

    char d = note.at(1);

    if(d == '0' || d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8')
    {
     
     
    }

    else
    {
	wrongCount++;
    }
  }

  if(note.length() == 3)
  {
    char c = note.at(0);

    if(c == 'C' || c == 'D'|| c == 'E' || c == 'F' || c == 'G' || c == 'B')
    {

    
    }

    else
    {
	wrongCount++;
    }

    char e = note.at(1);

    if(e == '#' || e == 'b')
    {
     
    
    }

    else
    {
      wrongCount++;
    }
    
     char d = note.at(2);

    if(d == '0' || d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8')
    {
     
    }

    else
    {
	wrongCount++;
    }
  }
  
  if (wrongCount >= 1)
  {
      return false;
  }

  else
  {
      return true;
  }
}

bool song::validateNoteLength(int i)
{
  int wrongCount = 0;

  if(i == 1 || i == 4 || i == 8 || i == 16 || i == 32)
  {

  }

  else
  {
    wrongCount++;
  }
  
   
  if (wrongCount >= 1)
  {
      return false;
  }

  else
  {
      return true;
  }

 

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

