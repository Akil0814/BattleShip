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
	virtual void on_render(SDL_Renderer* renderer, const SDL_Point& pos_dst, double angle) const;
	void reset();
	void set_loop(bool is_loop);
	void set_interval(double interval);
	void set_on_finished(PlayCallback on_finished);
	void on_update(double delta);

	void pause();
	void resume();

	bool is_finished() const;
	std::function<void()> get_call_back()const;


protected:

	double interval = 0.1;
	bool is_loop = true;
	bool is_finish = false;
	size_t idx_frame = 0;
	Timer timer;
	PlayCallback on_finished;
	const Atlas* texture_list;


private:


};
