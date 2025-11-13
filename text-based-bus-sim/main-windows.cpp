//
//  main.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//

//#include <iostream>
//#include "CustomFunctions.h"
//#include "menus.h"
//#pragma comment(lib, "user32")
//
//using namespace std;
//Menus m;
//CustomFunctions cfb;
//
//void fullscreen()
//{
//    keybd_event(VK_MENU, 0x38, 0, 0);
//    keybd_event(VK_RETURN, 0x1c, 0, 0);
//    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
//    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
//}
//
//int main()
//  {
//    fullscreen();
//    m.mainMenu();
//	m.routeSelector();
//
//    return 0;
//}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string myText;
    ifstream inFile;
    char del = '*';

    inFile.open("routes/routes.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }


    while (getline(inFile, myText, del))
        cout << "\n" << myText;
        cout << "\n";


    return 0;
}