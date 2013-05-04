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

trackerGUI::trackerGUI() :
wheight(13),
whorizontal("+-------------------+"),
wvertical("|                   |")
{
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();

	wstarty = (LINES - 10) / 2;
	wstartx = (COLS - 21) / 2;
	wwidth = 21;
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

	while((ch = getch()) != 9)
	{
		switch(ch)
		{
			case KEY_DOWN:
			case KEY_UP:
				current = current == 0 ? 1 : 0;
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
			case 9: // Tab
				break;
			case 10: // Enter
				note.push_back(field[0].getBuffer());
				length.push_back(toolBox.char2int(field[1].getCBuffer()));
				refreshWindow();
				field[0].resetBuffer();
				field[1].resetBuffer();
				mvprintw(field[0].getYpos(), field[0].getXpos(), "      ");
				mvprintw(field[1].getYpos(), field[1].getXpos(), "      ");
				current = 0;
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
			case KEY_BACKSPACE:
				field[current].delFromBuffer();
				mvprintw(field[current].getYpos(), field[current].getXpos(), "      ");
				mvprintw(field[current].getYpos(), field[current].getXpos(), "%s", field[current].getCBuffer());
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
			case KEY_RIGHT:
				field[current].moveRight();
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
			case KEY_LEFT:
				field[current].moveLeft();
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
			default:
				field[current].addToBuffer((char) ch);
				mvprintw(field[current].getYpos(), field[current].getXpos(), "%s", field[current].getCBuffer());
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
		}
	}
	attroff(COLOR_PAIR(1));
	getch();
	endwin();
}

int main()
{
	trackerGUI gui;

	return 0;
}
