#include <iostream>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/kd.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "class_sound.h"

using namespace synth;

using namespace std;

sound::sound(int l, int t)
{

  length = l;
  tone = t;


}

void sound::makeSound(int l, int h)
{
	int fd = open("/dev/console", O_WRONLY);
  	ioctl(fd, KIOCSOUND, (int)(1193180/h));
  	usleep(1000*l);
  	ioctl(fd, KIOCSOUND, 0);
  	close(fd);

}



void sound::quickSequence(vector<sound> param)
{
  	int fd = open("/dev/console", O_WRONLY);

	for(int i = 0; i < param.size(); i++)
	{
	  ioctl(fd, KIOCSOUND, (int)(1193180/param[i].tone));
	  usleep(1000*param[i].length);
	}

  	ioctl(fd, KIOCSOUND, 0);
  	close(fd);
}

int sound::getNumber()
{
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

int sound::random()
{
  srand (time(NULL));
  int myRandom = rand() % 5000 +1;
  return myRandom;
}	

int main(){

  return 0;

}
