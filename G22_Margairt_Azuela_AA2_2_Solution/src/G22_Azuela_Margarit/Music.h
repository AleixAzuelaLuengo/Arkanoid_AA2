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
	void PauseMusic();
	void ResumeMusic();
private:
	Mix_Music *track;
	
};

