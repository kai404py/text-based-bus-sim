//
//  main.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//

#include <iostream>

//#include "main.h"
#include "tts.h"
#include "windows.h"

#include "bus.cpp"

void hello();

int main()
  {
    //CustomWTTS tts;
    hello();

    return 0;
}

void hello()
{
    CustomWTTS tts;

    tts.Speak("Hello, welcome to the text based bus simulator!");
    sleep_for(1s);
    system("cls");
    Drawbus(1);
}