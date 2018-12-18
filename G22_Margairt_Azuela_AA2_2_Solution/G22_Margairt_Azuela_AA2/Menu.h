#pragma once
#include "Button.h"
#include "Scene.h"

class Menu: public Scene
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

