#pragma once
#include"scene.h"
#include"game_manager.h"

class SettleScene:public Scene
{
public:
	SettleScene();
	~SettleScene();

	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void on_input(const SDL_Event& event);

private:

};

