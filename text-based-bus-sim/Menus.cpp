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
    cfa.setColor(7, 0);
    system("cls");
    cfa.setColor(7, 0);
    cfa.redraw(12, "Not in Service");
    cfa.setColor(7, 0);
}

int Menus::routeSelector() {

again:
    int option;
    static int j = 0;
    system("cls");
    vector<string> routes = cfa.getRoutes();
	int drawRouteAt = 14;

    do {
        cfa.setColor(7, 0);
        cfa.redraw(12, "Not in Service");

        gotoxy(50, 12);
        cout << "Routes:";

        int startY = 14;
        int drawY = startY;

        gotoxy(50, startY);
        for (size_t i = 0; i < routes.size(); i++) {

            if ((int)i == j) {
                cfa.setColor(0, 7);
            }
            else {
                cfa.setColor(7, 0);
            }

            gotoxy(50, drawY);
            cout << routes[i];
            drawY++;
        }

        cfa.setColor(7, 0);
        gotoxy(50, drawY + 2);
        cout << "USE UP AND DOWN ARROW KEYS...";

        option = _getch();

        switch (option) {
        case 80:
            j++;
            if (j >= (int)routes.size()) j = 0;
            break;

        case 72:
            j--;
            if (j < 0) j = routes.size() - 1;
            break;
        }

    } while (option != 13);

    int selectedRoute = stoi(routes[j]);

    g.startRoute(selectedRoute);

    return 0;
}


int Menus::destinationSelector(string routeNum, string inbound, string outbound)
{
    int option;
    int j = 0;
    cls();
    vector<string> dests = { inbound, outbound, "Back" };

    do {
        cfa.setColor(7, 0);

        cfa.redraw(0, routeNum, "Route");

        gotoxy(50, 12);
        cout << "Destinations:";

        int drawY = 14;

        for (int i = 0; i < dests.size(); i++) {

            if (i == j)
                cfa.setColor(0, 7);
            else
                cfa.setColor(7, 0);

            gotoxy(50, drawY);
            cout << dests[i];
            drawY += 2;
        }

        cfa.setColor(7, 0);
        gotoxy(50, drawY);
        cout << "USE UP AND DOWN ARROW KEYS...";

        option = _getch();

        switch (option) {
        case 80:
            j++;
            if (j >= dests.size()) j = 0;
            break;

        case 72:
            j--;
            if (j < 0) j = dests.size() - 1;
            break;
        }

    } while (option != 13);

    system("cls");
    cfa.setColor(7, 0);

    if (j == 0) return 3;
    if (j == 1) return 2;
    routeSelector();
    return 0;
}

int Menus::mainMenu() {
again:
    int option;
    static int j = 0;
    system("cls");

    do {
        cfa.setColor(7, 0);
        cfa.redraw(12, "Not in Service");
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
		cfa.redraw(0, "Welcome");
        sleep_for(1s);
        return 0;
    case 1:
        cls();
        cfa.setColor(7, 0);
        cout << "IDK me i guess";
        cfa.setColor(7, 0);
        sleep_for(2s);
        mainMenu();
    case 2:
        cls();
        cfa.setColor(7, 0);
        exit(0);
    }
    return 0;
}
