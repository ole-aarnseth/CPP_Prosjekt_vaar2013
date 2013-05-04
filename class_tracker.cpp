#include "class_tracker.h"
#include "class_mainMenu.h"

using namespace music;

song mySong("Untitled", 100);
char myArr[255];

void tracker::createWindow()
{
	int tempy = wstarty;
	int stop = wheight - 2;

	char *wh = (char*)whorizontal.c_str();
	char *wv = (char*)wvertical.c_str();

	mvprintw(tempy, wstartx, "%s", wh);

	for (int i = 0; i < stop; i++)
	mvprintw(++tempy, wstartx, "%s", wv);

	mvprintw(++tempy, wstartx, "%s", wh);
	mvprintw(wstarty - 1, (COLS - 16) / 2, "Note:   Length:");
	refresh();
}

void tracker::refreshWindow()
{
	attroff(COLOR_PAIR(1));
	int tempy = wstarty + wheight - 2;
	int tempx = wstartx + 5;
	int stop = wheight - 2;

	if (stop < note.size())
	{
		int y = note.size() - 1;
		for (int i = 0; i < stop; i++)
		{
			mvprintw(tempy, tempx, "               ");
			attron(A_UNDERLINE);
			mvprintw(tempy--, tempx, "%s       %d", (char*)note[y].c_str(), length[y]);
			attroff(A_UNDERLINE);
			y--;
		}
	}

	else
	{
		for (int i = note.size() - 1; i >= 0; i--)
		{
			mvprintw(tempy, tempx, "               ");
			attron(A_UNDERLINE);
			mvprintw(tempy--, tempx, "%s       %d", (char*)note[i].c_str(), length[i]);
			attroff(A_UNDERLINE);
		}
	}

	attron(COLOR_PAIR(1));
}

void tracker::track(){

	int currentbar = 0;
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
	str = toolBox.convertLetter(key);
	note myNote(str, toolBox.char2int(length));

	  if(mySong.addNotes(myNote,currentbar)){
	  dispMenu();
	  char buff[500];
	  printw("\n");
	  printw(toolBox.int2char(buff, currentbar));
	  printw("\n");
	  printw(mySong.bar2char(buff, currentbar));
	  }
	  else{
	  printw("Invalid insertion!");
	  }
	}

	if(ch == KEY_F(3))
	{

	  char noteindeks[10];
	  echo();
	  printw("\nNumber of note to delete: ");
	  printw("\n");
	  getstr(noteindeks);

	  if(mySong.deleteNote(currentbar, toolBox.char2int(noteindeks)))
	  {
	    dispMenu();
	    char buff[500];
	    printw("\n");
	    printw(toolBox.int2char(buff, currentbar));
	    printw("\n");
	    printw(mySong.bar2char(buff, currentbar));
	  }

	  else
	  {
	    printw("Could not delete note!");
	  }
	}

	if(ch == KEY_F(4)){
	mySong.addBar();
	currentbar++;
	dispMenu();
	}

	if(ch == KEY_F(6)){
	char buffer[10];
	printw("\nHow many times? ");
	echo();
	getstr(buffer);
	int iterations = toolBox.char2int(buffer);
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
	int tall = toolBox.char2int(buffer);
	for(int i = 1; i < mySong.getBar(tall-1).getAntT(); i++)
	{
	  mySong.deleteNote(tall, i);
	}
	if(mySong.delBar(toolBox.char2int(buffer)))
	{
	    dispMenu();

	}

	else
	{
	    printw("Invalid selection!");
	}

	}

	if(ch == KEY_F(8)){
	char buffer[10];
	echo();
	printw("New BPM: ");
	getstr(buffer);
	mySong.setBpm(toolBox.char2int(buffer));
	dispMenu();
	}

	if(ch == KEY_F(9)){
	currentbar = 1;
	demo myDemo;
	mySong = myDemo.grieg();
	dispMenu();
	char buff[255];
	printw("\n");
	printw(mySong.bar2char(buff, currentbar));
	}

	if(ch == KEY_F(17)){
	char buffer[10];
	echo();
	bar myBar = mySong.getBar(mySong.barCount()-1);
	toolBox.dbl2char(myBar.getTimeleft(),buffer);
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
	  currentbar = 0;
	  mySong = song("Untitled", 100);
	  dispMenu();
	}

	if(ch == KEY_F(12))
		break;//Exits program

	if(ch == 259 && mySong.barCount() > currentbar)//<
	{
	    clear();
	    dispMenu();
	    currentbar++;
	    char buff[1000];
	    printw("\n");
	    printw(toolBox.int2char(buff, currentbar));
	    printw("\n");
	    printw(mySong.bar2char(buff, currentbar));
	}

	if(ch == 258 && currentbar-1 != 0)//<
	{
	    clear();
	    dispMenu();
	    currentbar--;
	    char buff[1000];
	    printw("\n");
	    printw(toolBox.int2char(buff, currentbar));
	    printw("\n");
	    printw(mySong.bar2char(buff, currentbar));
	}

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
	printw(toolBox.int2char(myArr,mySong.getBpm()));
	printw(" | Bar count: ");
	printw(toolBox.int2char(myArr,mySong.barCount()));
	printw(" | Note count: ");
	printw(toolBox.int2char(myArr,mySong.noteCount()));

	printw("\n\n");
}
