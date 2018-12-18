#include "Menu.h"
#include "Play.h"
#include "Ranking.h"
#include "Renderer.h"

enum SceneType { MENU, RANKING, PLAY, SPLASHSCREEN, END};

int main(int, char*[])
{
	Renderer::Instance();
	SceneType scene = SceneType::MENU;
	while (scene != SceneType::END)
	{
		switch (scene)
		{
		
		case(SceneType::MENU):
		{
			Menu menu;
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