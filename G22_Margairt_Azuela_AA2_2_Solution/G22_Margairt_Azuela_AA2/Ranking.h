#pragma once
#include <vector>
#include <string>
class Ranking
{
public:
	Ranking();
	~Ranking();
	void checkIfInRanking(int);
private:
	std::vector<std::pair<std::string, int>> rankingList;
protected:
	void Update();
	void Draw();
};

