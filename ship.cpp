#include"ship.h"
#include<iostream>

void Ship::on_update(double delta)
{
	
}
void Ship::on_render(SDL_Renderer* renderer)
{
	if (horizontal)
		SDL_RenderCopyEx(renderer, ship_texture, nullptr, &ship_rect, 0, nullptr, SDL_FLIP_NONE);
	else
		SDL_RenderCopyEx(renderer, ship_texture, nullptr, &ship_rect, 90.0, nullptr, SDL_FLIP_NONE);

}
void Ship::on_input(const SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && check_cursor_hit(event.button.x, event.button.y))
	{
		dx = event.button.x - ship_rect.x;
		dy = event.button.y - ship_rect.y;
		ship_in_move = true;
	}

	if (event.type == SDL_MOUSEBUTTONUP)
	{
		ship_in_move = false;
		dx = 0;
		dy = 0;
	}

	if (ship_in_move && event.type == SDL_MOUSEMOTION)
	{
		set_position({ event.motion.x - dx, event.motion.y - dy });
	}
}

void Ship::init_ship(SDL_Texture* texture,int size,SDL_Point first_pos)
{
	ship_texture = texture;
	ship_size = size;
	absolute_position = first_pos;
	ship_rect.h = 50, ship_rect.w = 50 * size;
}


void Ship::rotate_ship()
{
	horizontal ? horizontal = false, ship_rect.w = 50, ship_rect.h = 50 * ship_size
		: horizontal = true, ship_rect.h = 50, ship_rect.w = 50 * ship_size;
}

void Ship::get_hit(const int damage)
{
	hp = hp - damage;
	if (hp <= 0)
		sink = true;
}

void Ship::set_position(const SDL_Point& pos)
{
	absolute_position = pos;

	ship_rect.x = pos.x;
	ship_rect.y = pos.y;
}
void Ship::set_index(const SDL_Point& index)
{
	index_position = index;
	absolute_position.x = index.x * 50;
	absolute_position.y = index.y * 50;

	ship_rect.x = index.x;
	ship_rect.y = index.y;
}

const SDL_Point& Ship::get_position()const
{
	return absolute_position;
}


const SDL_Point& Ship::get_index()const
{
	return index_position;
}

int Ship::get_ship_size()const
{
	return ship_size;
}

bool Ship::is_horizontal()const
{
	return horizontal;
}

bool Ship::is_sink()const
{
	return sink;
}

int Ship::get_num_of_missile()const
{
	return missile;
}

bool Ship::check_cursor_hit(int x, int y)const
{
	return x >= ship_rect.x && x < (ship_rect.x + ship_rect.w) &&
		y >= ship_rect.y && y < (ship_rect.y + ship_rect.h);
}
