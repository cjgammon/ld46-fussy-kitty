
#include "guy.h"
#include "property.h"

const int moodCount = 7;
const String moods[moodCount] = {"HAPPY", "HUNGRY", "BORED", "SAD", "TIRED", "SICK", "DEAD"};

unsigned long previousMillis = 0;
const long interval = 1000;

bool despair = false;
bool dead = false;

Property hunger = Property("HUNGRY", 10, 0, 5, 0, 1.0); //name, max, min, mid, value, inc
Property boredom = Property("BORED", 10, 0, 5, 0, 0.5);
Property sadness = Property("SAD", 10, 0, 5, 0, 0.25);

Property death = Property("DEAD", 10, 0, 5, 0, 1);

const int statusCount = 3;
Property statuses[statusCount] = {hunger, boredom, sadness};

Guy::Guy(Arduboy2 arduboy)
{
  _arduboy = arduboy;
}

void Guy::draw() {
  
  _arduboy.setCursor(0, 30);
  _arduboy.print(death.value);

  for (int i = 0; i < statusCount; i++) {
    _arduboy.setCursor(0, i * 10);
    _arduboy.print(statuses[i].value);
  }

  _arduboy.setCursor(0, 40);
  _arduboy.print(moods[_mood]);
}

void Guy::update() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    for (int i = 0; i < statusCount; i++) {
      statuses[i].value += statuses[i].inc;
    }

    if (despair) {
      death.value += death.inc;
    } else {
      death.value = death.min;
    }
    
    previousMillis = currentMillis;
  }

  checkMood();
}

void Guy::checkMood() {
    int tmpMood = 0;
    int maxCount = 0;
    
    for (int i = 0; i < statusCount; i++) {
      if (int(statuses[i].value) > statuses[i].mid) {
        
        for (int j = 0; j < moodCount; j++) {
          if (statuses[i].name == moods[j]) {
            if (tmpMood == 0) {
               tmpMood = j;
            }
          }
        }
        
      }

      if (int(statuses[i].value) > statuses[i].max) {
        maxCount++;
      }
    }

    if (maxCount > 0) {
      tmpMood = 5; //sick
      despair = true;
    } else {
      despair = false;
    }

    if (death.value > death.max) {
      dead = true;
      tmpMood = 6;
    }

    _mood = tmpMood;
}

void Guy::apply(int action) {
  
  if (action == 0) { //feed
    statuses[0].value = statuses[0].min;
  }
  
  if (action == 1) { //play
    statuses[1].value = statuses[1].min;
  }
  if (action == 2) { //pet
    statuses[2].value = statuses[2].min;
  }
  
}
