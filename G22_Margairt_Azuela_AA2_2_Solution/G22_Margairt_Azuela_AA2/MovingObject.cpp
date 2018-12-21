#include "MovingObject.h"



MovingObject::MovingObject()
{
}



Vector2 MovingObject::BallBounce(Rect ball, Rect obj, Vector2 ballSpeed)
{
	//Vector2 direction = { ball.GetBallPos().x + ball.GetSpeed().x, ball.GetBallPos().y + ball.GetSpeed().y };
	
	//if ((ball.position.y <= (obj.position.y + obj.proportions.y - 1)) && (ball.position.y >= (obj.position.y + 1)))
	if ((((ballSpeed.x < 0) && (ball.position.x == (obj.position.x + obj.proportions.x * 2)))
		|| (((ballSpeed.x > 0) && (ball.position.x + ball.proportions.x == obj.position.x + obj.proportions.x)))) && ((ball.position.y <= (obj.position.y + obj.proportions.y - 1)) && (ball.position.y >= (obj.position.y - obj.proportions.y/2 + 1))))
	{
		ballSpeed.x *= -1;
	}
	else if ((((ballSpeed.y < 0) && (ball.position.y == (obj.position.y + obj.proportions.y)))
		|| (((ballSpeed.y > 0) && (ball.position.y + ball.proportions.y == obj.position.y)))) && ((ball.position.x > (obj.position.x + obj.proportions.x + ball.proportions.x / 2 - 1)) && (ball.position.x < obj.position.x - ball.proportions.x / 2 + 1)))
	{
		ballSpeed.y *= -1;
	}
	return ballSpeed;
}

template<class T>
bool MovingObject::Collision(T ball, T collision)
{
	
	if ((ball.x > collision.x) && (ball.x < (collision.x + collision.w)) && (ball.y > collision.y) && (ball.y < (collision.y + collision.h))) return true;
	if ((ball.x + ball.w > collision.x) && (ball.x + ball.w < (collision.x + collision.w)) && (ball.y > collision.y) && (ball.y < (collision.y + collision.h))) return true;
	if ((ball.x > collision.x) && (ball.x < (collision.x + collision.w)) && (ball.y + ball.h > collision.y) && (ball.y + ball.h < (collision.y + collision.h))) return true;
	if ((ball.x + ball.w > collision.x) && (ball.x + ball.w < (collision.x + collision.w)) && (ball.y + ball.h > collision.y) && (ball.y + ball.h < (collision.y + collision.h))) return true;

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
