#pragma once
#include"scene.h"
#include"player.h"
#include"game_manager.h"

class PVPScene :public Scene
{

public:
	PVPScene();
	~PVPScene();

	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void on_input(const SDL_Event& event);

private:
	Player* p1 = nullptr;
	Player* p2 = nullptr;
	Player* current_player = nullptr;

};