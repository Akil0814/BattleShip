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

	Tex_Ship_1,
	Tex_Ship_2,
	Tex_Ship_3,
	Tex_Ship_4,
	Tex_Ship_5,


	Tex_Tile_hit,
	Tex_Tile_miss,
	Tex_Tile_unknow,

	Tex_Missile_0001,
	Tex_Missile_0002,
	Tex_Missile_0003,

	Tex_SetTarget,
	Tex_Hand,


	Tex_GetTarget_0001,
	Tex_GetTarget_0002,
	Tex_GetTarget_0003,
	Tex_GetTarget_0004,
	Tex_GetTarget_0005,

	Tex_Explosion_0001,
	Tex_Explosion_0002,
	Tex_Explosion_0003,
	Tex_Explosion_0004,
	Tex_Explosion_0005,
	Tex_Explosion_0006,
	Tex_Explosion_0007,
	Tex_Explosion_0008,
	Tex_Explosion_0009,
	Tex_Explosion_0010,
	Tex_Explosion_0011,
	Tex_Explosion_0012,
	Tex_Explosion_0013,
	Tex_Explosion_0014,
	Tex_Explosion_0015,
	Tex_Explosion_0016,

	Tex_Explosion_big_0001,
	Tex_Explosion_big_0002,
	Tex_Explosion_big_0003,
	Tex_Explosion_big_0004,
	Tex_Explosion_big_0005,
	Tex_Explosion_big_0006,
	Tex_Explosion_big_0007,
	Tex_Explosion_big_0008,
	Tex_Explosion_big_0009,
	Tex_Explosion_big_0010,
	Tex_Explosion_big_0011,
	Tex_Explosion_big_0012,

	Tex_MissTarget0001,
	Tex_MissTarget0002,
	Tex_MissTarget0003,
	Tex_MissTarget0004,
	Tex_MissTarget0005,
	Tex_MissTarget0006,
	Tex_MissTarget0007,
	Tex_MissTarget0008,
	Tex_MissTarget0009,
	Tex_MissTarget0010,

	Sound_Fire01,

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
