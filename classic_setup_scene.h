#pragma once
#include"scene.h"
#include"button.h"
#include"scene_type.h"
#include"game_manager.h"
#include"player.h"

#include"board.h"

class ClassicSetupScene :public Scene
{
public:
	ClassicSetupScene();
	~ClassicSetupScene();

	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void on_input(const SDL_Event& event);

private:
	void next_player();

private:
	Button next_button;

	Player* p1 = nullptr;
	Player* p2 = nullptr;
	Player* current_player = nullptr;
};
