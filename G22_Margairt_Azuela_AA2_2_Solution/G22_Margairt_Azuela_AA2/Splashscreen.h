#pragma once
#include "Scene.h"

class Splashscreen: public Scene
{ 
public:
	Splashscreen();
	~Splashscreen();
	void Update();
	void Draw();

private:
	int tuputamadre;
};

