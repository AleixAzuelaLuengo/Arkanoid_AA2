#pragma once
#include <string>
#include "../../../dep/inc/SDL/SDL.h"
#include "../../../dep/inc/SDL/SDL_image.h"
#include "../../../dep/inc/SDL/SDL_ttf.h"

struct MyColor
{
	Uint8 r, g, b, a;
};

struct Vector2
{
	int x, y;
};

struct Font
{
	std::string path, id;
	int size;
};

struct MyText
{
	std::string id, text;
	MyColor idColor;
};

struct Rect
{	
	Vector2 position, proportions;
};




