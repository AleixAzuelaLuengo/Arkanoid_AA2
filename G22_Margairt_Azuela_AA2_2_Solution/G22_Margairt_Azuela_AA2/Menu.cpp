#include "Menu.h"
#include "Renderer.h"
#include "Constants.h"
Menu::Menu()
{
	BG.position.x = 0;
	BG.position.y = 0;
	BG.proportions.x = SCREEN_WIDTH;
	BG.proportions.y = SCREEN_HEIGHT;
	startGame.id = "PLAY_TEXT_TEXTURE";
	startGame.text = "Play";
	startGame.idColor.r = 255;
	startGame.idColor.g = 0;
	startGame.idColor.b = 0;
	startGame.font.path = MENU_FONT;
	startGame.font.id = "PLAY_FONT";
	Renderer::Instance()->LoadTexture("BG_MENU", BACKGROUND_MENU);
	Renderer::Instance()->LoadFont(startGame.font);
	Renderer::Instance()->LoadTextureText(startGame.id, startGame);
}


Menu::~Menu()
{
}

void Menu::Update()
{
}

void Menu::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", BG);
	
}
