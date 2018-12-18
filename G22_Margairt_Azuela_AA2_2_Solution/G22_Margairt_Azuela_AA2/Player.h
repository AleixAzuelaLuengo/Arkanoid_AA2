#pragma once
#include "Types.h"
enum PlayerState{};
class Player
{
public:
	Player();
	~Player();
	Vector2 GetPosition();
	void SetPosition(int x, int y );
	int GetHP();
	void SetHp(int);
	int GetPuntuation();
	void SetPuntuation(int);
	int GetSpeed();
	void SetSpeed(int);
	PlayerState GetState();
	void SetState(PlayerState);

private:
	int HP;
	int puntuation;
	PlayerState state;
	Rect PlayerRect;
};

