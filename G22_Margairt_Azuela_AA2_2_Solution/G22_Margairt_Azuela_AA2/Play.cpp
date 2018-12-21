#include "Play.h"
#include "Constants.h"
#include "Renderer.h"
#include "MovingObject.h"
#include <iostream>


Play::Play()
{

	PauseBG = { 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT };
	
	pause.text = "PAUSE";
	pause.font.size = 80;
	pause.idColor = ButtonNotSelected;
	pause.font.path = MENU_FONT;
	pause.font.id = "PAUSE_FONT";
	pause.rect = { 0, SCREEN_HEIGHT / 7, 500,100 };
	pause.rect.position.x = (SCREEN_WIDTH / 2) - (pause.rect.proportions.x / 2);

	soundOnSwitch.text = "Sound On";
	soundOnSwitch.font.size = 80;
	soundOnSwitch.font.path = MENU_FONT;
	soundOnSwitch.font.id = "SoundON_FONT";
	soundOnSwitch.idColor = ButtonNotSelected;
	soundOnSwitch.rect = { 0, SCREEN_HEIGHT / 2, 200,50 };
	soundOnSwitch.rect.position.x = (SCREEN_WIDTH / 6) - (soundOnSwitch.rect.proportions.x / 2);

	BG = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	playerRight.SetPosition(SCREEN_WIDTH - SCREEN_WIDTH / 11, SCREEN_HEIGHT / 2);

	playerLeft.SetPosition(10, SCREEN_HEIGHT / 2 -45);
	playerLeft.SetPosHealth(SCREEN_WIDTH/10, SCREEN_HEIGHT - SCREEN_HEIGHT/10, 3);
	playerLeft.SetPosHealth(playerLeft.GetHPBar(3).position.x + playerLeft.GetHPBar(3).proportions.x + 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 2);
	playerLeft.SetPosHealth(playerLeft.GetHPBar(2).position.x + playerLeft.GetHPBar(2).proportions.x + 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 1);
	

	playerRight.SetPosition(SCREEN_WIDTH /2 /*- SCREEN_WIDTH / 11*/, SCREEN_HEIGHT / 2 -45);
	playerRight.SetPosHealth(SCREEN_WIDTH - (SCREEN_WIDTH / 10)*2 -35, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 3);
	playerRight.SetPosHealth(playerRight.GetHPBar(3).position.x - playerRight.GetHPBar(3).proportions.x -10 , SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 2);
	playerRight.SetPosHealth(playerRight.GetHPBar(2).position.x - playerRight.GetHPBar(2).proportions.x - 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 1);

	playerLeft.SetTextPos(SCREEN_WIDTH / 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 6 + 5);
	playerRight.SetTextPos(SCREEN_WIDTH - (SCREEN_WIDTH / 10) * 4 - 15, SCREEN_HEIGHT - SCREEN_HEIGHT / 6 + 5);
	
	ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x*2, playerLeft.GetRect().position.y);

	Renderer::Instance()->LoadTexture("BRICK", BRICK_SPRITESHEET);
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
	if (sceneStatus == sceneState::START_GAME)
	{
		if (input.GetInput(Inputs::InputType::Quit))
		{
			sceneStatus = sceneState::EXIT;
			gameState = stateType::MENU;
			input.SetInput( Inputs::InputType::Quit, false);
		}
		if (input.GetInput(Inputs::InputType::SpaceBar))
		{
			sceneStatus = sceneState::RUNNING;
		}
		if (input.GetInput(input.W))
		{
			playerLeft.MoveUp();
			ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y);
		}
		else if (input.GetInput(input.S))
		{
			playerLeft.MoveDown();
			ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y);
		}
		if (input.GetInput(input.UpArrow))
		{
			playerRight.MoveUp();
		}
		else if (input.GetInput(input.DownArrow))
		{
			playerRight.MoveDown();
		}
	}
	else if(sceneStatus == sceneState::RUNNING)
	{
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
		Vector2 aux = MovingObject::Instance()->playerLimits(playerLeft.GetPosition());
		playerLeft.SetPosition(aux.x, aux.y);

		aux = MovingObject::Instance()->playerLimits(playerRight.GetPosition());
		playerRight.SetPosition(aux.x, aux.y);

		for(int i=0; i<11;i++)
			for(int j=0; j<12; j++)
				if(brickList[i][j] != nullptr)
					if (MovingObject::Instance()->Collision(ball.GetRect(), brickList[i][j]->GetRect()))
					{
						ball.SetSpeed(MovingObject::Instance()->BallBounce(ball.GetRect(), brickList[i][j]->GetRect(), ball.GetSpeed()));
						brickList[i][j]->SetHP(brickList[i][j]->GetHP()-1);

						switch (brickList[i][j]->GetHP())
						{
						case 0:
							//Destroy
							break;
						case 1:
							//Animacio
							break;
						case 2:
							//Animacio
							break;
						case 3:
							//Animacio
							break;

						default:
							break;
						}
					}



		ball.SetSpeed(MovingObject::Instance()->ballLimits(ball.GetPosition(), ball.GetSpeed()));
		ball.SetSpeed(MovingObject::Instance()->BallBounce(ball.GetRect(), playerLeft.GetRect(), ball.GetSpeed()));
		ball.SetSpeed(MovingObject::Instance()->BallBounce(ball.GetRect(), playerRight.GetRect(), ball.GetSpeed()));
		ball.SetPosition(ball.GetPosition().x + ball.GetSpeed().x, ball.GetPosition().y + ball.GetSpeed().y);

		playerLeft.SetPuntuation((playerLeft.GetPuntuation() + 1));
		playerLeft.SetText(playerLeft.GetPuntuation());
		Renderer::Instance()->LoadTextureText(playerLeft.GetText().font.id, playerLeft.GetText());
		
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
			{
				soundOnSwitch.text = "Sound Off";
				input.SetInput(Inputs::InputType::LeftClick, false);
			}
			else if (soundOnSwitch.text == "Sound Off" && input.GetInput(Inputs::LeftClick))
			{
				soundOnSwitch.text = "Sound On";
				input.SetInput(Inputs::InputType::LeftClick, false);
			}
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
	std::vector<Brick> brickList;
	int lenght = brick.GetVectorLenght();
	for (int i = 0; i < lenght; i++) brickList.push_back(brick.GetBrick(i));
	for (int i = 0; i < lenght; i++) brickList[i].SetID(i);
	for (int i = 0; i < lenght; i++) brickList[i].SetPosition(brickList[i].GetPosition('x')*BRICK_WIDTH + 300 , brickList[i].GetPosition('y')*BRICK_HEIGHT );
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerLeft.GetFlipedRect(), 90);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerRight.GetFlipedRect(), 90);
	Renderer::Instance()->PushImage("BALL", ball.GetRect());
	Renderer::Instance()->PushImage(playerLeft.GetText().font.id, playerLeft.GetText().rect);
	Renderer::Instance()->PushImage(playerRight.GetText().font.id, playerRight.GetText().rect);
	

	for (int i = 0; i < lenght; i++)
	{
		if (brickList[i].GetType() == 'N') Renderer::Instance()->PushRotatedSprite("BRICK", GREENBLOCK_FIRST, brickList[i].GetRect(), 90);
		if (brickList[i].GetType() == 'H') Renderer::Instance()->PushRotatedSprite("BRICK", REDBLOCK_FIRST, brickList[i].GetRect(), 90);
		if (brickList[i].GetType() == 'F') Renderer::Instance()->PushRotatedSprite("BRICK", FIXEDBLOCK_FIRST, brickList[i].GetRect(), 90);
	}
	
	if(playerLeft.GetHP() >= 3)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(3));
	if (playerLeft.GetHP() >= 2)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(2));
	if (playerLeft.GetHP() >= 1)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(1));
	
	if (playerRight.GetHP() >= 3)
		Renderer::Instance()->PushImage("PLAYER", playerRight.GetHPBar(3));
	if (playerRight.GetHP() >= 2)
		Renderer::Instance()->PushImage("PLAYER", playerRight.GetHPBar(2));
	if (playerRight.GetHP() >= 1)
		Renderer::Instance()->PushImage("PLAYER", playerRight.GetHPBar(1));

	if (sceneStatus == sceneState::PAUSED)
	{
		Renderer::Instance()->PushImage("PAUSE_BG", PauseBG);
		Renderer::Instance()->PushImage(pause.font.id, pause.rect);
		Renderer::Instance()->PushImage(soundOnSwitch.font.id, soundOnSwitch.rect);
	}
	
}
