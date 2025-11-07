#include "menus.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "tts.h"
#include "windowsH.h"
#include "draw.h"

using namespace std;
Draw d;

void hello()
{
    CustomWTTS tts;

    cout << "____    __    ____     _______     __           ______      ______      .___  ___.     _______ \n";
    cout << "\\   \\  /  \\  /   /    |   ____|   |  |         /      |    /  __  \\     |   \\/   |    |   ____|\n";
    cout << " \\   \\/    \\/   /     |  |__      |  |        |  ,----'   |  |  |  |    |  \\  /  |    |  |__   \n";
    cout << "  \\            /      |   __|     |  |        |  |        |  |  |  |    |  |\\/|  |    |   __|  \n";
    cout << "   \\    /\\    /       |  |____    |  `----.   |  `----.   |  `--'  |    |  |  |  |    |  |____ \n";
    cout << "    \\__/  \\__/        |_______|   |_______|    \\______|    \\______/     |__|  |__|    |_______|\n";

    tts.Speak("Hello, welcome to the text based bus simulator");

    sleep_for(1s);
    system("cls");
    d.Bus();
}

void foreColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void cls() {
    system("cls");
}

int Menus::mainMenu() {
again:
    int option;
    static int j = 0;
    system("cls");

    do {
        foreColor(7);
        gotoxy(17, 7);
        cout << "-- MENU --" << endl;
        gotoxy(9, 9);
        cout << "Start" << endl;
        gotoxy(9, 11);
        cout << "Credits" << endl;
        gotoxy(9, 13);
        cout << "Quit" << endl;

        gotoxy(9, 17);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            foreColor(8);
            gotoxy(9, 9);
            cout << "Start" << endl;
        }
        if (j == 1) {
            foreColor(8);
            gotoxy(9, 11);
            cout << "Credits" << endl;
        }
        if (j == 2) {
            foreColor(8);
            gotoxy(9, 13);
            cout << "Quit" << endl;
        }

        option = _getch();
        switch (option) {
        case 80: j++; if (j > 2) j = 0; break;
        case 72: j--; if (j < 0) j = 2; break;
        }
    } while (option != 13);

    switch (j) {
    case 0:
        cls();
        foreColor(7);
        hello();
        _getch();
        break;
    case 1:
        cls();
        foreColor(7);
        cout << "IDK me i guess";
        _getch();
        break;
    case 2:
        cls();
        foreColor(7);
        return 0;
    }
}
