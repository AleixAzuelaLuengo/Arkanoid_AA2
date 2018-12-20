#include "Menu.h"
#include "Renderer.h"
#include "MovingObject.h"
#include "Constants.h"
#include <iostream>
Menu::Menu()
{	
	BG = { 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT };

	startGame.text = "Play";
	startGame.font.size = 80;
	startGame.idColor = ButtonNotSelected;
	startGame.font.path = MENU_FONT;
	startGame.font.id = "PLAY_FONT";
	startGame.rect = { 0, SCREEN_HEIGHT / 6, 100,50 };
	startGame.rect.position.x = (SCREEN_WIDTH / 2) - (startGame.rect.proportions.x / 2);

	ranking.text = "Ranking";
	ranking.font.size = 80;
	ranking.font.path = MENU_FONT;
	ranking.font.id = "RANKING_FONT";
	ranking.idColor = ButtonNotSelected;
	ranking.rect = { 0, SCREEN_HEIGHT / 4, 200,50 };
	ranking.rect.position.x = (SCREEN_WIDTH / 2) - (ranking.rect.proportions.x / 2);

	soundOnSwitch.text = "Sound On";
	soundOnSwitch.font.size = 80;
	soundOnSwitch.font.path = MENU_FONT;
	soundOnSwitch.font.id = "SoundON_FONT";
	soundOnSwitch.idColor = ButtonNotSelected;
	soundOnSwitch.rect = { 0, SCREEN_HEIGHT / 3, 200,50 };
	soundOnSwitch.rect.position.x = (SCREEN_WIDTH / 2) - (soundOnSwitch.rect.proportions.x / 2);

	exit.text = "Exit";
	exit.font.size = 80;
	exit.font.path = MENU_FONT;
	exit.font.id = "Exit_FONT";
	exit.idColor = ButtonNotSelected;
	exit.rect = { 0, SCREEN_HEIGHT / 2, 100,50 };
	exit.rect.position.x = (SCREEN_WIDTH / 2) - (exit.rect.proportions.x / 2);

	Renderer::Instance()->LoadTexture("BG_MENU", BACKGROUND_MENU);
	Renderer::Instance()->LoadFont(startGame.font);
	Renderer::Instance()->LoadTextureText(startGame.font.id, startGame);
	Renderer::Instance()->LoadFont(ranking.font);
	Renderer::Instance()->LoadTextureText(ranking.font.id, ranking);
	Renderer::Instance()->LoadFont(soundOnSwitch.font);
	Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);
	Renderer::Instance()->LoadFont(exit.font);
	Renderer::Instance()->LoadTextureText(exit.font.id, exit);
}


Menu::~Menu()
{
	Renderer::Instance()->Clear();
}

void Menu::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState)
{
	if (input.GetInput(Inputs::InputType::Quit))
	{
		sceneStatus = sceneState::EXIT;
		gameState = stateType::END;
		input.SetInput(Inputs::InputType::Quit, false);
	}
	if (MovingObject::Instance()->MouseCollision(startGame.rect, input))
	{
		startGame.idColor = ButtonSelected;
		if (input.GetInput(Inputs::LeftClick))
		{
			sceneStatus = sceneState::EXIT;
			gameState = stateType::PLAY;
		}
	}
	else
	{
		startGame.idColor = ButtonNotSelected;
	}

	if (MovingObject::Instance()->MouseCollision(ranking.rect, input))
	{
		ranking.idColor = ButtonSelected;
		if (input.GetInput(Inputs::LeftClick))
		{
			sceneStatus = sceneState::EXIT;
			gameState = stateType::MENU;
		}
	}
	else
	{
		ranking.idColor = ButtonNotSelected;
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

	if (MovingObject::Instance()->MouseCollision(exit.rect, input))
	{
		exit.idColor = ButtonSelected;
		if (input.GetInput(Inputs::LeftClick))
		{
			sceneStatus = sceneState::EXIT;
			gameState = stateType::END;
		}
	}
	else
	{
		exit.idColor = ButtonNotSelected;
	}
	Renderer::Instance()->LoadTextureText(startGame.font.id, startGame);
	Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);
	Renderer::Instance()->LoadTextureText(ranking.font.id, ranking);
	Renderer::Instance()->LoadTextureText(exit.font.id, exit);
}

void Menu::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushImage(startGame.font.id, startGame.rect);
	Renderer::Instance()->PushImage(ranking.font.id, ranking.rect);
	Renderer::Instance()->PushImage(soundOnSwitch.font.id, soundOnSwitch.rect);
	Renderer::Instance()->PushImage(exit.font.id, exit.rect);
}
