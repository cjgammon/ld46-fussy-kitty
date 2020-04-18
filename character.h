#ifndef Character_h
#define Character_h

#include <Arduboy2.h>

class Character
{
  public:
  Character(Arduboy2 arduboy);
  void draw();
  private:
  Arduboy2 _arduboy;
};
#endif
