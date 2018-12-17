#pragma once
#include "Scene.h"
#include "Inputs.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	void LoadScene(Scene );
	Inputs GetInput();
	void SetInput(bool , InputType );
	Scene GetScene();
	void SetScene(Scene );
private:
	Inputs inputList;
	Scene scene;
};

