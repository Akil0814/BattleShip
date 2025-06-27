#include"classic_setup_scene.h"
ClassicSetupScene::ClassicSetupScene()
	:next_button(GameManager::instance()->get_renderer(), {800,500,100,50}, { 800,500,100,50 },
	TxtTextureManager::instance()->get_txt_texture(GameManager::instance()->get_renderer(), ResourcesManager::instance()->get_font(ResID::Font_72), "NEXT"),
	nullptr, nullptr)
{
}

ClassicSetupScene::~ClassicSetupScene()
{
}

void ClassicSetupScene::on_enter()
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
			GameManager::instance()->switch_scene(SceneType::ClassicPVE);
		});
}
void ClassicSetupScene::on_exit()
{

}

void ClassicSetupScene::on_update(double delta)
{
	current_player->on_update_for_setup(delta);
}
void ClassicSetupScene::on_render(SDL_Renderer* renderer)
{
	next_button.on_render();
	current_player->on_render_for_setup(renderer);

}
void ClassicSetupScene::on_input(const SDL_Event& event)
{
	next_button.process_event(event);
	current_player->on_input_for_setup(event);
}

void ClassicSetupScene::next_player()
{
	current_player == p1 ? current_player = p2 : current_player = p1;
}