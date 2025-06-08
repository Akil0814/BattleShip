#pragma once
#include"scene.h"
#include"scene_type.h"
#include "menu_scene.h"
#include"classic_setup_scene.h"

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

	Scene* classic_PVE_scene;
	Scene* classic_PVP_scene;
	Scene* classic_setup_scene;

	Scene* new_type_PVE_scene;
	Scene* new_type_PVP_scene;
	Scene* new_type_setup_scene;


};