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
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState );
	void Draw();
	void setNewPlayer(char *, int);
private:
	std::vector<std::pair<char *, int>> rankingList;
	std::pair<char*, int> newPlayer;
	void ReadFile();
	void Sort(std::vector<std::pair<char*, int>> &a);
protected:
	
};

