#include "Ranking.h"
#include "Renderer.h"
#include <iostream>
#include <string>

Ranking::Ranking()
{
	
	ReadFile();
	for (int i = 0; i < rankingList.size(); i++)
	{
		Renderer::Instance()->LoadFont(ranking[i].font);
		Renderer::Instance()->LoadTextureText(ranking[i].font.id, ranking[i]);
	}

}


Ranking::~Ranking()
{
	
}

void Ranking::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState, Music &music)
{
	if (input.GetInput(Inputs::InputType::Quit))
	{
		sceneStatus = sceneState::EXIT;
		gameState = stateType::MENU;
		input.SetInput(Inputs::InputType::Quit, false);
	}
}

void Ranking::Draw()
{
	Renderer::Instance()->Render();
	Renderer::Instance()->PushImage("BG_MENU", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	for (int i = 0; i < 10; i++) Renderer::Instance()->PushImage(ranking[i].font.id, ranking[i].rect);
	
}

void Ranking::setNewPlayer(char * name, int points)
{
	newPlayer.first = name;
	newPlayer.second = points;
}

void Ranking::ReadFile()
{
	std::pair<char *, int> temp;
	std::ifstream myFileIn("../../res/files/ranking.bin", std::ios::in | std::ios::binary);

	for (int i = 0; i < 10; i++)
	{
		std::pair<char *, int> temp2;
		char a[4];
		myFileIn.read(reinterpret_cast<char*> (&a), sizeof(char) * 4);
		myFileIn.read(reinterpret_cast<char*> (&temp2.second), sizeof(int));
		temp2.first = a;
		ranking[i].text = a;
		rankingList.push_back(temp2);
	}
	for (int i = 0; i < 10; i++)
	{
		int b;
		char a[4];
		myFileIn.read(reinterpret_cast<char*> (&a), sizeof(char) * 4);
		myFileIn.read(reinterpret_cast<char*> (&b), sizeof(int));
		rankingList[i].first = a;
	}
	
	myFileIn.close();

	temp.first = newPlayer.first;
	temp.second = newPlayer.second;
	rankingList.push_back(temp);
	
	Sort(rankingList);
	rankingList.pop_back();

	for (int i = 0; i < rankingList.size(); i++)
	{
		ranking[i].text += "  " + std::to_string(rankingList[i].second);
		ranking[i].idColor = White;
		ranking[i].font.path = MENU_FONT;
		ranking[i].font.size = 20;
		ranking[i].rect.proportions = { 300, 40 };
		ranking[i].rect.position.x = SCREEN_WIDTH / 2 - ranking[i].rect.proportions.x / 2;
		ranking[i].rect.position.y = ranking[i].rect.proportions.y + i * ranking[i].rect.proportions.y;
	}

	ranking[1].font.id = "FIRST_PLAYER";
	ranking[2].font.id = "SECOND_PLAYER";
	ranking[3].font.id = "THIRD_PLAYER";
	ranking[4].font.id = "FOURTH_PLAYER";
	ranking[5].font.id = "FIFTH_PLAYER";
	ranking[6].font.id = "SIXTH_PLAYER";
	ranking[7].font.id = "SEVENTH_PLAYER";
	ranking[8].font.id = "EIGHT_PLAYER";
	ranking[9].font.id = "NINETH_PLAYER";
	ranking[0].font.id = "TENTH_PLAYER";
	

	std::ofstream myFile("../../res/files/ranking.bin", std::ios::out | std::ios::binary);
	for (int i = 0; i < rankingList.size(); i++)
	{
		char *a = rankingList[i].first;
		int b = rankingList[i].second;
		myFile.write(reinterpret_cast<char*> (a), sizeof(char) * 4);
		myFile.write(reinterpret_cast<const char*> (&b), sizeof(int));
	}
	myFile.close();

	/*char x[4] = "VRL";
	char *a = x;
	int b = 200;

	std::ofstream myFile("../../res/files/ranking.bin", std::ios::out | std::ios::binary);
	for (int i = 0; i < 10; i++)
	{
		myFile.write(reinterpret_cast<char*> (a), sizeof(char) * 4);
		myFile.write(reinterpret_cast<char*> (&b), sizeof(b));
	}
	myFile.close(); */
}

void Ranking::Sort(std::vector<std::pair<char*, int>> &a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size() - i - 1; j++)
			if (a[j + 1].second > a[j].second)
			{
				std::pair<char*, int> temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}


