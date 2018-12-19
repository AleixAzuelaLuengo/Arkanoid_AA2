#pragma once
#include "Scene.h"

class Splashscreen: public Scene
{ 
public:
	Splashscreen();
	~Splashscreen();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();

private:
	
};

