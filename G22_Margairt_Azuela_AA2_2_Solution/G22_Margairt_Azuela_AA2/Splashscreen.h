#pragma once
#include "Scene.h"
#include "Types.h"
#include "Constants.h"
#include "Renderer.h"

class Splashscreen: public Scene
{ 
public:
	Splashscreen();
	~Splashscreen();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();

private:
	
};

