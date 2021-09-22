#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

#include "../include/func.h"
//#include "View.h"
//#include "Model.h"
//#include "Controller.h"

class Model {
  private:
    float x_current;
    float y_current;
  public:
    Model();
    ~Model();
    int get_x();
    void set_x(float new_x);
    int get_y();
    void set_y(float new_y);
};

Model::Model() {
  this->x_current = 100.0;
  this->y_current = 100.0;
}

Model::~Model(){}

int Model::get_x(){return this->x_current;}
void Model::set_x(float new_x){this->x_current=new_x;}
int Model::get_y(){return this->y_current;}
void Model::set_y(float new_y){this->y_current=new_y;}

class View{
  private:
    Model &model;
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Rect target;
    SDL_Texture *sprite_0;
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
  this->background = IMG_LoadTexture(renderer, "../assets/park.jpeg");

  // Quadrado onde a textura sera desenhada
  this->target.x = model.get_x();
  this->target.y = model.get_y();
  SDL_QueryTexture(this->sprite_0, nullptr, nullptr, &(this->target.w), &(this->target.h));

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
  SDL_RenderCopy(this->renderer, this->sprite_0, nullptr, &(this->target));
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
  if (state[SDL_SCANCODE_LEFT]){
    this->model.set_x(this->model.get_x() - 1);
  }
  if (state[SDL_SCANCODE_RIGHT]){
    this->model.set_x(this->model.get_x() + 1);
  }
  if (state[SDL_SCANCODE_UP]){
    this->model.set_y(this->model.get_y() - 1);
  }
  if (state[SDL_SCANCODE_DOWN]){
    this->model.set_y(this->model.get_y() + 1);
  }

  while (SDL_PollEvent(&(this->event))) {
    if (this->event.type == SDL_QUIT) {
      this->on = false;
    }
  }
}

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
