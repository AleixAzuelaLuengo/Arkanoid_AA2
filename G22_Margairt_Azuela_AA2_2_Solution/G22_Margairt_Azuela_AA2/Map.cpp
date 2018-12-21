#include "Map.h"
#include "../dep/inc/XML/rapidxml.hpp"
#include "../dep/inc/XML/rapidxml_utils.hpp"
#include "../dep/inc/XML/rapidxml_iterators.hpp"
#include "../dep/inc/XML/rapidxml_print.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int Map::GetVectorLenght()
{
	return brickList.size();
}

Brick Map::GetBrick(int position)
{
	return brickList[position];
}

Map::Map()
{
	int normalHP[2];
	int hardHP[2];
	rapidxml::xml_document<> doc;
	std::ifstream file("../res/file/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_node<> *pNode = pRoot->first_node("BrickInfo");

	std::string name = pNode->first_node()->name();
	if (name == "Normal")
	{
		normalHP[0] = std::stoi(pNode->first_node()->first_attribute()->value());
		normalHP[1] = std::stoi(pNode->first_node()->first_attribute()->next_attribute()->value());
	}
	pNode = pNode->first_node()->next_sibling();
	name = pNode->name();
	if (name == "Heavy")
	{
		hardHP[0] = std::stoi(pNode->first_attribute()->value());
		hardHP[1] = std::stoi(pNode->first_attribute()->next_attribute()->value());
	}

	pNode = pRoot->first_node()->next_sibling()->first_node();
	Brick tempBrick;

	for (pNode; pNode; pNode = pNode->next_sibling())
	{
		tempBrick.SetPosition(std::stoi(pNode->first_attribute()->value()), std::stoi(pNode->first_attribute()->next_attribute()->value()));
		tempBrick.SetType(*pNode->first_attribute()->next_attribute()->next_attribute()->value());
		if (tempBrick.GetType() == 'N') tempBrick.SetPuntuation((rand() % (normalHP[1] - normalHP[0] + 1) + normalHP[0]));
		if (tempBrick.GetType() == 'H') tempBrick.SetPuntuation((rand() % (hardHP[1] - hardHP[0] + 1) + hardHP[0]));
		if (tempBrick.GetType() == 'F') tempBrick.SetHP(-1);

		if (tempBrick.GetType() == 'N') tempBrick.SetHP(1);
		if (tempBrick.GetType() == 'H') tempBrick.SetHP(3);
		if (tempBrick.GetType() == 'F') tempBrick.SetHP(-1);
		brickList.push_back(tempBrick);
	}
	//tempBrick.SetPosition( SCRE,200);
	tempBrick.SetType('N');
	tempBrick.SetPuntuation((rand() % (normalHP[1] - normalHP[0] + 1) + normalHP[0]));
	brickList.push_back(tempBrick);
}