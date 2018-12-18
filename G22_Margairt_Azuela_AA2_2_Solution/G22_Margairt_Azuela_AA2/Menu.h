#pragma once
#include "Button.h"
#include "Scene.h"

class Menu: public Scene
{
public:
	Menu();
	~Menu();
private:
	Button startGame;
	Button ranking;
	Button soundSwitch;
	int test;
protected:
	void Update();
	void Draw();
};

