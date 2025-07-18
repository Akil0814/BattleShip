#include"ship.h"
#include<iostream>


//增加防止一次选中多个船只


void Ship::on_update(double delta)
{
	
}

void Ship::on_render(SDL_Renderer* renderer)
{
	static SDL_Point pivot{ 25, 25 };
	if (horizontal)
		SDL_RenderCopyEx(renderer, ship_texture, nullptr, &render_rect, 0, &pivot, SDL_FLIP_NONE);
	else
		SDL_RenderCopyEx(renderer, ship_texture, nullptr, &render_rect, 90.0, &pivot, SDL_FLIP_NONE);
}

void Ship::on_input(const SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && check_cursor_hit(event.button.x, event.button.y))
	{
		ship_in_move = true;

		if (event.button.button == SDL_BUTTON_LEFT)
		{
			dx = event.button.x - collision_rect.x;
			dy = event.button.y - collision_rect.y;
			
		}

		if (event.button.button == SDL_BUTTON_RIGHT)
			rotate_ship();
	}

	if (event.type == SDL_MOUSEBUTTONUP)
	{
		ship_in_move = false;
		dx = 0;
		dy = 0;
		if (pos_valid)
		{
			set_position(absolute_position);
			last_position = absolute_position;
			pos_valid = false;
		}
		else
		{
			set_position(last_position);
		}
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
	render_rect.h = 50, render_rect.w = 50 * size;
	set_position(first_pos);
	last_position = first_pos;
}

void Ship::rotate_ship()
{
	horizontal = !horizontal;
	
	update_rect();
}

void Ship::update_rect()
{
	collision_rect.x = absolute_position.x;
	collision_rect.y = absolute_position.y;
	render_rect.x = absolute_position.x;
	render_rect.y = absolute_position.y;
	if (horizontal) {
		collision_rect.w = 50 * ship_size;
		collision_rect.h = 50;
	}
	else {
		collision_rect.w = 50;
		collision_rect.h = 50 * ship_size;
	}
}

void Ship::set_position(const SDL_Point& pos)
{
	absolute_position = pos;

	update_rect();
}


const SDL_Point& Ship::get_position()const
{
	return absolute_position;
}

int Ship::get_ship_size()const
{
	return ship_size;
}

bool Ship::is_horizontal()const
{
	return horizontal;
}

bool Ship::check_cursor_hit(int x, int y)const
{
	return x >= collision_rect.x && x < (collision_rect.x + collision_rect.w) &&
		y >= collision_rect.y && y < (collision_rect.y + collision_rect.h);
}

bool Ship::check_motion()const
{
	return ship_in_move;
}

void Ship::pos_is_valid()
{
	pos_valid = true;
}
