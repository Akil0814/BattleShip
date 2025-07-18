#pragma once
#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_type.h"
#include"game_manager.h"
#include"resources_manager.h"
#include"txt_texture_manager.h"

class MenuScene :public Scene
{
private:
	Button button_PVP;

public:
	MenuScene();
	~MenuScene();

	void on_enter();
	void on_exit();

	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void on_input(const SDL_Event& event);
};

#endif // !_MENU_CENE_H_



