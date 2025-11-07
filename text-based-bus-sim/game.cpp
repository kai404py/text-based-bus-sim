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
	string routes[2][4] = {
		{"0", "1", "2", "3"},
		{"1", "25", "101", "201"}
	};

	string stops[4][5] = {
		{"Stop 1 - 1", "Stop 2", "Stop 3", "Stop 4"},
		{"Stop 1 - 25", "Stop 2", "Stop 3", "Stop 4"},
		{"Stop 1 - 101", "Stop 2", "Stop 3", "Stop 4"},
		{"Stop 1 - 201", "Stop 2", "Stop 3", "Stop 4"},
	};

	system("cls");
	cf.setColor(7, 0);
	cout << "Loading Route " << RouteNumber << endl;
	sleep_for(1s);
	system("cls");
	d.RouteNumber(RouteNumber);
	sleep_for(1s);
	system("cls");

	for (int j = 0; j < 4; j++) {
		int num = stoi(routes[1][j]);
		if (num == RouteNumber) {
			int id = stoi(routes[0][j]);
			PrintStops(stops[id]);
			break;
		}
		else {
			continue;
		}
	}
	
	cout << endl;
}