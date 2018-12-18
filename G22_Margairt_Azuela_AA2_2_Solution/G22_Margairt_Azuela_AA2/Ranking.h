#pragma once
#include <vector>
#include <string>
class Ranking
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

