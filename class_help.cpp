#include <iostream>
#include "class_help.h"
#include <curses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <stdio.h>
#include <stdlib.h>



using namespace music;

void help::printHelp()
{
  initscr();
  echo();
  cbreak();
  raw();
 
  keypad(stdscr, TRUE);
  attron(A_BOLD);
  printw("\nHjelpemeny for BeepTracker.");
  attroff(A_BOLD); 
  refresh();
  endwin();
}
