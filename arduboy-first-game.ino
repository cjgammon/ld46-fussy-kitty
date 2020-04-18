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

int playerx = 5;
int playery = 10;

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // first we clear our screen to black
  arduboy.clear();
  arduboy.pollButtons();

  if(arduboy.pressed(LEFT_BUTTON)) {
      playerx = playerx - 1;
  }
  if(arduboy.pressed(RIGHT_BUTTON)) {
      playerx = playerx + 1;
  }
  if(arduboy.pressed(UP_BUTTON)) {
      playery = playery - 1;
  }
  if(arduboy.pressed(DOWN_BUTTON)) {
      playery = playery + 1;
  }

  // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0)
  //arduboy.setCursor(4, 20);

  // then we print to screen what is in the Quotation marks ""
  //arduboy.print(F("Hello, world4!"));
  arduboy.fillRect(0, 0, 100, 300, BLACK);
  arduboy.fillRect(10, 0, 300, 300);

  Sprites::drawExternalMask(playerx, playery, guy1, guy1_mask, 0, 0);

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}
