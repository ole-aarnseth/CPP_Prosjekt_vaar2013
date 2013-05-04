#ifndef CLASS_SONG_H
#define CLASS_SONG_H

#include <string>
#include "class_bar.h"

namespace music{

	class song
	{
	std::string title;
	int bpm;
	std::vector<bar> bars;
		
		public:
			song(std::string c_title, int c_bpm);
			int getBpm();
			std::string getTitle();
			void rename(std::string newtitle);
			void setBpm(int newbpm);
			bool addNotes(note myNote, int bar);
			bool addBar();
			int barCount();
			bool validateNote(std::string);
			bool validateNoteLength(int);
			void play();
			bar getBar(int i);
			bool delBar(int i);
			const char* bar2char(char *src, int number);
			int noteCount();
			void rnTitle(std::string newname);
			bool deleteNote(int, int);
	};

}

#endif
