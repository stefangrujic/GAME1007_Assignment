#include "SoundManager.h"


SoundManager* SoundManager::s_pInstance = NULL;

SoundManager::SoundManager()
{
	mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{
	Mix_CloseAudio;

bool load(std::string filename, std::string id, sound_type);
{
	if (type == Sound_MUSIC)
	{
		Mix_Music * pMusic = Mix_LoadMUS(filename.c_str())
		if (pMusic == 0)
		{
			printf("Could not load Music With error: %s\n ", Mix_GetError())
				return false;
		}

		m_music[id] = pMusic;
		return true;
	}
	else if (type == Sound_SFX)
	{
		Mix_Chunk* pChunk = Mix_LoadWAV(filename.c_str());
		if (pChunk == 0)
		{
			printf("Could not load SFX With error: %s\n ", Mix_GetError())
				return false;
		}

		m_sfxs[id] = pChunk;
		return true;

	}
	
	return false;
}

void SoundManager:: PlaySound(std::string id, int loop);
{
    
}

void SoundManager::PlayMusic(std::string id, int loop);
{
	Mix_PlayMusic(m_music[id], loop);
}