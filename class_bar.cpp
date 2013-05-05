#include "class_bar.h"
#include <iostream>

using namespace music;

//Ved opprettelse av en bar, vil alltid timeused være 0, men
//dekrementere etthvert som noter settes inn.  
bar::bar(){timeused = 0;}

//Notes settes inn. Timeused oppdateres. Legg merke til bruk av double da
//en tones lengde egentlig er en brøk, 1/4, 1/8 osv. 
//En full takt vil da være 1. Hvis ikke innsetting er vellykket, returneres false.
bool bar::addNote(note myNote){
double one = 1;
if(timeused + (one/(double)myNote.getLength()) <= 1){
  notes.push_back(myNote);
  timeused = timeused + (one/(double)myNote.getLength());
  return true;
  }
return false;
}

//Returnerer note på indeks i.
note bar::getNote(int i){
if((i) < notes.size()){
  return notes.at(i);
  }
}

//returnerer hele vecotren med noter.
std::vector<note> bar::getNotes(){
  return notes;
}

//returnerer antall noter i takten (bar).
int bar::getAntT(){
return notes.size();
}

//returner tid brukt i takten.
double bar::getTimeleft(){
  return timeused;
}

//sletter note @i.
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
