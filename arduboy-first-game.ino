/*
Hello, World! example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for writing a program for Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include <Arduboy2.h>

#include "guy.h"
#include "menu.h"

Arduboy2 arduboy;

int playerx = 5;
int playery = 10;

Menu _mainmenu = Menu(arduboy);
Guy _character = Guy(arduboy);

int action = -1;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(15);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  arduboy.pollButtons();

  if(arduboy.justPressed(LEFT_BUTTON)) {
      _mainmenu.prev();
  }
  
  if(arduboy.justPressed(RIGHT_BUTTON)) {
      _mainmenu.next();
  }
  
  if (arduboy.justPressed(A_BUTTON)) {
    action = _mainmenu.value();
    _character.apply(action);
  }

  _character.update();

  _character.draw();
  _mainmenu.draw();

  arduboy.display();
}
