#pragma once

class Dude
{
public:
	Dude(int x, int y, int width, int height);
	int x;
	int y;
	int width;
	int height;
	void ClampToScreen();
};