#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <math.h>

#include "../include/func.h"
//#include "View.h"
//#include "Model.h"
//#include "Controller.h"

class Model {
  private:
    float x_current=0;
    float y_current=0;
    float angle=0;
    float speed=0;
    float maxSpeed=12;
    float acc=0.2;
    float dec=0.3;
    float turnSpeed=0.08;
    float caixa1x= 380;
    float caixa1y= 200;
    int coleta1=0;
    int score=0;
    float caixa2x= 90;
    float caixa2y= 150;
    int coleta2=0;
    float caixa3x= 400;
    float caixa3y= 300;
    int coleta3=0;
    int coleta4=0;
    int coleta5=0;
    float caixa4x= 500;
    float caixa4y= 100;
    float caixa5x= 60;
    float caixa5y= 380;
    
    
  public:
    Model();
    ~Model();
    float get_x();
    void set_x(float new_x);
    float get_y();
    void set_y(float new_y);
    float get_angle();
    void set_angle(float new_angle);
    float get_speed();
    void set_speed(float new_speed);
    float get_maxSpeed();
    float get_turnSpeed();
    float get_acc();
    float get_dec();
    float get_caixa1x();
    float get_caixa1y();
    float get_caixa2x();
    float get_caixa2y();
    float get_caixa3x();
    float get_caixa3y();
    int get_coleta1();
    void set_coleta1(int new_coleta1);
    int get_score();
    void set_score(int new_score);
    int get_coleta2();
    void set_coleta2(int new_coleta2);
    int get_coleta3();
    void set_coleta3(int new_coleta3);
    int get_coleta4();
    int get_coleta5();
    void set_coleta4(int new_coleta4);
    void set_coleta5(int new_coleta5);
    float get_caixa4x();
    float get_caixa4y();
    float get_caixa5x();
    float get_caixa5y();
    
    
    
    
};

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
//view
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

