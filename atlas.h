#pragma once
#include<vector>
#include<SDL.h>

class Atlas
{
public:
	Atlas()=default;
	~Atlas()=default;

	void clear();

	int get_size() const;

	void add_Texture(SDL_Texture* new_texture);

	void add_Textures(std::initializer_list<SDL_Texture*> textures);

	SDL_Texture* get_texture(size_t num)const;


#if __cplusplus >= 201703L
	template<typename... Textures>
	void add_Textures(Textures*... textures)
	{
		(texture_list.push_back(textures), ...);
	}
#endif

private:
	std::vector<SDL_Texture*>texture_list;
};