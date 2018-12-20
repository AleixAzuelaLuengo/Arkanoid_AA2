#include "Player.h"
#include "Constants.h"
#include "Renderer.h"


Player::Player()
{
	puntuationText.text = "Points: ";
	puntuationText.font.size = 8;
	puntuationText.idColor = Black;
	puntuationText.font.path = MENU_FONT;
	puntuationText.font.id = "PUNTUATION_FONT";
	puntuationText.rect = { 0, 0, 100,40 };
	speed = 4;
	PlayerRect.proportions = { PLAYER_WIDTH, PLAYER_HEIGHT };
	HP = 3;
	for(int i = 0; i < HP; i++) hpBAR[i] = { 0 , 0 , PLAYER_HEIGHT  , PLAYER_WIDTH };

	Renderer::Instance()->LoadTexture("PLAYER", PLAYER_SPRITE);
	Renderer::Instance()->LoadFont(puntuationText.font);
	Renderer::Instance()->LoadTextureText(puntuationText.font.id, puntuationText);
	
}


Player::~Player()
{
}

Vector2 Player::GetPosition()
{
	return PlayerRect.position;
}

void Player::SetSpeed(int newSpeed)
{
	speed = newSpeed;
}

int Player::GetSpeed()
{
	return speed;
}

Rect Player::GetFlipedRect()
{
	return Rect{ PlayerRect.position.x, PlayerRect.position.y, PlayerRect.proportions.y, PlayerRect.proportions.x };
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

int Player::GetPuntuation(int)
{
	return 0;
	//return puntuation[i][][][];
}

void Player::SetPuntuation(int newPunt)
{
	//puntuation = newPunt;
}



void Player::MoveUp()
{
	PlayerRect.position.y -= speed;
}

void Player::MoveDown()
{
	PlayerRect.position.y += speed;
}

PlayerState Player::GetState()
{
	return state;
}

void Player::SetState(PlayerState newState)
{
	state = newState;
}

Rect Player::GetRect()
{
	
	return PlayerRect;
}

Rect Player::GetHPBar(int i)
{
	return hpBAR[i-1];
}

MyText Player::GetText()
{
	return puntuationText;
}

void Player::SetTextPos(int x, int y)
{
	puntuationText.rect.position.x = x;
	puntuationText.rect.position.y = y;
}

void Player::SetPosHealth(int x, int y, int numHP)
{
	hpBAR[numHP-1].position.x = x;
	hpBAR[numHP-1].position.y = y;
}