View::View(Model &model) : model(model){
  // Inicializando o subsistema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
  }

  // Criando uma janela
  this->window = nullptr;
  this->window = SDL_CreateWindow("Demonstrção de jogo com SDL2",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
  if (this->window==nullptr) { // Em caso de erro...
    std::cout << SDL_GetError();
    SDL_Quit();
  }

  // Inicializando o renderizador
  this->renderer = SDL_CreateRenderer(
      this->window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (this->renderer==nullptr) { // Em caso de erro...
    SDL_DestroyWindow(this->window);
    std::cout << SDL_GetError();
    SDL_Quit();
  }

  // Carregando texturas
  // personagem
  this->sprite_0 = IMG_LoadTexture(renderer, "../assets/car.png");
  // fundo
  this->background = IMG_LoadTexture(renderer, "../assets/arena.png");
  //pedra 1
  this->sprite_1 = IMG_LoadTexture(renderer, "../assets/rock.png");
  //numero 1
  this->sprite_2 = IMG_LoadTexture(renderer, "../assets/1.png");
  //pedra 2
  this->sprite_3 = IMG_LoadTexture(renderer, "../assets/rock.png");
  //numero 2
  this->sprite_4 = IMG_LoadTexture(renderer, "../assets/2.png");
  //pedra 3
  this->sprite_5 = IMG_LoadTexture(renderer, "../assets/rock.png");
  //numero 3
  this->sprite_6 = IMG_LoadTexture(renderer, "../assets/3.png");
  //pedra 4
  this->sprite_7 = IMG_LoadTexture(renderer, "../assets/rock.png");
  //numero 4
  this->sprite_8 = IMG_LoadTexture(renderer, "../assets/4.png");
  //pedra 5
  this->sprite_9 = IMG_LoadTexture(renderer, "../assets/rock.png");
  //numero 5
  this->sprite_10 = IMG_LoadTexture(renderer, "../assets/5.png");
  
  
  
  // Quadrado onde a textura sera desenhada
  this->target.x = model.get_x();
  this->target.y = model.get_y();
  this->rock_1.x= 380;
  this->rock_1.y=200;
  this->number_1.x=590;
  this->number_1.y=430;
  this->number_2.x=590;
  this->number_2.y=430;
  this->number_3.x=590;
  this->number_3.y=430;
  this->number_4.x=590;
  this->number_4.y=430;
  this->number_5.x=590;
  this->number_5.y=430;
  this->rock_2.x= 90;
  this->rock_2.y=150;
  this->rock_3.x= 400;
  this->rock_3.y=300;
  this->rock_4.x= 500;
  this->rock_4.y=100;
  this->rock_5.x= 60;
  this->rock_5.y=380;
  
  SDL_QueryTexture(this->sprite_0, nullptr, nullptr, &(this->target.w), &(this->target.h));
  SDL_QueryTexture(this->sprite_1, nullptr, nullptr, &(this->rock_1.w), &(this->rock_1.h));
  SDL_QueryTexture(this->sprite_2, nullptr, nullptr, &(this->number_1.w), &(this->number_1.h));
  SDL_QueryTexture(this->sprite_3, nullptr, nullptr, &(this->rock_2.w), &(this->rock_2.h));
  SDL_QueryTexture(this->sprite_4, nullptr, nullptr, &(this->number_2.w), &(this->number_2.h));
    SDL_QueryTexture(this->sprite_5, nullptr, nullptr, &(this->rock_3.w), &(this->rock_3.h));
  SDL_QueryTexture(this->sprite_6, nullptr, nullptr, &(this->number_3.w), &(this->number_3.h));
   SDL_QueryTexture(this->sprite_7, nullptr, nullptr, &(this->rock_4.w), &(this->rock_4.h));
  SDL_QueryTexture(this->sprite_8, nullptr, nullptr, &(this->number_4.w), &(this->number_4.h));
   SDL_QueryTexture(this->sprite_9, nullptr, nullptr, &(this->rock_5.w), &(this->rock_5.h));
  SDL_QueryTexture(this->sprite_10, nullptr, nullptr, &(this->number_5.w), &(this->number_5.h));
  
  

}

View::~View(){
  SDL_DestroyTexture(this->sprite_0);
  SDL_DestroyTexture(this->background);
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}

void View::render(){
  this->target.x = model.get_x();
  this->target.y = model.get_y();
 
  //desenhar cena
  SDL_RenderClear(this->renderer);
  SDL_RenderCopy(this->renderer, this->background, nullptr, nullptr);
  if(this->model.get_coleta1()==0){
  SDL_RenderCopy(this->renderer, this->sprite_1, nullptr, &(this->rock_1));
  }
  if(this->model.get_coleta2()==0){
  SDL_RenderCopy(this->renderer, this->sprite_3, nullptr, &(this->rock_2));
  }
  if(this->model.get_coleta3()==0){
  SDL_RenderCopy(this->renderer, this->sprite_5, nullptr, &(this->rock_3));
  }
  if(this->model.get_coleta4()==0){
  SDL_RenderCopy(this->renderer, this->sprite_7, nullptr, &(this->rock_4));
  }
  if(this->model.get_coleta5()==0){
  SDL_RenderCopy(this->renderer, this->sprite_9, nullptr, &(this->rock_5));
  }
  if(this->model.get_score()==1){
  SDL_RenderCopy(this->renderer, this->sprite_2, nullptr, &(this->number_1));
  }
  if(this->model.get_score()==2){
  SDL_RenderCopy(this->renderer, this->sprite_4, nullptr, &(this->number_2));
  }
  if(this->model.get_score()==3){
  SDL_RenderCopy(this->renderer, this->sprite_6, nullptr, &(this->number_3));
  }
  if(this->model.get_score()==4){
  SDL_RenderCopy(this->renderer, this->sprite_8, nullptr, &(this->number_4));
  }
  if(this->model.get_score()==5){
  SDL_RenderCopy(this->renderer, this->sprite_10, nullptr, &(this->number_5));
  }
  
  
  SDL_RenderCopyEx(this->renderer, this->sprite_0, nullptr, &(this->target), this->model.get_angle()*(180/3.141592), NULL, SDL_FLIP_NONE);
  SDL_RenderPresent(this->renderer);
  // Delay para diminuir o framerate
  SDL_Delay(10);

}

class Controller{
  private:
    bool on;
    SDL_Event event;
    Model &model;
    const Uint8* state;
  public:
    Controller(Model &model);
    ~Controller();
    void polling();
    bool get_on();
    void overlap(float box_x, float box_y, int num);
};

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

if(state[SDL_SCANCODE_R]){
this->model.set_x(250);
this->model.set_y(250);
this->model.set_coleta1(0);
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

int main() {
  Model model = Model();
  View view = View(model);
  Controller controller = Controller(model);

  while(controller.get_on()) {
    controller.polling();
    view.render();
  }

  model.~Model();
  view.~View();
  controller.~Controller();

  return 0;
}
