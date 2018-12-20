#include "Ball.h"
#include "Constants.h"


Ball::Ball()
{
	ballRect.proportions = { BALL_WIDTH, BALL_HEIGHT };
	speed.x = 1;
	speed.y = 1;
}


Ball::~Ball()
{
}

void Ball::SetSpeed(Vector2 vec)
{
	speed.x = vec.x;
	speed.y = vec.y;
}

void Ball::SetPosition(int x, int y)
{
	ballRect.position = { x , y };
}

Vector2 Ball::GetSpeed()
{
	return speed;
}

Vector2 Ball::GetPosition()
{
	return ballRect.position;
}

Rect Ball::GetRect()
{
	return ballRect;
}


