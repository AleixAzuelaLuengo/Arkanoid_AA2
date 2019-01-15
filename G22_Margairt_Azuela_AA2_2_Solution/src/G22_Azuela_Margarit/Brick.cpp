#include "Brick.h"



Brick::Brick()
{
	brickRect = { 0,0,BRICK_WIDTH, BRICK_HEIGHT };
	spriteRect = { 0 , 0 , 40, 20 };
}

Brick::~Brick()
{
}

template <class T>
Brick::Brick(T newHp, T newPuntuation, int prob, T i, T j, T brickType)
{
	type = brickType;
	hp = newHp;
	puntuation = newPuntuation;
	probability = prob;
	brickRect.position.x = i;
	brickRect.position.y = j;
}



void Brick::SetPuntuation(int newPuntuation)
{
	puntuation = newPuntuation;
}

void Brick::SetProbability(int newProb)
{
	probability = newProb;
}

void Brick::SetPosition(int i, int j)
{
	brickRect.position.x = i;
	brickRect.position.y = j;
}

int Brick::GetPosition(char coordenates)
{
	if (coordenates == 'x') return brickRect.position.x;
	if (coordenates == 'y') return brickRect.position.y;
}

int Brick::GetPuntuation()
{
	return puntuation;
}

void Brick::SetID(int newId)
{
	id = newId;
}

int Brick::GetID()
{
	return id;
}

Rect Brick::GetRect()
{
	return brickRect;
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

void Brick::SetType(char newType)
{
	if (newType == 'N') 
		type = BrickType::N;
	if (newType == 'H') 
		type = BrickType::H;
	if (newType == 'F') 
		type = BrickType::F;
}

char Brick::GetType()
{
	if (type == BrickType::N) return 'N';
	if (type == BrickType::H) return 'H';	
	if (type == BrickType::F) return 'F';
}

Rect Brick::GetSpriteRect()
{
	return spriteRect;
}

int Brick::GetNumAnimation()
{
	return numAnimation;
}

void Brick::Animate()
{
	if (this->type == BrickType::N && hp == 1) {
		spriteRect = GREENBLOCK_FIRST; 
		return;
	}
	else if (this->type == BrickType::H) 
	{
		if(hp == 3) spriteRect = REDBLOCK_FIRST;
		else if (hp == 2) spriteRect = REDBLOCK_SECOND;
		else if (hp == 1) spriteRect = REDBLOCK_THIRD;
	}
	else if (this->type == BrickType::F)
	{
		if (hp % 2 != 0) spriteRect = FIXEDBLOCK_FIRST;
		else if (hp % 2 == 0) spriteRect = FIXEDBLOCK_SECOND;
		return;
	}
	if (hp == 0 && spriteRect.position.x < 200)
	{
		frameTimeSprite++;
		if (FPS / frameTimeSprite <= 9)
		{
			spriteRect.position.x += PROPORTIONS_BLOCKS;
			frameTimeSprite = 0;
		}
	}
}

Rect Brick::GetFlipedRect()
{
	return Rect{ brickRect.position.x - brickRect.proportions.x , brickRect.position.y , brickRect.proportions.y, brickRect.proportions.x };
}
