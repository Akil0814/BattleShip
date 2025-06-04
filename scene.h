#pragma once

#include <SDL.h>

class Scene
{
public:
        Scene() = default;
        virtual ~Scene() = default;

	virtual void on_enter() = 0;
	virtual void on_update() = 0;
        virtual void on_draw() = 0;
        // Use SDL_Event instead of the undefined ExMessage type
        virtual void on_input(const SDL_Event& event) = 0;
        virtual void on_exit() = 0;

protected:

};
