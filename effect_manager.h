#pragma once
#include"manager.h"
#include<SDL.h>
#include<vector>

enum class EffectID
{
	SelectTarget,
	WaterSplash_single,
	WaterSplash_plural,
	Explosion,
	ExplosionTwice,
};

class EffectManager:public Manager<EffectManager>
{
	friend class Manager<EffectManager>;
public:
	void on_update();
	void on_render();

	bool init_effect();
	void add_effect(const SDL_Point& postion,EffectID effect_type);


protected:
	EffectManager();
	~EffectManager();
private:
	std::vector<std::> effects;
};
