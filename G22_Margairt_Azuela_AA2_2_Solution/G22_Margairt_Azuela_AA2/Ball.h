#pragma once
#include "Types.h"
class Ball
{
public:
	Ball();
	~Ball();
	void SetSpeed(Vector2 );
	void SetPosition(int, int);
	Vector2 GetSpeed();
	Vector2 GetBallPos();
	Rect GetRect();
private:
	Vector2 speed;
	Rect ballRect;
};

