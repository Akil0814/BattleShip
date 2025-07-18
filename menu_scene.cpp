#include"menu_scene.h"

MenuScene::MenuScene()
	:button_PVP({ 100,50,200,70 }, { 100,50,200,70 },
			 TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(),ResourcesManager::instance()->get_font(ResID::Font_48), "   PVP   "),
			 nullptr, nullptr),
	button_PVE({ 100,150,200,70 }, { 100,150,200,70 },
		TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(), ResourcesManager::instance()->get_font(ResID::Font_48), "   PVE   "),
		nullptr, nullptr)
{
	button_PVP.set_on_click([]
		{
			GameManager::instance()->set_PVE(false);
			GameManager::instance()->set_player(false);
			GameManager::instance()->switch_scene(SceneType::Setup);
		});

	button_PVE.set_on_click([]
		{
			GameManager::instance()->set_PVE(true);
			GameManager::instance()->set_player(true);
			GameManager::instance()->switch_scene(SceneType::Setup);
		});
}

MenuScene::~MenuScene() = default;

void MenuScene::on_enter()
{
	WINDOW_WIDTH = 400;
	WINDOW_HEIGHT = 600;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);

}
void MenuScene::on_exit(){}

void MenuScene::on_update(double delta){}

void MenuScene::on_render(SDL_Renderer* renderer)
{
	button_PVP.on_render(renderer);
	button_PVE.on_render(renderer);

	SDL_SetRenderDrawColor(renderer,back_ground_color.r, back_ground_color.g, back_ground_color.b, back_ground_color.a);
}
void MenuScene::on_input(const SDL_Event& event)
{
	button_PVP.on_input(event);
	button_PVE.on_input(event);

}