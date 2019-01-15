#include "MovingObject.h"
#include <iostream>


MovingObject::MovingObject()
{
}



int MovingObject::BallBounce(Rect ball, Rect obj, Vector2 ballSpeed)
{

	if (((ball.position.x + ball.proportions.x == obj.position.x) || (ball.position.x + ball.proportions.x == obj.position.x +1)) && (ballSpeed.x > 0 ) &&
		((ball.position.y + ball.proportions.y) >= obj.position.y) && (ball.position.y <= (obj.position.y + obj.proportions.y)))
	{
		return 1;
	}

	if (((ball.position.x == obj.position.x + obj.proportions.x) || (ball.position.x == obj.position.x + obj.proportions.x - 1)) && (ballSpeed.x < 0) &&
		((ball.position.y + ball.proportions.y) >= obj.position.y) && (ball.position.y <= (obj.position.y + obj.proportions.y)))
	{
		return 2;
	}

	if (((ball.position.y + ball.proportions.y == obj.position.y) || (ball.position.y + ball.proportions.y == obj.position.y + 1)) && (ballSpeed.y > 0) &&
		((ball.position.x + ball.proportions.x) >= obj.position.x) && (ball.position.x <= (obj.position.x + obj.proportions.x)))
	{
		return 3;
	}

	if (((ball.position.y == obj.position.y + obj.proportions.y) || (ball.position.y == obj.position.y + obj.proportions.y - 1)) && (ballSpeed.y < 0) &&
		((ball.position.x + ball.proportions.x) >= obj.position.x) && (ball.position.x <= (obj.position.x + obj.proportions.x)))
	{
		return 4;
	}


	return 0;
}



bool MovingObject::Collision(Rect player, Rect collision)
{
	if (((collision.position.x + collision.proportions.x) >= player.position.x) && (collision.position.x <= (player.position.x + player.proportions.x)) &&
		((collision.position.y + collision.proportions.y) >= player.position.y) && (collision.position.y <= (player.position.y + player.proportions.y)))
	{
		return true;
	}

	return false;
}


bool MovingObject::MouseCollision(Rect obj1, Inputs Mouse)
{
	return ((Mouse.GetMousePos(Inputs::MousePosition::X) > obj1.position.x)
		&& (Mouse.GetMousePos(Inputs::MousePosition::X) < (obj1.position.x + obj1.proportions.x))
		&& (Mouse.GetMousePos(Inputs::MousePosition::Y) > obj1.position.y)
		&& (Mouse.GetMousePos(Inputs::MousePosition::Y) < (obj1.position.y + obj1.proportions.y)));
}

Vector2 MovingObject::ballLimits(Vector2 ballP, Vector2 ballS)
{
	if (ballP.x <= MAP_START_X_AND_Y ) ballS.x = 0;
	else if (ballP.x >= MAP_END_X) ballS.x = 1;

	if (ballP.y <= MAP_START_X_AND_Y || ballP.y >= MAP_END_Y) ballS.y = -ballS.y;

	return ballS;
}





Vector2 MovingObject::playerLimits(Vector2 p, int speed)
{
	if (p.y < MAP_START_X_AND_Y)
		p.y += speed;
	if (p.y + PLAYER_HEIGHT > MAP_END_Y + 15 )
		p.y -= speed;
	return p;
}


