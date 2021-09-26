#include "Peces.h"

Peces::Peces(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Peces::update()
{  m_y = m_y + 0.3f;

  if (m_y >= 39) {m_x = rand() % 110 + 1; m_y = 1; }
}

void Peces::draw()
{
    mvaddch(m_y, m_x, '>');
    mvaddch(m_y, m_x + 1, '<');
    mvaddch(m_y, m_x + 2, '>');

}

void Peces::alimento( Pinguino &rPinguino)
{   
    if(m_x >= rPinguino.getX() && m_x <= rPinguino.getX() + 4 && m_y >= rPinguino.getY() 
    && m_y <= rPinguino.getY() + 5 )
    {
      
    rPinguino.setPuntos(rPinguino.getPuntos() + 1);
  
      m_y = 1; m_x = rand() % 110 + 1;
    }
  
}

int Peces::getX(){return m_x;}
int Peces::getY(){return m_y;}
void Peces::setPuntos(int puntos) {m_puntos = puntos;}
int Peces::getPuntos() {}