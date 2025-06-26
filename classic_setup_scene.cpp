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
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;

}
void ClassicSetupScene::on_exit()
{

}

void ClassicSetupScene::on_update(double delta)
{
	current_player->on_update_for_setup(delta);
}
void ClassicSetupScene::on_render(SDL_Renderer* renderer)
{
	current_player->on_render_for_setup(renderer);
}
void ClassicSetupScene::on_input(const SDL_Event& event)
{
	current_player->on_input_for_setup(event);
}

void ClassicSetupScene::next_player()
{
	current_player == p1 ? current_player = p2 : current_player = p1;
}