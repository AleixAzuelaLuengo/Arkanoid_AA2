#include "Menu.h"
#include "Play.h"
#include "Ranking.h"
#include "Renderer.h"
#include "GameManager.h"

int main(int, char*[])
{
	Renderer::Instance();
	Menu menu;
	GameManager gm = GameManager();
	while (1)
	{
		gm.Update();
		gm.Draw();
	}

	return 0;
}