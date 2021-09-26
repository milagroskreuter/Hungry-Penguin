#pragma once
#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include "Pinguino.h"

using namespace std;

class Peces{
    public:
     Peces(int x, int y);

     void alimento(Pinguino &rPinguino);
     void update();
     void draw();

     int getX();
     int getY();
     
     void setPuntos(int puntos = 0);
     int getPuntos();
     
    private:
     float m_x, m_y;
     int m_puntos = 0;
};