#pragma once
#include"manager.h"

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <unordered_map>

enum class ResID
{
	Font_16,
	Font_24,
	Font_48,
	Font_72,
	Font_128,



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

	TTF_Font* get_font(ResID id) const;
	Mix_Chunk* get_sound(ResID id) const;
	Mix_Music* get_music(ResID id) const;
	SDL_Texture* get_texture(ResID id)const;

protected:
	ResourcesManager() {};
	~ResourcesManager() {};

private:
	FontPool font_pool;
	SoundPool sound_pool;
	MusicPool music_pool;
	TexturePool texture_pool;
};
