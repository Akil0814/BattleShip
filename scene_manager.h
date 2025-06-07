#pragma once
#ifndef _SCENE_MANAGER_H_

#include"manager.h"
#include"scene.h"

class Scene;

class SceneManager :public Manager<SceneManager>
{
	friend class Manager<SceneManager>;
protected:

	SceneManager() = default;

	~SceneManager() = default;

public:
	void set_current_scene(Scene* scene);
	void switch_to(Scene* scene);

	void on_update(double delta);
	void on_render();
	void on_input(const SDL_Event& event);

private:
	Scene* current_scene = nullptr;

};

#endif // !_SCENE_MANAGER_H_
