#include "Play.h"
#include "Constants.h"
#include "Renderer.h"
#include "MovingObject.h"
#include <iostream>


Play::Play()
{
	Renderer::Instance()->Clear();
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

	playerLeft.SetPosition(26, SCREEN_HEIGHT / 2 - 45);
	playerLeft.SetPosHealth(SCREEN_WIDTH / 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 3);
	playerLeft.SetPosHealth(playerLeft.GetHPBar(3).position.x + playerLeft.GetHPBar(3).proportions.x + 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 2);
	playerLeft.SetPosHealth(playerLeft.GetHPBar(2).position.x + playerLeft.GetHPBar(2).proportions.x + 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 1);


	playerRight.SetPosition(SCREEN_WIDTH - 29 - playerRight.GetRect().proportions.x, SCREEN_HEIGHT / 2 - 45);
	playerRight.SetPosHealth(SCREEN_WIDTH - (SCREEN_WIDTH / 10) * 2 - 35, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 3);
	playerRight.SetPosHealth(playerRight.GetHPBar(3).position.x - playerRight.GetHPBar(3).proportions.x - 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 2);
	playerRight.SetPosHealth(playerRight.GetHPBar(2).position.x - playerRight.GetHPBar(2).proportions.x - 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 10, 1);

	playerLeft.SetTextPos(SCREEN_WIDTH / 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 6 + 5);
	playerRight.SetTextPos(SCREEN_WIDTH - (SCREEN_WIDTH / 10) * 4 - 15, SCREEN_HEIGHT - SCREEN_HEIGHT / 6 + 5);

	ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y + playerLeft.GetRect().proportions.y / 2 -ball.GetRect().proportions.y/2);
	lastPlayer = 0;
	spawnPlayer = 0;

	int lenght = brick.GetVectorLenght();
	for (int i = 0; i < lenght; i++) brickList.push_back(brick.GetBrick(i));
	for (int i = 0; i < lenght; i++) brickList[i].SetID(i);
	for (int i = 0; i < lenght; i++) brickList[i].SetPosition(brickList[i].GetPosition('x')*BRICK_WIDTH + SCREEN_WIDTH / 3, brickList[i].GetPosition('y')*BRICK_HEIGHT + brickList[i].GetRect().proportions.y);

	Renderer::Instance()->LoadTexture("BRICK", BRICK_SPRITESHEET);
	Renderer::Instance()->LoadTexture("BALL", BALL_SPRITE);
	Renderer::Instance()->LoadFont(pause.font);
	Renderer::Instance()->LoadTextureText(pause.font.id, pause);
	Renderer::Instance()->LoadFont(soundOnSwitch.font);
	Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);

	gameOver = false;
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
			input.SetInput(Inputs::InputType::Quit, false);
		}
		if (input.GetInput(Inputs::InputType::SpaceBar))
		{
			sceneStatus = sceneState::RUNNING;
			if (spawnPlayer == 0)
			{
				int y = rand() % 2;
				if (y == 0)
					ball.SetSpeed(Vector2{ 2, 2 });
				else
					ball.SetSpeed(Vector2{ 2, -2 });
			}
			if (spawnPlayer == 1)
			{
				int y = rand() % 2;
				if (y == 0)
					ball.SetSpeed(Vector2{ -2, 2 });
				else
					ball.SetSpeed(Vector2{ -2, -2 });
			}
		}
		if (input.GetInput(input.W))
		{
			playerLeft.MoveUp();
			if(spawnPlayer ==0)
				ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y + playerLeft.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
		}
		else if (input.GetInput(input.S))
		{
			playerLeft.MoveDown();
			if (spawnPlayer == 0)
				ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y + playerLeft.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
		}
		if (input.GetInput(input.UpArrow))
		{
			playerRight.MoveUp();
			if(spawnPlayer ==1)
				ball.SetPosition(playerRight.GetRect().position.x - playerRight.GetRect().proportions.x * 2, playerRight.GetRect().position.y + playerRight.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
		}
		else if (input.GetInput(input.DownArrow))
		{
			playerRight.MoveDown();
			if (spawnPlayer == 1)
				ball.SetPosition(playerRight.GetRect().position.x - playerRight.GetRect().proportions.x * 2, playerRight.GetRect().position.y + playerRight.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
		}
	}
	else if (sceneStatus == sceneState::RUNNING && !gameOver)
	{
		if (input.GetInput(Inputs::InputType::Quit))
		{
			sceneStatus = sceneState::EXIT;
			gameState = stateType::MENU;
			input.SetInput(Inputs::InputType::Quit, false);
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
		Vector2 aux = MovingObject::Instance()->playerLimits(playerLeft.GetPosition());
		playerLeft.SetPosition(aux.x, aux.y);
		

		aux = MovingObject::Instance()->playerLimits(playerRight.GetPosition());
		playerRight.SetPosition(aux.x, aux.y);
		int collision;
		for (int i = 0; i < brickList.size(); i++)
		{
			if (brickList[i].GetHP() > 0 || brickList[i].GetHP() < 0)
			{
				collision = MovingObject::Instance()->BallBounce(ball.GetRect(), brickList[i].GetRect(), ball.GetSpeed());
				if (collision != 0)
				{
					Vector2 vel = ball.GetSpeed();
					if (collision == 1)
					{
						vel.x = -2;
						ball.SetSpeed(vel);
					}
					else if (collision == 2)
					{
						vel.x = 2;
						ball.SetSpeed(vel);
					}
					else if (collision == 3)
					{
						vel.y = -2;
						ball.SetSpeed(vel);
					}
					else if (collision == 4)
					{
						vel.y = +2;
						ball.SetSpeed(vel);
					}

					brickList[i].SetHP(brickList[i].GetHP() - 1);

				}
			}
		}

		collision = MovingObject::Instance()->BallBounce(ball.GetRect(), playerLeft.GetRect(), ball.GetSpeed());
		if (collision != 0)
		{
			Vector2 vel = ball.GetSpeed();
			if (collision == 1)
			{
				vel.x = -2;
				ball.SetSpeed(vel);
			}
			else if (collision == 2)
			{
				vel.x = 2;
				ball.SetSpeed(vel);
			}
			else if (collision == 3)
			{
				vel.y = -2;
				ball.SetSpeed(vel);
			}
			else if (collision == 4)
			{
				vel.y = +2;
				ball.SetSpeed(vel);
			}
			lastPlayer = 0;
		}
		collision = MovingObject::Instance()->BallBounce(ball.GetRect(), playerRight.GetRect(), ball.GetSpeed());
		if (collision != 0)
		{
			Vector2 vel = ball.GetSpeed();
			if (collision == 1)
			{
				vel.x = -2;
				ball.SetSpeed(vel);
			}
			else if (collision == 2)
			{
				vel.x = 2;
				ball.SetSpeed(vel);
			}
			else if (collision == 3)
			{
				vel.y = -2;
				ball.SetSpeed(vel);
			}
			else if (collision == 4)
			{
				vel.y = 2;
				ball.SetSpeed(vel);
			}
			lastPlayer = 1;
		}


		ball.SetSpeed(MovingObject::Instance()->ballLimits(ball.GetPosition(), ball.GetSpeed()));
		if (ball.GetSpeed().x == 0)
		{
			ball.SetSpeed(Vector2{ 0,0 });
			ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y + playerLeft.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
			sceneStatus = sceneState::START_GAME;
			spawnPlayer = 0;
			playerLeft.SetHp(playerLeft.GetHP()-1);
			
		}
		else if (ball.GetSpeed().x == 1)
		{
			ball.SetSpeed(Vector2{ 0,0 });
			ball.SetPosition(playerRight.GetRect().position.x - playerRight.GetRect().proportions.x * 2, playerRight.GetRect().position.y + playerRight.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
			sceneStatus = sceneState::START_GAME;
			spawnPlayer = 1;
			playerRight.SetHp(playerRight.GetHP() - 1);
		}
		ball.SetPosition(ball.GetPosition().x + ball.GetSpeed().x, ball.GetPosition().y + ball.GetSpeed().y);
		if (ball.GetPosition().y == 239 || ball.GetPosition().y == 241)
		{
			std::cout << ball.GetPosition().y << std::endl;
		}
		playerLeft.SetPuntuation((playerLeft.GetPuntuation()));
		playerLeft.SetText(playerLeft.GetPuntuation());
		Renderer::Instance()->LoadTextureText(playerLeft.GetText().font.id, playerLeft.GetText());

		if (playerLeft.GetHP() <= 0 || playerRight.GetHP() <= 0)
		{
			gameOver = true;
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
	else if (gameOver)
	{
		if (playerLeft.GetHP() <= 0)
		{
			std::cout << "Player2 wins! Put your name: ";
			std::string nom;
			std::cin >> nom;
		}
		else
		{
				std::cout << "Player1 wins! Put your name: ";
				std::string nom;
				std::cin >> nom;
		}
	}

	if (playerLeft.GetHP() == 0 || playerRight.GetHP() == 0)
	{
		char* name = nullptr;
		std::cout << "Instert a Username" << std::endl;
		std::cin >> name;
		newPlayer.first = name;
		if (playerLeft.GetHP() == 0) newPlayer.second = playerRight.GetPuntuation();
		if(playerRight.GetHP() == 0) newPlayer.second =  playerLeft.GetPuntuation();

	}
}

void Play::Draw()
{

	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerLeft.GetFlipedRect(), 90);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerRight.GetFlipedRect(), 90);
	Renderer::Instance()->PushImage("BALL", ball.GetRect());
	Renderer::Instance()->PushImage(playerLeft.GetText().font.id, playerLeft.GetText().rect);
	Renderer::Instance()->PushImage(playerRight.GetText().font.id, playerRight.GetText().rect);


	for (int i = 0; i < brickList.size(); i++)
	{
		if (brickList[i].GetType() == 'N' && brickList[i].GetHP() == 1)
		{
			Renderer::Instance()->PushRotatedSprite("BRICK", GREENBLOCK_FIRST, brickList[i].GetFlipedRect(), 90);
			long sec = 0;
			sec += DELAY_TIME;
			if (sec <= 300 && sec >= 250 && brickList[i].GetHP() == 0)
			{
				Renderer::Instance()->PushRotatedSprite("BRICK", GREENBLOCK_SECOND, brickList[i].GetFlipedRect(), 90);
			}
			else if (sec <= 600 && sec >= 500 && brickList[i].GetHP() == 0)
			{
				Renderer::Instance()->PushRotatedSprite("BRICK", GREENBLOCK_THIRD, brickList[i].GetFlipedRect(), 90);
				brickList[i].SetHP(-1);
			}
		}
		if (brickList[i].GetType() == 'H')
		{
			if (brickList[i].GetHP() == 3) Renderer::Instance()->PushRotatedSprite("BRICK", REDBLOCK_FIRST, brickList[i].GetFlipedRect(), 90);
			else if (brickList[i].GetHP() == 2) Renderer::Instance()->PushRotatedSprite("BRICK", REDBLOCK_SECOND, brickList[i].GetFlipedRect(), 90);
			else if (brickList[i].GetHP() == 1) Renderer::Instance()->PushRotatedSprite("BRICK", REDBLOCK_THIRD, brickList[i].GetFlipedRect(), 90);
		}
		if (brickList[i].GetType() == 'F')
		{
			if (brickList[i].GetHP() % 2 != 0) Renderer::Instance()->PushRotatedSprite("BRICK", FIXEDBLOCK_FIRST, brickList[i].GetFlipedRect(), 90);
			else if (brickList[i].GetHP() % 2 == 0) Renderer::Instance()->PushRotatedSprite("BRICK", FIXEDBLOCK_SECOND, brickList[i].GetFlipedRect(), 90);
		}
	}

	if (playerLeft.GetHP() >= 3)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(3));
	else if (playerLeft.GetHP() >= 2)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(2));
	else if (playerLeft.GetHP() >= 1)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(1));

	if (playerRight.GetHP() >= 3)
		Renderer::Instance()->PushImage("PLAYER", playerRight.GetHPBar(3));
	else if (playerRight.GetHP() >= 2)
		Renderer::Instance()->PushImage("PLAYER", playerRight.GetHPBar(2));
	else if (playerRight.GetHP() >= 1)
		Renderer::Instance()->PushImage("PLAYER", playerRight.GetHPBar(1));

	if (sceneStatus == sceneState::PAUSED)
	{
		Renderer::Instance()->PushImage("PAUSE_BG", PauseBG);
		Renderer::Instance()->PushImage(pause.font.id, pause.rect);
		Renderer::Instance()->PushImage(soundOnSwitch.font.id, soundOnSwitch.rect);
	}

}

