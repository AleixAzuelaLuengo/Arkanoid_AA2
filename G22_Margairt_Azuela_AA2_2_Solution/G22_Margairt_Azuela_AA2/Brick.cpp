#include "Brick.h"



Brick::Brick()
{
}


Brick::~Brick()
{
}

void Brick::SetPuntuation(int newPuntuation)
{
	puntuation = newPuntuation;
}

void Brick::SetProbability(int newProb)
{
	probability = newProb;
}

int Brick::GetPuntuation()
{
	return puntuation;
}

int Brick::GetProbability()
{
	return probability;
}

void Brick::SetHP(int newHP)
{
	hp = newHP;
}

int Brick::GetHP()
{
	return hp;
}

void Brick::SetType(BrickType newType)
{
	type = newType;
}

BrickType Brick::GetType()
{
	return type;
}
