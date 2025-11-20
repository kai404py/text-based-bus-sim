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

void scrollDest(string staticText, string scrolling) {
    int count = 0;
	string original = scrolling;
    cfa.redraw(12, "~", staticText + " " + scrolling);
    sleep_for(500ms);

    for (int i = 0; scrolling.length() != '\0'; i++)
    {
        cfa.redraw(12, "~", staticText + " " + scrolling);

        scrolling = scrolling.substr(1, scrolling.length());


		sleep_for(200ms);
    }

    scrollDest(staticText, original);
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

        gotoxy(70, 12);
        cout << "Routes:";

        int startY = 14;
        int drawY = startY;

        gotoxy(70, startY);
        if (routes.size() < 1) {
            system("cls");
            scrollDest("oops!", "Faild To Load Destinations");
            exit(0);
        }

        for (size_t i = 0; i < routes.size(); i++) {

            if ((int)i == j) {
                cfa.setColor(0, 7);
            }
            else {
                cfa.setColor(7, 0);
            }

            gotoxy(70, drawY);
            cout << routes[i];
            drawY++;
        }

        cfa.setColor(7, 0);
        gotoxy(70, drawY + 2);
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

        gotoxy(70, 12);
        cout << "Destinations:";

        int drawY = 14;

        if (sizeof(dests) < 1) {
            system("cls");
			scrollDest("oops!", "Faild To Load Destinations");
            exit(0);
        }

        for (int i = 0; i < dests.size(); i++) {

            if (i == j)
                cfa.setColor(0, 7);
            else
                cfa.setColor(7, 0);

            gotoxy(70, drawY);
            cout << dests[i];
            drawY += 2;
        }

        cfa.setColor(7, 0);
        gotoxy(70, drawY);
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
        gotoxy(70, 12);
        cout << "          Menu   " << endl;
        gotoxy(70,14);
        cout << "          Start            " << endl;
        gotoxy(70, 16);
        cout << "         Credits           " << endl;
        gotoxy(70, 18);
        cout << "          Quit             " << endl;

        gotoxy(70, 21);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            cfa.setColor(0, 7);
            gotoxy(70, 14);
            cout << "          Start          " << endl;
        }
        if (j == 1) {
            cfa.setColor(0, 7);
            gotoxy(70, 16);
            cout << "         Credits         " << endl;
        }
        if (j == 2) {
            cfa.setColor(0, 7);
            gotoxy(70, 18);
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
        cout << "ME\nWe3School\nGeeksForGeeks\nStackoverflow";
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
