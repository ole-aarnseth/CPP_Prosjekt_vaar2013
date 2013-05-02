#ifndef CLASS_TRACKERGUI_H
#define CLASS_TRACKERGUI_H

#include <ncurses.h>
#include "class_formField.h"
#include <vector>
#include <string>

namespace music{

	class trackerGUI
	{
		int ch, wstarty, wstartx, wheight;
		std::string whorizontal, wvertical;
		std::vector<std::string> note;
		std::vector<int> length;
		std::vector<formField> field;

		void createWindow();
		void refreshWindow();

		public:
			trackerGUI();
	};
}

#endif
