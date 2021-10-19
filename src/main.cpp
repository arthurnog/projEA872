#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <math.h>

#include "../include/func.h"
#include "../include/View.h"
#include "../include/Model.h"
#include "../include/Controller.h"


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
