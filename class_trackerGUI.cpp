#include "class_trackerGUI.h"

using namespace music;

void trackerGUI::createWindow()
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

void trackerGUI::refreshWindow()
{
	attroff(COLOR_PAIR(1));
	int tempy = wstarty + wheight - 2;
	int tempx = wstartx + 5;
	int stop = wheight - 2;

	bar ba = mySong.getBar(currentbar);
	std::vector<note> notelist = ba.getNotes();

	if (stop < notelist.size())
	{
		int y = notelist.size() - 1;
		for (int i = 0; i < stop; i++)
		{
			mvprintw(tempy, tempx, "               ");
			attron(A_UNDERLINE);
			mvprintw(tempy--, tempx, "%s       %d", (char*)notelist[y].getKey().c_str(), notelist[y].getLength());
			attroff(A_UNDERLINE);
			y--;
		}
	}

	else
	{
		for (int i = notelist.size() - 1; i >= 0; i--)
		{
			mvprintw(tempy, tempx, "               ");
			attron(A_UNDERLINE);
			mvprintw(tempy--, tempx, "%s       %d", (char*)notelist[i].getKey().c_str(), notelist[i].getLength());
			attroff(A_UNDERLINE);
		}
	}

	attron(COLOR_PAIR(1));
}

void trackerGUI::dispMenu()
{
	//clear();
	int pos = (COLS - 48) / 2;
	mvprintw(1, pos, "  ____");
	mvprintw(2, pos, " / ___|___  _ __ ___  _ __   ___  ___  ___ _ __ ");
	mvprintw(3, pos, "| |   / _ \\| '_ ` _ \\| '_ \\ / _ \\/ __|/ _ \\ '__|");
	mvprintw(4, pos, "| |__| (_) | | | | | | |_) | (_) \\__ \\  __/ |   ");
	mvprintw(5, pos, " \\____\\___/|_| |_| |_| .__/ \\___/|___/\\___|_|");
	mvprintw(6, pos, "                     |_|");

	pos = (COLS - 70) / 2;
	mvprintw(8, pos, "F2 = NOTE + | F4 BAR + | F6 = PLAY | F8 = BPM | F9 = DEMO | F12 = EXIT");
	mvprintw(9, pos, "F3 = NOTE - | F5 BAR - | F4 = CP BARS | F7 = RN SONG | F10 = NEW SONG");
	mvprintw(10, pos, "-----------------------------------------------------------------------");
	move(11, pos);
	printw("Song name: ");
	printw((char*)mySong.getTitle().c_str());
	printw(" | Current BPM: ");
	printw(toolBox.int2char(myArr,mySong.getBpm()));
	printw(" | Bar count: ");
	printw(toolBox.int2char(myArr,mySong.barCount()));
	printw(" | Note count: ");
	printw(toolBox.int2char(myArr,mySong.noteCount()));

	//printw("\n\n");
}

