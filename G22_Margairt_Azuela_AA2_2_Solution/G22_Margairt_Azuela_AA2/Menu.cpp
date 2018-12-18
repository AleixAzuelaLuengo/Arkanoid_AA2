#include "Menu.h"
#include "Renderer.h"
#include "Constants.h"
Menu::Menu()
{	
	BG = { 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT };
	startGame.text = "Play";
	startGame.font.size = 8;
	startGame.idColor = { 0 , 255 , 0 , 0 };
	startGame.font.path = MENU_FONT;
	startGame.font.id = "PLAY_FONT";
	startGame.rect = { (SCREEN_WIDTH / 2) - startGame.rect.proportions.x / 2, SCREEN_HEIGHT / 5, 100,50 };

	ranking.text = "Ranking";
	ranking.font.size = 8;
	ranking.font.path = MENU_FONT;
	ranking.font.id = "RANKING_FONT";
	ranking.idColor = { 0 , 255 , 0 , 0 };
	ranking.rect = { (SCREEN_WIDTH / 2) - ranking.rect.proportions.x / 2, SCREEN_HEIGHT / 3, 100,50 };

	soundSwitch.text = "Sound On";
	soundSwitch.font.size = 8;
	soundSwitch.font.path = MENU_FONT;
	soundSwitch.font.id = "SoundON_FONT";
	soundSwitch.idColor = { 0 , 255 , 0 , 0 };
	soundSwitch.rect = { (SCREEN_WIDTH / 2) - ranking.rect.proportions.x / 2, SCREEN_HEIGHT / 2, 100,50 };

	Renderer::Instance()->LoadTexture("BG_MENU", BACKGROUND_MENU);
	Renderer::Instance()->LoadFont(startGame.font);
	Renderer::Instance()->LoadTextureText(startGame.font.id, startGame);
	Renderer::Instance()->LoadFont(ranking.font);
	Renderer::Instance()->LoadTextureText(ranking.font.id, ranking);
	Renderer::Instance()->LoadFont(soundSwitch.font);
	Renderer::Instance()->LoadTextureText(soundSwitch.font.id, soundSwitch);
}


Menu::~Menu()
{
}

void Menu::Update()
{
	test = 10;
}

void Menu::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushImage(startGame.font.id, startGame.rect);
	Renderer::Instance()->PushImage(ranking.font.id, ranking.rect);
	Renderer::Instance()->PushImage(soundSwitch.font.id, soundSwitch.rect);
}
