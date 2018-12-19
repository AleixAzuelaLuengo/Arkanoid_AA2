#pragma once
#include "Types.h"
#include "Inputs.h"

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
	~MovingObject();
	template <class T> void Move(T object, Vector2 speed);
	template <class T> void detectCollision(T object, Vector2 speed);
	template <class T> Vector2 changeSpeed(T object, Vector2 collision);
	bool MouseCollision(Rect obj1, Inputs Mouse);
};


