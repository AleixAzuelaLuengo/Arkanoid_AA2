#pragma once
#include "Types.h"
#include "Inputs.h"

class MovingObject
{
public:
	MovingObject();
	~MovingObject();
	template <class T> void Move(T object, Vector2 speed);
	template <class T> void detectCollision(T object, Vector2 speed);
	template <class T> Vector2 changeSpeed(T object, Vector2 collision);
	template <class T> bool Collision(T obj1, Inputs obj2);
};


