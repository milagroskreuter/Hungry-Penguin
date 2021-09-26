#pragma once
#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <strings.h>

#include "Pinguino.h"
#include "Peces.h"

using namespace std;

class Enemigo{
    public:
     Enemigo(int x, int y);
     void update();
     void draw();
     void velocidad();
     void comer(Pinguino &rPinguino);
     void puntos(Peces rPeces);
     void rapidisimo();

    private:
     float m_x, m_y, m_x2;

};