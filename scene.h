#pragma once
class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void on_enter() = 0;
	virtual void on_update() = 0;
	virtual void on_draw() = 0;
	virtual void on_input(const ExMessage& msg) = 0;
	virtual void on_exit() = 0;

protected:

};