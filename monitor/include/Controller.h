#include <SDL2/SDL_image.h>
#include "../include/Model.h"
#include "../include/View.h"

using namespace std;

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
    void save_memorycard();
    void load_memorycard();
};
