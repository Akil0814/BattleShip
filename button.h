#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_mixer.h>//“Ù∆µø‚
#include <SDL_image.h>//ÕºœÒø‚

#include<string>
#include<iostream>
#include<functional>

class Button
{
public:
	enum class Status
	{
		Idle = 0,
		Hovered,
		Pushed
	};

public:

	Button(SDL_Renderer* renderer,SDL_Rect rect_button, SDL_Rect rect_message, SDL_Texture* texture_message,
			Mix_Chunk* sound_effect_down, Mix_Chunk* sound_effect_up);

	Button(SDL_Renderer* renderer, SDL_Rect rect_button, SDL_Rect rect_message, SDL_Texture* texture_message,
			Mix_Chunk* sound_effect_down, Mix_Chunk* sound_effect_up,
			SDL_Color color_idle,SDL_Color color_hovered, SDL_Color color_pushed, SDL_Color color_frame);

	Button(SDL_Renderer* renderer, SDL_Rect rect_button, SDL_Rect rect_message, SDL_Texture* texture_message,
			Mix_Chunk* sound_effect_down, Mix_Chunk* sound_effect_up,
			SDL_Texture* texture_idle,SDL_Texture* texture_hovered, SDL_Texture* texture_pushed);

	~Button() = default;

	void on_render();
	void process_event(const SDL_Event& event);
	void set_on_click(std::function<void()> func);
	Status get_status()const;

private:

	bool check_cursor_hit(int x, int y)const;

	template<typename T>
	void init_assert(T* ptr, const std::string& err_msg)const;

private:

	SDL_Renderer* renderer = nullptr;

	SDL_Rect rect_button;
	SDL_Rect rect_message;

	Mix_Chunk* sound_effect_down = nullptr;//“Ù–ß
	Mix_Chunk* sound_effect_up = nullptr;//“Ù–ß

	SDL_Texture* texture_message = nullptr;
	SDL_Texture* texture_idle = nullptr;
	SDL_Texture* texture_hovered = nullptr;
	SDL_Texture* texture_pushed = nullptr;

	SDL_Color color_frame = { 0,0,0,255 };

	
	SDL_Color color_idle = { 180, 180, 180, 255 };
	SDL_Color color_hovered = { 200, 200, 200, 255 };
	SDL_Color color_pushed = { 130, 130, 130, 255 };

	Status status = Status::Idle;

	std::function<void()> on_click = nullptr;

	bool have_sound_effect_down = false;
	bool have_sound_effect_up = false;

	bool have_texture = false;
	bool have_message = false;

	//bool will_hold = false;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Button::Button(SDL_Renderer* renderer, SDL_Rect rect_button, SDL_Rect rect_message, SDL_Texture* texture_message,
				Mix_Chunk* sound_effect_down, Mix_Chunk* sound_effect_up)
{

	init_assert<SDL_Renderer>(renderer, "Butten Renderer Error");
	this->renderer = renderer;
	this->rect_button = rect_button;

	if (texture_message != nullptr)
	{
		have_message = true;
		this->rect_message = rect_message;
		this->texture_message = texture_message;
	}

	if (sound_effect_down != nullptr)
	{
		have_sound_effect_down = true;
		this->sound_effect_down = sound_effect_down;
	}

	if (sound_effect_up != nullptr)
	{
		have_sound_effect_up = true;
		this->sound_effect_up = sound_effect_up;
	}


}

Button::Button(SDL_Renderer* renderer, SDL_Rect rect_button, SDL_Rect rect_message, SDL_Texture* texture_message,
	Mix_Chunk* sound_effect_down, Mix_Chunk* sound_effect_up,
	SDL_Color color_idle, SDL_Color color_hovered, SDL_Color color_pushed, SDL_Color color_frame)
	:Button(renderer, rect_button, rect_message, texture_message, sound_effect_down, sound_effect_up)
{
	this->color_idle = color_idle;
	this->color_hovered= color_hovered;
	this->color_pushed=color_pushed;
	this->color_frame = color_frame;
}

