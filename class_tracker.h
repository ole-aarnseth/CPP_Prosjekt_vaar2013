#ifndef CLASS_TRACKER_H
#define CLASS_TRACKER_H

#include <iostream>
#include "class_song.h"
#include "class_sound.h"
#include <ncurses.h>
#include <string>
#include "class_tools.h"
#include "class_demo.h"
#include "class_mainMenu.h"

namespace music{

	class tracker
	{
		song mySong;
		int ch, wstarty, wstartx, wheight, wwidth;
		std::string whorizontal, wvertical;
		std::vector<std::string> notelist;
		std::vector<int> length;
		tools toolBox;

		void createWindow();
		void refreshWindow();

		public:
		  tracker();
		  void track();
		  void dispMenu();
	};

}

#endif
