#pragma once
#include "Button.h"
#include "Scene.h"
#include "Inputs.h"

class Menu: public Scene
{
public:
	Menu();
	~Menu();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();
private:
	Rect BG;
	MyText startGame;
	MyText ranking;
	MyText soundOnSwitch;
	MyText exit;
	bool soundOn;
};

