//
//  main.cpp
//  text-based-bus-sim
//
//  Created by Kai on 06/11/2025.
//

#include <iostream>
#include "CustomFunctions.h"
#include "menus.h"
#pragma comment(lib, "user32")

using namespace std;
Menus m;
CustomFunctions cfb;
Draw Md;

void fullscreen()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void splashScreen()
{
    cfb.setColor(7, 0);
    cfb.gotoXY(0, 0);
    Md.Dest("Welcome To", "~");
    sleep_for(500ms);
    cfb.gotoXY(0, 11);
    Md.Dest("The Text Based", "~");
    sleep_for(500ms);
    cfb.gotoXY(0, 22);
    Md.Dest("Bus Sim", "~");

    sleep_for(2s);
    system("cls");
    for (int i = 0; i < 2; i++)
    {
        cfb.gotoXY(0, 0);
        Md.Dest("~", "Loading.");
        sleep_for(500ms);
        system("cls");
        cfb.gotoXY(0, 0);
        Md.Dest("~", "Loading..");
        sleep_for(500ms);
        system("cls");
        cfb.gotoXY(0, 0);
        Md.Dest("~", "Loading...");
        sleep_for(500ms);
        system("cls");
        cfb.gotoXY(0, 0);
        Md.Dest("~", "Loading....");
        sleep_for(500ms);
        system("cls");
        cfb.gotoXY(0, 0);
        Md.Dest("~", "Loading.....");
        sleep_for(500ms);
        system("cls");
    }
}

int main()
  {
    fullscreen();
    splashScreen();
    m.mainMenu();
	m.routeSelector();

    return 0;
}