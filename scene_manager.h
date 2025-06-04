#pragma once
#include"manager.h"
#include"scene.h"
#include"menu_scene.h"

#include <unordered_map>


class SceneManager:public Manager<SceneManager>
{
	friend class Manager<SceneManager>;


public:

	enum class SceneType
	{
		Menu,
		Setting,

		ClassicPVE,
		ClassicPVP,
		ClassicSetup,

		NewTypePVE,
		NewTypePVP,
		NewTypeSetup
	};

	typedef std::unordered_map<SceneManager::SceneType,Scene*> ScenePool;


protected:

	SceneManager() = default;

	~SceneManager() = default;

public:
	void init_scene_pool()
	{
		scene_pool[SceneManager::SceneType::Menu] = new MenuScene;
	}

	void set_current_scene(Scene* scene)
	{
		current_scene = scene;
		current_scene->on_enter();
	}

	void switch_to(SceneType type)
	{
		current_scene->on_exit();

		current_scene = get_scene(type);

		current_scene->on_enter();
	}

	void on_update(double delta)
	{
		current_scene->on_update(delta);
	}

	void on_render()
	{
		current_scene->on_render();
	}

	void on_input(const SDL_Event& event)
	{
		current_scene->on_input(event);
	}

private:

	Scene* get_scene(SceneManager::SceneType type)
	{
		auto it = scene_pool.find(type);

		if (it != scene_pool.end())
			return it->second;
		return nullptr;
	}

private:
	Scene* current_scene = nullptr;
	ScenePool scene_pool;

};