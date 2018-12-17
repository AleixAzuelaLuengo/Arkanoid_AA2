#pragma once
#include "Types.h"
class Ball
{
public:
	Ball();
	~Ball();
	void SetSpeed(Vector2 );
	void SetPosition(Vector2 );
	Vector2 GetSpeed();
	Vector2 GetBallPos();
private:
	Vector2 speed;
	Rect ballRect;
};

