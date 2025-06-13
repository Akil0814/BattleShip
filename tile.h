#pragma once
#define SIZE_TILE 50
#include<SDL.h>

class Tile {
public:
    enum class Status { Unknown, Miss, Hit, SomeThing };

    Tile() = default;

    Status getStatus() const
    {
        return status;
    }

    void change_status(Status status)
    {
        this->status = status;
    }

    bool hasShip()const
    {
        return have_ship;

    }

    void placeShip()
    {
        have_ship = true;
        status = Status::Unknown;
    }

    void markMiss()
    {
        if (status == Status::Unknown)
            status = Status::Miss;
    }

    void markHit()
    {
        if (status == Status::Unknown && have_ship)
            status = Status::Hit;
    }

    SDL_Rect* get_rect()
    {
        return &tile_rect;
    }

private:
    SDL_Rect tile_rect = { 0,0,50,50 };

    Status status = Status::Unknown;
    bool   have_ship = false;
};