#pragma once
#include <vector>
#include <string>
#include "Scene.h"
#include "Types.h"
#include "MovingObject.h"

class Ranking: public Scene
{
public:
	Ranking();
	~Ranking();
	void checkIfInRanking(int);
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();
private:
	std::vector<std::pair<std::string, int>> rankingList;
protected:
	
};

