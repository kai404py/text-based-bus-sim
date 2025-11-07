#include "menus.h"
#include "game.h"

CustomFunctions cfa;
Draw da;
game g;

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void cls() {
    system("cls");
    cfa.setColor(7, 0);
    cfa.redraw(12, "NIS", 0);
}

int Menus::routeSelector() {

again:
    int option;
    static int j = 0;
    system("cls");

    do {
        cfa.setColor(7, 0);
        cfa.redraw(12, "NIS", 0);
        cfa.setColor(7, 0);
        gotoxy(50, 12);
        cout << "Routes:" << endl;
        gotoxy(50, 14);
        cout << "25" << endl;
        gotoxy(50, 15);
        cout << "99" << endl;
        gotoxy(50, 16);
        cout << "101" << endl;
        gotoxy(50, 17);
        cout << "103" << endl;
        gotoxy(50, 18);
        cout << "000" << endl;

        gotoxy(50, 23);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            cfa.setColor(0, 7);
            gotoxy(50, 14);
            cout << "25" << endl;
        }
        if (j == 1) {
            cfa.setColor(0, 7);
            gotoxy(50, 15);
            cout << "99" << endl;
        }
        if (j == 2) {
            cfa.setColor(0, 7);
            gotoxy(50, 16);
            cout << "101" << endl;
        }
        if (j == 3) {
            cfa.setColor(0, 7);
            gotoxy(50, 17);
            cout << "103" << endl;
        }
        if (j == 4) {
            cfa.setColor(0, 7);
            gotoxy(50, 18);
            cout << "000" << endl;
        }

        option = _getch();
        switch (option) {
        case 80: j++; if (j > 6) j = 0; break;
        case 72: j--; if (j < 0) j = 6; break;
        }
    } while (option != 13);

    switch (j) {

    case 0:
        g.startRoute(25);
        break;
    case 1:
        g.startRoute(99);
        break;
    case 2:
        g.startRoute(101);
        break;
    case 3:
        g.startRoute(103);
        break;
    case 4:
        g.startRoute(000);
        break;
    }


    return 0;
}


int Menus::destinationSelector(string routeNum, string inbound, string outbound) {

again:
    int option;
    static int j = 0;
    system("cls");

    do {
        cfa.setColor(7, 0);
        cfa.redraw(12, routeNum, 0);
        cfa.redraw(0, "route", 0);
        cfa.setColor(7, 0);
        gotoxy(50, 12);
        cout << "Destinations:" << endl;
        gotoxy(50, 14);
        cout << inbound << endl;
        gotoxy(50, 16);
        cout << outbound << endl;

        gotoxy(50, 19);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            cfa.setColor(0, 7);
            gotoxy(50, 14);
            cout << inbound << endl;

        }
        if (j == 1) {
            cfa.setColor(0, 7);
            gotoxy(50, 16);
            cout << outbound << endl;
        }

        option = _getch();
        switch (option) {
        case 80: j++; if (j > 1) j = 0; break;
        case 72: j--; if (j < 0) j = 1; break;
        }
    } while (option != 13);

    switch (j) {

    case 0:
        cfa.setColor(7, 0);
        system("cls");
        return 3;
    case 1:
        cfa.setColor(7, 0);
        system("cls");
        return 2;
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
        cfa.redraw(12, "NIS", 0);
        cfa.setColor(7, 0);
        gotoxy(50, 12);
        cout << "          Menu   " << endl;
        gotoxy(50,14);
        cout << "          Start            " << endl;
        gotoxy(50, 16);
        cout << "         Credits           " << endl;
        gotoxy(50, 18);
        cout << "          Quit             " << endl;

        gotoxy(50, 21);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            cfa.setColor(0, 7);
            gotoxy(50, 14);
            cout << "          Start          " << endl;
        }
        if (j == 1) {
            cfa.setColor(0, 7);
            gotoxy(50, 16);
            cout << "         Credits         " << endl;
        }
        if (j == 2) {
            cfa.setColor(0, 7);
            gotoxy(50, 18);
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
		cfa.redraw(0, "Hello", 0);
        sleep_for(1s);
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
        return 1;
    }
    return 0;
}
