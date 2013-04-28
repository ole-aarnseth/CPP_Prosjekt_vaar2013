#include "class_mainMenu.h"

using namespace menu;

mainMenu::mainMenu() :
startx(0),
starty(0)
{
	choices[0] = "Piano Mode";
	choices[1] = "Tracker Mode";
	choices[2] = "Help";
	choices[3] = "Exit";

	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	curs_set(0); // Hide cursor
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);

	// Set header-text:
	int pos = (80 - 48) / 2;
	mvprintw(1, pos, " __  __       _         __  __                  ");
	mvprintw(2, pos, "|  \\/  | __ _(_)_ __   |  \\/  | ___ _ __  _   _ ");
	mvprintw(3, pos, "| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |");
	mvprintw(4, pos, "| |  | | (_| | | | | | | |  | |  __/ | | | |_| |");
	mvprintw(5, pos, "|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|");

	refresh();
	print_menu(menu_win, highlight);
	while(true)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = N_CHOICES;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == N_CHOICES)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}

	clrtoeol();
	refresh();
	endwin();

	if (choice == 1)
	{
		// <start piano mode>
	}

	else if (choice == 2)
	{
		// <start tracker mode>
	}

	else if (choice == 3)
	{
		// <display help text>
	}

	else
	{
		// exit
	}
}


void mainMenu::print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < N_CHOICES; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", (char*)choices[i].c_str());
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", (char*)choices[i].c_str());
		++y;
	}
	wrefresh(menu_win);
}
