#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/Model.h"

using namespace std;

class View{
  private:
     Model &model;
     SDL_Renderer* renderer;
     SDL_Window* window;
     SDL_Rect target;
     SDL_Rect rock_1;
     SDL_Rect rock_2;
     SDL_Rect rock_3;
    SDL_Rect rock_4;
    SDL_Rect rock_5;
    SDL_Rect box;
    SDL_Rect number_1;
    SDL_Rect number_2;
    SDL_Rect number_3;
    SDL_Rect number_4;
    SDL_Rect number_5;
    SDL_Texture *sprite_0;
    SDL_Texture *sprite_1;
    SDL_Texture *sprite_2;
    SDL_Texture *sprite_3;
    SDL_Texture *sprite_4;
    SDL_Texture *sprite_5;
    SDL_Texture *sprite_6;
    SDL_Texture *sprite_7;
    SDL_Texture *sprite_8;
    SDL_Texture *sprite_9;
    SDL_Texture *sprite_10;
    SDL_Texture *sprite_11;
    SDL_Texture *sprite_12;
    SDL_Texture *sprite_13;
    SDL_Texture *sprite_14;
    SDL_Texture *background;
    
  public:
    View(Model &model);
    ~View();
    void render();
    
};
