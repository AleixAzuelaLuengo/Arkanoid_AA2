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

void Player::SetPosition(Vector2 newPos)
{
	PlayerRect.position = newPos;
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
	return speed;
}

void Player::SetSpeed(int newSpeed)
{
	speed = newSpeed;
}

PlayerState Player::GetState()
{
	return state;
}

void Player::SetState(PlayerState newState)
{
	state = newState;
}
