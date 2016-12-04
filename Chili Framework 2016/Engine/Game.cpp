/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();		// erase
	UpdateModel();			//
	ComposeFrame();			// render
	gfx.EndFrame();			// present
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!inhibitUp)
		{
			vy -= 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			vy += 1;
			inhibitDown = true;
		}
	} 
	else
	{
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!inhibitLeft)
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!inhibitRight)
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vx = 0;
		vy = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		c = Color('ff', '0', '0');
	}
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		target = FRAME;
	}
	else
	{
		target = CROSS;
	}

	/*if (vx >= 2) 
	{
		vx = 2;
	} 
	else if (vx <= -2)
	{
		vx = -2;
	}

	if (vy >= 2) 
	{
		vy = 2;
	}
	else if (vy <= -2)
	{
		vy = -2;
	}*/

	x += vx;
	y += vy;
}

void Game::ComposeFrame()
{
	switch (target) {
	case FRAME:
		gfx.PutPixel(x + 5, y + 5, c);
		gfx.PutPixel(x + 5, y + 4, c);
		gfx.PutPixel(x + 5, y + 3, c);
		gfx.PutPixel(x + 5, y - 3, c);
		gfx.PutPixel(x + 5, y - 4, c);
		gfx.PutPixel(x + 5, y - 5, c);
		gfx.PutPixel(x - 5, y + 5, c);
		gfx.PutPixel(x - 5, y + 4, c);
		gfx.PutPixel(x - 5, y + 3, c);
		gfx.PutPixel(x - 5, y - 3, c);
		gfx.PutPixel(x - 5, y - 4, c);
		gfx.PutPixel(x - 5, y - 5, c);
		gfx.PutPixel(x + 5, y + 5, c);
		gfx.PutPixel(x + 4, y + 5, c);
		gfx.PutPixel(x + 3, y + 5, c);
		gfx.PutPixel(x - 3, y + 5, c);
		gfx.PutPixel(x - 4, y + 5, c);
		gfx.PutPixel(x - 5, y + 5, c);
		gfx.PutPixel(x + 5, y - 5, c);
		gfx.PutPixel(x + 4, y - 5, c);
		gfx.PutPixel(x + 3, y - 5, c);
		gfx.PutPixel(x - 3, y - 5, c);
		gfx.PutPixel(x - 4, y - 5, c);
		gfx.PutPixel(x - 5, y - 5, c);
		break;
	case CROSS:
	default:
		gfx.PutPixel(x + 3, y, c);
		gfx.PutPixel(x + 4, y, c);
		gfx.PutPixel(x + 5, y, c);
		gfx.PutPixel(x - 3, y, c);
		gfx.PutPixel(x - 4, y, c);
		gfx.PutPixel(x - 5, y, c);
		gfx.PutPixel(x, y + 3, c);
		gfx.PutPixel(x, y + 4, c);
		gfx.PutPixel(x, y + 5, c);
		gfx.PutPixel(x, y - 3, c);
		gfx.PutPixel(x, y - 4, c);
		gfx.PutPixel(x, y - 5, c);
		break;
	}
}
