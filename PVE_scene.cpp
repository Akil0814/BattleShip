#include"PVE_scene.h"

PVEScene::PVEScene()
{

}
PVEScene::~PVEScene()
{

}

void PVEScene::on_enter()
{
	WINDOW_WIDTH = 1280;
	WINDOW_HEIGHT = 560;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;
}
void PVEScene::on_exit()
{

}

void PVEScene::on_update(double delta)
{

}
void PVEScene::on_render(SDL_Renderer* renderer)
{

}
void PVEScene::on_input(const SDL_Event& event)
{

}