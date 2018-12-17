#pragma once
#include "Button.h"
class Menu
{
public:
	Menu();
	~Menu();
private:
	Button startGame;
	Button ranking;
	Button soundSwitch;
protected:
	void Update();
	void Draw();
};

