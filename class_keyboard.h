#ifndef CLASS_KEYBOARD_H
#define CLASS_KEYBOARD_H


#include "class_sound.h"


namespace music{

  class keyboard{

    sound s;
    freq::FreqNote freq;

  public:
    keyboard();
    void playSound();
    

  };



}
