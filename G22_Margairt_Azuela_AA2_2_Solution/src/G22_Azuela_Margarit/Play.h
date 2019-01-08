#pragma once
#include "Player.h"
#include "Ball.h"
#include "Types.h"
#include "Map.h"
#include "Scene.h"

class Play: public Scene
{
public:
	Play();
	~Play();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();
private:
	Rect BG;
	Rect PauseBG;
	Player playerLeft;
	Player playerRight;
	Ball ball;
	Map brick;
	//Brick *brickList[][];
	SDL_Event event;
	MyText pause;
	MyText soundOnSwitch;
	std::vector<Brick> brickList;

};

