#pragma once
#include <string>
#include <SDL_types.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

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
	Font font;
};


struct Rect
{	
	Vector2 position, proportions;
};





