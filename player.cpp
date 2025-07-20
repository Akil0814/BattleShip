#include"player.h"

#include<iostream>//test
/*
 1.旋转可用性检测bug
 2.在移动时对船只进行旋转的状态退回异常->限制一次输入中只能进行一种行为
*/

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

	if (have_ship_in_move == true)
	{
		current_ship->on_input(event);
		if (!current_ship->check_motion())
		{
			have_ship_in_move = false;

			SDL_Point p = board.place_ship(current_ship->get_position(), current_ship->get_ship_size(), current_ship->is_horizontal());
			if (p.x != -1)
			{
				current_ship->set_position(p);
				std::cout << "put" << std::endl;
			}
			else
			{
				current_ship->set_position(current_ship_last_pos);
				board.place_ship(current_ship_last_pos, current_ship->get_ship_size(), current_ship->is_horizontal());
			}
			current_ship = nullptr;
			std::cout << "stop move" << std::endl;
		}

	}
	else 
	{
		for (auto& ship : ship_list)
		{
			ship->on_input(event);
			if (ship->check_motion())
			{
				std::cout << "start move" << std::endl;
				have_ship_in_move = true;
				current_ship = ship;
				current_ship_last_pos = current_ship->get_position();
				board.move_ship(current_ship_last_pos, current_ship->get_ship_size(), current_ship->is_horizontal());

			}
			if (ship->check_rotate())
			{
				current_ship = ship;
				current_ship_last_pos = current_ship->get_position();
				board.move_ship(current_ship_last_pos, current_ship->get_ship_size(), !current_ship->is_horizontal());

				SDL_Point p = board.place_ship(current_ship->get_position(), current_ship->get_ship_size(), current_ship->is_horizontal());
				if (p.x != -1)
				{
					current_ship->set_position(p);
					std::cout << "R put" << std::endl;
				}
				else
				{
					current_ship->rotate_ship();
					current_ship->set_position(current_ship_last_pos);
					board.place_ship(current_ship_last_pos, current_ship->get_ship_size(), current_ship->is_horizontal());
				}

				std::cout << "rotated YYY" << std::endl;
			}
		}
	}
}
