#pragma once

#include"manager.h"


#include<iostream>
#include<SDL.h>
#include <SDL_ttf.h>//×ÖÌå¿â
#include <SDL_mixer.h>//ÒôÆµ¿â
#include <SDL_image.h>//Í¼Ïñ¿â
#include <SDL2_gfxPrimitives.h>

class GameManager:public Manager<GameManager>
{
public:
	GameManager();
	~GameManager();

	int run(int argc, char** argv);

private:

	void init_assert(bool flag, const char* err_msg)
	{
		if (flag)
			return;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, u8"Game Start Error", err_msg, window);
		exit(-1);
	}

	void on_input();


	void on_update(double delta);


	void on_render();


private:
	SDL_Event event;
	bool is_quit = false;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Texture* tex_tile_map = nullptr;

};


