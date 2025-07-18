#include"scene_pool.h"

ScenePool* ScenePool::scene_pool = nullptr;

Scene* ScenePool::get_scene(SceneType type)
{
	switch (type)
	{
	case SceneType::Menu:
		if (cheek_invalid(menu_scene))
			menu_scene = new MenuScene;
		return menu_scene;
		break;

	case SceneType::Setting:
		if (cheek_invalid(setting_scene))
			//setting_scene = new MenuScene;
		return setting_scene;
		break;

	case SceneType::PVE:
		if (cheek_invalid(PVE_scene))
			//classicPVE_scene = new MenuScene;
		return PVE_scene;
		break;

	case SceneType::PVP:
		if (cheek_invalid(PVP_scene))
			//menu_scene = new MenuScene;
		return PVP_scene;
		break;

	case SceneType::Setup:
		if (cheek_invalid(setup_scene))
			setup_scene = new SetupScene;
		return setup_scene;
		break;


	default:
		return nullptr;
		break;
	}

	return nullptr;
}

void ScenePool::delete_scene(SceneType type)
{
	switch (type)
	{
	case SceneType::Menu:

		if (cheek_invalid(menu_scene))
			return;
		delete menu_scene;

		break;

	case SceneType::Setting:

		if (cheek_invalid(setting_scene))
			return;
		delete setting_scene;

		break;

	case SceneType::PVE:

		if (cheek_invalid(PVE_scene))
			return;
		delete PVE_scene;

		break;

	case SceneType::PVP:

		if (cheek_invalid(PVP_scene))
			return;
		delete  PVP_scene;

		break;

	case SceneType::Setup:

		if (cheek_invalid(setup_scene))
			return;
		delete setup_scene;

		break;

	default:
		break;
	}
}

bool ScenePool::cheek_invalid(Scene* scene)
{
	if (scene == nullptr)
		return true;

	return false;
}

