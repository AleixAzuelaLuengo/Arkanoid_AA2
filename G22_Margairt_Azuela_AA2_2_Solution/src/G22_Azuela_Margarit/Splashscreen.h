#pragma once
#include "Scene.h"
#include "Types.h"
#include "Constants.h"
#include "Renderer.h"
#include "Music.h"

class Splashscreen: public Scene
{ 
public:
	Splashscreen();
	~Splashscreen();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState, Music &music);
	void Draw();

private:
	Rect BG;
	Rect PauseBG;
	MyText ArkanoidText;
	int speed;
	double sec = 0;
};

