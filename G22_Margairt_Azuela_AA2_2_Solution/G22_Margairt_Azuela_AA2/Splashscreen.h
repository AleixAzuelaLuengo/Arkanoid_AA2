#pragma once
#include "Scene.h"
#include "Types.h"
class Splashscreen: public Scene
{ 
public:
	Splashscreen();
	~Splashscreen();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();

private:
	Rect BG;
	Rect PauseBG;
	MyText ArkanoidText;
	int speed;
	double sec = 0;
};

