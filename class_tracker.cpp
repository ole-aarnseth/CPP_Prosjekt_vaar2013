#include "class_tracker.h"
#include "class_mainMenu.h"

using namespace music;

tools mytools;
song mySong("Untitled", 100);
char myArr[255];

void tracker::track(){

	int ch;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	refresh();
		
	dispMenu();
	
	while(true){
	
	ch = getch();
	
	if(ch == KEY_F(2)){
	char key[10];
	char length[10];
	char buffer[255];
	std::string str;
	echo();
	printw("\nEnter key: ");
	getstr(key);  
	printw("Enter length: ");
	getstr(length);
	str = mytools.convertLetter(key);
	note myNote(str, mytools.char2int(length));
	  if(mySong.addNotes(myNote, mySong.barCount()-1)){
	  dispMenu();
	  char buff[255];
	  printw("\n");
	  printw(mySong.bar2char(buff, mySong.barCount()-1));
	  }
	  else{
	  printw("Invalid insertion!");
	  }
	}
	
	if(ch == KEY_F(4)){
	mySong.addBar(); 
	dispMenu();
	}
	
	if(ch == KEY_F(6)){
	char buffer[10];
	printw("\nHow many times? ");
	echo();
	getstr(buffer);
	int iterations = mytools.char2int(buffer);
	for(int i = 0; i < iterations; i++){
	  mySong.play();
	}
	printw("\nDone ");
	}
	
	if(ch == KEY_F(5)){
	char buffer[10];
	printw("\nWhat bar do you want to erase? ");
	echo();
	getstr(buffer);  
	if(!mySong.delBar(mytools.char2int(buffer)))
	  printw("Invalid selection!");
	dispMenu();
	}

	if(ch == KEY_F(8)){
	char buffer[10];
	echo();
	printw("New BPM: ");
	getstr(buffer);
	mySong.setBpm(mytools.char2int(buffer));
	dispMenu();
	}
	
	if(ch == KEY_F(9)){
	demo myDemo;
	mySong = myDemo.grieg();
	dispMenu();
	}
	
	if(ch == KEY_F(17)){
	char buffer[10];
	echo();  
	bar myBar = mySong.getBar(mySong.barCount()-1);
	mytools.dbl2char(myBar.getTimeleft(),buffer);
	printw("Timeleft in the current bar: ");
	printw(buffer);
	printw("\n");
	}
	
	if(ch == KEY_F(7)){
	char buffer[255];
	printw("\nNew name: ");
	echo();
	getstr(buffer);
	mySong.rnTitle(buffer);
	dispMenu();
	}
	
	if(ch == KEY_F(10)){
	mySong = song("Untitled", 100);
	dispMenu();
	}
	
	if(ch == KEY_F(12))
		break;//Exits program

	refresh();
	}
	endwin();
	
  mainMenu mainM;
}

void tracker::dispMenu(){
clear();
int pos = (80 - 48) / 2;
	mvprintw(1, pos, "   ___        __                 ______");
	mvprintw(2, pos, "  / _ \\ ___  / /_ ___ _  ____   /_  __/");
	mvprintw(3, pos, " / , _// -_)/ __// _ `/ / __/ _  / /");
	mvprintw(4, pos, "/_/|_| \\__/ \\__/ \\_,_/ /_/   (_)/_/");
	printw("\n");

	printw("\nF2 = NOTE + | F4 BAR + | F6 = PLAY | F8 = BPM | F9 = DEMO | F12 = EXIT");
	printw("\nF3 = NOTE - | F5 BAR - | F4 = CP BARS | F7 = RN SONG | F10 = NEW SONG  \n");
	printw("-----------------------------------------------------------------------");
	
	printw("\nSong name: ");
	printw(mySong.getTitle().c_str());
	printw(" | Current BPM: ");
	printw(mytools.int2char(myArr,mySong.getBpm()));
	printw(" | Bar count: ");
	printw(mytools.int2char(myArr,mySong.barCount()));
	printw(" | Note count: ");
	printw(mytools.int2char(myArr,mySong.noteCount()));
	
	printw("\n\n");
}