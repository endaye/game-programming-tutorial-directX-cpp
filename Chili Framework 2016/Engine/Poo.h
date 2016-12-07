#pragma once

class Poo
{
public:
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isEaten = false;
public:
	void Update();
	void ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight);
private:

};
