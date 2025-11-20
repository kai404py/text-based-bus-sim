#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "tts.h"
#include "windowsH.h"
#include "draw.h"

using namespace std;

struct RouteData { string number; string inbound; string outbound; string filename; vector<string> inboundStops; vector<string> outboundStops; };

class CustomFunctions
{
public:
	void setColor(int textColor, int bgColor);
	void gotoXY(int x, int y);
	void redrawDest(int returnTo, int id, int direction);
	void redraw(int returnTo, string dest, string num = "~");
	CustomFunctions();
	vector<string> getRoutes();
	vector<RouteData> loadRoutes();
	vector<string> loadStops(const string& routeNum, int direction);
	vector<RouteData> data;
};