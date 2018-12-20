#include "GameManager.h"
#include <iostream>



GameManager::GameManager()
{
	currentScene = new Menu();
}


GameManager::~GameManager()
{

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

	while (SDL_PollEvent(&event))
	{
			switch (event.type) {
			case SDL_QUIT:
				SetInput(true, Inputs::InputType::Quit);
				break;
			case SDL_KEYUP: 
				if (event.key.keysym.sym == SDLK_ESCAPE) 
					SetInput(false, Inputs::InputType::Quit);
				if (event.key.keysym.sym == SDLK_w) 
					SetInput(false, Inputs::InputType::W);
				if (event.key.keysym.sym == SDLK_s)
					SetInput(false, Inputs::InputType::S);
				if (event.key.keysym.sym == SDLK_UP)
					SetInput(false, Inputs::InputType::UpArrow);
				if (event.key.keysym.sym == SDLK_DOWN)
					SetInput(false, Inputs::InputType::DownArrow);
				if (event.key.keysym.sym == SDLK_SPACE)
					SetInput(false, Inputs::InputType::SpaceBar);
				if (event.key.keysym.sym == SDLK_p)
					SetInput(false, Inputs::InputType::P);
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					SetInput(true, Inputs::InputType::Quit);
				if (event.key.keysym.sym == SDLK_w)
					SetInput(true, Inputs::InputType::W);
				if (event.key.keysym.sym == SDLK_s)
					SetInput(true, Inputs::InputType::S);
				if (event.key.keysym.sym == SDLK_UP)
					SetInput(true, Inputs::InputType::UpArrow);
				if (event.key.keysym.sym == SDLK_DOWN)
					SetInput(true, Inputs::InputType::DownArrow);
				if (event.key.keysym.sym == SDLK_SPACE)
					SetInput(true, Inputs::InputType::SpaceBar);
				if (event.key.keysym.sym == SDLK_p)
					SetInput(true, Inputs::InputType::P);
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
				currentScene->sceneStatus = currentScene->sceneState::RUNNING;
			}
			
	}		
	currentScene->Update(inputs, currentScene->sceneStatus, currentScene->gameState);
}

void GameManager::Draw()
{
	currentScene->Draw();
}
