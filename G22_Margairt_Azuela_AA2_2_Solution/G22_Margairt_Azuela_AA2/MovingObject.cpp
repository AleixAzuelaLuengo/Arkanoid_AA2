#include "MovingObject.h"



MovingObject::MovingObject()
{
}


MovingObject::~MovingObject()
{
}

template<class T>
inline void MovingObject::detectCollision(T object, Vector2 speed)
{
}

template<class T>
bool MovingObject::Collision(T obj1, Inputs obj2)
{
	return ((obj2.GetMousePos(MousePosition::X) > obj1.position.x) 
		&& (obj2.GetMousePos(MousePosition::X) < (obj1.position.x + obj1.proportions.x))
		&& (obj2.GetMousePos(MousePosition::Y) > obj1.position.y)
		&& (obj2.GetMousePos(MousePosition::Y) < (obj1.position.y + obj1.proportions.y)));

	return false;
}

