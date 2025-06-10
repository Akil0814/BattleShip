#include"classic_setup_scene.h"
ClassicSetupScene::ClassicSetupScene()
{
}

ClassicSetupScene::~ClassicSetupScene()
{
}

void ClassicSetupScene::on_enter()
{
	WINDOW_WIDTH = 500;
	WINDOW_HEIGHT = 500;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	std::cout << "classic set up" << std::endl;

}
void ClassicSetupScene::on_exit()
{

}

void ClassicSetupScene::on_update(double delta)
{

}
void ClassicSetupScene::on_render()
{
	SDL_SetRenderDrawColor(GameManager::instance()->get_renderer(),water_color.r,water_color.g,water_color.b,water_color.a);
}
void ClassicSetupScene::on_input(const SDL_Event& event)
{

}