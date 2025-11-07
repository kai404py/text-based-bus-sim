#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "tts.h"
#include "windowsH.h"
#include "draw.h"

using namespace std;

class CustomFunctions
{
public:
	void setColor(int textColor, int bgColor);
	void gotoXY(int x, int y);
	void redrawDest(int returnTo, int id, int direction);
	void redraw(int returnTo, string dest, int X);
};