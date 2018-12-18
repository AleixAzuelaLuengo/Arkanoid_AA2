#include "GameManager.h"




GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}



bool GameManager::GetInput(InputType i)
{
	return inputs.GetInput(i);
}

float GameManager::GetMouse(MousePosition i)
{
	return inputs.GetMousePos(i);
}

void GameManager::SetInput(bool i, InputType x)
{
	inputs.SetInput(x, i);
}

void GameManager::SetMouse(float, MousePosition)
{
	
}



void GameManager::update()
{
	while (!GetInput(InputType::Quit))
	{
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SetInput(true, InputType::Quit);
				break;
			case SDL_KEYUP:
			case SDL_KEYDOWN:
				SetInput(event.key.keysym.sym == SDLK_ESCAPE, InputType::Quit);

				SetInput(event.key.keysym.sym == SDLK_w, InputType::W);
				SetInput(event.key.keysym.sym == SDLK_s, InputType::S);
				SetInput(event.key.keysym.sym == SDLK_a, InputType::A);
				SetInput(event.key.keysym.sym == SDLK_d, InputType::D);

				SetInput(event.key.keysym.sym == SDLK_UP, InputType::UpArrow);
				SetInput(event.key.keysym.sym == SDLK_DOWN, InputType::DownArrow);
				SetInput(event.key.keysym.sym == SDLK_RIGHT, InputType::RightArrow);
				SetInput(event.key.keysym.sym == SDLK_LEFT, InputType::LeftArrow);

				SetInput(event.key.keysym.sym == SDLK_SPACE, InputType::SpaceBar);
				break;
			case SDL_MOUSEBUTTONDOWN:
				SetInput(event.button.button == SDL_BUTTON_LEFT, InputType::LeftClick);
				break;
			case SDL_MOUSEMOTION:
				SetMouse(event.motion.x, MousePosition::X);
				SetMouse(event.motion.y, MousePosition::Y);
				break;
			default:;
			}
		}

		/*switch (gameState)
		{
		case stateType::SplashScreen:
			currentScene = new SplashScreen;
			
			break;
		case stateType::Menu:
			currentScene = new Menu;
			 
			break;
		case stateType::Play:
			currentScene = new Play;
			break;
		case stateType::Ranking:
			currentScene = new Ranking;
			break;
		}*/
	}
}

void GameManager::Draw()
{
}
