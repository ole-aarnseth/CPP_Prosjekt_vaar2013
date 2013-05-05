CMP=g++
CUR=-lncurses

all: music show_msg

music: beeptracker.o class_mainMenu.o class_keyboard.o class_tracker.o class_sound.o class_freqnote.o class_song.o class_bar.o class_note.o class_tools.o class_demo.o class_help.o
	$(CMP) beeptracker.o class_mainMenu.o class_keyboard.o class_tracker.o class_sound.o class_freqnote.o class_song.o class_bar.o class_note.o class_tools.o class_demo.o class_help.o -o beeptracker $(CUR)

beeptracker.o: beeptracker.cpp
	$(CMP) -c beeptracker.cpp

class_mainMenu.o: class_mainMenu.cpp class_mainMenu.h
	$(CMP) -c class_mainMenu.cpp class_mainMenu.h $(CUR)
	
class_keyboard.o: class_keyboard.cpp class_keyboard.h
	$(CMP) -c class_keyboard.cpp class_keyboard.h $(CUR)
	
class_tracker.o: class_tracker.cpp class_tracker.h
	$(CMP) -c class_tracker.cpp class_tracker.h $(CUR)
	
class_sound.o: class_sound.cpp class_sound.h
	$(CMP) -c class_sound.cpp class_sound.h
	
class_freqnote.o: class_freqnote.cpp class_freqnote.h
	$(CMP) -c class_freqnote.cpp class_freqnote.h
	
class_song.o: class_song.cpp class_song.h
	$(CMP) -c class_song.cpp class_song.h
	
class_bar.o: class_bar.cpp class_bar.h
	$(CMP) -c class_bar.cpp class_bar.h
	
class_note.o: class_note.cpp class_note.h
	$(CMP) -c class_note.cpp class_note.h
	
class_tools.o: class_tools.cpp class_tools.h
	$(CMP) -c class_tools.cpp class_tools.h

class_demo.o: class_demo.cpp class_demo.h
	$(CMP) -c class_demo.cpp class_demo.h

class_help.o: class_help.cpp class_help.h
	$(CMP) -c class_help.cpp class_help.h $(CUR)

show_msg:
	@echo Type \'./beeptracker\' to execute program
	
clean:
	@rm -f *.o *.gch music
