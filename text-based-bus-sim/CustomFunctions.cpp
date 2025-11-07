#include "CustomFunctions.h"

Draw cfd;

void CustomFunctions::setColor(int textColor, int bgColor) {
    std::cout << "\033[" << textColor << ";" << bgColor << "m";
}

void CustomFunctions::gotoXY(int x, int y) {
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	cout << "                                                                                                                                                                                                                                                                                       ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void CustomFunctions::redrawDest(int returnTo, int id, int direction) {
	gotoXY(0, 0);
	cfd.Destination(id, direction);
	gotoXY(0, returnTo);
}

void CustomFunctions::redraw(int returnTo, string dest, int X) {
	gotoXY(0, 0);
	cfd.Dest(dest);
	gotoXY(0, returnTo);
}