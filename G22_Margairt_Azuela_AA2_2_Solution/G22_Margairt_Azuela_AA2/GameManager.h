#pragma once
#include "Scene.h"
#include "Inputs.h"
#include "Types.h"
#include "Menu.h"
#include "Play.h"
#include "Splashscreen.h"
#include "Ranking.h"


class GameManager
{
public:
	GameManager();
	~GameManager();
	
	bool GetInput(Inputs::InputType);
	float GetMouse(Inputs::MousePosition);
	void SetInput(bool , Inputs::InputType );
	void SetMouse(float, Inputs::MousePosition);
	void Update();
	void Draw();
private:
	
	Inputs inputs;
	Scene *currentScene;
	SDL_Event event;
};

