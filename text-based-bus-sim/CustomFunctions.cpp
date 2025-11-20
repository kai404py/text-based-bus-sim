#include "CustomFunctions.h"

Draw cfd;

void CustomFunctions::setColor(int textColor, int bgColor) {
    cout << "\033[" << textColor << ";" << bgColor << "m";
}

void CustomFunctions::gotoXY(int x, int y) {
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	cout << "                                                                                                                                                                                                                                                                                       ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void CustomFunctions::redraw(int returnTo, string dest, string num) {
	gotoXY(0, 0);
	cfd.Dest(dest, num);
	gotoXY(0, returnTo);
}

CustomFunctions::CustomFunctions() {}

vector<RouteData> CustomFunctions::loadRoutes() {
    vector<RouteData> routes;
    ifstream inFile("routes/routes.txt");

    if (!inFile) {
        cout << "Unable to open routes.txt";
        exit(1);
    }

    string line;
    while (getline(inFile, line, ',')) {

        if (line.empty()) continue;

        stringstream ss(line);
        RouteData r;

        getline(ss, r.number, '*');
        getline(ss, r.inbound, '*');
        getline(ss, r.outbound, '*');
        getline(ss, r.filename, '*');

        // Trim whitespace
        auto trim = [](string& s) {
            while (!s.empty() && isspace(s.front())) s.erase(s.begin());
            while (!s.empty() && isspace(s.back())) s.pop_back();
            };

        trim(r.number);
        trim(r.inbound);
        trim(r.outbound);
        trim(r.filename);

        routes.push_back(r);
    }

    return routes;
}

vector<string> CustomFunctions::getRoutes() {
    vector<string> routes;
    ifstream inFile("routes/routes.txt");

    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    string line;
    while (getline(inFile, line, ',')) {

        if (line.empty()) continue;

        while (!line.empty() && (line.front() == '\n' || line.front() == '\r' || line.front() == ' '))
            line.erase(line.begin());
        while (!line.empty() && (line.back() == '\n' || line.back() == '\r' || line.back() == ' '))
            line.pop_back();

        stringstream ss(line);
        string routeNumber;
        getline(ss, routeNumber, '*');

        routes.push_back(routeNumber);
    }

    return routes;
}

vector<string> CustomFunctions::loadStops(const string& routeNum, int direction) {

    vector<string> stops;
    string filename = "routes/" + routeNum + ".txt";

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open: " << filename << endl;
        return stops;
    }

    string line;
    bool readingBlock = false;
    string blockHeader = to_string(direction) + " - {";

    while (getline(file, line)) {

        if (line.find(blockHeader) != string::npos) {
            readingBlock = true;
            continue;
        }

        if (readingBlock && line.find("}") != string::npos) {
            break;
        }

        if (readingBlock) {
            size_t pos = 0;

            while ((pos = line.find("\"")) != string::npos) {
                size_t end = line.find("\"", pos + 1);
                if (end == string::npos) break;

                string stop = line.substr(pos + 1, end - pos - 1);
                stops.push_back(stop);

                line = line.substr(end + 1);
            }
        }
    }

    return stops;
}
