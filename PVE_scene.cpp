#include"PVE_scene.h"

ClassicPVEScene::ClassicPVEScene()
{

}
ClassicPVEScene::~ClassicPVEScene()
{

}

void ClassicPVEScene::on_enter()
{
	WINDOW_WIDTH = 1280;
	WINDOW_HEIGHT = 560;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;
}
void ClassicPVEScene::on_exit()
{

}

void ClassicPVEScene::on_update(double delta)
{

}
void ClassicPVEScene::on_render(SDL_Renderer* renderer)
{

}
void ClassicPVEScene::on_input(const SDL_Event& event)
{

}