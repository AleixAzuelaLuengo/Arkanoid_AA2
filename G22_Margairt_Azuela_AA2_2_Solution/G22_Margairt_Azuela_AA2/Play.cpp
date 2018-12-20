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
	if (input.GetInput(Inputs::InputType::Quit))
	{
		sceneStatus = sceneState::EXIT;
		gameState = stateType::MENU;
	}
	if (input.GetInput(input.W))
	{
		playerLeft.MoveUp();
	}
	else if (input.GetInput(input.S))
	{
		playerLeft.MoveDown();
	}
	if (input.GetInput(input.UpArrow))
	{
		playerRight.MoveUp();
	}
	else if (input.GetInput(input.DownArrow))
	{
		playerRight.MoveDown();
	}
	Vector2 aux = MovingObject::Instance()->playerLimits(playerLeft.GetPosition());
	playerLeft.SetPosition(aux.x, aux.y);

	aux = MovingObject::Instance()->playerLimits(playerRight.GetPosition());
	playerRight.SetPosition(aux.x, aux.y);

	ball.SetSpeed(MovingObject::Instance()->ballLimits(ball.GetPosition(), ball.GetSpeed()));
	ball.SetPosition(ball.GetPosition().x + ball.GetSpeed().x, ball.GetPosition().y + ball.GetSpeed().y);
}

void Play::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerLeft.GetFlipedRect(), 90);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerRight.GetFlipedRect(), 90);
	Renderer::Instance()->PushImage("BALL", ball.GetRect());
	
}
