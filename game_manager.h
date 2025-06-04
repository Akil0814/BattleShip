#pragma once

#include"manager.h"
#include"scene_manager.h"

#include<iostream>

#include<SDL.h>
#include <SDL_ttf.h>//�����
#include <SDL_mixer.h>//��Ƶ��
#include <SDL_image.h>//ͼ���
#include <SDL2_gfxPrimitives.h>

class GameManager:public Manager<GameManager>
{
	friend class Manager<GameManager>;

public:
	int run(int argc, char** argv);

	SDL_Window* get_window()const;

	SDL_Renderer* get_renderer()const;

protected:
	GameManager();
	~GameManager();

private:

	void on_input(const SDL_Event& event);

	void on_update(double delta);

	void on_render();


private:
	void init_assert(bool flag, const char* err_msg)
	{
		if (flag)
			return;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, u8"Game Start Error", err_msg, window);
		exit(-1);
	}


private:

	const int FPS = 60;
	bool is_quit = false;

	SDL_Event event;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};


