//22 18 83 35
#include <iostream>
#include "class_song.h"
#include "class_sound.h"
#include <ncurses.h>
#include <string>
#include "class_tools.h"

using namespace music;
 
int main(){
tools mytools;
song mySong("Untitled", 120);

char myArr[255];

	int ch;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
    	printw("Retarded Tracker!\n\n");
	printw("F2 = ADD NOTE | F3 ADD BAR | F4 = PLAY | F5 = CHANGE BPM | F6 = GRIEG MODE | F12 = EXIT\n");
	
	printw("\nSong name: ");
	printw(mySong.getTitle().c_str());
	printw("| Current BPM: ");
	printw(mytools.int2char(myArr,mySong.getBpm()));
	printw("| Bar count: ");
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
	  printw(myNote.getKey().c_str());
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
	mySong = song("Grieg", 50);
	mySong.addBar();
	note myNote("A#2", 8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("D#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("F3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("F3",4);
	mySong.addNotes(myNote, mySong.barCount()-1);
	
	mySong.addBar();
	myNote = note("E3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("E3",4);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("D#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("B2",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("D#3",4);
	mySong.addNotes(myNote, mySong.barCount()-1);
	
	mySong.addBar();
	myNote = note("A#2", 8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("D#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("F3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("F3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("A#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	
	mySong.addBar();
	myNote = note("G#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("F3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("C#3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("F3",8);
	mySong.addNotes(myNote, mySong.barCount()-1);
	myNote = note("G#3",2);
	mySong.addNotes(myNote, mySong.barCount()-1);
	printw("\nDef 2 iterasjoner for best effekt, '30' BPM for techno.");
	
	
	
	//myNote = note("C3",8);
	//mySong.addNotes(myNote, mySong.barCount()-1);
	}

	if(ch == KEY_F(12))
		break;//Exits program

	refresh();
	}
	endwin();
return 0;
}

