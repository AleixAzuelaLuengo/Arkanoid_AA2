#include "GameManager.h"




GameManager::GameManager()
{
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

void GameManager::SetMouse(float, Inputs::MousePosition)
{
	
}



void GameManager::Update()
{
	while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SetInput(true, Inputs::InputType::Quit);
				break;
			case SDL_KEYUP:
			case SDL_KEYDOWN:
				SetInput(event.key.keysym.sym == SDLK_ESCAPE, Inputs::InputType::Quit);

				SetInput(event.key.keysym.sym == SDLK_w, Inputs::InputType::W);
				SetInput(event.key.keysym.sym == SDLK_s, Inputs::InputType::S);
				SetInput(event.key.keysym.sym == SDLK_a, Inputs::InputType::A);
				SetInput(event.key.keysym.sym == SDLK_d, Inputs::InputType::D);

				SetInput(event.key.keysym.sym == SDLK_UP, Inputs::InputType::UpArrow);
				SetInput(event.key.keysym.sym == SDLK_DOWN, Inputs::InputType::DownArrow);
				SetInput(event.key.keysym.sym == SDLK_RIGHT, Inputs::InputType::RightArrow);
				SetInput(event.key.keysym.sym == SDLK_LEFT, Inputs::InputType::LeftArrow);

				SetInput(event.key.keysym.sym == SDLK_SPACE, Inputs::InputType::SpaceBar);
				break;
			case SDL_MOUSEBUTTONDOWN:
				SetInput(event.button.button == SDL_BUTTON_LEFT, Inputs::InputType::LeftClick);
				break;
			case SDL_MOUSEMOTION:
				SetMouse(event.motion.x, Inputs::MousePosition::X);
				SetMouse(event.motion.y, Inputs::MousePosition::Y);
				break;
			default:;
			}

			switch (gameState)
			{
			case stateType::SPLASHSCREEN:
				currentScene = new Splashscreen();
				break;
			case stateType::MENU:
				delete currentScene;
				currentScene = new Menu();
				break;
			case stateType::PLAY:
				delete currentScene;
				currentScene = new Play();
				break;
			case stateType::RANKING:
				delete currentScene;
				currentScene = new Ranking();
				break;
			}
			currentScene->Update(inputs);
	}		
}

void GameManager::Draw()
{
	currentScene->Draw();
}
