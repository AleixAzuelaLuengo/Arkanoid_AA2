#include "Splashscreen.h"

Splashscreen::Splashscreen()
{
	PauseBG = { 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT };
	BG = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	ArkanoidText.text = "ARKANOID ";
	ArkanoidText.font.size = 100;
	ArkanoidText.idColor = Black;
	ArkanoidText.font.path = MENU_FONT;
	ArkanoidText.font.id = "ARKANOID_FONT";
	ArkanoidText.rect = { 0, 0, 500,100 };
	ArkanoidText.rect.position.x = SCREEN_WIDTH - ArkanoidText.rect.proportions.x - 125;

	Renderer::Instance()->LoadTexture("PAUSE_BG", PAUSE_BG);
	Renderer::Instance()->LoadFont(ArkanoidText.font);
	Renderer::Instance()->LoadTextureText(ArkanoidText.font.id, ArkanoidText);
}


Splashscreen::~Splashscreen()
{
}

void Splashscreen::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState)
{
	sec += DELAY_TIME;
	if (sec >= 3000)
	{
		sceneStatus = sceneState::EXIT;
		gameState = stateType::MENU;
	}
	if(ArkanoidText.idColor.r < 255) ArkanoidText.idColor.r += 1;
	
	ArkanoidText.rect.position.y += 1;
	Renderer::Instance()->LoadTextureText(ArkanoidText.font.id, ArkanoidText);
}

void Splashscreen::Draw()
{
	Renderer::Instance()->Render();
	
	Renderer::Instance()->PushImage("BG_MENU", BG);
	Renderer::Instance()->PushImage("PAUSE_BG", PauseBG);
	Renderer::Instance()->PushImage(ArkanoidText.font.id, ArkanoidText.rect);
	
}
