//
//  main.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//

//#include "main.h"
#include "bus.cpp"
#include "tts.h"

#include <iostream>

#include "windows.h"
//#include "linux.h"

void hello()
{
  CustomTTS tts;
  tts.Speak("Hello, welcome to the text based bus simulator!");
  sleep(1);
  system("clr");
  bus();
}

int main()
  {
    CustomTTS tts;
    hello();
    

    
    bus();
    return 0;
}
