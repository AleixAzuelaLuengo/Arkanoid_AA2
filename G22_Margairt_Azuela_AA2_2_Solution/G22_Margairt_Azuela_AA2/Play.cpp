#include "Play.h"
#include "Constants.h"
#include "Renderer.h"
#include "MovingObject.h"



Play::Play()
{
	BG = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	playerLeft.SetPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2);
	playerRight.SetPosition(SCREEN_WIDTH - SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2);
	ball.SetPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	Renderer::Instance()->LoadTexture("BG_MENU", BACKGROUND_MENU);
	Renderer::Instance()->LoadTexture("PLAYER", PLAYER_SPRITE);
	Renderer::Instance()->LoadTexture("BALL", BALL_SPRITE);
}


Play::~Play()
{
}

void Play::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState)
{
	if (input.GetInput(input.W))
	{
		playerLeft.SetPosition((playerLeft.GetPosition().x)  , (playerLeft.GetPosition().y + 1));
	}
	else if (input.GetInput(input.S))
	{
		playerLeft.SetPosition((playerLeft.GetPosition().x), (playerLeft.GetPosition().y - 1));
	}
	if (input.GetInput(input.UpArrow))
	{
		playerRight.SetPosition((playerRight.GetPosition().x), (playerRight.GetPosition().y + 1));
	}
	else if (input.GetInput(input.DownArrow))
	{
		playerRight.SetPosition((playerRight.GetPosition().x), (playerRight.GetPosition().y - 1));
	}
}

void Play::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushImage("PLAYER", playerLeft.GetRect());
	Renderer::Instance()->PushImage("PLAYER", playerRight.GetRect());
	Renderer::Instance()->PushImage("BALL", ball.GetRect());
}
