#include "Play.h"
#include "Constants.h"
#include "Renderer.h"
#include "MovingObject.h"
#include <iostream>
#include "PowerUp.h"
#include <time.h>

Play::Play()
{
	Renderer::Instance()->Clear();
	PauseBG = { 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT };
	playerLeft.SetSpeed(brick.GetPlayerSpeed());
	playerRight.SetSpeed(brick.GetPlayerSpeed());

	playerLeft.SetId("1");
	playerRight.SetId("2");

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

	ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y + playerLeft.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
	lastPlayer = 0;
	spawnPlayer = 0;

	int lenght = brick.GetVectorLenght();
	for (int i = 0; i < lenght; i++) brickList.push_back(brick.GetBrick(i));
	for (int i = 0; i < lenght; i++) brickList[i].SetID(i);
	for (int i = 0; i < lenght; i++) brickList[i].SetPosition(brickList[i].GetPosition('x')*BRICK_WIDTH + SCREEN_WIDTH / 3, brickList[i].GetPosition('y')*BRICK_HEIGHT + brickList[i].GetRect().proportions.y);

	for (int i = 0; i < 3; i++)
	{
		name[i].text = 'A';
		name[i].font.path = MENU_FONT;
		name[i].font.size = 90;
		name[i].idColor = White;
		name[i].rect.proportions = { 63, 100 };
	}

	name[0].font.id = "FIRST_LETTER_FONT";
	name[1].font.id = "SECOND_LETTER_FONT";
	name[2].font.id = "THIRD_LETTER_FONT";
	name[0].rect.position = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2 };
	name[1].rect.position = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };
	name[2].rect.position = { SCREEN_WIDTH / 2 + 200 , SCREEN_HEIGHT / 2 };

	winningPlayer.font.id = "WINNINGPLAYER";
	winningPlayer.font.size = 90;
	winningPlayer.font.path = MENU_FONT;
	winningPlayer.text = " WON PLEASE ENTER A USERNAME";
	winningPlayer.idColor = White;
	winningPlayer.rect.position = { 50, 150 };
	winningPlayer.rect.proportions = { 700 , 50 };

	startGame[0].font.id = "START_GAME";
	startGame[0].font.size = 90;
	startGame[0].font.path = MENU_FONT;
	startGame[0].text = " START GAME ";
	startGame[0].idColor = White;
	startGame[0].rect.position = { SCREEN_WIDTH/4 - 50, 100 };
	startGame[0].rect.proportions = { 500 , 100 };

	startGame[1].font.id = "SPACE_BAR";
	startGame[1].font.size = 90;
	startGame[1].font.path = MENU_FONT;
	startGame[1].text = " SPACE BAR TO START ";
	startGame[1].idColor = White;
	startGame[1].rect.position = { 300, 200 };
	startGame[1].rect.proportions = { 250 , 50 };

	for (int i = 0; i < 3; i++) {
		Renderer::Instance()->LoadFont(name[i].font);
		Renderer::Instance()->LoadTextureText(name[i].font.id, name[i]);
	}
	for (int i = 0; i < 2; i++) {
		Renderer::Instance()->LoadFont(startGame[i].font);
		Renderer::Instance()->LoadTextureText(startGame[i].font.id, startGame[i]);
	}

	Renderer::Instance()->LoadTexture("BRICK", BRICK_SPRITESHEET);
	Renderer::Instance()->LoadTexture("BALL", BALL_SPRITE);
	Renderer::Instance()->LoadTexture("POWERUP", POWER_UP_SPRITE);
	Renderer::Instance()->LoadFont(winningPlayer.font);
	Renderer::Instance()->LoadTextureText(winningPlayer.font.id, winningPlayer);
	Renderer::Instance()->LoadFont(pause.font);
	Renderer::Instance()->LoadTextureText(pause.font.id, pause);
	Renderer::Instance()->LoadFont(soundOnSwitch.font);
	Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);
	Renderer::Instance()->LoadFont(playerLeft.GetFont());
	Renderer::Instance()->LoadFont(playerRight.GetFont());
	Renderer::Instance()->LoadTextureText(playerRight.GetText().font.id, playerRight.GetText());
	Renderer::Instance()->LoadTextureText(playerLeft.GetText().font.id, playerLeft.GetText());
	gameOver = false;
}


Play::~Play()
{
}

