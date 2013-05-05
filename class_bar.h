#ifndef CLASS_BAR_H
#define CLASS_BAR_H

#include <string>
#include <vector>
#include "class_note.h"


namespace music{

	class bar
	{
	std::vector<note> notes;//Alle notene i en bar.
	int ant_noter;	//Used for iteration
	double timeused; //Holde øye med hvor mye av takten som gjenstår.		
		public:
			bar();
			bool addNote(note myNote);
			bool removeNote(int i);
			bool checkSpace(note myNote);
			note getNote(int i);
			int getAntT();
			double getTimeleft();
			std::vector<note> getNotes();
			bool deleteNote(int);
	};

}

#endif
