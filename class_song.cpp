#include "class_song.h"
#include "class_sound.h"
#include "class_tools.h"
#include "class_note.h"

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

void song::rnTitle(std::string newname){
  title = newname;
}

void song::rename(std::string newtitle){
  title = newtitle;
}

void song::setBpm(int newbpm){
  bpm = newbpm;
}

bool song::addNotes(note myNote, int barindeks){
  if(barindeks-1 < bars.size()){
    
    if(bars[barindeks-1].addNote(myNote))
    {
    return true;
    }
  return false;
  }

  return false;
}

bool song::addBar(){
  bar newbar;
  bars.push_back(newbar);
}

int song::barCount(){
  return bars.size();
}

int song::noteCount(){
int counter = 0;
  for(int i = 0; i < bars.size(); i++){
    counter += bars[i].getAntT();
  }
  return counter;
}

void song::play(){
  sound mySound;
  mySound.playSequence(mySound.parse(bars,bpm));
}

bar song::getBar(int i){
  return bars[i];
}

bool song::delBar(int i){
  
  if(i == 0)
  {
    return false;
  }

  if(i <= bars.size())
  {    
    bars.erase(bars.begin()+i);
    return true;
  }

return false;
}

const char* song::bar2char(char *src, int number){
  std::string output;
  tools myTools;
  bar thisbar = bars[number-1];
  std::vector<note> notes = thisbar.getNotes();
  
  for(int i = 0; i < notes.size(); i++)
  {
    output.append(myTools.int2string(i+1));
    output.append(": ");
    output.append(notes[i].toString());   
  }

src = (char*)output.c_str();
return src;
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

    if(c == 'C' || c == 'D'|| c == 'E' || c == 'F' || c == 'G' || c == 'B' || c == 'A')
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

    if(c == 'C' || c == 'D'|| c == 'E' || c == 'F' || c == 'G' || c == 'B' || c == 'A')
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

bool song::deleteNote(int barindeks, int noteindeks)
{
  if(barindeks-1 < bars.size())
  {
    
    if(bars[barindeks-1].deleteNote(noteindeks))
    {
      return true;
    }

    return false;
  }

  return false;

}
