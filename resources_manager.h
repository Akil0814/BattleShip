#pragma once
#include"manager.h"

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <unordered_map>

enum class ResID
{

};

typedef std::unordered_map<ResID, TTF_Font*> FontPool;
typedef std::unordered_map<ResID, Mix_Chunk*> SoundPool;
typedef std::unordered_map<ResID, Mix_Music*> MusicPool;
typedef std::unordered_map<ResID, SDL_Texture*> TexturePool;

class ResourcesManager : public Manager<ResourcesManager>
{
	friend class Manager<ResourcesManager>;

public:

public:

	bool load_from_file(SDL_Renderer* renderer);

	const FontPool& get_font_pool();

	const SoundPool& get_sound_pool();

	const MusicPool& get_music_pool();

	const TexturePool& get_texture_pool();

protected:
	ResourcesManager() {};
	~ResourcesManager() {};

private:
	FontPool font_pool;
	SoundPool sound_pool;
	MusicPool music_pool;
	TexturePool texture_pool;
};
