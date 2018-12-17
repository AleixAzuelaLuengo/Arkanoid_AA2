#pragma once
#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include "Button.h"

class Play
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
protected:
	void Update();
	void Draw();

};

