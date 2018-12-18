#pragma once
#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include "Button.h"
#include "Scene.h"

class Play: public Scene
{
public:
	Play();
	~Play();
private:
	Player playerLeft;
	Player playerRight;
	Ball ball;
	//Brick *brickList[][];
	Button soundSwitch;
	SDL_Event event;
	
protected:
	void Update();
	void Draw();

};

