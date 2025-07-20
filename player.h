#pragma once
#include<vector>
#include"board.h"
#include"ship.h"

class Player
{
public:
	Player();
	~Player();

	void on_render(SDL_Renderer* renderer);
	void on_update(double delta);
	virtual void on_input(const SDL_Event& event);

private:

	bool is_win = false;
	bool have_ship_in_move = false;


	Ship* current_ship = nullptr;
	SDL_Point current_ship_last_pos = {0,0};
	std::vector<Ship*> ship_list;
	Board board;
};