Button::Button(SDL_Renderer* renderer, SDL_Rect rect_button, SDL_Rect rect_message, SDL_Texture* texture_message,
	Mix_Chunk* sound_effect_down, Mix_Chunk* sound_effect_up,
	SDL_Texture* texture_idle, SDL_Texture* texture_hovered, SDL_Texture* texture_pushed)
	:Button(renderer, rect_button, rect_message, texture_message, sound_effect_down, sound_effect_up)
{
	init_assert<SDL_Texture>(texture_idle, "Butten Texture_idle Error");
	init_assert<SDL_Texture>(texture_hovered, "Butten Texture_hovered Error");
	init_assert<SDL_Texture>(texture_pushed, "Butten Texture_pushed Error");
	have_texture = true;

	this->texture_idle = texture_idle;
	this->texture_hovered = texture_hovered;
	this->texture_pushed = texture_pushed;
}

template<typename T>
void Button::init_assert(T* ptr, const std::string& err_msg)const
{
	if (ptr == nullptr)
	{
		std::cout << err_msg << std::endl;
		exit(-1);
	}
}

void Button::on_render()
{
	if (!have_texture)
	{
		switch (status)
		{
		case Status::Idle:
			SDL_SetRenderDrawColor(renderer, color_idle.r, color_idle.g, color_idle.b, color_idle.a);
			break;
		case Status::Hovered:
			SDL_SetRenderDrawColor(renderer, color_hovered.r, color_hovered.g, color_hovered.b, color_hovered.a);
			break;
		case Status::Pushed:
			SDL_SetRenderDrawColor(renderer, color_pushed.r, color_pushed.g, color_pushed.b, color_pushed.a);
			break;
		}
		SDL_RenderFillRect(renderer, &rect_button);
		SDL_SetRenderDrawColor(renderer, color_frame.r, color_frame.g, color_frame.b, color_frame.a);
		SDL_RenderDrawRect(renderer, &rect_button);

		if (have_message)
			SDL_RenderCopy(renderer, texture_message, nullptr, &rect_message);
	}
	else
	{
		switch (status)
		{
		case Status::Idle:
			SDL_RenderCopy(renderer, texture_idle, nullptr, &rect_button);
			break;
		case Status::Hovered:
			SDL_RenderCopy(renderer, texture_hovered, nullptr, &rect_button);
			break;
		case Status::Pushed:
			SDL_RenderCopy(renderer, texture_pushed, nullptr, &rect_button);
			break;
		}
		if (have_message)
			SDL_RenderCopy(renderer, texture_message, nullptr, &rect_message);
	}

}

void Button::process_event(const SDL_Event& event)
{

	switch (event.type)
	{
	case SDL_MOUSEMOTION:
		if (status == Status::Idle && check_cursor_hit(event.motion.x, event.motion.y))
			status = Status::Hovered;
		else if (status == Status::Hovered && !check_cursor_hit(event.motion.x, event.motion.y))
			status = Status::Idle;
		break;

	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (check_cursor_hit(event.button.x, event.button.y))
			{
				status = Status::Pushed;
				if (have_sound_effect_down)
					Mix_PlayChannel(-1, sound_effect_down, 0);
			}
		}
		break;

	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (status == Status::Pushed)
			{
				status = Status::Idle;
				if (have_sound_effect_up)
					Mix_PlayChannel(-1, sound_effect_up, 0);

				if (check_cursor_hit(event.button.x, event.button.y))
				{
					if (on_click)
						on_click();
				}
			}
		}
		break;

	default:
		break;
	}
}

bool Button::check_cursor_hit(int x, int y)const
{
	return x >= rect_button.x && x < (rect_button.x + rect_button.w) &&
		y >= rect_button.y && y < (rect_button.y + rect_button.h);

}

void Button::set_on_click(std::function<void()> func)
{
	on_click = std::move(func);
}

Button::Status Button::get_status()const
{
	return status;
}