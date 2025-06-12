#pragma once
#include"timer.h"
#include"atlas.h"

#include <SDL.h>
#include <vector>
#include <functional>

class Animation
{
public:
	typedef std::function<void()> PlayCallback;

public:
	Animation();
	~Animation() = default;

	void set_frame(const Atlas* atlas);
	void on_render(SDL_Renderer* renderer, SDL_Rect& rect, double angle) const;
	void on_render(SDL_Renderer* renderer, const SDL_Point& pos_dst, double angle) const;
	void reset();
	void set_loop(bool is_loop);
	void set_interval(double interval);
	void set_on_finished(PlayCallback on_finished);
	void on_update(double delta);

	void pause();
	void resume();


private:

	Timer timer;
	bool is_loop = true;
	size_t idx_frame = 0;
	PlayCallback on_finished;
	const Atlas* texture_list;
};
