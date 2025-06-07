#pragma once
#include"scene.h"
#include"button.h"

class MenuScene:public Scene
{
private:
	Button classic;

public:
	MenuScene();
	~MenuScene();

	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render();
	void on_input(const SDL_Event& event);
};

