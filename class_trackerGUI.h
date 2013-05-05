#ifndef CLASS_TRACKERGUI_H
#define CLASS_TRACKERGUI_H

#include <ncurses.h>
#include "class_formField.h"
#include "class_tools.h"
#include <vector>
#include <string>

namespace music{

	class trackerGUI
	{
		int ch, wstarty, wstartx, wheight, wwidth;
		std::string whorizontal, wvertical;
		std::vector<std::string> note;
		std::vector<int> length;
		std::vector<formField> field;
		tools toolBox;

		void createWindow();
		void refreshWindow();

		public:
			trackerGUI();
	};
}

#endif
