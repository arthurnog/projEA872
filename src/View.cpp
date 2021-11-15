#include "../include/View.h"
#include "../include/Model.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <math.h>
using namespace std;

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
  // // fundo
  // this->background = IMG_LoadTexture(renderer, "../assets/arena.png");
  // //pedra 1
  // this->sprite_1 = IMG_LoadTexture(renderer, "../assets/rock.png");
  // //numero 1
  // this->sprite_2 = IMG_LoadTexture(renderer, "../assets/1.png");
  // //pedra 2
  // this->sprite_3 = IMG_LoadTexture(renderer, "../assets/rock.png");
  // //numero 2
  // this->sprite_4 = IMG_LoadTexture(renderer, "../assets/2.png");
  // //pedra 3
  // this->sprite_5 = IMG_LoadTexture(renderer, "../assets/rock.png");
  // //numero 3
  // this->sprite_6 = IMG_LoadTexture(renderer, "../assets/3.png");
  // //pedra 4
  // this->sprite_7 = IMG_LoadTexture(renderer, "../assets/rock.png");
  // //numero 4
  // this->sprite_8 = IMG_LoadTexture(renderer, "../assets/4.png");
  // //pedra 5
  // this->sprite_9 = IMG_LoadTexture(renderer, "../assets/rock.png");
  // //numero 5
  // this->sprite_10 = IMG_LoadTexture(renderer, "../assets/5.png");

  this->sprite_11 = IMG_LoadTexture(renderer, "../assets/rock.png");
  
  
  
  // Quadrado onde a textura sera desenhada
  this->target.x = model.get_x();
  this->target.y = model.get_y();
  this->box.x = model.get_box_x();
  this->box.y = model.get_box_y();
  // this->rock_1.x= 380;
  // this->rock_1.y=200;
  // this->number_1.x=590;
  // this->number_1.y=430;
  // this->number_2.x=590;
  // this->number_2.y=430;
  // this->number_3.x=590;
  // this->number_3.y=430;
  // this->number_4.x=590;
  // this->number_4.y=430;
  // this->number_5.x=590;
  // this->number_5.y=430;
  // this->rock_2.x= 90;
  // this->rock_2.y=150;
  // this->rock_3.x= 400;
  // this->rock_3.y=300;
  // this->rock_4.x= 500;
  // this->rock_4.y=100;
  this->rock_5.x= 60;
  this->rock_5.y=380;
  
  SDL_QueryTexture(this->sprite_11, nullptr, nullptr, &(this->box.w), &(this->box.h));
  SDL_QueryTexture(this->sprite_0, nullptr, nullptr, &(this->target.w), &(this->target.h));
  // SDL_QueryTexture(this->sprite_1, nullptr, nullptr, &(this->rock_1.w), &(this->rock_1.h));
  // SDL_QueryTexture(this->sprite_2, nullptr, nullptr, &(this->number_1.w), &(this->number_1.h));
  // SDL_QueryTexture(this->sprite_3, nullptr, nullptr, &(this->rock_2.w), &(this->rock_2.h));
  // SDL_QueryTexture(this->sprite_4, nullptr, nullptr, &(this->number_2.w), &(this->number_2.h));
  //   SDL_QueryTexture(this->sprite_5, nullptr, nullptr, &(this->rock_3.w), &(this->rock_3.h));
  // SDL_QueryTexture(this->sprite_6, nullptr, nullptr, &(this->number_3.w), &(this->number_3.h));
  //  SDL_QueryTexture(this->sprite_7, nullptr, nullptr, &(this->rock_4.w), &(this->rock_4.h));
  // SDL_QueryTexture(this->sprite_8, nullptr, nullptr, &(this->number_4.w), &(this->number_4.h));
   SDL_QueryTexture(this->sprite_9, nullptr, nullptr, &(this->rock_5.w), &(this->rock_5.h));
  // SDL_QueryTexture(this->sprite_10, nullptr, nullptr, &(this->number_5.w), &(this->number_5.h));
  
  

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
  this->box.x = model.get_box_x();
  this->box.y = model.get_box_y();

  //desenhar cena
  SDL_RenderClear(this->renderer);
  SDL_RenderCopy(this->renderer, this->background, nullptr, nullptr);
  // if(this->model.get_coleta1()==0){
  // SDL_RenderCopy(this->renderer, this->sprite_1, nullptr, &(this->rock_1));
  // }
  // if(this->model.get_coleta2()==0){
  // SDL_RenderCopy(this->renderer, this->sprite_3, nullptr, &(this->rock_2));
  // }
  // if(this->model.get_coleta3()==0){
  // SDL_RenderCopy(this->renderer, this->sprite_5, nullptr, &(this->rock_3));
  // }
  // if(this->model.get_coleta4()==0){
  // SDL_RenderCopy(this->renderer, this->sprite_7, nullptr, &(this->rock_4));
  // }
  if(this->model.get_coleta5()==0){
  SDL_RenderCopy(this->renderer, this->sprite_9, nullptr, &(this->rock_5));
  }
  // if(this->model.get_score()==1){
  // SDL_RenderCopy(this->renderer, this->sprite_2, nullptr, &(this->number_1));
  // }
  // if(this->model.get_score()==2){
  // SDL_RenderCopy(this->renderer, this->sprite_4, nullptr, &(this->number_2));
  // }
  // if(this->model.get_score()==3){
  // SDL_RenderCopy(this->renderer, this->sprite_6, nullptr, &(this->number_3));
  // }
  // if(this->model.get_score()==4){
  // SDL_RenderCopy(this->renderer, this->sprite_8, nullptr, &(this->number_4));
  // }
  // if(this->model.get_score()==5){
  // SDL_RenderCopy(this->renderer, this->sprite_10, nullptr, &(this->number_5));
  // }
  SDL_RenderCopy(this->renderer, this->sprite_11, nullptr, &(this->box));
  SDL_RenderCopyEx(this->renderer, this->sprite_0, nullptr, &(this->target), this->model.get_angle()*(180/3.141592), NULL, SDL_FLIP_NONE);
  SDL_RenderPresent(this->renderer);
  // Delay para diminuir o framerate
  SDL_Delay(10);

}
