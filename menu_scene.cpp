#include"menu_scene.h"

MenuScene::MenuScene()
	:classic(GameManager::instance()->get_renderer(), { 100,50,250,100 }, { 100,50,250,100 }, nullptr, nullptr, nullptr)
{
	classic.set_on_click([]
		{
			std::cout << "classic" << std::endl;
			GameManager::instance()->switch_scene(SceneType::ClassicSetup);
		});
}

MenuScene::~MenuScene()
{

}

void MenuScene::on_enter()
{
	WINDOW_WIDTH = 720;
	WINDOW_HEIGHT = 540;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);

}
void MenuScene::on_exit()
{
	std::cout << "exit" << std::endl;////////////////////////////////
}

void MenuScene::on_update(double delta)
{
}
void MenuScene::on_render()
{
	classic.on_render();

}
void MenuScene::on_input(const SDL_Event& event)
{
	classic.process_event(event);
}