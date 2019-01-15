#pragma once
#include "Types.h"
#include "Constants.h"
class PowerUp
{
public:
	
	PowerUp();
	~PowerUp();
	void SetSpeed(int);
	int GetSpeed();
	Vector2 GetPosition();
	void SetPosition(int x, int y);
	Rect GetRect();
	void SetPowerUpType(powerUpType);
	powerUpType GetType();
private:
	powerUpType type;
	int speed;
	Rect powerUpRect;
};

