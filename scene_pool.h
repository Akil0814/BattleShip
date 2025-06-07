#pragma once

class Scene;

//ScenePool* ScenePool::scene_pool = nullptr;

class ScenePool
{
public:

	static ScenePool* instance()//ʵ�ֵ���ģʽ
	{
		if (!scene_pool)
			scene_pool = new ScenePool();//�̲߳���ȫ

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