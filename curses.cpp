//g++ curses.cpp -o curse -lncurses
#include <ncurses.h>
#include <iostream>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct tone_t{
	int tone;
	int length;
	};

class spkr {
	
	public:
	void makeSound(int length, int hz);
	void playSequence(std::vector<tone_t>);	
	int getNumber();
	void quickSequence(std::vector<tone_t>);
	int randum();
};  

void spkr::makeSound(int length, int hz){
  	int fd = open("/dev/console", O_WRONLY);
  	ioctl(fd, KIOCSOUND, (int)(1193180/hz));
  	usleep(1000*length);
  	ioctl(fd, KIOCSOUND, 0);
  	close(fd);
	}

void spkr::playSequence(std::vector<tone_t> param){
for(int i = 0; i< param.size(); i++)
	{
	makeSound(param[i].length, param[i].tone);
	}
}

void spkr::quickSequence(std::vector<tone_t> param){
  	int fd = open("/dev/console", O_WRONLY);

	for(int i = 0; i < param.size(); i++)
	{
  	ioctl(fd, KIOCSOUND, (int)(1193180/param[i].tone));
  	usleep(1000*param[i].length);
	}

  	ioctl(fd, KIOCSOUND, 0);
  	close(fd);
}
	
int spkr::getNumber(){
std::string input = "";
int myNumber = 0;

	while (true) 
	{
	std::getline(std::cin, input);
	std::stringstream myStream(input);
	if (myStream >> myNumber)
		break;
	}
	 	
return myNumber;
}	

int spkr::randum()
{
srand (time(NULL));
int myRandom = rand() % 5000 +1;
return myRandom;
}

int main(){
int duration = 0;
spkr speaker;

duration = speaker.getNumber();

	int ch;

	initscr();
	raw();							
	keypad(stdscr, TRUE);
	noecho();


    	printw("Retarded piano!\n");

    	while(true)
	{
	ch = getch();	

	if(ch == KEY_F(12))
		break;

	if(ch == 97)
		speaker.makeSound(duration, 262); //262

	if(ch == 115)
		speaker.makeSound(duration, 293);

	if(ch == 100)
		speaker.makeSound(duration, 329);

	if(ch == 102)
		speaker.makeSound(duration, 349);

	if(ch == 103)
		speaker.makeSound(duration, 392);

	if(ch == 104)
		speaker.makeSound(duration, 440);	

	if(ch == 106)
		speaker.makeSound(duration, 493);

	if(ch == 107)
		speaker.makeSound(duration, 523);

	if(ch == 119)//W
		speaker.makeSound(duration, 277);

	if(ch == 101)//E
		speaker.makeSound(duration, 311);

	if(ch == 116)//t
		speaker.makeSound(duration, 370);

	if(ch == 121)
		speaker.makeSound(duration, 415);

	if(ch == 117)
		speaker.makeSound(duration, 466);

	

	if(ch == KEY_F(11))
		{
		speaker.makeSound(30, 262);
		speaker.makeSound(20, 293);
		speaker.makeSound(20, 329);
		speaker.makeSound(20, 349);		
		speaker.makeSound(20, 392);
		speaker.makeSound(20, 440);
		speaker.makeSound(20, 493);
		speaker.makeSound(20, 523);
		}
					
	if(ch == KEY_F(10))
	{
		speaker.makeSound(70, 100);
		speaker.makeSound(40, 95);
		speaker.makeSound(30, 90);
		speaker.makeSound(20, 85);
		speaker.makeSound(18, 80);
		speaker.makeSound(16, 75);
		speaker.makeSound(14, 70);
		speaker.makeSound(12, 65);
		speaker.makeSound(10, 60);
		speaker.makeSound(8, 55);
		speaker.makeSound(5, 50);
		speaker.makeSound(2, 45);

	
	}
	
	
	/*else
	{	printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}*/

	refresh();
    	//getch();
   	}	
	endwin();
	return 0;
}


