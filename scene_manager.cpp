#include "scene_manager.h"
#include"menu_scene.h"


void  SceneManager::init_scene_pool()
{
	scene_pool[SceneManager::SceneType::Menu] = new MenuScene;
}

void SceneManager::set_current_scene(Scene* scene)
{
	current_scene = scene;
	current_scene->on_enter();
}

void SceneManager::switch_to(SceneType type)
{
	current_scene->on_exit();

	current_scene = get_scene(type);

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

Scene* SceneManager::get_scene(SceneManager::SceneType type)
{
	auto it = scene_pool.find(type);

	if (it != scene_pool.end())
		return it->second;
	return nullptr;
}