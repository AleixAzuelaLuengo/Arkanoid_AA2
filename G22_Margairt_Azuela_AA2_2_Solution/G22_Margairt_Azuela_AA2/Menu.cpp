#include "Menu.h"
#include "Renderer.h"
#include "Constants.h"
Menu::Menu()
{	
	BG = { 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT };

	startGame.text = "Play";
	startGame.font.size = 8;
	startGame.idColor = ButtonNotSelected;
	startGame.font.path = MENU_FONT;
	startGame.font.id = "PLAY_FONT";
	startGame.rect = { 0, SCREEN_HEIGHT / 5, 100,50 };
	startGame.rect.position.x = (SCREEN_WIDTH / 2) - (startGame.rect.proportions.x / 2);

	ranking.text = "Ranking";
	ranking.font.size = 8;
	ranking.font.path = MENU_FONT;
	ranking.font.id = "RANKING_FONT";
	ranking.idColor = ButtonNotSelected;
	ranking.rect = { 0, SCREEN_HEIGHT / 3, 200,50 };
	ranking.rect.position.x = (SCREEN_WIDTH / 2) - (ranking.rect.proportions.x / 2);

	soundOnSwitch.text = "Sound On";
	soundOnSwitch.font.size = 8;
	soundOnSwitch.font.path = MENU_FONT;
	soundOnSwitch.font.id = "SoundON_FONT";
	soundOnSwitch.idColor = ButtonNotSelected;
	soundOnSwitch.rect = { 0, SCREEN_HEIGHT / 2, 200,50 };
	soundOnSwitch.rect.position.x = (SCREEN_WIDTH / 2) - (soundOnSwitch.rect.proportions.x / 2);

	Renderer::Instance()->LoadTexture("BG_MENU", BACKGROUND_MENU);
	Renderer::Instance()->LoadFont(startGame.font);
	Renderer::Instance()->LoadTextureText(startGame.font.id, startGame);
	Renderer::Instance()->LoadFont(ranking.font);
	Renderer::Instance()->LoadTextureText(ranking.font.id, ranking);
	Renderer::Instance()->LoadFont(soundOnSwitch.font);
	Renderer::Instance()->LoadTextureText(soundOnSwitch.font.id, soundOnSwitch);
}


Menu::~Menu()
{
	Renderer::Instance()->Clear();
}

void Menu::Update()
{
	/*
	startGame.idColor = ButtonSelected;
	ranking.idColor = ButtonSelected;
	soundOnSwitch.idColor = ButtonSelected;

	soundOnSwitch.text = "Sound Off";
	soundOnSwitch.text = "Sound On";
	*/
}

void Menu::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushImage(startGame.font.id, startGame.rect);
	Renderer::Instance()->PushImage(ranking.font.id, ranking.rect);
	Renderer::Instance()->PushImage(soundOnSwitch.font.id, soundOnSwitch.rect);
}
