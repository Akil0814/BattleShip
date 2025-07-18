#include"setup_scene.h"
SetupScene::SetupScene()
	:next_button({800,500,100,50}, { 800,500,100,50 },
	TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(), ResourcesManager::instance()->get_font(ResID::Font_72), "NEXT"),
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
		if (current_player == p1)
			next_player();
		else
			GameManager::instance()->switch_scene(SceneType::PVE);
		});
}
void SetupScene::on_exit()
{

}

void SetupScene::on_update(double delta)
{
	current_player->on_update_for_setup(delta);
}
void SetupScene::on_render(SDL_Renderer* renderer)
{
	next_button.on_render(renderer);
	current_player->on_render_for_setup(renderer);

}
void SetupScene::on_input(const SDL_Event& event)
{
	next_button.on_input(event);
	current_player->on_input_for_setup(event);
}

void SetupScene::next_player()
{
	current_player == p1 ? current_player = p2 : current_player = p1;
}