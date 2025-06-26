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
	void on_input(const SDL_Event& event);

	void on_render_for_setup(SDL_Renderer* renderer);
	void on_update_for_setup(double delta);
	void on_input_for_setup(const SDL_Event& event);

private:

	double money = 0;
	int num_of_missile = 0;
	bool is_win = false;
	std::vector<Ship*> ship_list;
	Board board;
};

