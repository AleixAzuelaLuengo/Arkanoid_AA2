#pragma once



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
	enum SceneType { SPLASHSCREEN, MENU, PLAY, RANKING, END };
	SceneType actualScene;
};

