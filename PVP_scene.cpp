#include"PVP_scene.h"

PVPScene::PVPScene()
{

}
PVPScene::~PVPScene()
{

}

void PVPScene::on_enter()
{
	WINDOW_WIDTH = 1280;
	WINDOW_HEIGHT = 560;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;
}
void PVPScene::on_exit()
{

}

void PVPScene::on_update(double delta)
{

}
void PVPScene::on_render(SDL_Renderer* renderer)
{

}
void PVPScene::on_input(const SDL_Event& event)
{

}