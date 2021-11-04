#include "../include/Model.h"
#include "../include/Caixa.h"
#include "../include/json.hpp"
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <math.h>
using namespace std;

Model::Model() {
  this->x_current = 250.0;
  this->y_current = 250.0;
}

Model::~Model(){}

float Model::get_x(){return this->x_current;}
void Model::set_x(float new_x){this->x_current=new_x;}
float Model::get_y(){return this->y_current;}
void Model::set_y(float new_y){this->y_current=new_y;}
float Model::get_angle(){return this->angle;;}
void Model::set_angle(float new_angle){this->angle=new_angle;}
float Model::get_speed(){return this->speed;}
void Model::set_speed(float new_speed){this->speed=new_speed;}
float Model::get_maxSpeed(){return this->maxSpeed;}
float Model::get_turnSpeed(){return this->turnSpeed;}
float Model::get_acc(){return this->acc;}
float Model::get_dec(){return this->dec;}
float Model::get_box_x(){return this->caixa.get_x();}
float Model::get_box_y(){return this->caixa.get_y();}
void Model::set_box_pos(){this->caixa.set_pos();}
float Model::get_caixa1x(){return this->caixa1x;}
float Model::get_caixa1y(){return this->caixa1y;}
float Model::get_caixa2x(){return this->caixa2x;}
float Model::get_caixa2y(){return this->caixa2y;}
float Model::get_caixa3x(){return this->caixa3x;}
float Model::get_caixa3y(){return this->caixa3y;}
int Model::get_coleta1(){return this->coleta1;}
void Model::set_coleta1(int new_coleta1){this->coleta1=new_coleta1;}
int Model::get_coleta2(){return this->coleta2;}
void Model::set_coleta2(int new_coleta2){this->coleta2=new_coleta2;}
int Model::get_coleta3(){return this->coleta3;}
void Model::set_coleta3(int new_coleta3){this->coleta3=new_coleta3;}
int Model::get_coleta4(){return this->coleta4;}
void Model::set_coleta4(int new_coleta4){this->coleta4=new_coleta4;}
int Model::get_coleta5(){return this->coleta5;}
void Model::set_coleta5(int new_coleta5){this->coleta5=new_coleta5;}
int Model::get_score(){return this->score;}
void Model::set_score(int new_score){this->score=new_score;}
float Model::get_caixa4x(){return this->caixa4x;}
float Model::get_caixa4y(){return this->caixa4y;}
float Model::get_caixa5x(){return this->caixa5x;}
float Model::get_caixa5y(){return this->caixa5y;}
