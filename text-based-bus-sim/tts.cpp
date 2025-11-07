//
//  tts.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//
#include "tts.h"

string replace(string text) {
    string replace_word = "opp";
    string replace_by = "opposite";
    size_t pos = text.find(replace_word);
    while (pos != string::npos) {
        text.replace(pos, replace_word.size(), replace_by);
        pos = text.find(replace_word,
            pos + replace_by.size());
    }

    replace_word = "adj";
    replace_by = "adjacent";
    pos = text.find(replace_word);
    while (pos != string::npos) {
        text.replace(pos, replace_word.size(), replace_by);
        pos = text.find(replace_word,
            pos + replace_by.size());
    }

    replace_word = "PH";
    replace_by = "Pub";
    pos = text.find(replace_word);
    while (pos != string::npos) {
        text.replace(pos, replace_word.size(), replace_by);
        pos = text.find(replace_word,
            pos + replace_by.size());
    }

    replace_word = "nr";
    replace_by = "near";
    pos = text.find(replace_word);
    while (pos != string::npos) {
        text.replace(pos, replace_word.size(), replace_by);
        pos = text.find(replace_word,
            pos + replace_by.size());
    }

    return text;
}

void CustomTTS::Speak(string text)
{
    cout << text;
    
    text = replace(text);

    string str = "say " + text;

    const char* command = str.c_str();

    //std::cout << "\n" << text << std::endl;
    std::cout << "\n";
    
    system(command);
}
