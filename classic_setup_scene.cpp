#include"classic_setup_scene.h"
ClassicSetupScene::ClassicSetupScene()
{
}

ClassicSetupScene::~ClassicSetupScene()
{
}

void ClassicSetupScene::on_enter()
{
	WINDOW_WIDTH = 1280;
	WINDOW_HEIGHT = 720;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	board.set_size(10, 10);
}
void ClassicSetupScene::on_exit()
{

}

void ClassicSetupScene::on_update(double delta)
{
	board.on_update(delta);
}
void ClassicSetupScene::on_render()
{
	board.on_render(GameManager::instance()->get_renderer());

}
void ClassicSetupScene::on_input(const SDL_Event& event)
{
	board.on_input(event);
}