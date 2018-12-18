#pragma once
#include "Button.h"

class Menu
{
public:
	Menu();
	~Menu();
	void Update();
	void Draw();
private:
	Rect BG;
	MyText startGame;
	MyText ranking;
	MyText soundSwitch;
	
};

