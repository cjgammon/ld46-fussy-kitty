

#include <Arduboy2.h>

#include "guy.h"
#include "menu.h"

Arduboy2 arduboy;
BeepPin1 beep; // class instance for speaker pin 1

Menu _mainmenu = Menu(arduboy);
Guy _character = Guy(arduboy);

int state = 0;
int action = -1;


void setup() {
  arduboy.begin();
  beep.begin(); // set up the hardware for playing tones
  arduboy.setFrameRate(15);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  beep.timer(); // handle tone duration

  arduboy.clear();
  arduboy.pollButtons();

  if (state == 0) {
    menuUpdate();
  } else {
    gameUpdate();
  }

  arduboy.display();
}

void menuUpdate() {
  Sprites::drawOverwrite (0, 0, title, 0);

  if (arduboy.justPressed(A_BUTTON)) {
    state = 1;
  }
}

void gameUpdate() {
  
  if(arduboy.justPressed(LEFT_BUTTON)) {
      _mainmenu.prev();
  }
  
  if(arduboy.justPressed(RIGHT_BUTTON)) {
      _mainmenu.next();
  }
  
  if (arduboy.justPressed(A_BUTTON)) {
    //beep.tone(beep.freq(1000), 100);
    action = _mainmenu.value();
    _character.apply(action);
  }
  
  _character.update();
  _character.draw();
  _mainmenu.draw();
}
