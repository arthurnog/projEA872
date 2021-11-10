#include "../include/Model.h"
#include "../include/Carro.h"
#include "../include/json.hpp"
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <math.h>
using namespace std;

Carro::Carro(){
    this->x_current = rand() % 540 + 40;
    this->y_current = rand() % 380 + 40;
}

Carro::~Carro(){}

float Carro::get_x(){return this->x_current;}
void Carro::set_x(float new_x){this->x_current=new_x;}
float Carro::get_y(){return this->y_current;}
void Carro::set_y(float new_y){this->y_current=new_y;}
float Carro::get_angle(){return this->angle;}
void Carro::set_angle(float new_angle){this->angle=new_angle;}
float Carro::get_speed(){return this->speed;}
void Carro::set_speed(float new_speed){this->speed=new_speed;}
float Carro::get_maxSpeed(){return this->maxSpeed;}
float Carro::get_turnSpeed(){return this->turnSpeed;}
float Carro::get_acc(){return this->acc;}
float Carro::get_dec(){return this->dec;}