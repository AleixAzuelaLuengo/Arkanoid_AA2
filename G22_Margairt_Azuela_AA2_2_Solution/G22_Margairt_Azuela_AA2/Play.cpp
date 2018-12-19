#include "Play.h"



Play::Play()
{
}


Play::~Play()
{
}

void Play::Update(Inputs &input, sceneState &sceneStatus, stateType &gameState)
{
	if (input.GetInput(input.W))
	{
		playerLeft.SetPosition((playerLeft.GetPosition().x)  , (playerLeft.GetPosition().y + 1));
	}
	else if (input.GetInput(input.S))
	{
		playerLeft.SetPosition((playerLeft.GetPosition().x), (playerLeft.GetPosition().y - 1));
	}
	if (input.GetInput(input.UpArrow))
	{
		playerRight.SetPosition((playerRight.GetPosition().x), (playerRight.GetPosition().y + 1));
	}
	else if (input.GetInput(input.DownArrow))
	{
		playerRight.SetPosition((playerRight.GetPosition().x), (playerRight.GetPosition().y - 1));
	}
}

void Play::Draw()
{
}
