
#include <WString.h>
#include "menu.h"

const int menuitemcount = 3;
const String menuitems[menuitemcount] = {"FEED", "PLAY", "PET"};

int menuY = 55;
int current = 0;

Menu::Menu(Arduboy2 arduboy)
{
  _arduboy = arduboy;
}

void Menu::next()
{
  if (current < menuitemcount - 1) {
    current ++;
  }
}

void Menu::prev()
{
  if (current > 0) {
    current --;
  }
}

int Menu::value()
{
  return current;
}

void Menu::draw()
{
  _arduboy.fillRect(0, menuY - 3, 128, 1);

  int menuX = 3;
  for (int i = 0; i < menuitemcount; i++) {
    if (i == current) {
      _arduboy.fillRect(menuX - 2, menuY - 1, 1, 10);
    }
    _arduboy.setCursor(menuX, menuY);
    _arduboy.print(menuitems[i]);
    menuX += 30;
  }
}
