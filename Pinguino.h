#pragma once
#include <iostream>
#include <ncurses.h>

class Pinguino{
public:
     Pinguino(int x, int y);
     void setup();
     void draw();
     void update();
     
     void setX(int x);
     void setY(int y);

     int getX();
     int getY();
     
     void setVidas(int vidas);
     int getVidas();
     
     void setPuntos(int puntos);
     int getPuntos();
    

private:
    int m_x, m_y;
    int m_vidas;
    bool m_fin;
    int m_puntos;
    int puntaje;
};

