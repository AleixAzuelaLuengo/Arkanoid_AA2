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
	enum stateType { SPLASHSCREEN, MENU, PLAY, RANKING, END }gameState = stateType::MENU;
	bool GetInput(InputType);
	float GetMouse(MousePosition);
	void SetInput(bool , InputType );
	void SetMouse(float, MousePosition);
	void Update();
	void Draw();
private:
	
	Inputs inputs;
	Scene *currentScene;
	SDL_Event event;
};

