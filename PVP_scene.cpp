#include"PVP_scene.h"

PVPScene::PVPScene()
{

}
PVPScene::~PVPScene()
{

}

void PVPScene::on_enter()
{
	WINDOW_WIDTH = 1090;
	WINDOW_HEIGHT = 600;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;
	current_player->set_board_pos({ 30,30 });
	get_other_player()->set_board_pos({ 560,30 });
}
void PVPScene::on_exit()
{

}

void PVPScene::on_update(double delta)
{
	current_player->on_update(delta);
	if (current_player->finish_round())
		current_player = get_other_player();
}
void PVPScene::on_render(SDL_Renderer* renderer)
{
	current_player->on_render(renderer);
	get_other_player()->on_render(renderer);
	get_other_player()->draw_cover(renderer);
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
}
void PVPScene::on_input(const SDL_Event& event)
{
	current_player->on_input(event);
}
Player* PVPScene::get_other_player()
{
	return current_player == p1 ? p2 : p1;
}