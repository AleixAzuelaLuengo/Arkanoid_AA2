#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Scene.h"
#include "Types.h"
#include "MovingObject.h"
#include <algorithm>
class Ranking: public Scene
{
public:
	Ranking();
	~Ranking();
	void checkIfInRanking(int);
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState);
	void Draw();
	void ReadFile(char *a, int puntuation);
	
private:
	std::vector<std::pair<char *, int>> rankingList;
	char ReadChar(char *, int lenght);
protected:
	
};

