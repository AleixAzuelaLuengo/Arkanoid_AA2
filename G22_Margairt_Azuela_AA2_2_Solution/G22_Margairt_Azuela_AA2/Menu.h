#pragma once
#include "Button.h"
#include "Scene.h"

class Menu: public Scene
{
public:
	Menu();
	~Menu();
	void Update(Inputs &input);
	void Draw();
private:
	Rect BG;
	MyText startGame;
	MyText ranking;
	MyText soundOnSwitch;
	bool soundOn;
};

