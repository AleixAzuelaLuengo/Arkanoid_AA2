#pragma once
#include "Types.h"
enum PlayerState{};
class Player
{
public:
	Player();
	~Player();
	Vector2 GetPosition();
	Rect GetFlipedRect();
	void SetPosition(int x, int y );
	int GetHP();
	void SetHp(int);
	int GetPuntuation();
	void SetPuntuation(int);
	void MoveUp();
	void MoveDown();
	PlayerState GetState();
	void SetState(PlayerState);
	Rect GetRect();
private:
	int HP;
	int puntuation;
	PlayerState state;
	Rect PlayerRect;
};

