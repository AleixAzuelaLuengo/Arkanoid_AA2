#pragma once


enum SceneType{SplachScreen, Menu, Play, Ranking, END};
class Scene
{
public:
	Scene();
	~Scene();
	
	//void SetMusic(Music );
	//Music GetMusic();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	
private:
	//Music track;
	SceneType actualScene;
};

