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


bool MovingObject::MouseCollision(Rect obj1, Inputs Mouse)
{
	return ((Mouse.GetMousePos(Inputs::MousePosition::X) > obj1.position.x)
		&& (Mouse.GetMousePos(Inputs::MousePosition::X) < (obj1.position.x + obj1.proportions.x))
		&& (Mouse.GetMousePos(Inputs::MousePosition::Y) > obj1.position.y)
		&& (Mouse.GetMousePos(Inputs::MousePosition::Y) < (obj1.position.y + obj1.proportions.y)));

}

MovingObject *MovingObject::movingObject = nullptr;
