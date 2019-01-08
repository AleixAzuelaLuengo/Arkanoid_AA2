#include "Ranking.h"



Ranking::Ranking()
{
	char a[4] = "VRL";
	ReadFile(a, 600);
}


Ranking::~Ranking()
{
	
}

void Ranking::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState)
{
	
}

void Ranking::Draw()
{
}

void Ranking::ReadFile(char *name, int score)
{
	std::vector<std::pair<char *, int>> rankingList;
	std::vector<std::pair<char *, int>> readRankingList;
	std::pair<char *, int> temp;

	std::ifstream myFileIn("../../res/files/ranking.bin", std::ios::in | std::ios::binary);

	for (int i = 0; i < 10; i++)
	{
		std::pair<char *, int> temp2;
		char a[4];
		myFileIn.read(reinterpret_cast<char*> (&a), sizeof(char) * 4);
		myFileIn.read(reinterpret_cast<char*> (&temp2.second), sizeof(int));
		temp2.first = a;
		rankingList.push_back(temp2);
	}
	myFileIn.close();

	temp.first = name;
	temp.second = score;
	rankingList.push_back(temp);
	
	Sort(rankingList);
	rankingList.pop_back();

	std::ofstream myFile("../../res/files/ranking.bin", std::ios::out | std::ios::binary);
	for (int i = 0; i < rankingList.size(); i++)
	{
		char *a = rankingList[i].first;
		int b = rankingList[i].second;
		myFile.write(reinterpret_cast<char*> (a), sizeof(char) * 4);
		myFile.write(reinterpret_cast<const char*> (&b), sizeof(int));
	}
	myFile.close();
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


