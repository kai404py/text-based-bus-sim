#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <iostream>

using namespace std;

class Draw
{
public:
	void Bus();
	void Dest(string name);
	//void RouteNumber(int RouteNumber);
	void Destination(int RouteNumber, int Direction);
};

#endif