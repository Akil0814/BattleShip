#pragma once

class Scene;

//ScenePool* ScenePool::scene_pool = nullptr;

class ScenePool
{
public:

	static ScenePool* instance()//实现单例模式
	{
		if (!scene_pool)
			scene_pool = new ScenePool();//线程不安全

		return scene_pool;
	}

	Scene* get_scene();

private:
	ScenePool()=default;
	~ScenePool() = default;;

private:
	static ScenePool* scene_pool;
	Scene* menu_scene;
};