//
//  main.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//

#include <iostream>
#include "CustomFunctions.h"
#include "Menus.h"
#pragma comment(lib, "user32")

using namespace std;
Menus m;
CustomFunctions cfb;

void hello()
{
  CustomTTS tts;
  tts.Speak("Hello, welcome to the text based bus simulator!");
  sleep(1);
  system("clear");
  Drawbus(1);
}

int main()
  {
    fullscreen();
    m.mainMenu();
	m.routeSelector();

    return 0;
}

