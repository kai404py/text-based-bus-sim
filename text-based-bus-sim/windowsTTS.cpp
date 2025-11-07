#include "tts.h"

void CustomWTTS::Speak(string text)
{
    cout << text;

    string str = "powerShell -Command ";
    
    str += '"';
        
    str += "Add-Type -AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('";

    str += text + "')";

    str += ';"';


	//[DEBUG] - Debug the powershell command
	//std::cout << str << endl;

    const char* command = str.c_str();

    std::cout << "\n" << text << "\n" << std::endl;

    system(command);
}
