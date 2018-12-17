#pragma once
#include "Types.h"
class MovingObject
{
public:
	MovingObject();
	~MovingObject();
	template <class T> void Move(T object, Vector2 speed);
	template <class T> void detectCollision(T object, Vector2 speed);
	template <class T> Vector2 changeSpeed(T object, Vector2 collision);
};

