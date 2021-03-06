#include "class_help.h"
#include "class_mainMenu.h"

using namespace music;

//printer ut info om hvordan man bruker programmet.
void help::printHelp()
{
  initscr();
  echo();
  cbreak();
  raw();
 
  attron(A_BOLD);
  printw("\nHjelpemeny for BeepTracker.\n\n");
  attroff(A_BOLD); 
  
  printw("I Composer kan man lage sin egen sang, samt spille av denne sangen. For å lage en låt, må man først opprette en bar som kan holde på noter. Dette gjøres ved å trykke på F4. Deretter kan man legge til en note ved å trykke på F2. Det kan velges mellom noter fra A til G, og opp til åttende oktav, for eksempel A4 eller B#2. Etter dette velges notens lengde. Mulige notelengder er 1, 2, 4, 8, 16, og 32. Notelengden er egentlig en brøk, for eksempel ¼ . Når en skriver notelengden, spesifiserer man nevnerdelen av brøken. Denne lengden er også med på å bestemme hvor mange andre noter man kan ha i en bar. For eksempel hvis notens lengde var ¼ , kan det legges til tre ¼ noter til. Dette utgjør da en takt (bar). Notene og baren de tilhører vises så på skjermen."); 
  printw("\n\n");
  printw("Når en bar er full, må det opprettes en ny bar hvis man vil ha med flere noter. Ved å bruke piltastene, kan man bla gjennom de forskjellige barene, og se hvilke noter som tilhører dem. Denne navigasjonen brukes også for å velge hvilken bar en nylig skapt note havner i. For å slette en note, trykk F3. Oppgi deretter notens plassering som står til venstre for noten, og trykk enter. Ved sletting av bars trykk F5, og skriv inn barens nummer.");
  printw("\n\n");
  printw("En ferdigkomponert låt avspilles ved å trykke på F6. Hvor fort låta spilles av bestemmes av bpm (beats per minute). Bpm kan endres på ved å trykke F8, og skrive inn en ønsket verdi. For å endre sangens tittel trykk på F7, og skriv inn den nye tittelen. Hvis man vil lage en helt ny låt trykker man på F10. Det er også mulighet for å spille av en demo av Dovregubbens Hall. Dette gjøres ved å trykke på F9. Da lastes demoen inn, og man starter låta ved bruk av F6.\n\n");

  printw("Press any key to return to main menu");
  
  getch();
  
  refresh();
  endwin();
  mainMenu mainM;
}
