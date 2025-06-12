#pragma once
#include<SDL.h>

class Ship
{
public:
	enum class ShipType
	{
		Destroyer_MNF_Mogador,//����

		LightCruiser_HMS_Belfast,//��Ѳ��
		HeavyCruiser_Prinz_Eugen,//��Ѳ��
		SuperHeavyCruiser_IJN_Azuma,//����Ѳ��

		BattleCruiserHMS_Hood,//ս��Ѳ��
		BattleshipUSS_New_Jersey,//ս�н�

		AviationBattleship_USS_Kearsarge,//����ս�н�

		AircraftCarrier_USS_Enterprise,//����ĸ��
		LightAircraftCarrier_HMS_Theseus,//���ͺ���ĸ��

		Submarine_RN_Maggiore_Baracca,//Ǳͧ
		RepairShip_USS_Vestal//ά��

	};


public:
	Ship()=default;
	virtual ~Ship() = 0;

	virtual void on_update(double delta) = 0;
	virtual void on_render(SDL_Renderer* renderer) = 0;

	void get_ship_size();
	bool check_is_sink();
	void get_num_of_missile();

private:
	int missile = 0;
	bool is_sink=false;
	int ship_size = 0;
};