#include"resources_manager.h"

bool ResourcesManager::load_from_file(SDL_Renderer* renderer)
{

	return true;
}

const FontPool& ResourcesManager::get_font_pool()
{
	return font_pool;
}

const SoundPool& ResourcesManager::get_sound_pool()
{
	return sound_pool;
}

const MusicPool& ResourcesManager::get_music_pool()
{
	return music_pool;
}

const TexturePool& ResourcesManager::get_texture_pool()
{
	return texture_pool;
}