#include "../include/View.h"
#include "../include/Model.h"
#include "../include/Controller.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <math.h>
#include "../include/json.hpp"
#include <fstream>
using namespace std;
using nlohmann::json;

//---------------------------------------------------------------------

void Controller::overlap (float box_x, float box_y, int num){
//lado de cima do bloco (colisao)
if((this->model.get_y()>=(box_y-40.5)) && (this->model.get_y()<=box_y) && (this->model.get_x()>=(box_x-22)) && (this->model.get_x()<=(box_x+22)))
{

switch(num){

case 1:
this->model.set_coleta1(1);
break;

case 2:
this->model.set_coleta2(1);
break;

case 3:
this->model.set_coleta3(1);
break;

case 4:
this->model.set_coleta4(1);
break;

case 5:
this->model.set_coleta5(1);
break;


}

this->model.set_score((this->model.get_score()+1));

}

//lado de baixo do bloco (colisao)
if((this->model.get_y()<=(box_y+40.5)) && (this->model.get_y()>=box_y) && (this->model.get_x()>=(box_x-22)) && (this->model.get_x()<=(box_x+22)))
{
//this->model.set_x();
this->model.set_y((box_y+40.5));
}

//lateral esquerda do bloco
if((this->model.get_x()>=(box_x-40.5)) && (this->model.get_x()<=box_x) && (this->model.get_y()>=(box_y-22)) && (this->model.get_y()<=(box_y+22)))
{
//this->model.set_x();
this->model.set_x((box_x-40.5));
}

//lateral direita do bloco
if((this->model.get_x()<=(box_x+40.5)) && (this->model.get_x()>=box_x) && (this->model.get_y()>=(box_y-22)) && (this->model.get_y()<=(box_y+22)))
{
//this->model.set_x();
this->model.set_x((box_x+40.5));
}



}


void Controller::save_memorycard(){

json j;
j["x_current"]=this->model.get_x();
j["y_current"]=this->model.get_y();
j["angle"]=this->model.get_angle();
j["speed"]=this->model.get_speed();

std::ofstream f2;
f2.open("data.json");
f2<<j;
f2.close();

}

void Controller::load_memorycard(){
json j2;
std::ifstream f2;
f2.open("data.json");
f2>>j2;
f2.close();
this->model.set_x(j2["x_current"]);
this->model.set_y(j2["y_current"]);
this->model.set_angle(j2["angle"]);
this->model.set_speed(j2["speed"]);

}


//---------------------------------------------------------------------


Controller::Controller(Model &model) : model(model){
  this->on = true;
  this->state = SDL_GetKeyboardState(nullptr);
}

Controller::~Controller(){}

bool Controller::get_on(){return this->on;}

void Controller::polling(){
  // Polling de eventos
  
  SDL_PumpEvents(); // atualiza estado do teclado
  
  
  if((state[SDL_SCANCODE_UP]) && (this->model.get_speed())<(this->model.get_maxSpeed()))
  {
  if ((this->model.get_speed())<0){this->model.set_speed(this->model.get_speed()+this->model.get_dec());
  }
  else {this->model.set_speed(this->model.get_speed()+this->model.get_acc());}
  
  }
  
  if((state[SDL_SCANCODE_DOWN]) && (this->model.get_speed())>(-1)*(this->model.get_maxSpeed()))
  {
  if ((this->model.get_speed())>0){this->model.set_speed(this->model.get_speed()-this->model.get_dec());
  }
  else {this->model.set_speed(this->model.get_speed()-this->model.get_acc());}
  
  }
  //----------------------------------
  if(!(state[SDL_SCANCODE_UP]) && !((state[SDL_SCANCODE_DOWN])))
  {
  if((this->model.get_speed()-this->model.get_dec())>0){
  this->model.set_speed(this->model.get_speed()-this->model.get_dec());
  }
  else if((this->model.get_speed()+this->model.get_dec())<0){
  this->model.set_speed(this->model.get_speed()+this->model.get_dec());
  }
  else {this->model.set_speed(0);}
  
  }
  
  
//-------------------------------------

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//---------------------------------------

if((state[SDL_SCANCODE_RIGHT])&&(this->model.get_speed() !=0)){
this->model.set_angle((this->model.get_angle())+((this->model.get_turnSpeed())*((this->model.get_speed())/(this->model.get_maxSpeed()))));
}

if((state[SDL_SCANCODE_LEFT])&&(this->model.get_speed() !=0)){
this->model.set_angle((this->model.get_angle())-((this->model.get_turnSpeed())*((this->model.get_speed())/(this->model.get_maxSpeed()))));
}

this->model.set_x((this->model.get_x())+(sin(this->model.get_angle())*this->model.get_speed()));

this->model.set_y((this->model.get_y())-(cos(this->model.get_angle())*this->model.get_speed()));

if(state[SDL_SCANCODE_C]){
save_memorycard();
}

if(state[SDL_SCANCODE_L]){
load_memorycard();
}

//colisao com as bordas da arena
if(this->model.get_x()<0)
{
this->model.set_x(0);
}
if(this->model.get_y()<0)
{
this->model.set_y(0);
}
if(this->model.get_x()>640)
{
this->model.set_x(640);
}
if(this->model.get_y()>480)
{
this->model.set_y(480);
}

//--------------------------------------------------



if(this->model.get_coleta1()==0){
overlap(this->model.get_caixa1x(), this->model.get_caixa1y(), 1);}

if(this->model.get_coleta2()==0){
overlap(this->model.get_caixa2x(), this->model.get_caixa2y(), 2);}

if(this->model.get_coleta3()==0){
overlap(this->model.get_caixa3x(), this->model.get_caixa3y(), 3);}

if(this->model.get_coleta4()==0){
overlap(this->model.get_caixa4x(), this->model.get_caixa4y(), 4);}

if(this->model.get_coleta5()==0){
overlap(this->model.get_caixa5x(), this->model.get_caixa5y(), 5);}



//---------------------------------------

  while (SDL_PollEvent(&(this->event))) {
    if (this->event.type == SDL_QUIT) {
      this->on = false;
    }
  }
}

//----------------------------------------




//----------------------------------------
