#include <iostream>
#include <sstream>
#include <curses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "class_keyboard.h"
#include "class_mainMenu.h"


using namespace music;
using namespace freq;
using namespace std;

//spiller av bestemte noter ved å trykke på bestemte taster på tastaturet.
void keyboard::playSound()
{
 
  int i = 0;
  bool dontstop = false;
  int ch;

  initscr();
  raw();  						
  keypad(stdscr, TRUE);
  noecho();
	  
  string tall = "012345678";
  
  char st = tall.at(i);
  char st1 = tall.at(i+1);

  printPiano(st, st1);	
  
  while(true)
  {
        ch = getch();	
	

	if(ch == 32)//space, øker oktav. Hvis makslengde er nådd, så går man tilbake til oktav 0.
	{
	  if(i == tall.length()-1)
	  {
	    i = 0;
	    st = tall.at(i);
	    st1 = tall.at(i+1);
	  }

	  else
	  {
	    ++i;
	    st = tall.at(i);
	    
	    if(st != '8')
	    {
	      st1 = tall.at(i+1);
	    }
	  }
	  
	   printPiano(st, st1);	
	}

	if(ch == 60)//<, minsker oktav.
	{
	   if(i > 0)
	   {
	    i--;
	    st = tall.at(i);
	    st1 = tall.at(i+1);
	   }
	  
	   printPiano(st, st1);
	}

        if(ch == KEY_F(12))//avslutter piano.
	{
	    break;
        }
        
        if(ch == 113 || ch == 81)//q
	{    
	    s.makeSound(1,1,dontstop);
	    if(dontstop == false)
	      dontstop = true;
	    else
	      dontstop = false;
	}
	  
	if(ch == 122 || ch == 90)//z
	{     
	    string str = "A";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	   
	}
		      
	if(ch == 120 || ch == 88)//x
	{
	    string str = "B";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}

	if(ch == 99 || ch == 67)//c
	{
	    string str = "C";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
        
	if(ch == 118 || ch == 86)//v
	{
	    string str = "D";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
        }
	
	if(ch == 98 || ch == 66)//b
	{
	    string str = "E";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
	
	if(ch == 110 || ch == 78)//n
	{
	    string str = "F";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}

	if(ch == 109 || ch == 77)//m
	{
	    string str = "G";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
	
	if(ch == 44)//,
	{     
	    string str = "A";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	   
	}
	    //rad over
	if(ch == 115 || ch == 83)//s
	{
	    string str = "A#";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
	 
	if(ch == 102 || ch == 70)//f
	{
	    string str = "C#";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
	   
        if(ch == 103 || ch == 71)//g
	{
	    string str = "D#";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
	   
        if(ch == 106 || ch == 74)//j
	{
	    string str = "F#";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}

	if(ch == 107 || ch == 75)//k
	{
	    string str = "G#";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f,dontstop);
	}
	
	refresh();
    }
	endwin();
  mainMenu mainM;
}

//printer ut et piano som viser hva du må trykke på for å spille av en note.
void keyboard::printPiano(char c, char d)
{
  
  // initscr();
  //clear();
  noecho();
  cbreak();

  curs_set(0); 
  
  // Set header-text:
  int pos = (80 - 48) / 2;
  mvprintw(0, pos, "_________________________________");
  mvprintw(1, pos, "|  | |  |  | | | |  |  | | | |  |");
  mvprintw(2, pos, "|  | |  |  | | | |  |  | | | |  |");
  mvprintw(3, pos, "|  |S|  |  |F| |G|  |  |J| |K|  |");
  mvprintw(4, pos, "|  |_|  |  |_| |_|  |  |_| |_|  |");
  mvprintw(5, pos, "|   |   |   |   |   |   |   |   |");
  mvprintw(6, pos, "| Z | X | C | V | B | N | M | , |");
  mvprintw(7, pos, "|___|___|___|___|___|___|___|___|\n");
  // mvprintw(8, pos, "  A A B   C C D D E   F F G G A\n");
  // mvprintw(9, pos, "  0 # 0   1 # 1 # 1   1 # 1 # 1\n");
  // mvprintw(10,pos, "    0       1   1       1   1\n  ");

  printw("\nPress Z to play note A");addch(c);
  printw("\nPress S to play note A#");addch(c);	    
  printw("\nPress X to play note B");addch(d);
  printw("\nPress C to play note C");addch(d);
  printw("\nPress F to play note C#");addch(d);
  printw("\nPress V to play note D");addch(d);
  printw("\nPress G to play note D#");addch(d);
  printw("\nPress B to play note E");addch(d);
  printw("\nPress N to play note F");addch(d);
  printw("\nPress J to play note F#");addch(d);
  printw("\nPress M to play note G");addch(d);
  printw("\nPress K to play note G#");addch(d);
  printw("\nPress , to play note A");addch(d);



  printw("\n\nPress CAPS to increase octaves or < to decrease.\n"); 
  printw("\nPress Q to toggle continuous note");
  printw("\n\nPress F12 to exit.");
   
  refresh();


}

