#include"resources_manager.h"

bool ResourcesManager::load_from_file(SDL_Renderer* renderer)
{
	font_pool[ResID::Font_16] = TTF_OpenFont("res/Basketball.otf", 16);
	font_pool[ResID::Font_24] = TTF_OpenFont("res/Basketball.otf", 24);
	font_pool[ResID::Font_48] = TTF_OpenFont("res/Basketball.otf", 48);
	font_pool[ResID::Font_72] = TTF_OpenFont("res/Basketball.otf", 72);
	font_pool[ResID::Font_128] = TTF_OpenFont("res/Basketball.otf", 128);

	for (const auto& pair : font_pool)
		if (!pair.second) return false;

	texture_pool[ResID::Tex_SetTarget] = IMG_LoadTexture(renderer, "res/set_target.png");
	texture_pool[ResID::Tex_Hand] = IMG_LoadTexture(renderer, "res/hand.png");


	texture_pool[ResID::Tex_Ship_1] = IMG_LoadTexture(renderer, "res/ship/Ship1.png");
	texture_pool[ResID::Tex_Ship_2] = IMG_LoadTexture(renderer, "res/ship/Ship2.png");
	texture_pool[ResID::Tex_Ship_3] = IMG_LoadTexture(renderer, "res/ship/Ship3.png");
	texture_pool[ResID::Tex_Ship_4] = IMG_LoadTexture(renderer, "res/ship/Ship4.png");
	texture_pool[ResID::Tex_Ship_5] = IMG_LoadTexture(renderer, "res/ship/Ship5.png");


	texture_pool[ResID::Tex_Tile_hit] = IMG_LoadTexture(renderer, "res/tile_hit.png");
	texture_pool[ResID::Tex_Tile_miss] = IMG_LoadTexture(renderer, "res/tile_miss.png");
	texture_pool[ResID::Tex_Tile_unknow] = IMG_LoadTexture(renderer, "res/tile_unknow.png");

	texture_pool[ResID::Tex_Missile_0001] = IMG_LoadTexture(renderer, "res/missile_on_fire/missile_0001.png");
	texture_pool[ResID::Tex_Missile_0002] = IMG_LoadTexture(renderer, "res/missile_on_fire/missile_0002.png");
	texture_pool[ResID::Tex_Missile_0003] = IMG_LoadTexture(renderer, "res/missile_on_fire/missile_0003.png");

	texture_pool[ResID::Tex_GetTarget_0001] = IMG_LoadTexture(renderer, "res/get_target/get_target_0001.png");
	texture_pool[ResID::Tex_GetTarget_0002] = IMG_LoadTexture(renderer, "res/get_target/get_target_0002.png");
	texture_pool[ResID::Tex_GetTarget_0003] = IMG_LoadTexture(renderer, "res/get_target/get_target_0003.png");
	texture_pool[ResID::Tex_GetTarget_0004] = IMG_LoadTexture(renderer, "res/get_target/get_target_0004.png");
	texture_pool[ResID::Tex_GetTarget_0005] = IMG_LoadTexture(renderer, "res/get_target/get_target_0005.png");

	texture_pool[ResID::Tex_Explosion_0001] = IMG_LoadTexture(renderer, "res/explosion/explosion_0001.png");
	texture_pool[ResID::Tex_Explosion_0002] = IMG_LoadTexture(renderer, "res/explosion/explosion_0002.png");
	texture_pool[ResID::Tex_Explosion_0003] = IMG_LoadTexture(renderer, "res/explosion/explosion_0003.png");
	texture_pool[ResID::Tex_Explosion_0004] = IMG_LoadTexture(renderer, "res/explosion/explosion_0004.png");
	texture_pool[ResID::Tex_Explosion_0005] = IMG_LoadTexture(renderer, "res/explosion/explosion_0005.png");
	texture_pool[ResID::Tex_Explosion_0006] = IMG_LoadTexture(renderer, "res/explosion/explosion_0006.png");
	texture_pool[ResID::Tex_Explosion_0007] = IMG_LoadTexture(renderer, "res/explosion/explosion_0007.png");
	texture_pool[ResID::Tex_Explosion_0008] = IMG_LoadTexture(renderer, "res/explosion/explosion_0008.png");
	texture_pool[ResID::Tex_Explosion_0009] = IMG_LoadTexture(renderer, "res/explosion/explosion_0009.png");
	texture_pool[ResID::Tex_Explosion_0010] = IMG_LoadTexture(renderer, "res/explosion/explosion_0010.png");
	texture_pool[ResID::Tex_Explosion_0011] = IMG_LoadTexture(renderer, "res/explosion/explosion_0011.png");
	texture_pool[ResID::Tex_Explosion_0012] = IMG_LoadTexture(renderer, "res/explosion/explosion_0012.png");
	texture_pool[ResID::Tex_Explosion_0013] = IMG_LoadTexture(renderer, "res/explosion/explosion_0013.png");
	texture_pool[ResID::Tex_Explosion_0014] = IMG_LoadTexture(renderer, "res/explosion/explosion_0014.png");
	texture_pool[ResID::Tex_Explosion_0015] = IMG_LoadTexture(renderer, "res/explosion/explosion_0015.png");
	texture_pool[ResID::Tex_Explosion_0016] = IMG_LoadTexture(renderer, "res/explosion/explosion_0016.png");

	texture_pool[ResID::Tex_Explosion_big_0001] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0001.png");
	texture_pool[ResID::Tex_Explosion_big_0002] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0002.png");
	texture_pool[ResID::Tex_Explosion_big_0003] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0003.png");
	texture_pool[ResID::Tex_Explosion_big_0004] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0004.png");
	texture_pool[ResID::Tex_Explosion_big_0005] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0005.png");
	texture_pool[ResID::Tex_Explosion_big_0006] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0006.png");
	texture_pool[ResID::Tex_Explosion_big_0007] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0007.png");
	texture_pool[ResID::Tex_Explosion_big_0008] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0008.png");
	texture_pool[ResID::Tex_Explosion_big_0009] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0009.png");
	texture_pool[ResID::Tex_Explosion_big_0010] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0010.png");
	texture_pool[ResID::Tex_Explosion_big_0011] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0011.png");
	texture_pool[ResID::Tex_Explosion_big_0012] = IMG_LoadTexture(renderer, "res/explosion_big/explosion_big_0012.png");

	texture_pool[ResID::Tex_MissTarget0001] = IMG_LoadTexture(renderer, "res/miss_target/missed_0001.png");
	texture_pool[ResID::Tex_MissTarget0002] = IMG_LoadTexture(renderer, "res/miss_target/missed_0002.png");
	texture_pool[ResID::Tex_MissTarget0003] = IMG_LoadTexture(renderer, "res/miss_target/missed_0003.png");
	texture_pool[ResID::Tex_MissTarget0004] = IMG_LoadTexture(renderer, "res/miss_target/missed_0004.png");
	texture_pool[ResID::Tex_MissTarget0005] = IMG_LoadTexture(renderer, "res/miss_target/missed_0005.png");
	texture_pool[ResID::Tex_MissTarget0006] = IMG_LoadTexture(renderer, "res/miss_target/missed_0006.png");
	texture_pool[ResID::Tex_MissTarget0007] = IMG_LoadTexture(renderer, "res/miss_target/missed_0007.png");
	texture_pool[ResID::Tex_MissTarget0008] = IMG_LoadTexture(renderer, "res/miss_target/missed_0008.png");
	texture_pool[ResID::Tex_MissTarget0009] = IMG_LoadTexture(renderer, "res/miss_target/missed_0009.png");
	texture_pool[ResID::Tex_MissTarget0010] = IMG_LoadTexture(renderer, "res/miss_target/missed_0010.png");


	for (const auto& pair : texture_pool)
		if (!pair.second) return false;


	sound_pool[ResID::Sound_Fire01] = Mix_LoadWAV("res/sound/fire_1.wav");

	for (const auto& pair : sound_pool)
		if (!pair.second) return false;


	
	for (const auto& pair : music_pool)
		if (!pair.second) return false;

	return true;
}

TTF_Font* ResourcesManager::get_font(ResID id) const
{
	auto it = font_pool.find(id);

	if (it == font_pool.end())
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Font ID %d not loaded", int(id));
		return nullptr;
	}
	return it->second;
}

Mix_Chunk* ResourcesManager::get_sound(ResID id) const
{
	auto it = sound_pool.find(id);

	if (it == sound_pool.end())
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Font ID %d not loaded", int(id));
		return nullptr;
	}
	return it->second;
}

Mix_Music* ResourcesManager::get_music(ResID id) const
{
	auto it = music_pool.find(id);

	if (it == music_pool.end())
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Font ID %d not loaded", int(id));
		return nullptr;
	}
	return it->second;
}

SDL_Texture* ResourcesManager::get_texture(ResID id)const
{
	auto it = texture_pool.find(id);

	if (it == texture_pool.end())
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Font ID %d not loaded", int(id));
		return nullptr;
	}
	return it->second;
}