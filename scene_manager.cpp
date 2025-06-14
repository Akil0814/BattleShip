#include "scene_manager.h"
#include<iostream>

void SceneManager::set_current_scene(Scene* scene)
{
	std::cout << "set scene" << std::endl;/////////////////////////////////////
	current_scene = scene;
	current_scene->on_enter();
}

void SceneManager::switch_to(Scene* scene)
{
	current_scene->on_exit();

	current_scene = scene;

	current_scene->on_enter();
}

void SceneManager::on_update(double delta)
{
	current_scene->on_update(delta);
}

void SceneManager::on_render()
{
	current_scene->on_render();
}

void SceneManager::on_input(const SDL_Event& event)
{
	current_scene->on_input(event);
}

