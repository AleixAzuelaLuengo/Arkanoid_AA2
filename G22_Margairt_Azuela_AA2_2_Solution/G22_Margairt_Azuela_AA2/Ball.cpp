#include "Ball.h"



Ball::Ball()
{
}


Ball::~Ball()
{
}

void Ball::SetSpeed(Vector2 newSpeed)
{
	speed = newSpeed;
}

void Ball::SetPosition(Vector2 newPos)
{
	ballRect.position = (newPos);
}

Vector2 Ball::GetSpeed()
{
	return speed;
}

Vector2 Ball::GetBallPos()
{
	return ballRect.position;
}


