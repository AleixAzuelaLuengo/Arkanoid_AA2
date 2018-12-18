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
	while (scene != SceneType::END)
	{
		gm.Update();
		switch (scene)
		{
		
		case(SceneType::MENU):
		{
			//Menu menu = Menu();
			menu.Update();
			menu.Draw();
			break;
		}
		case(SceneType::RANKING):
		{
			Ranking ranking;
			ranking.Update();
			ranking.Draw();
			break;
		}
		case(SceneType::PLAY):
		{
			Play play;
			play.Update();
			play.Draw();
			break;
		}
		default:
			scene = SceneType::END;
			break;
		}
	}

	return 0;
}