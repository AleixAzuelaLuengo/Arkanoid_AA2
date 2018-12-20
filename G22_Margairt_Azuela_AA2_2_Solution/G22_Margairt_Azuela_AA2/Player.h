#pragma once
#include "Types.h"
enum PlayerState{};
class Player
{
public:
	Player();
	~Player();
	Vector2 GetPosition();
	void SetSpeed(int);
	int GetSpeed();
	Rect GetFlipedRect();
	void SetPosition(int x, int y );
	int GetHP();
	void SetHp(int);
	int GetPuntuation(int );
	void SetPuntuation(int);
	void MoveUp();
	void MoveDown();
	PlayerState GetState();
	void SetState(PlayerState);
	Rect GetRect();
	Rect GetHPBar(int numHP);
	MyText GetText();
	void SetTextPos(int x, int y);
	void SetPosHealth(int x, int y, int numHP);
private:
	int HP;
	Rect hpBAR[3];
	MyText puntuationText;
	int puntuation[1][1][1][1];
	int speed;
	PlayerState state;
	Rect PlayerRect;
};

