#include "game.h"

CustomFunctions cf;
Draw d;

using namespace std;

//[DEBUG] cout all stops in a route
void PrintStops(string route[]) {
	int n = sizeof(route) / sizeof(route[0]);

	for (int j = 0; j < 4; j++) {
		cout << route[j] << " \n";
	}
	cout << endl;
}

void game::startRoute(int RouteNumber) {
	string stops[1][4] = {
		{"Stop 1", "Stop 2", "Stop 3", "Stop 4"}
	};

	cf.setColor(7, 0);
	cout << "Loading Route " << RouteNumber << endl;
	sleep_for(1s);
	system("cls");
	d.RouteNumber(RouteNumber);
	sleep_for(1s);
	system("cls");
	PrintStops(stops[0]);
}