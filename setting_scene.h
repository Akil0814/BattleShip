#pragma once
#include"scene.h"

class SettingScene :public Scene
{
public:
	SettingScene();
	~SettingScene();


	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render();
	void on_input(const SDL_Event& event);

private:

};
