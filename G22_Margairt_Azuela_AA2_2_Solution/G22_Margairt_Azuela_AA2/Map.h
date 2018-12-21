#pragma once
#include "Brick.h"

class Map
{
public:
	int bricks[11][12];


	Map();
	~Map();
	void ReadXML();
	
private:
	int rows;
	int cols;
	
};

