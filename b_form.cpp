#include <form.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main()
{	
        WINDOW *my_win;
        FIELD *field[3];
	FORM  *my_form;
	int ch, starty, startx, width, height;

	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	/* Initialize the fields */
	int inx = (COLS - 17) / 2; // Total length of both fields == 17
	int iny = (LINES - (LINES / 3));
	field[0] = new_field(1, 7, iny, inx, 0, 0);
	field[1] = new_field(1, 7, iny, inx + 10, 0, 0);
	field[2] = NULL;

	/* Set field options */
	set_field_back(field[0], COLOR_PAIR(1)); 	/* Print a line for the option 	*/
	set_field_fore(field[0], COLOR_PAIR(1));
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
	set_field_type(field[0], TYPE_ALNUM);
						/* Field is filled up 		*/
	set_field_back(field[1], COLOR_PAIR(1));
	set_field_fore(field[1], COLOR_PAIR(1));
	field_opts_off(field[1], O_AUTOSKIP);
	set_field_type(field[1], TYPE_ALNUM);

	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();

	// Create output window
	height = 14;
	width = 22;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	//mvprintw(4, 10, "Value 1:");
	//mvprintw(6, 10, "Value 2:");
	refresh();
	//form_driver(my_form, REQ_LAST_FIELD);
	my_win = create_newwin(height, width, starty, startx);
	refresh();
	/* Loop through to get user requests */
	while((ch = getch()) != 10)
	{	switch(ch)
		{
		        case KEY_DOWN:
			        form_driver(my_form, REQ_NEXT_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
			        form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
	                case 10:
			        break;
		        case KEY_BACKSPACE:
			        form_driver(my_form, REQ_DEL_PREV);
				form_driver(my_form, REQ_VALIDATION);
				break;
	                case KEY_RIGHT:
			        form_driver(my_form, REQ_NEXT_CHAR);
			        break;
		        case KEY_LEFT:
				form_driver(my_form, REQ_PREV_CHAR);
				break;
			default:
				/* If this is a normal character, it gets */
				/* Printed				  */
				form_driver(my_form, ch);
				form_driver(my_form, REQ_VALIDATION);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);

	endwin();
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
        WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);

	wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win)
{
        wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}
