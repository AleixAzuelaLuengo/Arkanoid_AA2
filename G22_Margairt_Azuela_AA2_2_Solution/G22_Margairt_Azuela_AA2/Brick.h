#pragma once
#include "Types.h"
#include "Constants.h"
class Brick
{
public:
	enum BrickType { N, H, F, END };
	Brick();
	~Brick();
	template<class T>Brick(T, T, int, T, T, T);
	void SetPuntuation(int );
	void SetProbability(int);
	void SetPosition(int, int);
	int GetPosition(char coordenates);
	int GetPuntuation();
	void SetID(int id);
	int GetID();
	Rect GetRect();
	int GetProbability();
	void SetHP(int );
	int GetHP();
	void SetType(char);
	char GetType();
private:
	Rect brickRect;
	int puntuation;
	int probability;
	int hp;
	char type;
	int id;
};


