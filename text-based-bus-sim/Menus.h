#pragma once
#include "CustomFunctions.h"

class Menus
{
public:
	int mainMenu();
	int routeSelector();
	int destinationSelector(string RouteNum, string inbound, string outbound);
};

