#pragma once
#include<SDL.h>
#include<functional>
#include<memory>
#include"animation.h"

class Effect :public Animation
{
public:
	Effect();
	~Effect();

	std::unique_ptr<Effect> clone()
	{
		auto e = std::make_unique<Effect>();

		// 2) 复制动画配置（帧集、间隔、loop、finished 回调）
		e->set_frame(texture_list);
		e->set_interval(interval);      // 需要在 Animation 加个 getter
		e->set_loop(is_loop);
		e->set_on_finished(Animation::get_call_back()); // 也需要个 getter

		return e;
	}

	bool is_finished();
	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void set_play_data(SDL_Point pos,double angle);
	void set_play_data(SDL_Rect rect, double angle);


private:

	bool is_loop = false;//
	double angle = 0;
	bool is_valid = false;
	bool have_rect = false;

	SDL_Point play_pos = { 0 };
	SDL_Rect play_rect;
};