void Play::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState, Music &music)
{
	if (!gameOver)
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
				if (spawnPlayer == 0)
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
				if (spawnPlayer == 1)
					ball.SetPosition(playerRight.GetRect().position.x - playerRight.GetRect().proportions.x * 2, playerRight.GetRect().position.y + playerRight.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
			}
			else if (input.GetInput(input.DownArrow))
			{
				playerRight.MoveDown();
				if (spawnPlayer == 1)
					ball.SetPosition(playerRight.GetRect().position.x - playerRight.GetRect().proportions.x * 2, playerRight.GetRect().position.y + playerRight.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
			}

			Vector2 aux = object.playerLimits(playerLeft.GetPosition(), playerLeft.GetSpeed());
			playerLeft.SetPosition(aux.x, aux.y);
			aux = object.playerLimits(playerRight.GetPosition(), playerRight.GetSpeed());
			playerRight.SetPosition(aux.x, aux.y);
		}
		else if (sceneStatus == sceneState::RUNNING && !gameOver)
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
			Vector2 aux = object.playerLimits(playerLeft.GetPosition(), playerLeft.GetSpeed());
			playerLeft.SetPosition(aux.x, aux.y);


			aux = object.playerLimits(playerRight.GetPosition(), playerRight.GetSpeed());
			playerRight.SetPosition(aux.x, aux.y);
			int collision;
			for (int i = 0; i < brickList.size(); i++)
			{
				if (brickList[i].GetHP() > 0 || brickList[i].GetHP() < 0)
				{
					collision = object.BallBounce(ball.GetRect(), brickList[i].GetRect(), ball.GetSpeed());
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
						if (brickList[i].GetHP() == 0)
						{
							int num = rand() % 100;
							if (num <= 19)
							{
								PowerUp* powerUp = new PowerUp();
								if (lastPlayer == 0)
									powerUp->SetSpeed(-1);
								else powerUp->SetSpeed(1);

								powerUp->SetPosition(brickList[i].GetRect().position.x, brickList[i].GetRect().position.y + brickList[i].GetRect().proportions.y / 2);
								int type = rand() % 3;
								switch (type)
								{
								case 0:
									powerUp->SetPowerUpType(powerUpType::EXTRA_LENGTH);
									break;
								case 1:
									powerUp->SetPowerUpType(powerUpType::MINI_LENGTH);
									break;
								case 2:
									powerUp->SetPowerUpType(powerUpType::SPEED);
									break;

								}
								powerUpList.push_back(powerUp);

							}
							if (lastPlayer == 0)
							{
								playerLeft.SetPuntuation(playerLeft.GetPuntuation() + brickList[i].GetPuntuation());
								Renderer::Instance()->LoadTextureText(playerLeft.GetText().font.id, playerLeft.GetText());
							}
							else if(lastPlayer == 1)
							{
								playerRight.SetPuntuation(playerRight.GetPuntuation() + brickList[i].GetPuntuation());
								Renderer::Instance()->LoadTextureText(playerRight.GetText().font.id, playerRight.GetText());
							}
						}
					}
				}
			}

			collision = object.BallBounce(ball.GetRect(), playerLeft.GetRect(), ball.GetSpeed());
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
			collision = object.BallBounce(ball.GetRect(), playerRight.GetRect(), ball.GetSpeed());
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


			ball.SetSpeed(object.ballLimits(ball.GetPosition(), ball.GetSpeed()));
			if (ball.GetSpeed().x == 0)
			{
				ball.SetSpeed(Vector2{ 0,0 });
				ball.SetPosition(playerLeft.GetRect().position.x + playerLeft.GetRect().proportions.x * 2, playerLeft.GetRect().position.y + playerLeft.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
				sceneStatus = sceneState::START_GAME;
				spawnPlayer = 0;
				playerLeft.SetHp(playerLeft.GetHP() - 1);
				if (playerLeft.GetPuntuation() > 50) playerLeft.SetPuntuation(playerLeft.GetPuntuation() - 50);
				else playerLeft.SetPuntuation(0);

				playerRight.SetPuntuation(playerRight.GetPuntuation() + 100);
				Renderer::Instance()->LoadTextureText(playerLeft.GetText().font.id, playerLeft.GetText());
				Renderer::Instance()->LoadTextureText(playerRight.GetText().font.id, playerRight.GetText());
			}
			else if (ball.GetSpeed().x == 1)
			{
				ball.SetSpeed(Vector2{ 0,0 });
				ball.SetPosition(playerRight.GetRect().position.x - playerRight.GetRect().proportions.x * 2, playerRight.GetRect().position.y + playerRight.GetRect().proportions.y / 2 - ball.GetRect().proportions.y / 2);
				sceneStatus = sceneState::START_GAME;
				spawnPlayer = 1;
				playerRight.SetHp(playerRight.GetHP() - 1);

				if (playerRight.GetPuntuation() > 50) playerRight.SetPuntuation(playerRight.GetPuntuation() - 50);
				else playerRight.SetPuntuation(0);

				playerLeft.SetPuntuation(playerLeft.GetPuntuation() + 100);
				Renderer::Instance()->LoadTextureText(playerRight.GetText().font.id, playerRight.GetText());
				Renderer::Instance()->LoadTextureText(playerLeft.GetText().font.id, playerLeft.GetText());
			}
			ball.SetPosition(ball.GetPosition().x + ball.GetSpeed().x, ball.GetPosition().y + ball.GetSpeed().y);


			for (int i = 0; i < powerUpList.size(); i++)
			{
				if (object.Collision(playerLeft.GetRect(), powerUpList[i]->GetRect()))
				{
					playerLeft.SetProportions(PLAYER_WIDTH, PLAYER_HEIGHT);
					playerLeft.SetSpeed(3);
					switch (powerUpList[i]->GetType())
					{
					case 0:
						playerLeft.SetProportions(playerLeft.GetRect().proportions.x, (int)(playerLeft.GetRect().proportions.y + (playerLeft.GetRect().proportions.y * 0.25f)));
						break;
					case 1:
						playerLeft.SetProportions(playerLeft.GetRect().proportions.x, (int)(playerLeft.GetRect().proportions.y - (playerLeft.GetRect().proportions.y * 0.25f)));
						break;
					case 2:
						playerLeft.SetSpeed((int)(round(playerLeft.GetSpeed() + (playerLeft.GetSpeed() * 0.2f))));
						break;
					default:
						break;
					}
					powerUpSec[0] = std::chrono::system_clock::now();
					powerUpList.erase(powerUpList.begin() + i);
				}
				else if (object.Collision(playerRight.GetRect(), powerUpList[i]->GetRect()))
				{
					playerRight.SetProportions(PLAYER_WIDTH, PLAYER_HEIGHT);
					playerRight.SetSpeed(3);
					switch (powerUpList[i]->GetType())
					{
					case 0:
						playerRight.SetProportions(playerRight.GetRect().proportions.x, (int)(playerRight.GetRect().proportions.y + (playerRight.GetRect().proportions.y * 0.25f)));
						break;
					case 1:
						playerRight.SetProportions(playerRight.GetRect().proportions.x, (int)(playerRight.GetRect().proportions.y - (playerRight.GetRect().proportions.y * 0.25f)));
						break;
					case 2:
						playerRight.SetSpeed((int)(round(playerRight.GetSpeed() + (playerRight.GetSpeed() * 0.2f))));
						break;
					default:
						break;
					}
					powerUpSec[1] = std::chrono::system_clock::now();
					powerUpList.erase(powerUpList.begin() + i);
				}
				else if (powerUpList[i]->GetPosition().x <= MAP_START_X_AND_Y || powerUpList[i]->GetPosition().x >= MAP_END_X)
				{
					powerUpList.erase(powerUpList.begin() + i);
				}
			}

			std::chrono::duration<double> elapsed = std::chrono::system_clock::now() - powerUpSec[0];

			if (elapsed.count() >= 10)
			{
				playerLeft.SetProportions(PLAYER_WIDTH, PLAYER_HEIGHT);
				playerLeft.SetSpeed(3);
			}

			elapsed = std::chrono::system_clock::now() - powerUpSec[1];
			if (elapsed.count() >= 10)
			{
				playerRight.SetProportions(PLAYER_WIDTH, PLAYER_HEIGHT);
				playerRight.SetSpeed(3);
			}



			for (int i = 0; i < powerUpList.size(); i++)
			{
				powerUpList[i]->SetPosition(powerUpList[i]->GetPosition().x + powerUpList[i]->GetSpeed(), powerUpList[i]->GetPosition().y);
			}

			if (playerLeft.GetHP() <= 0 || playerRight.GetHP() <= 0)
			{
				gameOver = true;
				if (playerLeft.GetHP() == 0)
				{
					winningPlayer.text = "Player 2 " + winningPlayer.text;
					Renderer::Instance()->LoadTextureText(winningPlayer.font.id, winningPlayer);
				}
				else
				{
					winningPlayer.text = "Player 1 " + winningPlayer.text;
					Renderer::Instance()->LoadTextureText(winningPlayer.font.id, winningPlayer);
				}
			}
		}
		else if (sceneStatus == sceneState::PAUSED)
		{
			if (input.GetInput(Inputs::InputType::Quit))
			{
				sceneStatus = sceneState::EXIT;
				gameState = stateType::MENU;
				input.SetInput(Inputs::InputType::Quit, false);
			}
			if (input.GetInput(input.SpaceBar))
			{
				sceneStatus = sceneState::RUNNING;
			}
			if (object.MouseCollision(soundOnSwitch.rect, input))
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
	else if (gameOver)
	{
		if (input.GetInput(input.UpArrow))
		{
			if (i < 25)
				i++;
			else
				i = 0;
			name[j].text = abecedario[i];
			input.SetInput(input.UpArrow, false);
		}
		else if (input.GetInput(input.DownArrow))
		{
			if (i > 0)
				i--;

			else
				i = 25;
			name[j].text = abecedario[i];
			input.SetInput(input.DownArrow, false);
		}
		if (input.GetInput(input.Enter))
		{
			nameChar[j] = abecedario[i];
			j++;
			input.SetInput(input.Enter, false);
		}

		if (j == 0)
		{
			name[0].idColor = ButtonSelected;
			name[1].idColor = White;
			name[2].idColor = White;
		}
		if (j == 1)
		{
			name[1].idColor = ButtonSelected;
			name[0].idColor = White;
			name[2].idColor = White;
		}
		if (j == 2)
		{
			name[2].idColor = ButtonSelected;
			name[1].idColor = White;
			name[0].idColor = White;
		}

		if (j == 3)
		{
			newPlayer.first = nameChar;
			if (playerLeft.GetHP() == 0) newPlayer.second = playerRight.GetPuntuation();
			if (playerRight.GetHP() == 0) newPlayer.second = playerLeft.GetPuntuation();
			ReadFile();
			sceneStatus = sceneState::EXIT;
			gameState = stateType::RANKING;
		}
		Renderer::Instance()->LoadTextureText(name[0].font.id, name[0]);
		Renderer::Instance()->LoadTextureText(name[1].font.id, name[1]);
		Renderer::Instance()->LoadTextureText(name[2].font.id, name[2]);
	}
}

