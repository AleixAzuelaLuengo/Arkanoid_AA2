#include "Menu.h"
#include "Play.h"
#include "Ranking.h"
#include "Renderer.h"
#include "GameManager.h"
enum SceneType { MENU, RANKING, PLAY, SPLASHSCREEN, END};

int main(int, char*[])
{
	GameManager gM;
	gM.Update();

	return 0;
}