trackerGUI::trackerGUI() :
wheight(19),
currentbar(0),
whorizontal("+-------------------+"),
wvertical("|                   |"),
mySong("Untitled", 100)
{
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	//raw(); added from tracker
	curs_set(1);

	dispMenu();

	wwidth = whorizontal.length();
	wstarty = ((LINES - wheight) / 2) + 6;
	wstartx = (COLS - wwidth) / 2;

	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	int inx = (COLS - 16) / 2; // Subtract total length of both fields
	int iny = wstarty + wheight;
	mvprintw(iny, inx - 10, "Input:");

	attron(COLOR_PAIR(1));
	mvprintw(iny, inx, "      ");
	field.push_back(formField(6, iny, inx));
	inx = inx + 9;
	mvprintw(iny, inx, "      ");
	field.push_back(formField(6, iny, inx));
	attroff(COLOR_PAIR(1));

	createWindow();
	attron(COLOR_PAIR(1));
	unsigned int current = 0;
	move(field[current].getYpos(), field[current].getXpos());

	while(true)
	{
		ch = getch();

		if (ch == 9) // Tab
		{
			current = current == 0 ? 1 : 0;
			move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
		}

		else if (ch == 10) // Enter
		{
			/*notelist.push_back(field[0].getBuffer());
			length.push_back(toolBox.char2int(field[1].getCBuffer()));
			refreshWindow();*/

			note myNote(field[0].getBuffer(), toolBox.char2int(field[1].getCBuffer()));

			if (mySong.addNotes(myNote, currentbar))
			{
				refreshWindow();
			}

			else
			// <print feilmld>

			field[0].resetBuffer();
			field[1].resetBuffer();
			mvprintw(field[0].getYpos(), field[0].getXpos(), "      ");
			mvprintw(field[1].getYpos(), field[1].getXpos(), "      ");
			current = 0;
			move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
		}

		else if (ch == KEY_BACKSPACE)
		{
			field[current].delFromBuffer();
			mvprintw(field[current].getYpos(), field[current].getXpos(), "      ");
			mvprintw(field[current].getYpos(), field[current].getXpos(), "%s", field[current].getCBuffer());
			move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
		}

		else if (ch == KEY_RIGHT)
		{
			field[current].moveRight();
			move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
		}

		else if (ch == KEY_LEFT)
		{
			field[current].moveLeft();
			move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
		}

		else if (ch == KEY_F(3))
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

		else if (ch == KEY_F(4))
		{
			mySong.addBar();
			currentbar++;
			dispMenu();
		}

		else if (ch == KEY_F(5))
		{
			char buffer[10];
			printw("\nWhat bar do you want to erase? ");
			echo();
			getstr(buffer);
			int tall = toolBox.char2int(buffer);

			for(int i = 1; i < mySong.getBar(tall-1).getAntT(); i++)
			mySong.deleteNote(tall, i);

			if(mySong.delBar(toolBox.char2int(buffer)))
			dispMenu();

			else
			printw("Invalid selection!");
		}

		else if (ch == KEY_F(6))
		{
			char buffer[10];
			printw("\nHow many times? ");
			echo();
			getstr(buffer);
			int iterations = toolBox.char2int(buffer);

			for(int i = 0; i < iterations; i++)
			mySong.play();

			printw("\nDone ");
		}

		else if (ch == KEY_F(7))
		{
			char buffer[255];
			printw("\nNew name: ");
			echo();
			getstr(buffer);
			mySong.rnTitle(buffer);
			dispMenu();
		}

		else if (ch == KEY_F(8))
		{
			char buffer[10];
			echo();
			printw("New BPM: ");
			getstr(buffer);
			mySong.setBpm(toolBox.char2int(buffer));
			dispMenu();
		}

		else if (ch == KEY_F(9))
		{
			currentbar = 1;
			demo myDemo;
			mySong = myDemo.grieg();
			dispMenu();
			char buff[255];
			printw("\n");
			printw(mySong.bar2char(buff, currentbar));
		}

		else if (ch == KEY_F(10))
		{
			currentbar = 0;
			mySong = song("Untitled", 100);
			dispMenu();
		}

		else if (ch == KEY_F(12)) // Exit
		break;

		else if (ch == KEY_F(17))
		{
			char buffer[10];
			echo();
			bar myBar = mySong.getBar(mySong.barCount() - 1);
			toolBox.dbl2char(myBar.getTimeleft(),buffer);
			printw("Timeleft in the current bar: ");
			printw(buffer);
			printw("\n");
		}

		else if (ch == KEY_UP && mySong.barCount() > currentbar)
		{
			//clear();
			dispMenu();
			currentbar++;
			char buff[1000];
			printw("\n");
			printw(toolBox.int2char(buff, currentbar));
			printw("\n");
			printw(mySong.bar2char(buff, currentbar));
		}

		else if (ch == KEY_DOWN && currentbar - 1 != 0 && mySong.barCount() > 0)
		{
			//clear();
			dispMenu();
			currentbar--;
			char buff[1000];
			printw("\n");
			printw(toolBox.int2char(buff, currentbar));
			printw("\n");
			printw(mySong.bar2char(buff, currentbar));
		}

		else
		{
			field[current].addToBuffer((char) ch);
			mvprintw(field[current].getYpos(), field[current].getXpos(), "%s", field[current].getCBuffer());
			move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
		}

		refresh();
	}
	attroff(COLOR_PAIR(1));

	endwin();

	mainMenu mainM;
}
