#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

#include "func.h"
//#include "View.h"
//#include "Model.h"
//#include "Controller.h"

class Model {
  private:
    float x_current;
    float y_current;
  public:
    Model()
    float get_x();
    void set_x(float new_x);
    float get_y();
    void set_y(float new_y);
}

Model::Model() {
  this->x_current = 100;
  this->y_current = 100;
}
float Model::get_x(){return this->x_current;}
void Model::set_x(float nex_x){this->x_current=new_x;}
float Model::get_y(){return this->y_current;}
void Model::set_y(float nex_y){this->y_current=new_y;}

class View{
  private:
    Model &mdl;
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Rect target;
    SDL_Texture *sprite_0;
    SDL_Texture *background;
  public:
    View(Model &model);
    ~View();
    void render();
}
//view
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

View::View(Model &model) : model(model){
  // Inicializando o subsistema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return 1;
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
  this->sprite_0 = IMG_LoadTexture(renderer, "../assets/capi.png");
  // fundo
  this->background = IMG_LoadTexture(renderer, "../assets/park.jpeg");

  // Quadrado onde a textura sera desenhada
  this->target.x = model.get_x;
  this->target.y = model.get_y;
  SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->target.w), &(this->target.h));

}

View::~View(){
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
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
//=============>
int main() {
  estou_aqui();
  //======================>

  // Controlador:
  bool rodando = true;

  // Variaveis para verificar eventos
  SDL_Event evento; // eventos discretos
  const Uint8* state = SDL_GetKeyboardState(nullptr); // estado do teclado

  // Laco principal do jogo
  while(rodando) {
    // Polling de eventos
    SDL_PumpEvents(); // atualiza estado do teclado
    if (state[SDL_SCANCODE_LEFT]) target.x -= 1;
    if (state[SDL_SCANCODE_RIGHT]) target.x += 1;
    if (state[SDL_SCANCODE_UP]) target.y -= 1;
    if (state[SDL_SCANCODE_DOWN]) target.y += 1;


    while (SDL_PollEvent(&evento)) {
      if (evento.type == SDL_QUIT) {
        rodando = false;
      }
      //view render()
    }
  }
  return 0;
}