void Play::Draw()
{
	if (playerLeft.GetPuntuation() > 0)
	{
		int x = 0;
	}

	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerLeft.GetFlipedRect(), 90);
	Renderer::Instance()->PushRotatedImage("PLAYER", playerRight.GetFlipedRect(), 90);
	Renderer::Instance()->PushImage("BALL", ball.GetRect());
	Renderer::Instance()->PushImage(playerLeft.GetText().font.id, playerLeft.GetText().rect);
	Renderer::Instance()->PushImage(playerRight.GetText().font.id, playerRight.GetText().rect);

	for (int i = 0; i < brickList.size(); i++)
	{
		brickList[i].Animate();
		Renderer::Instance()->PushRotatedSprite("BRICK", brickList[i].GetSpriteRect(), brickList[i].GetFlipedRect(), 90);
	}

	for (int i = 0; i < powerUpList.size(); i++)
	{
		if (powerUpList[i]->GetType() == powerUpType::EXTRA_LENGTH)
		{
			Renderer::Instance()->PushSprite("POWERUP", POWER_UP_EXTRA, powerUpList[i]->GetRect());
		}
		else if (powerUpList[i]->GetType() == powerUpType::MINI_LENGTH)
		{
			Renderer::Instance()->PushSprite("POWERUP", POWER_UP_MINI, powerUpList[i]->GetRect());
		}
		else if (powerUpList[i]->GetType() == powerUpType::SPEED)
		{
			Renderer::Instance()->PushSprite("POWERUP", POWER_UP_SPEED, powerUpList[i]->GetRect());
		}

	}

	if (playerLeft.GetHP() >= 3)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(3));
	if (playerLeft.GetHP() >= 2)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(2));
	if (playerLeft.GetHP() >= 1)
		Renderer::Instance()->PushImage("PLAYER", playerLeft.GetHPBar(1));

	if (playerRight.GetHP() == 3)
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
	if (sceneStatus == sceneState::START_GAME)
	{
		for (int i = 0; i < 2; i++) {
			Renderer::Instance()->PushImage(startGame[i].font.id, startGame[i].rect);
		}
	}
	if (gameOver)
	{
		Renderer::Instance()->PushImage("BG_MENU", BG);
		for (int i = 0; i < 3; i++) Renderer::Instance()->PushImage(name[i].font.id, name[i].rect);
		Renderer::Instance()->PushImage(winningPlayer.font.id, winningPlayer.rect);
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
		char *a = temp[i].first;
		int b = temp[i].second;
		myFile.write(reinterpret_cast<char*> (a), sizeof(char) * 4);
		myFile.write(reinterpret_cast<const char*> (&b), sizeof(int));
	}
	myFile.close();
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