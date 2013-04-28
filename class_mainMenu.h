#ifndef CLASS_MAINMENU_H
#define CLASS_MAINMENU_H

#include <ncurses.h>
#include <string>

#define WIDTH 17
#define HEIGHT 8
#define N_CHOICES 4

namespace menu{

	class mainMenu{
		int startx;
		int starty;
		std::string choices[N_CHOICES];
		void print_menu(WINDOW *menu_win, int highlight);

		public:
			mainMenu();
	};
}

#endif