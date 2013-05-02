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
	mvprintw(wstarty - 1, (COLS - 16) / 2, "Note:    Length:");
	refresh();
}

void trackerGUI::refreshWindow()
{
	int ty = (wheight / 2) + wstarty;
	int tx = ((wvertical.length() - 11) / 2) + wstartx;
	mvprintw(ty, tx, "%d", KEY_EXIT);
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

	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	int inx = (COLS - 16) / 2; // Total length of both fields == 17
	int iny = wstarty + wheight;
	mvprintw(iny, inx - 10, "Input:");

	attron(COLOR_PAIR(1));
	mvprintw(iny, inx, "      ");
	field.push_back(formField(6, iny, inx));
	inx = inx + 9;
	mvprintw(iny, inx, "      ");
	field.push_back(formField(6, iny, inx));
	attroff(COLOR_PAIR(1));

	/* Initialize the fields */
	//field[0] = new_field(1, 10, iny, inx, 0, 0);
	//field[1] = new_field(1, 10 , iny - 2, inx + 10, 0, 0); // 7
	//field[2] = NULL;

	/* Set field options */
	//set_field_back(field[0], COLOR_PAIR(1)); 	/* Print a line for the option 	*/
	//set_field_fore(field[0], COLOR_PAIR(1));
	//field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
	//set_field_type(field[0], TYPE_ALNUM);
						/* Field is filled up 		*/

	//set_field_back(field[1], COLOR_PAIR(1));
	//set_field_fore(field[1], COLOR_PAIR(1));
	//field_opts_off(field[1], O_AUTOSKIP);
	//set_field_type(field[1], TYPE_ALNUM);

	/* Create the form and post it */
	//my_form = new_form(field);
	//post_form(my_form);
	//refresh();

	createWindow();
	//refreshWindow();
	/* Loop through to get user requests */

	attron(COLOR_PAIR(1));
	unsigned int current = 0;
	move(field[current].getYpos(), field[current].getXpos());

	while((ch = getch()) != 10)
	{
		switch(ch)
		{
			case KEY_DOWN:
			case KEY_UP:
			case 9:
				current = current == 0 ? 1 : 0;
				move(field[current].getYpos(), field[current].getXpos() + field[current].getCpos());
				break;
			case 10: // Enter
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
				/* If this is a normal character, it gets */
				/* Printed				  */
				field[current].addToBuffer((char) ch);
				mvprintw(field[current].getYpos(), field[current].getXpos(), "%s", field[current].getCBuffer());
				break;
		}
	}
	attroff(COLOR_PAIR(1));
	/* Un post form and free the memory */
	/*unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);*/

	endwin();
}

int main()
{
	trackerGUI gay;

	return 0;
}
