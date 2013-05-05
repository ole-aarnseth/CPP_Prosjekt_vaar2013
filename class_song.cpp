#include "class_song.h"
#include "class_sound.h"
#include "class_tools.h"
#include "class_note.h"

using namespace music;

//konstruktør
song::song(std::string c_title, int c_bpm)
{
  title = c_title;
  bpm = c_bpm;
}

//getfunksjon for bpm.
int song::getBpm(){
  return bpm;
}

//getfunksjon for title.
std::string song::getTitle(){
  return title;
}

//setfunksjon for title;
void song::rnTitle(std::string newname){
  title = newname;
}

//setfunksjon for bpm.
void song::setBpm(int newbpm){
  bpm = newbpm;
}

//legger til en note på en bestemt bar, og returnerer true hvis operasjonen var vellykket.
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

//legger til en ny bar i vectoren bars.
bool song::addBar(){
  bar newbar;
  bars.push_back(newbar);
}

//returnerer størrelsen til vectoren bars.
int song::barCount(){
  return bars.size();
}

//returnerer antall noter totalt i bars.
int song::noteCount(){
int counter = 0;
  for(int i = 0; i < bars.size(); i++){
    counter += bars[i].getAntT();
  }
  return counter;
}

//kaller på playSequence og parse som spiller av alle bars og noter som befinner seg i bars, til et visst tempo.
void song::play(){
  sound mySound;
  mySound.playSequence(mySound.parse(bars,bpm));
}

//getfunksjon for vectoren bars.
bar song::getBar(int i){
  return bars[i];
}

//fjerner en bar fra vectoren bars.
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

//gjør om notene i bars til char.
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

//sjekker at riktig form for note blir tastet inn.
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

//sjekker at notens lengde er riktig.
bool song::validateNoteLength(int i)
{
  int wrongCount = 0;

  if(i == 1 || i == 2 || i == 4 || i == 8 || i == 16 || i == 32)
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

//sletter en note fra en gitt bar i vectoren bars.
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
