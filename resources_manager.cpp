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