#pragma once
#include<vector>
#include"ship.h"

class Player
{
public:
	Player();
	~Player();

private:

	double money = 0;
	int num_of_missile = 0;
	bool is_win = false;
	std::vector<Ship*> ship_list;
};

