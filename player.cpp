#include"player.h"

Player::Player()
{
	Ship* ship = new Ship;
	ship->init_ship(ResourcesManager::instance()->get_texture(ResID::Tex_Ship_5), 5, { 570,50 });
	ship_list.push_back(ship);

	ship = new Ship;
	ship->init_ship(ResourcesManager::instance()->get_texture(ResID::Tex_Ship_4), 4, { 570,120 });
	ship_list.push_back(ship);

	ship = new Ship;
	ship->init_ship(ResourcesManager::instance()->get_texture(ResID::Tex_Ship_3), 3, { 570,190 });
	ship_list.push_back(ship);

	ship = new Ship;
	ship->init_ship(ResourcesManager::instance()->get_texture(ResID::Tex_Ship_2), 3, { 570,260 });
	ship_list.push_back(ship);

	ship = new Ship;
	ship->init_ship(ResourcesManager::instance()->get_texture(ResID::Tex_Ship_1), 2, { 570,330 });

	ship_list.push_back(ship);
	board.set_board_pos({30, 30});
}

Player::~Player()
{
	for (auto& ship : ship_list)
		delete ship;
}
					
void Player::on_render(SDL_Renderer* renderer)	 
{
	board.on_render(renderer);

	for (auto& ship : ship_list)
		ship->on_render(renderer);

	EffectManager::instance()->on_render(renderer);//局内
}
void Player::on_update(double delta)
{
	board.on_update(delta);//局内

	for (auto& ship : ship_list)
		ship->on_update(delta);

	EffectManager::instance()->on_update(delta);//局内
}
void Player::on_input(const SDL_Event& event) 
{
	board.on_input(event);

	for (auto& ship : ship_list)
		ship->on_input(event);

}

