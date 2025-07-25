#include"PVE_scene.h"

PVEScene::PVEScene()
{

}
PVEScene::~PVEScene()
{

}

void PVEScene::on_enter()
{
	WINDOW_WIDTH = 1090;
	WINDOW_HEIGHT = 560;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;
	current_player->set_board_pos({ 30,30 });
	get_other_player()->set_board_pos({ 560,30 });
}
void PVEScene::on_exit()
{

}

void PVEScene::on_update(double delta)
{
	current_player->on_update(delta);
}
void PVEScene::on_render(SDL_Renderer* renderer)
{
	current_player->on_render(renderer);
	get_other_player()->on_render(renderer);

}
void PVEScene::on_input(const SDL_Event& event)
{
	current_player->on_input(event);
}
Player* PVEScene::get_other_player()
{
	return current_player == p1 ? p2 : p1;
}