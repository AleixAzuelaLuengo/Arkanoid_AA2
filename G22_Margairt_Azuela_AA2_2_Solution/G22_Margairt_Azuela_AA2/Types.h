#pragma once
#include <string>
#include <SDL_types.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

struct MyColor
{
	Uint8 r, g, b, a;
	MyColor();
	MyColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
};

struct Vector2
{
	int x, y;
	Vector2();
	Vector2(int newX, int newY);
};

struct Font
{
	std::string path, id;
	int size;
};

struct Rect
{
	Vector2 position, proportions;
	Rect();
	Rect(int x, int y, int w, int h);
};

struct MyText
{
	std::string text;
	MyColor idColor;
	Font font;
	Rect rect;


};








