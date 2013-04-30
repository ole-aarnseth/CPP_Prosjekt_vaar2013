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


using namespace music;
using namespace freq;
using namespace std;

keyboard::keyboard()
{

}

void keyboard::playSound()
{
 
  int i = 0;

  int ch;

  initscr();
  raw();  						
  keypad(stdscr, TRUE);
  noecho();
		
  char st;
  char st1;
  string tall = "012345678";
  
  while(i < 10)
  {
        ch = getch();	
	st = tall.at(i);
	
	if(st != '8')
	{
	   st1 = tall.at(i+1);
	}

	if(ch == 32)//space
	{
	  if(i == tall.length()-1)
	  {
	    i = 0;
	  }

	  else
	  {
	    i++;
	  }
	  
	}

	if(ch == 60)//<
	{
	   if(i > 0)
	   {
	    i--;
	   }
	  
	}

        if(ch == KEY_F(12))
	{
	    break;
        }   
	  
	if(ch == 122)//z
	{     
	    string str = "A";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	   
	}
		      
	if(ch == 120)//x
	{
	    string str = "B";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}

	if(ch == 99)//c
	{
	    string str = "C";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
        
	if(ch == 118)//v
	{
	    string str = "D";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
        }
	
	if(ch == 98)//b
	{
	    string str = "E";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
	
	if(ch == 110)//n
	{
	    string str = "F";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}

	if(ch == 109)//m
	{
	    string str = "G";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
	
	if(ch == 44)//,
	{     
	    string str = "A";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	   
	}
	    //rad over
	if(ch == 115)//s
	{
	    string str = "A#";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
	 
	if(ch == 102)//f
	{
	    string str = "C#";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
	   
        if(ch == 103)//g
	{
	    string str = "D#";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
	   
        if(ch == 106)//j
	{
	    string str = "F#";
	    str += st;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}

	if(ch == 107)//k
	{
	    string str = "G#";
	    str += st1;
	    float f = freq.calcFreq(str);
	    s.makeSound(100,f);
	}
	
	refresh();
    }
	endwin();  
}
