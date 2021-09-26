#pragma once
#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include "Pinguino.h"

using namespace std;

class Pezvida{
    public:
     Pezvida(int x, int y);

     void vidaa(Pinguino &rPinguino);
     void update();
     void draw();

     int getX();
     int getY();
     
     void setVidas(int puntos = 0);
     int getVidas();
     
    private:
     float m_x;
     float m_y;
     int m_puntos = 0;
};