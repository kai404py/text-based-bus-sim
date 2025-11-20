#include "game.h"
#include "Menus.h"

CustomFunctions cf;
Draw d;
Menus mn;
CustomWTTS Ctts;

using namespace std;


void start(const vector<string>& routeStops, const string& num, const string& dest)
{
    int baseY = 12;

    cf.redraw(baseY, dest, num);

	string lastStop = "Unknown Stop";

    if (routeStops.empty()) {
        Ctts.Speak("No stops were found for this route.");
        return;
    }

    for (size_t i = 0; i < routeStops.size(); i++) {
        lastStop = routeStops[i];
        Ctts.Speak("Next stop: " + routeStops[i]);

        cf.redraw(baseY, dest, num);

    }

    Ctts.Speak(
        "This bus terminates here. " + lastStop +
        " is our final stop. Please take all personal belongings with you."
    );
    exit(0);
}


int rollAllBlinds(const vector<RouteData>& data, int stopAtID, int direction)
{
    string prevNum = "~";
    string prevDest = "Not in Service";

    for (int i = 0; i <= stopAtID; i++) {

        string currNum = data[i].number;

        {
            string currDest = data[i].inbound;

            d.RollDestination(currNum, prevNum, currDest, prevDest);

            prevNum = currNum;
            prevDest = currDest;

            if (i == stopAtID && direction == 0) {
                system("cls");
                return 0;
            }
        }

        {
            string currDest = data[i].outbound;

            d.RollDestination(currNum, prevNum, currDest, prevDest);

            prevNum = currNum;
            prevDest = currDest;

            if (i == stopAtID && direction == 1) {
                system("cls");
                return 0;
            }
        }
    }

    system("cls");
    return 1;
}

void game::startRoute(int RouteNumber)
{
    vector<RouteData> data = cf.loadRoutes();
    string RouteNumberSTR = to_string(RouteNumber);

    system("cls");
    cf.setColor(7, 0);
    cf.redraw(0, RouteNumberSTR, "Loading...");
    sleep_for(1s);
    system("cls");

    int foundID = -1;

    for (size_t i = 0; i < data.size(); i++) {
        int loadedNum = 0;
        try {
            loadedNum = stoi(data[i].number);
        }
        catch (...) {
            continue;
        }

        if (loadedNum == RouteNumber) {
            foundID = static_cast<int>(i);
            break;
        }
    }

    if (foundID == -1) {
        cout << "Route not found\n";
        return;
    }

    RouteData& r = data[foundID];

    int direction = mn.destinationSelector(RouteNumberSTR, r.inbound, r.outbound) == 2 ? 1 : 0;

    string dest = (direction == 0 ? r.inbound : r.outbound);
    string num = r.number;

    sleep_for(500ms);
    rollAllBlinds(data, foundID, direction);

    vector<string> stops = cf.loadStops(r.number, direction);

    if (stops.empty()) {
        Ctts.Speak("No stops found for this route direction.");
        return;
    }

    start(stops, num, dest);

    cout << endl;
}
