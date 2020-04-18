
#include "guy.h"

const String moods[5] = {"HAPPY", "HUNGRY", "BORED", "SAD", "TIRED"};

unsigned long hungerPreviousMillis = 0;
const long hungerInterval = 1000;

unsigned long boredomPreviousMillis = 0;
const long boredomInterval = 2000;

unsigned long sadnessPreviousMillis = 0;
const long sadnessInterval = 3000;

int MAX_HUNGER = 10;
int MIN_HUNGER = 0;
int hunger = MIN_HUNGER;

int MAX_BOREDOM = 10;
int MIN_BOREDOM = 0;
int boredom = MIN_BOREDOM;

int MAX_SADNESS = 10;
int MIN_SADNESS = 0;
int sadness = MIN_SADNESS;

Guy::Guy(Arduboy2 arduboy)
{
  _arduboy = arduboy;
}

void Guy::draw() {
  _arduboy.setCursor(0, 0);
  _arduboy.print(boredom);
  
  _arduboy.setCursor(0, 10);
  _arduboy.print(hunger);

  _arduboy.setCursor(0, 20);
  _arduboy.print(sadness);
  
  _arduboy.setCursor(0, 40);
  _arduboy.print(moods[_mood]);
  
  //Sprites::drawExternalMask(0, 0, guy1, guy1_mask, 0, 0);
}

void Guy::update() {
  unsigned long currentMillis = millis();

/*
  updateInterval(currentMillis, hungerPreviousMillis, hungerInterval, hunger, MAX_HUNGER);
  updateInterval(currentMillis, boredomPreviousMillis, boredomInterval, boredom, MAX_BOREDOM);
  updateInterval(currentMillis, sadnessPreviousMillis, sadnessInterval, sadness, MAX_SADNESS);
*/

  if (currentMillis - hungerPreviousMillis >= hungerInterval) {
    if (hunger < MAX_HUNGER) {
       hunger++;
    }
    hungerPreviousMillis = currentMillis;
  }

  if (currentMillis - boredomPreviousMillis >= boredomInterval) {
    if (boredom < MAX_BOREDOM) {
       boredom++;
    }

    boredomPreviousMillis = currentMillis;
  }

  if (currentMillis - sadnessPreviousMillis >= sadnessInterval) {
    if (sadness < MAX_SADNESS) {
       sadness++;
    }

    sadnessPreviousMillis = currentMillis;
  }

  if (hunger > 5) {
    _mood = 1;
  } else if (sadness > 5) {
    _mood = 3;
  } else if (boredom > 5) {
    _mood = 2;
  } else if (hunger == MAX_HUNGER && sadness == MAX_SADNESS) {
    //die...
  } else {
    _mood = 0;
  }
}

void Guy::updateInterval(long currentMillis, long previousMillis, long interval, int value, int maxValue) {
    if (currentMillis - previousMillis >= interval) {
    if (value < maxValue) {
       value++;
    }
    previousMillis = currentMillis;
  }
}

void Guy::apply(int action) {
  if (action == 0) { //feed
    hunger = MIN_HUNGER;
  }
  if (action == 1) { //play
    boredom = MIN_BOREDOM;
  }
  if (action == 2) { //pet
    sadness = MIN_SADNESS;
  }
}
