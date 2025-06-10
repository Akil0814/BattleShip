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

	texture.add_Textures({ ResourcesManager::instance()->get_texture(ResID::Tex_Missile_0001),
						ResourcesManager::instance()->get_texture(ResID::Tex_Missile_0002),
						ResourcesManager::instance()->get_texture(ResID::Tex_Missile_0003)});//////////////

	missile.set_frame(texture);////////////

}
void ClassicSetupScene::on_exit()
{

}

void ClassicSetupScene::on_update(double delta)
{
	missile.on_update(delta);//////////////////
}
void ClassicSetupScene::on_render()
{
	SDL_SetRenderDrawColor(GameManager::instance()->get_renderer(),water_color.r,water_color.g,water_color.b,water_color.a);

	missile.on_render(GameManager::instance()->get_renderer(), {0,0},0);

}
void ClassicSetupScene::on_input(const SDL_Event& event)
{

}