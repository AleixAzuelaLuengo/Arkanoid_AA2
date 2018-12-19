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
	void Update(Inputs &input);
	void Draw();
private:
	Rect BG;
	Player playerLeft;
	Player playerRight;
	Ball ball;
	//Brick *brickList[][];
	Button soundSwitch;
	SDL_Event event;
	
protected:
	

};

