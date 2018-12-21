#include "Menu.h"
#include "Play.h"
#include "Ranking.h"
#include "Renderer.h"
#include "GameManager.h"
#include "Map.h"
#include <time.h>

int main(int, char*[])
{
	srand(time(NULL));
	Renderer::Instance();
	GameManager gm = GameManager();
	while (1)
	{
		gm.Update();
		gm.Draw();
	}

	return 0;
}