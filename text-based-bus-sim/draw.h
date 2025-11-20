#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <iostream>

using namespace std;

class Draw
{
public:
	void Bus();
	void Dest(const std::string& dest, const std::string& num);
	//void RouteNumber(int RouteNumber);
	void Destination(int RouteNumber, int Direction);
	void RollDestination(string RollToNum, string RollFromNum, string RollToDest, string RollFromDest);
};

#endif