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

	case SceneType::ClassicPVE:
		if (cheek_invalid(classic_PVE_scene))
			//classicPVE_scene = new MenuScene;
		return classic_PVE_scene;
		break;

	case SceneType::ClassicPVP:
		if (cheek_invalid(classic_PVP_scene))
			//menu_scene = new MenuScene;
		return classic_PVP_scene;
		break;

	case SceneType::ClassicSetup:
		if (cheek_invalid(classic_setup_scene))
			classic_setup_scene = new ClassicSetupScene;
		return classic_setup_scene;
		break;

	case SceneType::NewTypePVE:
		if (cheek_invalid(new_type_PVE_scene))
			//menu_scene = new MenuScene;
		return  new_type_PVE_scene;
		break;

	case SceneType::NewTypePVP:
		if (cheek_invalid(new_type_PVP_scene))
			//menu_scene = new MenuScene;
		return new_type_PVP_scene;
		break;

	case SceneType::NewTypeSetup:
		if (cheek_invalid(new_type_setup_scene))
			//menu_scene = new MenuScene;
		return new_type_setup_scene;
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

	case SceneType::ClassicPVE:

		if (cheek_invalid(classic_PVE_scene))
			return;
		delete classic_PVE_scene;

		break;

	case SceneType::ClassicPVP:

		if (cheek_invalid(classic_PVP_scene))
			return;
		delete  classic_PVP_scene;

		break;

	case SceneType::ClassicSetup:

		if (cheek_invalid(classic_setup_scene))
			return;
		delete classic_setup_scene;

		break;

	case SceneType::NewTypePVE:

		if (cheek_invalid(new_type_PVE_scene))
			return;
		delete new_type_PVE_scene;

		break;

	case SceneType::NewTypePVP:

		if (cheek_invalid(new_type_PVP_scene))
			return;
		delete new_type_PVP_scene;

		break;

	case SceneType::NewTypeSetup:

		if (cheek_invalid(new_type_setup_scene))
			return;
		delete new_type_setup_scene;

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

