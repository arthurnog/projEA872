#pragma once
using namespace std;

class Caixa {
    private:
        float x;
        float y;
        bool took = false;
    public:
        Caixa();
        ~Caixa();
        float get_x();
        float get_y();
        void set_pos();
        bool get_took();
        void set_took();
};