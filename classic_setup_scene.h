#pragma once
#include"scene.h"
#include"button.h"
#include"scene_type.h"
#include"game_manager.h"

class ClassicSetupScene :public Scene
{
public:
	ClassicSetupScene();
	~ClassicSetupScene();

	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render();
	void on_input(const SDL_Event& event);

private:

};
