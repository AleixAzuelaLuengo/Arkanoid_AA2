#pragma once
#include "Types.h"
#include "Scene.h"

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

