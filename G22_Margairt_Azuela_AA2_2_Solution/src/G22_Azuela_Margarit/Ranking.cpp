#include "Ranking.h"



Ranking::Ranking()
{
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
	/*std::ifstream myFileIn("ranking.bin", std::ios::in | std::ios::binary);
	std::ofstream myFile("ranking.bin", std::ios::out | std::ios::binary);

	std::pair<char *, int> temp;
	temp.first = name;
	temp.second = score;
	
	for (int i = 0; i < 10; i++)
	{
		std::pair<char *, int> temp2;
		myFileIn.read(reinterpret_cast<char*> (&temp2.first), sizeof(char) * 4);
		myFileIn.read(reinterpret_cast<char*> (&temp2.second), sizeof(int));
		rankingList.push_back(temp2);
	}
	for(int i = 0; i < rankingList.size(); i++)
		if (rankingList[i].second < score)
			rankingList.push_back(temp);

	std::sort(rankingList[0], rankingList[rankingList.size()]);

	for (int i = 1; i < rankingList.size(); i++)
	{
		myFile.write(reinterpret_cast<char*> (&rankingList[i].first), sizeof(sizeof(char) * 4));
		myFile.write(reinterpret_cast<char*> (&rankingList[i].second), sizeof(int));
	}*/

}


char Ranking::ReadChar(char *, int lenght)
{
	return 'a';
}


