#include "Pinguino.h"

Pinguino::Pinguino(int x, int y)
{
    m_x = x;
    m_y = y;
}
void Pinguino::setup()
{
    m_x = 60;
    m_y = 30;
    
    m_vidas = 3;
    m_puntos = 0;
    m_fin = false;
}

void Pinguino::update(){
    if(m_vidas <= 0)
    {
        m_fin = true;
    }
};

/*

(o_   
(/)_       |)__      |\___
          (:>__)X  (:o___(
           |)        |/                                       
                  


*/
void Pinguino::draw()
{   if(!m_fin){
    //pinguino vivo :)
    mvaddch(m_y, m_x + 2, '(');
    mvaddch(m_y, m_x + 3, 'o');
    mvaddch(m_y, m_x + 4, '_');
    mvaddch(m_y + 1, m_x + 2, '(');
    mvaddch(m_y + 1, m_x + 3, '/');
    mvaddch(m_y + 1, m_x + 4, ')');
    mvaddch(m_y + 1, m_x + 5, '_');
    } 
    else { //pinguino game over
     mvaddch(m_y + 1, m_x, '(');
    mvaddch(m_y, m_x + 1, '|');
    mvaddch(m_y + 1, m_x + 1, ':');
    mvaddch(m_y + 2, m_x + 1, '|');
    mvaddch(m_y, m_x + 2, ')');
    mvaddch(m_y + 1, m_x + 2, '>');
    mvaddch(m_y + 2, m_x + 2, ')');
    mvaddch(m_y, m_x + 3, '_');
    mvaddch(m_y, m_x + 4, '_');
    mvaddch(m_y + 1, m_x + 3, '_');
    mvaddch(m_y + 1, m_x + 4, '_');
    mvaddch(m_y + 1, m_x + 5, ')');
    mvaddch(m_y + 1, m_x + 6, 'X');
    }
}

void Pinguino::setX(int x){m_x = x;}
void Pinguino::setY(int y){m_y = y;}
void Pinguino::setVidas(int vidas) {m_vidas = vidas;}
int Pinguino::getVidas() {return m_vidas;}
void Pinguino::setPuntos(int puntos) {m_puntos = puntos;}
int Pinguino::getPuntos() {return m_puntos;}
int Pinguino::getX() {return m_x;}
int Pinguino::getY() {return m_y;}