#pragma once
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
private:
	int puntuation;
	int probability;
	int hp;
	BrickType type;
};

