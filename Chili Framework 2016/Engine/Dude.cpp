#include "Dude.h"
#include "Graphics.h"

Dude::Dude(int xVal, int yVal, int widthVal, int heightVal)
	:x(xVal), y(yVal), width(widthVal), height(heightVal)
{
}

void Dude::ClampToScreen()
{
	if (x <= 0)
	{
		x = 0;
	}
	else if (x + width >= Graphics::ScreenWidth - 1)
	{
		width = Graphics::ScreenWidth - 1 - x;
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (y + height >= Graphics::ScreenHeight - 1)
	{
		height = Graphics::ScreenHeight - 1 - y;
	}
}
