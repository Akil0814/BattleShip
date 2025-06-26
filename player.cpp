#include"player.h"

Player::Player()
{
	Ship*  ship=new Ship;
	ship->init_ship(ResourcesManager::instance()->get_texture(ResID::Tex_Ship), 5, { 50,50 });
	ship_list.push_back(ship);
}

Player::~Player()
{
	for (auto& ship : ship_list)
		delete ship;
}

void Player::on_render_for_setup(SDL_Renderer* renderer)
{
	board.on_render_for_setup(renderer);

	for (auto& ship : ship_list)
		ship->on_render(renderer);
}
void Player::on_update_for_setup(double delta)
{
	board.on_update_for_setup(delta);
	for (auto& ship : ship_list)
		ship->on_update(delta);
}
void Player::on_input_for_setup(const SDL_Event& event)
{
	board.on_input_for_setup(event);

	for (auto& ship : ship_list)
		ship->on_input(event);
}
					
void Player::on_render(SDL_Renderer* renderer)	 
{}
void Player::on_update(double delta)
{}
void Player::on_input(const SDL_Event& event) 
{}

