#pragma once
#include "Types.h"
enum BrickType{ };

class Brick
{
public:
	enum brickType { NORMAL, HEAVY, FIX, END };
	Brick();
	~Brick();
	Brick(BrickType, int);
	void SetPuntuation(int );
	void SetProbability(int);
	int GetPuntuation();
	int GetProbability();
	void SetHP(int );
	int GetHP();
	void SetType(BrickType);
	BrickType GetType();
	Rect GetRect();
private:
	int puntuation;
	int probability;
	int hp;
	BrickType type;
	Rect brickRect;
	//Rect brickRect;
};

