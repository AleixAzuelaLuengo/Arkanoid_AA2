#pragma once
#include "Types.h"
class Ball
{
public:
	Ball();
	~Ball();
	void SetSpeed(Vector2);
	void SetPosition(int, int);
	Vector2 GetSpeed();
	Vector2 GetPosition();
	Rect GetRect();
private:
	Vector2 speed;
	Rect ballRect;
};

