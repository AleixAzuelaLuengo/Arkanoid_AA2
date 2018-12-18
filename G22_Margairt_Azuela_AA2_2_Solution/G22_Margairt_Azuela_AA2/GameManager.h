#pragma once
#include "Scene.h"
#include "Inputs.h"
#include "Types.h"
#include "Menu.h"


class GameManager
{
public:
	GameManager();
	~GameManager();
	
	bool GetInput(InputType);
	float GetMouse(MousePosition);
	void SetInput(bool , InputType );
	void SetMouse(float, MousePosition);
	void update();
	void Draw();
private:
	enum stateType { SplashScreen, Menu, Play, Ranking, END };
	Inputs inputs;
	Scene *currentScene;
	stateType gameState;
	SDL_Event event;
};

