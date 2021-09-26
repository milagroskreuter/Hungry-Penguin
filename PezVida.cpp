#include "Pezvida.h"

Pezvida::Pezvida(int x, int y)
{
    m_x = x;
    m_y = 125;
}

void Pezvida::update()
{  m_y = m_y + 0.3f;
  
  if(m_y >= 500)
  {m_x = rand() % 110 + 1; m_y = 1;}

}

void Pezvida::draw()
{  /*,'`.(
     `.,'(
*/
    mvaddch(m_y, m_x +1, ',');
    mvaddch(m_y, m_x +2, '`');
    mvaddch(m_y, m_x +3, '`');
    mvaddch(m_y, m_x +4, '.');
    mvaddch(m_y, m_x +5, '(');
    mvaddch(m_y +1, m_x +1, '`');
    mvaddch(m_y +1, m_x +2, '.');
    mvaddch(m_y +1, m_x +3, ',');
    mvaddch(m_y +1, m_x +4, '`');
    mvaddch(m_y +1, m_x +5, '(');

}

void Pezvida::vidaa( Pinguino &rPinguino)
{   
    if(m_x >= rPinguino.getX() && m_x <= rPinguino.getX() + 4 && m_y >= rPinguino.getY() 
    && m_y <= rPinguino.getY() + 5 )
    {
      rPinguino.setVidas(rPinguino.getVidas() + 1);     
      m_y = 45;      
    }
  
}

int Pezvida::getX(){return m_x;}
int Pezvida::getY(){return m_y;}
