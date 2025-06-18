#pragma once
#include<vector>
#include <SDL.h>

#include"ship.h"

#include"tile.h"
#include"bullet.h"
#include"animation.h"
#include"resources_manager.h"
#include"effect_manager.h"

class Board
{
	typedef std::vector<std::vector<Tile>> TileBoard;

public:
	Board();
	~Board();


	void on_render(SDL_Renderer* renderer);
	void on_update(double delta);
	void on_input(const SDL_Event& event);

	void on_render_for_setup(SDL_Renderer* renderer);
	void on_update_for_setup(double delta);
	void on_input_for_setup(const SDL_Event& event);

	void set_size(int row, int col);
	void set_board_pos(SDL_Point point);

	static SDL_Texture* tile_hit;
	static SDL_Texture* tile_miss;
	static SDL_Texture* tile_unknown;

private:

	void draw_board(SDL_Renderer* renderer);
	void on_mouse_click(const SDL_Event& e);
	void on_mouse_move(const SDL_Event& e);
	bool is_inside(int x, int y) const;

private:

	Ship test_ship;

	bool on_animation = false;

	bool move_in_board = false;
	bool click_in_board = false;

	bool try_hit = false;

	bool find_target = false;
	bool hit_settlement = false;

	int board_render_x = 0;
	int board_render_y = 0;

	int index_x = 0;
	int index_y = 0;

	int row = 10;
	int col = 10;

	Bullet* missile;

	TileBoard board;

	SDL_Texture* set_target=nullptr;

	SDL_Point mouse_pos = {0};
	SDL_Point mouse_click_pos = { 0 };
	SDL_Point mouse_click_tile_center = {0};

	SDL_Rect current_rect;
	SDL_Rect rect_select_target;
	SDL_Rect rect_water_splash;
	SDL_Rect rect_explosion_target;

};
