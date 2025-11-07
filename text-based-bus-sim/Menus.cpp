#include "menus.h"
#include "game.h"

CustomFunctions cfa;
game g;

int hello()
{
    CustomWTTS tts;

    cout << "____    __    ____     _______     __           ______      ______      .___  ___.     _______ \n";
    cout << "\\   \\  /  \\  /   /    |   ____|   |  |         /      |    /  __  \\     |   \\/   |    |   ____|\n";
    cout << " \\   \\/    \\/   /     |  |__      |  |        |  ,----'   |  |  |  |    |  \\  /  |    |  |__   \n";
    cout << "  \\            /      |   __|     |  |        |  |        |  |  |  |    |  |\\/|  |    |   __|  \n";
    cout << "   \\    /\\    /       |  |____    |  `----.   |  `----.   |  `--'  |    |  |  |  |    |  |____ \n";
    cout << "    \\__/  \\__/        |_______|   |_______|    \\______|    \\______/     |__|  |__|    |_______|\n";

    //tts.Speak("Welcome to the text based bus simulator");

    sleep_for(1s);
    system("cls");

    return 0;
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

int Menus::routeSelector() {

    int routes[1] = { 1 };

again:
    int option;
    static int j = 0;
    system("cls");

    do {
        cfa.setColor(7, 0);
        gotoxy(17, 7);
        cout << "Routes:" << endl;
        gotoxy(9, 9);
        cout << "1" << endl;

        gotoxy(9, 17);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            cfa.setColor(0, 7);
            gotoxy(9, 9);
            cout << "1" << endl;
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
        cfa.setColor(7, 0);
        g.startRoute(1);
        _getch();
        break;
    }
    return 0;
}


int Menus::mainMenu() {
again:
    int option;
    static int j = 0;
    system("cls");

    do {
        cfa.setColor(7, 0);
        gotoxy(17, 7);
        cout << "  Menu   " << endl;
        gotoxy(9, 9);
        cout << "          Start            " << endl;
        gotoxy(9, 11);
        cout << "         Credits           " << endl;
        gotoxy(9, 13);
        cout << "          Quit             " << endl;

        gotoxy(9, 17);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            cfa.setColor(0, 7);
            gotoxy(9, 9);
            cout << "          Start          " << endl;
        }
        if (j == 1) {
            cfa.setColor(0, 7);
            gotoxy(9, 11);
            cout << "         Credits         " << endl;
        }
        if (j == 2) {
            cfa.setColor(0, 7);
            gotoxy(9, 13);
            cout << "          Quit         " << endl;
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
        cfa.setColor(7, 0);
        
		cout << "Starting game..." << endl;
		sleep_for(1s);
        cls();
		hello();
        return 0;
        _getch();
        break;
    case 1:
        cls();
        cfa.setColor(7, 0);
        cout << "IDK me i guess";
        _getch();
        break;
    case 2:
        cls();
        cfa.setColor(7, 0);
        return 0;
    }
    return 0;
}
