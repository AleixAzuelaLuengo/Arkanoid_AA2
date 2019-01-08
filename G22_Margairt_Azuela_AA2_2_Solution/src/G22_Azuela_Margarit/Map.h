#pragma once
#include "Brick.h"
#include "Constants.h"
#include <vector>
class Map
{
public:
	int GetVectorLenght();
	Brick GetBrick(int position);
	Map();
private:
	std::vector<Brick> brickList;
};