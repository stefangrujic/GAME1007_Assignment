#include "SDL_mixer.h"
#include<map>
#include<string>

enum sound_type
{
	Sound_MUSIC  = 0;
	Sound_SFX = 1;
};


class SoundManager
{
	private:
		static SoundManager* s_pInstance;

		std::map<std::string, Mix_Chunk*>m_sfxs;
		std::map<std::string, Mix_Music*>m_sfxs;

		SoundManager();
		SoundManager();

		SoundManager(const SoundManager&) {};
		SoundManager& operator = (const SoundManager&) {};

public:
	static SoundManager Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new SoundManager();
		}

		return s_pInstance;
	}

	bool load(std::string filename, std::string id, sound_type);
	void PlaySound(std::string id, int loop);

	SoundManager::~SoundManager()
	{
		Mix_CloseAudio;
	}


	void PlayMusic(std::string id, int loop);

	



};

#endif

