#include "PowerUp.h"
#include "Constants.h"


PowerUp::PowerUp()
{
	powerUpRect.proportions = { POWER_UP_WIDTH,POWER_UP_HEIGHT };
}


PowerUp::~PowerUp()
{
}

void PowerUp::SetSpeed(int s)
{
	speed = s;
}

int PowerUp::GetSpeed()
{
	return speed;
}

Vector2 PowerUp::GetPosition()
{
	return powerUpRect.position;
}

void PowerUp::SetPosition(int x, int y)
{
	powerUpRect.position = { x,y };
}

Rect PowerUp::GetRect()
{
	return powerUpRect;
}

void PowerUp::SetPowerUpType(powerUpType t)
{
	type = t;
}

powerUpType PowerUp::GetType()
{
	return type;
}


