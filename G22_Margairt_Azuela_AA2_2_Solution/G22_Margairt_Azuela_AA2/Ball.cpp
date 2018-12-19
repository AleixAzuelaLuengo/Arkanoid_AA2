#include "Ball.h"
#include "Constants.h"


Ball::Ball()
{
	ballRect.proportions = { BALL_WIDTH, BALL_HEIGHT };
}


Ball::~Ball()
{
}

void Ball::SetSpeed(Vector2 newSpeed)
{
	speed = newSpeed;
}

void Ball::SetPosition(int x, int y)
{
	ballRect.position = { x , y };
}

Vector2 Ball::GetSpeed()
{
	return speed;
}

Vector2 Ball::GetBallPos()
{
	return ballRect.position;
}

Rect Ball::GetRect()
{
	return ballRect;
}


