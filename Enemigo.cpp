#include "Enemigo.h"


Enemigo::Enemigo(int x, int y)
{  
    m_x = x;
    m_y = y;
}

void Enemigo::update()
{     
    m_x = m_x + 0.6f;

  if (m_x >= 119)
  {
    m_y = rand() % 30 + 1; 
    m_x = 1;
  }

}
void Enemigo::velocidad()
{  
    m_x = m_x + 0.8f;
    
  if (m_x >= 119)
  {
    m_y = rand() % 30 + 1; 
    m_x = 1;
  }
}

void Enemigo::rapidisimo(){

  m_x = m_x + 1;

  if (m_x >= 119)
  {
    m_y = rand() % 30 + 1; 
    m_x = 1;
  }

}

void Enemigo::draw()
{
    mvaddch(m_y, m_x, ')');
   
    mvaddch(m_y, m_x + 1, '_');
    mvaddch(m_y, m_x + 2, '_');
    mvaddch(m_y, m_x + 3, '_');
    mvaddch(m_y, m_x + 4, '_');
    mvaddch(m_y, m_x + 5, '/');
    mvaddch(m_y, m_x + 6, ')');
    mvaddch(m_y, m_x + 7, '_');
    mvaddch(m_y, m_x + 8, '_');
    mvaddch(m_y, m_x + 9, '_');
    mvaddch(m_y, m_x + 10, '_');

    mvaddch(m_y + 1, m_x, ')');
    mvaddch(m_y + 1, m_x + 1, '_');
    mvaddch(m_y + 1, m_x + 2, '_');
    mvaddch(m_y + 1, m_x + 3, 'v');
    mvaddch(m_y + 1, m_x + 5, '_');
    mvaddch(m_y + 1, m_x + 6, '_');
    mvaddch(m_y + 2, m_x + 7, ')');
    mvaddch(m_y + 2, m_x + 8, '/');
    mvaddch(m_y + 1, m_x + 9, '_');
    mvaddch(m_y + 1, m_x + 10, '*');
    mvaddch(m_y + 1, m_x + 11, '<');
}

void Enemigo::comer( Pinguino &rPinguino)
{
    if(m_x >= rPinguino.getX() && m_x <= rPinguino.getX() + 11 && m_y >= rPinguino.getY() 
    && m_y <= rPinguino.getY() + 3 )
    {
      rPinguino.setVidas(rPinguino.getVidas() - 1);
      m_y = rand() % 30 + 1;
      m_x = 1;      
      
    }
   
}