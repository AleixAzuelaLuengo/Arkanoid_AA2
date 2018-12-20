#include "MovingObject.h"



MovingObject::MovingObject()
{
}


template<class T>inline bool MovingObject::detectCollision(T ball, T obj)
{
	Vector2 direction = { ball.GetBallPos().x + ball.GetSpeed().x, ball.GetBallPos().y + ball.GetSpeed().y };
	
	if ((ball.x > obj.x) && (ball.x < (obj.x + obj.w)) && (ball.y > obj.y)
		&& (ball.y < (obj.y + obj.h))) return true;

	if ((ball.x + ball.w > obj.x) && (ball.x + ball.w < (obj.x + obj.w)) 
		&& (ball.y > obj.y) && (ball.y < (obj.y + obj.h))) return true;

	if ((ball.x > obj.x) && (ball.x < (obj.x + obj.w)) && (ball.y + ball.h > obj.y)
		&& (ball.y + ball.h < (obj.y + obj.h))) return true;

	if ((ball.x + ball.w > obj.x) && (ball.x + ball.w < (obj.x + obj.w))
		&& (ball.y + ball.h > obj.y) && (ball.y + ball.h < (obj.y + obj.h))) return true;

}


bool MovingObject::MouseCollision(Rect obj1, Inputs Mouse)
{
	return ((Mouse.GetMousePos(Inputs::MousePosition::X) > obj1.position.x)
		&& (Mouse.GetMousePos(Inputs::MousePosition::X) < (obj1.position.x + obj1.proportions.x))
		&& (Mouse.GetMousePos(Inputs::MousePosition::Y) > obj1.position.y)
		&& (Mouse.GetMousePos(Inputs::MousePosition::Y) < (obj1.position.y + obj1.proportions.y)));
}

Vector2 MovingObject::ballLimits(Vector2 ballP,  Vector2 ballS)
{
	if (ballP.x <= MAP_START_X_AND_Y || ballP.x >= MAP_END_X) ballS.x = -ballS.x;

	if (ballP.y <= MAP_START_X_AND_Y || ballP.y >= MAP_END_Y) ballS.y = -ballS.y;

	return ballS;
}





Vector2 MovingObject::playerLimits(Vector2 p)
{	
	if (p.y < MAP_START_X_AND_Y + PLAYER_HEIGHT / 2 - 10)
		p.y += 5;
	if (p.y > MAP_END_Y - PLAYER_HEIGHT / 2)
		p.y -= 5;
	return p;
}





MovingObject *MovingObject::movingObject = nullptr;
