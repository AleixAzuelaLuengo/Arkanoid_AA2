#pragma once

#include "Inputs.h"
#include "Music.h"

class Scene
{
public:
	Scene();
	~Scene();
	
	//void SetMusic(Music );
	//Music GetMusic();
	enum sceneState { START_GAME, RUNNING, PAUSED, EXIT }sceneStatus = sceneState::EXIT;
	enum stateType { SPLASHSCREEN, MENU, PLAY, RANKING, END }gameState = stateType::SPLASHSCREEN;
	
	virtual void Update(Inputs &input,sceneState &sceneStatus, stateType &gameState, Music &music) = 0;
	virtual void Draw() = 0;

private:

	//Music track;
	/*enum SceneState {RUNNING, EXIT, END};
	enum SceneType { SPLASHSCREEN, MENU, PLAY, RANKING, END };
	SceneType actualScene;
	SceneState state;*/

};