void Play::ReadFile()
{
	std::vector<std::pair<char *, int>> temp;
	std::ifstream myFileIn("../../res/files/ranking.bin", std::ios::in | std::ios::binary);

	for (int i = 0; i < 10; i++)
	{
		std::pair<char *, int> temp2;
		char a[4];
		myFileIn.read(reinterpret_cast<char*> (&a), sizeof(char) * 4);
		myFileIn.read(reinterpret_cast<char*> (&temp2.second), sizeof(int));
		temp2.first = a;
		temp.push_back(temp2);
	}
	myFileIn.close();
	temp.push_back(newPlayer);
	Sort(temp);
	temp.pop_back();

	std::ofstream myFile("../../res/files/ranking.bin", std::ios::out | std::ios::binary);
	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << temp[i].first << " : " << temp[i].second << std::endl;
		char *a = temp[i].first;
		int b = temp[i].second;
		myFile.write(reinterpret_cast<char*> (a), sizeof(char) * 4);
		myFile.write(reinterpret_cast<const char*> (&b), sizeof(int));
	}
	myFile.close();

	/*char x[4] = "VRL";
	char *a = x;
	int b = 200;

	std::ofstream myFile("../../res/files/ranking.bin", std::ios::out | std::ios::binary);
	for (int i = 0; i < 10; i++)
	{
		myFile.write(reinterpret_cast<char*> (a), sizeof(char) * 4);
		myFile.write(reinterpret_cast<char*> (&b), sizeof(b));
	}
	myFile.close(); */

}

void Play::Sort(std::vector<std::pair<char*, int>> &a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size() - i - 1; j++)
			if (a[j + 1].second > a[j].second)
			{
				std::pair<char*, int> temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}
