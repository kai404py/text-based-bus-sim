#include "game.h"
#include "Menus.h"

CustomFunctions cf;
Draw d;
Menus mn;
CustomWTTS Ctts;

using namespace std;


void start(string route[], int id, int direction) {
	int currentStop = 0;
	int baseY = 12;
	cf.redrawDest(baseY, id, direction);

	int n = sizeof(route[direction]);

	for (int stopID = 0; stopID < n; stopID++) {
		int stop = stopID;
		if (route[stop] == "") {
			Ctts.Speak("This Bus Terminates Here. " + route[stop - 1] + ", Is our final stop. Please take all personal belongings with you when alighting the vehicle.");
			break;
		}

		Ctts.Speak("Next Stop: " + route[stop]);

		cf.redrawDest(baseY, id, direction);
	}

}

int rollAllBlinds(string routes[], int stopAtRouteId, int stopAtDirection) {
	int n = stopAtRouteId;

	for (int i = 0; i <= n; i++) {
		int routeId = stoi(routes[i]);
		for (int dir = 0; dir <= 1; dir++) {
			d.RollDestination(routeId, dir);
			if (routeId == stopAtRouteId && dir == stopAtDirection) {
				system("cls");
				return 0;
			}

			sleep_for(100ms);
		}
	}

	return 1;
}

void game::startRoute(int RouteNumber) {
	string routes[2][4] = {
		{"0", "1", "2", "3"},
		{"25", "99", "101", "103"}
	};

	if (RouteNumber == 000) {
		rollAllBlinds(routes[0], 4, 0);
		std::exit(EXIT_SUCCESS);
	}

	string stops[4][2][50] = {
		{
			{"Hanley Bus Station", "Hanley, adj Harding Road", "Shelton, opp Wellesley Street", "Shelton, opp Stoke-on-Trent College", "Shelton, adj Seaford Street", "Shelton, opp Cadman Building", "Stoke-on-Trent Railway Station (opp)", "Stoke-upon-Trent, adj Seven Arches", "Stoke-upon-Trent, opp Lytton Street"},
			{"Stop 4 - 25", "Stop 3", "Stop 2", "Stop 1"}
		},
		{
			{"Stop 4 - 1", "Stop 3", "Stop 2", "Stop 1"},
			{"Newcastle Bus Station", "Newcastle Under Lyme, opp Hannover Street", "The Brampton, opp Sidmouth Avenue", "The Brampton Museum (opp)", "Newcastle Under Lyme, opp Sandy Lane", "May Avenue (opp)", "May Bank, opp Upper Marsh", "May Bank, opp Upper Marsh", "Wolstanton, opp St Margaret’s Church", "Wolstanton, opp Morris Square", "Wolstanton, adj Marsh Avenue", "Porthill, adj St Andrew`s Church", "Porthill, adj Second Avenue", "Porthill, opp Vale View",  "Longport Road (opp)", "Longport, adj Station Street", "Longport, adj Trubshaw Cross", "Longport, opp Brereton Place", "Brownhills High School (opp)", "Brownhills Business Park (adj)", "Tunstall, adj Highgate", "Tunstall, adj stop A", "Tunstall, adj stop E", "Tunstall Catholic Church (opp)", "Chell, adj Sunnyside Avenue", "Chell, opp Eastwood Avenue", "Chell, adj Greenbank Road", "Chell, opp Burslem Golf Club", "Chell, adj Irene Avenue", "Little Chell Lane (adj)", "Chell, adj Irene Avenue", "Chell, opp Gowan Avenue", "Chell, opp Carlton Avenue", "Chell, adj Stoneleigh Road", "Chell, adj Beswick Road", "Chell, opp Fegg Hayes Road", "Chell, adj Biddulph Road", "Chell, adj Biddulph Road", "Oxford, adj Cumberbatch Avenue", "Fegg Hayes Road (opp)", "Fegg Hayes, opp Johnson Place", "Chell Heath, adj Barncroft Road"}
		},
		{{"Stop 1 - 101", "Stop 2", "Stop 3", "Stop 4"}, {"Stop 4 - 101", "Stop 3", "Stop 2", "Stop 1"}},
		{{"Stop 1 - 103", "Stop 2", "Stop 3", "Stop 4"}, {"Stop 4 - 103", "Stop 3", "Stop 2", "Stop 1"}}
	};

	string destinations[4][3] = {
		{"25", "Keele", "Stoke-on-Trent"},
		{"99", "Newcastle", "Chell Heath, Knave"},
		{"101", "Stafford", "Stoke-on-Trent"},
		{"103", "Crewe", "Stoke-on-Trent"}
	};

	int currentStop = 0;

	string RouteNumberSTR = to_string(RouteNumber);

	system("cls");
	cf.setColor(7, 0);
	cf.redraw(0, RouteNumberSTR, 0);
	cf.redraw(0, "loading", 0);
	sleep_for(1s);
	system("cls");
	
	int totalRoutes = sizeof(routes[0]);
	int direction = 0;

	for (int j = 0; j < totalRoutes; j++) {
		int num = stoi(routes[1][j]);
		if (num == RouteNumber) {
			int id = stoi(routes[0][j]);

			for (int a = 0; j < totalRoutes; a++) {
				int num = stoi(destinations[a][0]);
				if (num == RouteNumber) {
					int id = stoi(destinations[a][0]);

					string inbound = destinations[a][1];
					string outbound = destinations[a][2];

					if (mn.destinationSelector(RouteNumberSTR, inbound, outbound) == 2) {
						direction = 1;
					} else {
						direction = 0;
					}

					break;
				}
			}

			cout << id << " " << direction << endl;

			sleep_for(500ms);

			rollAllBlinds(routes[0], id, direction);
			start(stops[id][direction], id, direction);
			break;
		}
		else {
			continue;
		}
	}
	
	cout << endl;
}