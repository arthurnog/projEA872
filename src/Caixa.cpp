#include "../include/Caixa.h"
#include "../include/json.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <math.h>

Caixa::Caixa(){
    this->x = rand() % 540 + 40;
    this->y = rand() % 380 + 40;
}

Caixa::~Caixa(){}

float Caixa::get_x(){return this->x;}
float Caixa::get_y(){return this->y;}
bool Caixa::get_took(){return this->took;}
void Caixa::set_took(){this->took = !this->took;}
void Caixa::set_pos(){
    this->x = rand() % 540 + 40;
    this->y = rand() % 380 + 40;
}