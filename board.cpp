#include"board.h"

SDL_Texture* Board::tile = nullptr;
SDL_Texture* Board::tile_hit = nullptr;
SDL_Texture* Board::tile_miss = nullptr;
SDL_Texture* Board::tile_unknown = nullptr;

Board::Board()
{
	set_target = ResourcesManager::instance()->get_texture(ResID::Tex_SetTarget);

	tile_hit = ResourcesManager::instance()->get_texture(ResID::Tex_Tile_hit);
	tile_miss = ResourcesManager::instance()->get_texture(ResID::Tex_Tile_miss);
	tile_unknown = ResourcesManager::instance()->get_texture(ResID::Tex_Tile_unknow);

	board.assign(row, std::vector<Tile>(col));

	get_target.set_frame(AtlasManager::instance()->get_atlas(AtlasID::GetTarget));
	get_target.set_interval(0.15);
	get_target.set_loop(false);
	get_target.set_on_finished([=]
		{
			on_animation = false;//
			find_target = true;
		});

	missile.set_frame(AtlasManager::instance()->get_atlas(AtlasID::Missile));
	missile.set_interval(0.1);
	missile.set_loop(true);
	missile.set_on_finished([=]
		{
			try_hit = false;
		});


	miss_target_effect.set_frame(AtlasManager::instance()->get_atlas(AtlasID::MissingTarget));
	miss_target_effect.set_interval(0.1);
	miss_target_effect.set_loop(false);
	miss_target_effect.set_on_finished([=]
		{
			try_hit_and_miss = false;
			miss_target_effect.reset();
		});

	explosion.set_frame(AtlasManager::instance()->get_atlas(AtlasID::ExplosionBig));
	explosion.set_interval(0.1);
	explosion.set_loop(false);
	explosion.set_on_finished([=]
		{
		});

	explosion_twice.set_frame(AtlasManager::instance()->get_atlas(AtlasID::Explosion));
	explosion_twice.set_interval(0.1);
	explosion_twice.set_loop(false);
	explosion_twice.set_on_finished([=]
		{
		});

}

Board::~Board()
{

}


void Board::on_render(SDL_Renderer* renderer)const
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


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			SDL_Rect rect = { j * SIZE_TILE,i * SIZE_TILE,SIZE_TILE,SIZE_TILE };

			switch (board[i][j].getStatus())
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


	SDL_Rect rect = { index_x * SIZE_TILE, index_y * SIZE_TILE,SIZE_TILE,SIZE_TILE };
	if (try_hit_and_miss)
		miss_target_effect.on_render(renderer, rect, 0);

	if (try_hit)
	{
		rect = { index_x * SIZE_TILE - 20,index_y * SIZE_TILE - 20,SIZE_TILE + 40,SIZE_TILE + 40 };
		get_target.on_render(renderer, rect, 0);
	}

	if (get_hit)
		explosion.on_render(renderer, rect, 0);

	if (move_in_board)
	{
		SDL_Rect target_rect = { mouse_pos.x-15,mouse_pos.y-15,30,30 };

		SDL_RenderCopy(renderer, set_target, nullptr, &target_rect);
	}

}

void Board::on_update(double delta)
{
	missile.on_update(delta);
	miss_target_effect.on_update(delta);
	explosion_twice.on_update(delta);
	get_target.on_update(delta);
	explosion.on_update(delta);
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
				index_y = (mouse_click_pos.y- board_render_x)/SIZE_TILE;

				if (board[index_x][index_y].getStatus() == Tile::Status::Unknown ||
					board[index_x][index_y].getStatus() == Tile::Status::SomeThing)
				{
					get_target.reset();
					try_hit = true;
					on_animation = true;
				}
			}
		}
		else
		{
			//sound effect

		}
	}
	else
	{
		click_in_board = false;

	}


}

bool Board::is_inside(int x, int y) const
{
	return x >= board_render_x
		&& x < board_render_x + SIZE_TILE * col
		&& y >= board_render_y
		&& y < board_render_y + SIZE_TILE * row;
}
