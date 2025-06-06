#pragma once
#include"scene.h"
#include"manager.h"

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
	void init_scene_pool();
	void set_current_scene(Scene* scene);
	void switch_to(SceneType type);

	void on_update(double delta);
	void on_render();
	void on_input(const SDL_Event& event);

private:

	Scene* get_scene(SceneManager::SceneType type);

private:
	Scene* current_scene = nullptr;
	ScenePool scene_pool;

};