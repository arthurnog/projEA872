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


class View{
  private:
    Model &model;
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Rect target;
    SDL_Rect rock_1;
    SDL_Texture *sprite_0;
    SDL_Texture *sprite_1;
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
  this->window = SDL_CreateWindow("Demonstracao do SDL2",
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
  //pedra
  this->sprite_1 = IMG_LoadTexture(renderer, "../assets/rock.png");


  // Quadrado onde a textura sera desenhada
  this->target.x = model.get_x();
  this->target.y = model.get_y();
  this->rock_1.x= 380;
  this->rock_1.y=200;
  SDL_QueryTexture(this->sprite_0, nullptr, nullptr, &(this->target.w), &(this->target.h));
  SDL_QueryTexture(this->sprite_1, nullptr, nullptr, &(this->rock_1.w), &(this->rock_1.h));

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
  //this->rock_1.x=380;
  //this->rock_1.y=190;
  //desenhar cena
  SDL_RenderClear(this->renderer);
  SDL_RenderCopy(this->renderer, this->background, nullptr, nullptr);
  SDL_RenderCopy(this->renderer, this->sprite_1, nullptr, &(this->rock_1));
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
};

Controller::Controller(Model &model) : model(model){
  this->on = true;
  this->state = SDL_GetKeyboardState(nullptr);
}

Controller::~Controller(){}

bool Controller::get_on(){return this->on;}

void Controller::polling(){
  // Polling de eventos
  
  SDL_PumpEvents(); // atualiza estado do teclado
  /*
  if (state[SDL_SCANCODE_LEFT]){
    this->model.set_angle(this->model.get_angle()-0.5);
  }
  if (state[SDL_SCANCODE_RIGHT]){
    this->model.set_angle(this->model.get_angle()+0.5);
  }
  if (state[SDL_SCANCODE_UP]){
    this->model.set_y((this->model.get_y() - 10));
  }
  if (state[SDL_SCANCODE_DOWN]){
    this->model.set_y(this->model.get_y() + 10);
  }
  */
  
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

}


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
