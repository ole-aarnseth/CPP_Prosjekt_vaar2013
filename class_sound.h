#ifndef CLASS_SOUND_H
#define CLASS_SOUND_H

#include <vector>

namespace synth{

class sound{

	int length;
	int tone;

	public:
	sound(int, int);
	void makeSound(int, int);
	void quickSequence(std::vector<sound>);
	void playSequence(std::vector<sound>);
	int getNumber();
	int random();

};

}

#endif
