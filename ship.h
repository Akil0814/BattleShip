#pragma once
#include<SDL.h>

class Ship
{
public:
	enum class ShipType
	{
		Destroyer_MNF_Mogador,//ÇýÖð½¢

		LightCruiser_HMS_Belfast,//ÇáÑ²Ñó½¢
		HeavyCruiser_Prinz_Eugen,//ÖØÑ²Ñó½¢
		SuperHeavyCruiser_IJN_Azuma,//³¬¼¶Ñ²Ñó½¢

		BattleCruiserHMS_Hood,//Õ½ÁÐÑ²Ñó½¢
		BattleshipUSS_New_Jersey,//Õ½ÁÐ½¢

		AviationBattleship_USS_Kearsarge,//º½¿ÕÕ½ÁÐ½¢

		AircraftCarrier_USS_Enterprise,//º½¿ÕÄ¸½¢
		LightAircraftCarrier_HMS_Theseus,//ÇáÐÍº½¿ÕÄ¸½¢

		Submarine_RN_Maggiore_Baracca,//Ç±Í§
		RepairShip_USS_Vestal//Î¬ÐÞ

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