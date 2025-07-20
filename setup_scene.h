#pragma once
#include"scene.h"
#include"button.h"
#include"scene_type.h"
#include"game_manager.h"

#include"player.h"
#include"human_player.h"
#include"computer_player.h"

class SetupScene :public Scene
{
public:
	SetupScene();
	~SetupScene();
	
	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void on_input(const SDL_Event& event);

private:
	void next_player();

private:

	Button next_button;
	Button start_button;

	bool move_current_ship = false;
	bool rotate_current_ship = false;

	Player* p1 = nullptr;
	Player* p2 = nullptr;
	Player* current_player = nullptr;
};
