#pragma once
#include"scene.h"
#include"scene_type.h"
#include "menu_scene.h"
#include"setup_scene.h"

class ScenePool
{
public:

	static ScenePool* instance()//实现单例模式
	{
		if (!scene_pool)
			scene_pool = new ScenePool();//线程不安全

		return scene_pool;
	}

	Scene* get_scene(SceneType type);
	
	void delete_scene(SceneType type);

private:
	ScenePool()=default;
	~ScenePool() = default;;

	bool cheek_invalid(Scene* scene);

private:
	static ScenePool* scene_pool;

	Scene* menu_scene;
	Scene* setting_scene;

	Scene* PVE_scene;
	Scene* PVP_scene;
	Scene* setup_scene;


};