#include "Types.h"

Rect::Rect()
{
}

Rect::Rect(int x, int y, int w, int h)
{
	position.x = x;
	position.y = y;
	proportions.x = w;
	proportions.y = h;
}

MyColor::MyColor()
{
}

MyColor::MyColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	r = red; g = green; b = blue; a = alpha;
}

Vector2::Vector2()
{
}

Vector2::Vector2(int newX, int newY)
{
	x = newX; y = newY;
}
