#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

Vector2 Player::GetPosition()
{
	return PlayerRect.position;
}

void Player::SetPosition(int newX, int newY)
{
	PlayerRect.position.x = newX;
	PlayerRect.position.y = newY;
}

int Player::GetHP()
{
	return HP;
}

void Player::SetHp(int newHP)
{
	HP = newHP;
}

int Player::GetPuntuation()
{
	return puntuation;
}

void Player::SetPuntuation(int newPunt)
{
	puntuation = newPunt;
}

int Player::GetSpeed()
{
	//return speed; 
	return 0;
}

void Player::SetSpeed(int newSpeed)
{
	//speed = newSpeed;
}

PlayerState Player::GetState()
{
	return state;
}

void Player::SetState(PlayerState newState)
{
	state = newState;
}
