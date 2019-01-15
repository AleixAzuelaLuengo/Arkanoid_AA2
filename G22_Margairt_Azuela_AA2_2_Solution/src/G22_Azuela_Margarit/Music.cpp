#include "Music.h"



Music::Music()
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	track = NULL;
	
}


Music::~Music()
{
}

void Music::LoadMusic()
{
	track = Mix_LoadMUS("../../res/au/mainTheme.mp3");
	if (track == NULL) std::cout << "No ha encontrado la música" << std::endl;
	Mix_PlayMusic(track, 100);
	Mix_VolumeMusic(2);
}

void Music::PauseMusic()
{
	Mix_PauseMusic();
}

void Music::ResumeMusic()
{
	Mix_ResumeMusic();
}
