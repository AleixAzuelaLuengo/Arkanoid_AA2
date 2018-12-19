#pragma once

#include "Inputs.h"

class Scene
{
public:
	Scene();
	~Scene();
	
	//void SetMusic(Music );
	//Music GetMusic();
	enum sceneState { RUNNING, EXIT }sceneStatus = sceneState::EXIT;
	enum stateType { SPLASHSCREEN, MENU, PLAY, RANKING, END }gameState = stateType::MENU;
	virtual void Update(Inputs &input, sceneState &sceneStatus, stateType &gameState) = 0;
	virtual void Draw() = 0;
	
private:
	//Music track;
	/*enum SceneState {RUNNING, EXIT, END};
	enum SceneType { SPLASHSCREEN, MENU, PLAY, RANKING, END };
	SceneType actualScene;
	SceneState state;*/
};

