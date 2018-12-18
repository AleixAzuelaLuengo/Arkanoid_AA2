#pragma once
#include "Scene.h"

class Splashscreen: public Scene
{ 
public:
	Splashscreen();
	~Splashscreen();
	void Update(Inputs &input);
	void Draw();

private:
	
};

