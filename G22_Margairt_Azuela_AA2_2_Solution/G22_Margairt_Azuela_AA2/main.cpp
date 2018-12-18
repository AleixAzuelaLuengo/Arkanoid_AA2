#include "Menu.h"
#include "Play.h"
#include "Ranking.h"
#include "Renderer.h"
#include "GameManager.h"
enum SceneType { MENU, RANKING, PLAY, SPLASHSCREEN, END};

int main(int, char*[])
{
	Renderer::Instance();
	Menu menu;
	GameManager gm = GameManager();
	SceneType scene = SceneType::MENU;
	while (1)
	{
		gm.Update();
		gm.Draw();
	}

	return 0;
}