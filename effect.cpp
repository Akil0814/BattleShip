#include "effect.h"

Effect::Effect()
{
}

Effect::~Effect()
{
}

bool Effect::is_finished()
{
	return Animation::is_finished();
}

void Effect::on_update(double delta)
{
	Animation::on_update(delta);
}

void Effect::on_render(SDL_Renderer* renderer)
{
	if (have_rect)
		Animation::on_render(renderer, play_rect, angle);
	else
		Animation::on_render(renderer,play_pos,angle);
}

void Effect::set_play_data(SDL_Point pos,double angle)
{
	play_pos = pos;
	this->angle = angle;
	have_rect = false;
	is_valid = true;
	Animation::reset();
	is_finish = false;
}

void Effect::set_play_data(SDL_Rect rect, double angel)
{
	play_rect = rect;
	this->angle = angle;
	have_rect = true;
	is_valid = true;
	Animation::reset();
	is_finish = false;
}
