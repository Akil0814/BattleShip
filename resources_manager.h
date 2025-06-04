#pragma once
#include"manager.h"

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <unordered_map>

enum class ResID
{

};

class ResourcesManager : public Manager<ResourcesManager>
{
	friend class Manager<ResourcesManager>;

public:

	typedef std::unordered_map<ResID, TTF_Font*> FontPool;
	typedef std::unordered_map<ResID, Mix_Chunk*> SoundPool;
	typedef std::unordered_map<ResID, Mix_Music*> MusicPool;
	typedef std::unordered_map<ResID, SDL_Texture*> TexturePool;

public:

	bool load_from_file(SDL_Renderer* renderer)
	{

		return true;
	}



	const FontPool& get_font_pool()
	{
		return font_pool;
	}

	const SoundPool& get_sound_pool()
	{
		return sound_pool;
	}

	const MusicPool& get_music_pool()
	{
		return music_pool;
	}

	const TexturePool& get_texture_pool()
	{
		return texture_pool;
	}

protected:
	ResourcesManager() {};
	~ResourcesManager() {};

private:
	FontPool font_pool;
	SoundPool sound_pool;
	MusicPool music_pool;
	TexturePool texture_pool;
};

