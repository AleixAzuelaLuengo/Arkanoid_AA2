#include "GameManager.h"
#include <iostream>



GameManager::GameManager()
{
	currentScene = new Menu();
}


GameManager::~GameManager()
{

}

bool GameManager::endGame()
{
	return false;
}

bool GameManager::GetInput(Inputs::InputType i)
{
	return inputs.GetInput(i);
}

float GameManager::GetMouse(Inputs::MousePosition i)
{
	return inputs.GetMousePos(i);
}

void GameManager::SetInput(bool i, Inputs::InputType x)
{
	inputs.SetInput(x, i);
}

void GameManager::SetMouse(float i, Inputs::MousePosition mouse)
{
	inputs.SetMouse(mouse, i);
	inputs.SetMouse(mouse, i);
}



void GameManager::Update()
{
	//Inputs
	while (SDL_PollEvent(&event))
	{
			switch (event.type) {
			case SDL_QUIT:
				SetInput(true, Inputs::InputType::Quit);
				break;
			case SDL_KEYUP: 
				switch (event.key.keysym.sym)
				{
				case(SDLK_ESCAPE):
					SetInput(false, Inputs::InputType::Quit);
					break;
				case(SDLK_w):
					SetInput(false, Inputs::InputType::W);
					break;
				case(SDLK_s):
					SetInput(false, Inputs::InputType::S);
					break;
				case(SDLK_UP):
					SetInput(false, Inputs::InputType::UpArrow);
					break;
				case(SDLK_DOWN):
					SetInput(false, Inputs::InputType::DownArrow);
					break;
				case(SDLK_SPACE):
					SetInput(false, Inputs::InputType::SpaceBar);
					break;
				case(SDLK_p):
					SetInput(false, Inputs::InputType::P);
					break;
				default:
					break;
				}
					break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case(SDLK_ESCAPE):
					SetInput(true, Inputs::InputType::Quit);
					break;
				case(SDLK_w):
					SetInput(true, Inputs::InputType::W);
					break;
				case(SDLK_s):
					SetInput(true, Inputs::InputType::S);
					break;
				case(SDLK_UP):
					SetInput(true, Inputs::InputType::UpArrow);
					break;
				case(SDLK_DOWN):
					SetInput(true, Inputs::InputType::DownArrow);
					break;
				case(SDLK_SPACE):
					SetInput(true, Inputs::InputType::SpaceBar);
					break;
				case(SDLK_p):
					SetInput(true, Inputs::InputType::P);
					break;
				default:
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					SetInput(true, Inputs::InputType::LeftClick);
				default:
					break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					SetInput(false, Inputs::InputType::LeftClick);
				default:
					break;
				}
				break;
			case SDL_MOUSEMOTION:
				SetMouse(event.motion.x, Inputs::MousePosition::X);
				SetMouse(event.motion.y, Inputs::MousePosition::Y);
				break;
			default:
				break;
			}
	}		
	//Scene Manager
	if (currentScene->sceneStatus == currentScene->sceneState::EXIT)
	{
		switch (currentScene->gameState)
		{
		case Scene::stateType::SPLASHSCREEN:
			currentScene = new Splashscreen();
			break;
		case Scene::stateType::MENU:
			delete currentScene;
			currentScene = new Menu();
			break;
		case Scene::stateType::PLAY:
			delete currentScene;
			currentScene = new Play();
			break;
		case Scene::stateType::RANKING:
			delete currentScene;
			currentScene = new Ranking();
			break;
		default:
			delete currentScene;
			exit(0);
			break;
		}
			currentScene->sceneStatus = currentScene->sceneState::START_GAME;
	}
	//Update de la escena en la que nos encontramos
	currentScene->Update(inputs, currentScene->sceneStatus, currentScene->gameState);
}

void GameManager::Draw()
{
	//Draw de la escena en la que nos encontramos
	currentScene->Draw();
}
