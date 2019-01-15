#pragma once

#include <string>
#include <SDL_mixer.h>
#include "Constants.h"
#include <iostream>

class Music
{
public:
	Music();
	~Music();
	void LoadMusic();
	//void PauseMusic(Mix_Music);
	//void ResumeMusi(Mix_Music);
private:
	Mix_Music *track;
	
};

