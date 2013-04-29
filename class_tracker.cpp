#include "class_tracker.h"

using namespace music;

void tracker::track(){

tools mytools;
song mySong("Untitled", 120);
char myArr[255];

	int ch;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	refresh();
	
	int pos = (80 - 48) / 2;
	mvprintw(1, pos, "   ___        __                 ______");
	mvprintw(2, pos, "  / _ \\ ___  / /_ ___ _  ____   /_  __/");
	mvprintw(3, pos, " / , _// -_)/ __// _ `/ / __/ _  / /");
	mvprintw(4, pos, "/_/|_| \\__/ \\__/ \\_,_/ /_/   (_)/_/");
	printw("\n");

	printw("\nF2 = NOTE + | F3 BAR + | F4 = PLAY | F5 = BPM | F6 = DEMO | F12 = EXIT\n");
	
	printw("\nSong name: ");
	printw(mySong.getTitle().c_str());
	printw(" | Current BPM: ");
	printw(mytools.int2char(myArr,mySong.getBpm()));
	printw(" | Bar count: ");
	printw(mytools.int2char(myArr,mySong.barCount()));
	printw("\n\n");
	
	
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
	printw("\nEnter length: ");
	getstr(length);
	str = key;
	note myNote(str, mytools.char2int(length));
	  if(mySong.addNotes(myNote, mySong.barCount()-1)){
	  printw("\nAdded note:");
	  printw((char*)myNote.getKey().c_str());
	  printw(", ");
	  printw(mytools.int2char(buffer,myNote.getLength()));
	  }
	  else{
	  printw("Invalid insertion!");
	  }
	}
	
	if(ch == KEY_F(3)){
	mySong.addBar(); 
	printw("\nBar count: ");
	printw(mytools.int2char(myArr,mySong.barCount()));
	}
	
	if(ch == KEY_F(4)){
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
	echo();
	printw("\nCurrent BPM: ");
	printw(mytools.int2char(myArr,mySong.getBpm())); 
	printw(", new BPM: ");
	getstr(buffer);
	mySong.setBpm(mytools.char2int(buffer));
	}
	
	if(ch == KEY_F(6)){
	demo myDemo;
	mySong = myDemo.grieg(); 
	}
	
	if(ch == KEY_F(7)){
	char buffer[10];
	echo();  
	bar myBar = mySong.getBar(mySong.barCount()-1);
	mytools.dbl2char(myBar.getTimeleft(),buffer);
	printw("Timeleft in the current bar: ");
	printw(buffer);
	printw("\n");
	}
	
	if(ch == KEY_F(12))
		break;//Exits program

	refresh();
	}
	endwin();
}