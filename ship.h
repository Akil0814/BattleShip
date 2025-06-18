#pragma once
#include<SDL.h>
#include"effect_manager.h"

class Ship
{
public:
	enum class ShipType
	{
		Destroyer_MNF_Mogador,//����  hp 2  

		LightCruiser_HMS_Belfast,//��Ѳ�� 3
		HeavyCruiser_Prinz_Eugen,//��Ѳ�� 3
		SuperHeavyCruiser_IJN_Azuma,//����Ѳ��  4

		BattleCruiserHMS_Hood,//ս��Ѳ�� 4
		BattleshipUSS_New_Jersey,//ս�н�  4  

		AviationBattleship_USS_Kearsarge,//����ս�н� ///5

		AircraftCarrier_USS_Enterprise,//����ĸ��   //5
		LightAircraftCarrier_HMS_Theseus,//���ͺ���ĸ��

		Submarine_RN_Maggiore_Baracca,//Ǳͧ //3
		RepairShip_USS_Vestal//ά�� //3

	};


public:
	Ship()=default;
	~Ship() = default;

	void on_update(double delta);
	void on_render(SDL_Renderer* renderer);
	void on_input(const SDL_Event& event);
	void init_ship(SDL_Texture* texture, int size, SDL_Point first_pos);


	void set_position(const SDL_Point&);
	void set_index(const SDL_Point&);

	void get_hit(const int damage);
	void rotate_ship();

	int get_ship_size()const;
	bool is_horizontal()const;
	bool is_sink()const;
	int get_num_of_missile()const;
	const SDL_Point& get_position()const;
	const SDL_Point& get_index()const;

	bool finish_moveing()const;
	bool check_cursor_hit(int x, int y)const;

private:

	SDL_Texture* ship_texture = nullptr;

	SDL_Point absolute_position;
	SDL_Point index_position;
	SDL_Rect ship_rect;

	int dx = 0;
	int dy = 0;

	int hp = 0;
	int ship_size = 0;
	int missile = 1;
	bool sink=false;
	bool horizontal = true;
	bool have_skill = false;
	bool ship_in_move = false;
};