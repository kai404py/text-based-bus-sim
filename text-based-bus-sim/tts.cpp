//
//  tts.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//
#include "tts.h"

void CustomTTS::Speak(string text)
{
    cout << text;
    
    string str = "say " + text;

    const char* command = str.c_str();

    std::cout << "\n" << text <<  "\n" << std::endl;
    
    system(command);
}
