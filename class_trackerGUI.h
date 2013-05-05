#ifndef CLASS_TRACKERGUI_H
#define CLASS_TRACKERGUI_H

#include <ncurses.h>
#include "class_song.h"
#include "class_sound.h"
#include "class_formField.h"
#include "class_tools.h"
#include "class_demo.h"
#include "class_mainMenu.h"
#include <vector>
#include <string>

#define CHAR_ARRAY_LENGTH 255

namespace music{

	class trackerGUI
	{
		int ch, wstarty, wstartx, wheight, wwidth, currentbar;
		std::string whorizontal, wvertical;
		std::vector<formField> field;
		tools toolBox;
		song mySong;
		char myArr[CHAR_ARRAY_LENGTH];

		void createWindow();
		void refreshWindow();
		void dispMenu();

		public:
			trackerGUI();
	};
}

#endif
