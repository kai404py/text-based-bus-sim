#include "tts.h"

string replaceTTS(string text) {
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

void CustomWTTS::Speak(string text)
{
    cout << text;

	text = replaceTTS(text);

    string str = "powerShell -Command ";
    
    str += '"';
        
    str += "Add-Type -AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('";

    str += text + "')";

    str += ';"';


	//[DEBUG] - Debug the powershell command
	//std::cout << str << endl;

    const char* command = str.c_str();

    //std::cout << "\n" << text << "\n" << std::endl;
    //system("cls");

    system(command);
}
