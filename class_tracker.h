#ifndef CLASS_TRACKER_H
#define CLASS_TRACKER_H

#include <iostream>
#include "class_song.h"
#include "class_sound.h"
#include <ncurses.h>
#include <string>
#include "class_tools.h"
#include "class_formField.h"
#include "class_demo.h"

namespace music{

	class tracker
	{
		int ch, wstarty, wstartx, wheight, wwidth;
		std::string whorizontal, wvertical;
		std::vector<std::string> notelist;
		std::vector<int> length;
		std::vector<formField> field;
		tools toolBox;

		void createWindow();
		void refreshWindow();

		public:
		  void track();
		  void dispMenu();
	};

}

#endif
