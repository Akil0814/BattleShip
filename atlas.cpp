#include "Atlas.h"

void Atlas::clear()
{
    texture_list.clear();
}

int Atlas::get_size() const
{
    return static_cast<int>(texture_list.size());
}

void Atlas::add_Texture(SDL_Texture* new_texture)
{
    texture_list.push_back(new_texture);
}

void Atlas::add_Textures(std::initializer_list<SDL_Texture*> textures)
{
    for (auto tex : textures) {
        texture_list.push_back(tex);
    }
}

SDL_Texture* Atlas::get_texture(size_t num)const
{
    if (texture_list.empty())
        return nullptr;
    return texture_list[num % texture_list.size()];
}