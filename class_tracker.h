#ifndef CLASS_TRACKER_H
#define CLASS_TRACKER_H

#include <iostream>
#include "class_song.h"
#include "class_sound.h"
#include <ncurses.h>
#include <string>
#include "class_tools.h"
#include "class_demo.h"

namespace music{

	class tracker
	{
		public:
		  void track();
		  void dispMenu();
	};

}

#endif
