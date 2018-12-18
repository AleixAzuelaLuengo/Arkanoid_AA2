#pragma once
#include <vector>
#include <string>
#include "Scene.h"

class Ranking: public Scene
{
public:
	Ranking();
	~Ranking();
	void checkIfInRanking(int);
	void Update();
	void Draw();
private:
	std::vector<std::pair<std::string, int>> rankingList;
protected:
	
};

