#include "Play.h"
#include "Constants.h"
#include "Renderer.h"
#include "MovingObject.h"



Play::Play()
{
	pause.text = "PAUSE";
	pause.font.size = 8;
	pause.idColor = ButtonNotSelected;
	pause.font.path = MENU_FONT;
	pause.font.id = "PAUSE_FONT";
	pause.rect = { 0, SCREEN_HEIGHT / 7, 500,100 };
	pause.rect.position.x = (SCREEN_WIDTH / 2) - (pause.rect.proportions.x / 2);

	soundOnSwitch.text = "Sound On";
	soundOnSwitch.font.size = 8;
	soundOnSwitch.font.path = MENU_FONT;
	soundOnSwitch.font.id = "SoundON_FONT";
	soundOnSwitch.idColor = ButtonNotSelected;
	soundOnSwitch.rect = { 0, SCREEN_HEIGHT / 2, 200,50 };
	soundOnSwitch.rect.position.x = (SCREEN_WIDTH / 6) - (soundOnSwitch.rect.proportions.x / 2);

	BG = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	playerLeft.SetPosition(10, SCREEN_HEIGHT / 2);
	playerRight.SetPosition(SCREEN_WIDTH - SCREEN_WIDTH / 11, SCREEN_HEIGHT / 2);
	ball.SetPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	Renderer::Instance()->LoadTexture("BG_MENU", BACKGROUND_MENU);
	Renderer::Instance()->LoadTexture("PLAYER", PLAYER_SPRITE);
	Renderer::Instance()->LoadTexture("BALL", BALL_SPRITE);
	Renderer::Instance()->LoadFont(pause.font);
	Renderer::Instance()->LoadTextureText(pause.font.id, pause);
	Renderer::Instance()->LoadFont(soundOnSwitch.font);
	Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);
}


Play::~Play()
{
}

void Play::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState)
{

	if(sceneStatus == sceneState::RUNNING)
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
		else if (input.GetInput(input.P) && sceneStatus == sceneState::RUNNING)
		{
			sceneStatus = sceneState::PAUSED;
		}
	}
	else if (sceneStatus == sceneState::PAUSED)
	{
		if (input.GetInput(input.SpaceBar))
		{
			sceneStatus = sceneState::RUNNING;
		}
		if (MovingObject::Instance()->MouseCollision(soundOnSwitch.rect, input))
		{
			soundOnSwitch.idColor = ButtonSelected;

			if (soundOnSwitch.text == "Sound On" && input.GetInput(Inputs::LeftClick))
				soundOnSwitch.text = "Sound Off";
			else if (soundOnSwitch.text == "Sound Off" && input.GetInput(Inputs::LeftClick))
				soundOnSwitch.text = "Sound On";
		}
		else
		{
			soundOnSwitch.idColor = ButtonNotSelected;
		}
		Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);
	}
}

void Play::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerLeft.GetFlipedRect(), 90);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerRight.GetFlipedRect(), 90);
	Renderer::Instance()->PushImage("BALL", ball.GetRect());
	if (sceneStatus == sceneState::PAUSED)
	{
		Renderer::Instance()->PushImage(pause.font.id, pause.rect);
		Renderer::Instance()->PushImage(soundOnSwitch.font.id, soundOnSwitch.rect);
	}
	
}
