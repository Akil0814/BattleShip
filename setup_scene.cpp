#include"setup_scene.h"
SetupScene::SetupScene()
	:next_button({800,500,100,50}, { 815,505,70,40 },
	TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(), ResourcesManager::instance()->get_font(ResID::Font_48), "NEXT"),
	nullptr, nullptr),
	start_button({ 800,500,100,50 }, { 815,505,70,40 },
		TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(), ResourcesManager::instance()->get_font(ResID::Font_48), "START"),
		nullptr, nullptr)
{
}

SetupScene::~SetupScene()
{
}

void SetupScene::on_enter()
{
	WINDOW_WIDTH = 1000;
	WINDOW_HEIGHT = 560;
	SDL_SetWindowSize(GameManager::instance()->get_window(), WINDOW_WIDTH, WINDOW_HEIGHT);
	p1 = GameManager::instance()->get_player1();
	p2 = GameManager::instance()->get_player2();
	current_player = p1;

	next_button.set_on_click([&] {
			next_player();
		});

	start_button.set_on_click([&]
		{
			if(auto* pt=dynamic_cast<HumanPlayer*>(p2))
				GameManager::instance()->switch_scene(SceneType::PVP);
			else
				GameManager::instance()->switch_scene(SceneType::PVE);
		});
}

void SetupScene::on_exit()
{

}

void SetupScene::on_update(double delta)
{
	current_player->on_update(delta,true);
}
void SetupScene::on_render(SDL_Renderer* renderer)
{
	start_button.on_render(renderer);
	if (auto* pt = dynamic_cast<HumanPlayer*>(p2))
	{
		if (current_player == p1)
			next_button.on_render(renderer);
	}

	current_player->on_render(renderer,true);

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

}
void SetupScene::on_input(const SDL_Event& event)
{
	if (auto* pt = dynamic_cast<HumanPlayer*>(p2))
	{
		if (current_player == p1)
			next_button.on_input(event);
		else
			start_button.on_input(event);
	}
	
	if (auto* pt = dynamic_cast<ComputerPlayer*>(p2))
		start_button.on_input(event);

	current_player->on_input(event,true);
}

void SetupScene::next_player()
{
	current_player == p1 ? current_player = p2 : current_player = p1;
}