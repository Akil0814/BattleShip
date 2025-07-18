#include"player.h"

#include<iostream>//test

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

	EffectManager::instance()->on_render(renderer);//����
}

void Player::on_update(double delta)
{
	board.on_update(delta);//����

	for (auto& ship : ship_list)
		ship->on_update(delta);

	EffectManager::instance()->on_update(delta);//����
}

void Player::on_input(const SDL_Event& event) 
{
	board.on_input(event);
	if (have_ship_in_move == true)
	{
		std::cout << "in move" << std::endl;
		current_ship->on_input(event);
		if (!current_ship->check_motion())
		{
			have_ship_in_move = false;

			if(board.check_available(current_ship->get_position()));
			{
				std::cout << "available" << std::endl;
				current_ship->set_position({ event.button.x, event.button.y });
			}

			current_ship = nullptr;
			std::cout << "stop move" << std::endl;
		}
	}

	for (auto& ship : ship_list)
	{
		ship->on_input(event);
		if (ship->check_motion())
		{
			have_ship_in_move = true;
			current_ship = ship;
		}
	}

}

