#include"board.h"

SDL_Texture* Board::tile_hit = nullptr;
SDL_Texture* Board::tile_miss = nullptr;
SDL_Texture* Board::tile_unknown = nullptr;

Board::Board()
{
	tile_hit = ResourcesManager::instance()->get_texture(ResID::Tex_Tile_hit);
	tile_miss = ResourcesManager::instance()->get_texture(ResID::Tex_Tile_miss);
	tile_unknown = ResourcesManager::instance()->get_texture(ResID::Tex_Tile_unknow);

	board.assign(row, std::vector<Tile>(col));

	EffectManager::instance()->set_on_finished(EffectID::SelectTarget, [this]()
		{
			find_target = true;
		});

	EffectManager::instance()->set_on_finished(EffectID::WaterSplash_single, [this]()
		{
			on_animation = false;
			board[index_x][index_y].change_status(Tile::Status::Miss);
		});

	EffectManager::instance()->set_on_finished(EffectID::Explosion, [this]()
		{
			on_animation = false;
			board[index_x][index_y].change_status(Tile::Status::Hit);
		});
}

Board::~Board()
{

}

void Board::on_render(SDL_Renderer* renderer)
{
	draw_board(renderer);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			SDL_Rect rect = { i * SIZE_TILE,j * SIZE_TILE,SIZE_TILE,SIZE_TILE };

			switch (board[i][j].get_status())
			{
			case Tile::Status::Miss:
				SDL_RenderCopy(renderer, tile_miss, nullptr, &rect);
				break;
			case Tile::Status::Hit:
				SDL_RenderCopy(renderer, tile_hit, nullptr, &rect);
				break;
			case Tile::Status::SomeThing:
				SDL_RenderCopy(renderer, tile_unknown, nullptr, &rect);
				break;
			default:
				break;
			}
		}
	}


	if (find_target)

	if (move_in_board)
	{
		SDL_Rect target_rect = { mouse_pos.x-15,mouse_pos.y-15,30,30 };

	}

}

void Board::on_update(double delta)
{
	if (find_target)
	{
			find_target = false;

			if (board[index_x][index_y].has_ship())
			{
				EffectManager::instance()->show_effect(EffectID::Explosion, rect_explosion_target, 0);
			}
			else
			{
				EffectManager::instance()->show_effect(EffectID::WaterSplash_single, rect_water_splash, 0);
			}
	}
}

void Board::on_input(const SDL_Event& event)
{
	on_mouse_move(event);

	if (on_animation)
		return;
	on_mouse_click(event);
}

void Board::set_size(int row, int col)
{
	this->row = row;
	this->col = col;
	board.assign(row, std::vector<Tile>(col));
}

void Board::set_board_pos(SDL_Point point)
{
	board_render_x = point.x;
	board_render_y = point.y;
}

void Board::on_mouse_move(const SDL_Event& event)
{
	if (is_inside(event.motion.x, event.motion.y))
	{
		move_in_board = true;
		mouse_pos.x = event.motion.x;
		mouse_pos.y = event.motion.y;
	}
	else
		move_in_board = false;
}

void Board::on_mouse_click(const SDL_Event& event)
{
	if (is_inside(event.button.x, event.button.y))
	{
		click_in_board = true;

		if (event.type == SDL_MOUSEBUTTONUP)
		{

			mouse_click_pos.x = event.button.x;
			mouse_click_pos.y = event.button.y;

			if (event.button.button == SDL_BUTTON_LEFT)
			{
				index_x = (mouse_click_pos.x- board_render_x)/SIZE_TILE;
				index_y = (mouse_click_pos.y- board_render_y)/SIZE_TILE;

				mouse_click_tile_center.x = board_render_x + index_x * SIZE_TILE + SIZE_TILE / 2;
				mouse_click_tile_center.y = board_render_y + index_y * SIZE_TILE + SIZE_TILE / 2;

				if (board[index_x][index_y].get_status() == Tile::Status::Unknown ||
					board[index_x][index_y].get_status() == Tile::Status::SomeThing)//确定棋盘格状态
				{
					rect_select_target = { board_render_x + index_x * SIZE_TILE - 20,board_render_y + index_y * SIZE_TILE - 20,SIZE_TILE + 40,SIZE_TILE + 40};//计算特效位置
					rect_water_splash = { board_render_x + index_x * SIZE_TILE - 20,board_render_y + index_y * SIZE_TILE,SIZE_TILE + 40,SIZE_TILE };

					rect_explosion_target = { board_render_x + index_x * SIZE_TILE - 20,board_render_y + index_y * SIZE_TILE - 40 , SIZE_TILE + 40,SIZE_TILE + 40 };
					EffectManager::instance()->show_effect(EffectID::SelectTarget, rect_select_target, 0);//向特效管理器提交选中特效

					//on_animation = true;//进入播放动画
				}
			}
		}
	}
	else
	{
		click_in_board = false;
		SDL_ShowCursor(SDL_ENABLE);
	}
}


bool Board::is_inside(int x, int y) const
{
	return x >= board_render_x
		&& x < board_render_x + SIZE_TILE * col
		&& y >= board_render_y
		&& y < board_render_y + SIZE_TILE * row;
}

void  Board::draw_board(SDL_Renderer* renderer)
{
	//深海蓝的棋盘背景矩形
	SDL_Rect board_rect{ board_render_x, board_render_y, col * SIZE_TILE, row * SIZE_TILE };
	SDL_SetRenderDrawColor(renderer, 30, 63, 102, 255);
	SDL_RenderFillRect(renderer, &board_rect);

	//半透明网格线
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 10, 55, 50, 120);

	// 竖线
	for (int i = 0; i <= col; ++i) {
		int x = board_render_x + i * SIZE_TILE;
		SDL_RenderDrawLine(renderer, x, board_render_y, x, board_render_y + row * SIZE_TILE);
	}

	// 横线
	for (int j = 0; j <= row; ++j) {
		int y = board_render_y + j * SIZE_TILE;
		SDL_RenderDrawLine(renderer, board_render_x, y, board_render_x + col * SIZE_TILE, y);
	}
}

bool Board::check_available(SDL_Point pos,int ship_size,bool is_horizontal)
{
	SDL_Point index;
	index.x = (pos.x- board_render_x)/50;
	index.y = (pos.y- board_render_y)/50;

	if (!board[index.x][index.y].has_ship())
	{
		if (is_horizontal)
		{
			for (int i = 1; i < ship_size; i++)
			{
				if (index.x + i <= col)
				{
					if (board[index.x + i][index.y].has_ship())
						return false;
				}
				else
					return false;
			}
		}
		else
		{
			for (int i = 1; i < ship_size; i++)
			{
				if (index.y + i <= row)
				{
					if (board[index.x][index.y+i].has_ship())
						return false;
				}
				else
					return false;
			}

		}
		return true;
	}

	return false;
}
