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
#include "sprites.h"

// make an instance of arduboy used for many functions
Arduboy2 arduboy;

#include "menu.h"

int playerx = 5;
int playery = 10;

Menu mainmenu = Menu(arduboy);

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
      mainmenu.prev();
  }
  
  if(arduboy.justPressed(RIGHT_BUTTON)) {
      mainmenu.next();
  }
  
  if (arduboy.justPressed(A_BUTTON)) {
    action = mainmenu.value();
  }

  Sprites::drawExternalMask(playerx, playery, guy1, guy1_mask, 0, 0);

  mainmenu.draw();

  arduboy.display();
}
