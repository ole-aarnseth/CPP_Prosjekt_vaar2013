CMP=g++
CUR=-lncurses

all: music show_msg

music: proto.o class_mainMenu.o class_keyboard.o class_trackerGUI.o class_sound.o class_freqnote.o class_song.o class_bar.o class_note.o class_tools.o class_formField.o class_demo.o
	$(CMP) proto.o class_mainMenu.o class_keyboard.o class_trackerGUI.o class_sound.o class_freqnote.o class_song.o class_bar.o class_note.o class_tools.o class_formField.o class_demo.o -o music $(CUR)

proto.o: proto.cpp
	$(CMP) -c proto.cpp $(CUR)

class_mainMenu.o: class_mainMenu.cpp class_mainMenu.h
	$(CMP) -c class_mainMenu.cpp class_mainMenu.h $(CUR)
	
class_keyboard.o: class_keyboard.cpp class_keyboard.h
	$(CMP) -c class_keyboard.cpp class_keyboard.h $(CUR)
	
class_trackerGUI.o: class_trackerGUI.cpp class_trackerGUI.h
	$(CMP) -c class_trackerGUI.cpp class_trackerGUI.h $(CUR)
	
class_sound.o: class_sound.cpp class_sound.h
	$(CMP) -c class_sound.cpp class_sound.h $(CUR)
	
class_freqnote.o: class_freqnote.cpp class_freqnote.h
	$(CMP) -c class_freqnote.cpp class_freqnote.h $(CUR)
	
class_song.o: class_song.cpp class_song.h
	$(CMP) -c class_song.cpp class_song.h $(CUR)
	
class_bar.o: class_bar.cpp class_bar.h
	$(CMP) -c class_bar.cpp class_bar.h $(CUR)
	
class_note.o: class_note.cpp class_note.h
	$(CMP) -c class_note.cpp class_note.h $(CUR)
	
class_tools.o: class_tools.cpp class_tools.h
	$(CMP) -c class_tools.cpp class_tools.h $(CUR)
	
class_formField.o: class_formField.cpp class_formField.h
	$(CMP) -c class_formField.cpp class_formField.h

class_demo.o: class_demo.cpp class_demo.h
	$(CMP) -c class_demo.cpp class_demo.h $(CUR)

show_msg:
	@echo Type \'./music\' to execute program
	
clean:
	@rm -f *.o *.gch music