#pragma once
#include "Types.h"
#include "Scene.h"
#include "MovingObject.h"
#include "Music.h"

class Menu: public Scene
{
public:
	Menu();
	~Menu();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState, Music &music);
	void Draw();
private:
	MovingObject object;
	Rect BG;
	MyText startGame;
	MyText ranking;
	MyText soundOnSwitch;
	MyText exit;
	bool soundOn;
};

