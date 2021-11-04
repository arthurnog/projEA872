#pragma once
using namespace std;
#include "../include/Caixa.h"

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
    Caixa caixa;
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
    float get_box_x();
    float get_box_y();
    void set_box_pos();
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
