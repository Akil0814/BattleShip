#include"menu_scene.h"

MenuScene::MenuScene()
	:classic(GameManager::instance()->get_renderer(), { 100,50,200,70 }, { 100,50,200,70 },
			 TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(),ResourcesManager::instance()->get_font(ResID::Font_72), "Classic Game Mod"),
			 nullptr, nullptr)
{
	classic.set_on_click([]
		{
			GameManager::instance()->switch_scene(SceneType::ClassicSetup);
		});
}

MenuScene::~MenuScene()
{

}

void MenuScene::on_enter()
{
	WINDOW_WIDTH = 400;
	WINDOW_HEIGHT = 600;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);

}
void MenuScene::on_exit()
{
}

void MenuScene::on_update(double delta)
{
}
void MenuScene::on_render()
{
	classic.on_render();
	SDL_SetRenderDrawColor(GameManager::instance()->get_renderer(), back_ground_color.r, back_ground_color.g, back_ground_color.b, back_ground_color.a);
}
void MenuScene::on_input(const SDL_Event& event)
{
	classic.process_event(event);
}