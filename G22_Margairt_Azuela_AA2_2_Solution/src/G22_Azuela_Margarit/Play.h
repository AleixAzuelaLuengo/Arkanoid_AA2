#pragma once
#include "Player.h"
#include "Ball.h"
#include "Types.h"
#include "Ranking.h"
#include "Map.h"
#include "Scene.h"
#include "PowerUp.h"
#include "MovingObject.h"
#include <chrono>
#include "Music.h"

class Play: public Scene
{
public:
	Play();
	~Play();
	void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState, Music &music);
	void Draw();
private:
	MovingObject object;
	Rect BG;
	Rect PauseBG;
	Player playerLeft;
	Player playerRight;
	Ball ball;
	Map brick;
	//Brick *brickList[][];
	SDL_Event event;
	MyText pause;
	MyText name[3];
	MyText winningPlayer;
	MyText startGame[2];
	char nameChar[4];
	int i = 0;
	int j = 0;
	MyText soundOnSwitch;
	std::vector<Brick> brickList;
	std::vector<PowerUp*> powerUpList;
	std::pair<char *, int> newPlayer;
	void Sort(std::vector<std::pair<char*, int>> &a);
	void ReadFile();
	int lastPlayer;
	int spawnPlayer;
	char abecedario[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool gameOver;
	std::chrono::system_clock::time_point powerUpSec[2];
};

