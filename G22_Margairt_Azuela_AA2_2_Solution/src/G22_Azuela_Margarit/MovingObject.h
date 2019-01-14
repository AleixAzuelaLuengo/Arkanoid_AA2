#pragma once
#include "Types.h"
#include "Inputs.h"
#include "Constants.h"
#include <vector>

class MovingObject
{
private:
	static MovingObject *movingObject;

public:
	static MovingObject *Instance()
	{
		if (movingObject == nullptr) { movingObject = new MovingObject; }
		return movingObject;
	};
	MovingObject();
	template <class T> void Move(T object, Vector2 speed);
	int BallBounce(Rect ball, Rect obj, Vector2 ballSpeed);
	bool Collision(Rect ball, Rect collision);
	bool MouseCollision(Rect obj1, Inputs Mouse);
	Vector2 ballLimits(Vector2 ballP, const Vector2 ballS);
	Vector2 playerLimits(Vector2 playerP, int);
};


