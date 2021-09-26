//Villan Braian
//Kreuter Milagros

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include <math.h>
#include <strings.h>


#include "Pinguino.h"
#include "Enemigo.h"
#include "Peces.h"
#include "Pezvida.h"

using namespace std;

Pinguino elPinguino(0, 0);
Enemigo tiburon(0, 19);
Enemigo tiburoncito(0, 25);
Enemigo tiburonzon(0, 30);
Peces chiquito(100 , 0);
Pezvida unavida(100, 0);

vector<Peces> Pez;
vector<Pinguino> Pingui;

//variables y constantes
const int DELAY = 30;
const int ANCHO = 120;
const int ALTO = 40;

int puntaje;
bool game_over;
bool salir;
bool principio;
bool ganar;

//declaro funciones
void setup();
void input();
void update();
void draw();
void gameover();
void inicio();
void instrucciones();
void ganaste();


int main()
{
  initscr(); noecho(); curs_set(FALSE); keypad(stdscr, TRUE); nodelay(stdscr, TRUE);
  if (LINES < ALTO || COLS < ANCHO){ endwin(); printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO); exit(1); }
  inicio(); cout << endl; return 0;
}

void inicio()
{   
   do{ int eleccion = getch();
   //titulo y   x
    mvprintw(6, 38, " _   _");
    mvprintw(7, 38, "| | | |  _   _   _ ___     __ _   _ __   _   _ ");
    mvprintw(8, 38, "| |_| | | | | | | '_  |   / _` | | '__| | | | |");
    mvprintw(9, 38, "|  _  | | |_| | | | | |  | (_| | | |    | |_| |");
    mvprintw(10, 38,"|_| |_| |___,_| |_| |_|  |__,| | |_|    |___, |");
    mvprintw(11, 38,"                         |____/         |____/ ");

    mvprintw(12, 35, " _____                                  _         ");
    mvprintw(13, 35, "|  _  |   ___   _ ___    __ _   _   _  (_)  _ ___ ");
    mvprintw(14, 35, "| |_) |  / _ | | '_  |  / _` | | | | | | | | '_  | ");
    mvprintw(15, 35, "|  __/  |  __/ | | | | | (_| | | |_| | | | | | | |");
    mvprintw(16, 35, "|_|     |____| |_| |_|  |__, | |___,_| |_| |_| |_|");
    mvprintw(17, 35, "                        |___/                     ");
    
    //menu
    mvprintw(19, 48, "¿Cuantos peces podes comer?");
    mvprintw(23, 54, "AR | JUGAR");
    mvprintw(25, 54, "AB | INSTRUCCIONES");
    mvprintw(27, 54, "ESC | SALIR ");
    mvprintw(34, 35, "Flecha Arriba - Jugar | Flecha Abajo - Instrucciones");
    mvprintw(35, 38, "Villan Braian - Kreuter Milagros - UNA - 2021");
    box(stdscr, 0, 0);
    
    //ESQUINAS
      //     y  x
    mvaddch(22, 52, ACS_ULCORNER); mvaddch(22, 72, ACS_URCORNER); mvaddch(28, 52, ACS_LLCORNER); mvaddch(28, 72, ACS_LRCORNER);
    //LINEAS HORIZONTALES ARRIBA Y ABAJO
    mvhline(22, 53, ACS_HLINE, 19); mvhline(28, 53, ACS_HLINE, 19);
    //LINEAS DEL MEDIO
    mvhline(24, 53, ACS_HLINE, 19); mvhline(26, 53, ACS_HLINE, 19);
    //LINEAS VERTICALES
    mvvline(23, 52, ACS_VLINE, 5); mvvline(23, 72, ACS_VLINE, 5);
    refresh();
     salir = false; switch (eleccion){
     case KEY_UP: setup(); while(!salir) {while (!game_over){input(); update(); draw();} gameover();}
     break;
     case KEY_DOWN: while(!principio){principio = false; erase(); instrucciones(); } break;
     case 27: endwin(); exit(1); break; 
     default: break;}} while (!game_over);
     refresh();} 

void instrucciones()
{ erase();
  
  box(stdscr, 0, 0);
        // y  x
  
  mvprintw(1, 2, " ___               _                            _ ");
  mvprintw(2, 2, "|_ _|  _ __   ___ | |_   _ _   _  _   __   __  (_)  ___   _ __   ___   ___");
  mvprintw(3, 2, " | |  | '  | (_-< |  _| | '_| | || | / _| / _| | | | _ | | '  | | -_) (_-<");
  mvprintw(4, 2, "|___| |_||_| /__/ |___| |_|   |__,_| |__| |__| |_| |___| |_||_| |___| /__/");
 
  //BLOQUE 1 - HISTORIA
  mvprintw(34, 46, "Presiona ESC para volver al inicio");
  mvprintw(8, 5, "BETO, EL PINGUINO, TIENE HAMBRE...");
  mvprintw(11, 5, "¿Lo ayudas a recolectar su comida?");
  mvprintw(13, 5, "Pero, CUIDADO, HAY TIBURONES EN EL AGUA");
  mvprintw(15, 10, ")_____/)_____"); 
  mvprintw(16, 10, ")--v____ __`<");         
  mvprintw(17, 10, "       )/ ");
  mvprintw(16, 25, "Son muy peligrosos");
  mvprintw(19, 5, "Cuantos mas peces recolectes, mas puntos obtendras");
  mvprintw(21, 12, "><>");
  mvprintw(21, 17, "¿No se ven deliciosos? :p");

  mvprintw(26, 24, "Espero que me ayudes:(");
  mvprintw(24, 10, "      .___.");
  mvprintw(25, 10, "     ´     `");
  mvprintw(26, 10, "    | O _ O | ");
  mvprintw(27, 10, "    ´   V   ` ");
  mvprintw(28, 10, "  .' ´     ` `.");
  mvprintw(29, 10, " ´ _|       |_ `");
  mvprintw(30, 10, "(_´ |       | `_)");
  mvprintw(31, 10, "    |       |");
  mvprintw(32, 10, "  __|__>-<__|__");
  mvprintw(33, 10, "    ~;´´    ``;~");
  mvprintw(34, 12, "BETO, EL PINGUINO");

  //BLOQUE 2 - INSTRUCCIONES
  mvprintw(7, 65, "IMPORTANTE");
  mvprintw(9, 66, "Utiliza las flechas del teclado para");
  mvprintw(10, 66, "moverte por la pantalla.");
  mvprintw(12, 66, "Recolecta la mayor cantidad de peces que puedas");
  mvprintw(14, 66, "Y ten mucho cuidado con los tiburones...");
  mvprintw(16, 66, "Solo tienes 3 vidas pero...");
  mvprintw(18, 66, "Si encontras el pez de la suerte, ");
  mvprintw(19, 66, "te regala una vida extra :D");

  mvaddch(21, 66, ',');
  mvaddch(21, 67, '`');
  mvaddch(21, 68, '`');
  mvaddch(21, 69, '.');
  mvaddch(21, 70, '(');
  
  mvaddch(22, 66, '`');
  mvaddch(22, 67, '.');
  mvaddch(22, 68, ',');
  mvaddch(22, 69, '`');
  mvaddch(22, 70, '(');
  mvprintw(22, 73, "<- Si, este es el pez de la suerte");
  mvprintw(25, 66, "Beto estara muy agradecido :)");
  mvvline(7, 60, ACS_VLINE, 25);
  
  int volver = getch(); switch(volver){case 27: erase(); inicio(); break; default: break;}
  refresh();
}

void setup()
{ game_over = false; elPinguino.setup(); puntaje = 0; for (int i = 0; i < 10; i++){Pez.push_back(Peces(rand() % 119 + 1, 1));}
}

void input()
{
  int tecla = getch();
  switch (tecla){case KEY_UP: if (elPinguino.getY() > 1) elPinguino.setY(elPinguino.getY() - 1); break;
  case KEY_DOWN: if (elPinguino.getY() < ALTO - 3) elPinguino.setY(elPinguino.getY() + 1); break;
  case KEY_LEFT: if (elPinguino.getX() > 1) elPinguino.setX(elPinguino.getX() - 1); break;
  case KEY_RIGHT: if (elPinguino.getX() < ANCHO - 9) elPinguino.setX(elPinguino.getX() + 1); break;
  case 27: game_over = TRUE; break;
  default: break;}
}

void update()
{
 elPinguino.update(); if (elPinguino.getVidas() <= 0){game_over = true;}

 tiburon.update(); tiburon.comer(elPinguino);
 tiburoncito.velocidad(); tiburoncito.comer(elPinguino);
 tiburonzon.rapidisimo(); tiburoncito.comer(elPinguino);
 chiquito.update(); chiquito.alimento(elPinguino);
 unavida.update(); unavida.vidaa(elPinguino);

 for (int i = 0; i < Pez.size(); i++){ Pez[i].update(); Pez[i].alimento(elPinguino); }
 
 
}

void draw()
{
  erase(); box(stdscr, 0, 0);
  mvprintw(0, 40, "HUNGRY PENGUIN"); mvprintw(0, 80, "[  VIDAS      ]"); mvprintw(0, 5, "[ PECES:     ]");
  
  for (int i = 1; i < elPinguino.getPuntos(); i++){mvprintw(0, 13, "%d", i);}
  
  for (int j = 0; j < elPinguino.getVidas(); j++) {  mvaddch(0, 89 + j, A_ALTCHARSET | 246); }
  for (int s = 0; s < Pez.size(); s++) {  Pez[s].draw(); }

  tiburon.draw(); tiburoncito.draw(); tiburonzon.draw(); elPinguino.draw(); chiquito.draw(); 
  unavida.draw(); delay_output(DELAY); refresh();
}

void gameover()
{
  box(stdscr, 0, 0);
  mvprintw(0, 40, "HUNGRY PENGUIN"); mvprintw(0, 80, "[  VIDAS      ]"); mvprintw(0, 5, "[ PECES:     ]");
  for (int i = 0; i < elPinguino.getPuntos(); i++) { mvprintw(0, 15, "%d", i);}
  for (int l = 0; l < elPinguino.getVidas(); l++)  mvaddch(0, 89 + l, A_ALTCHARSET | 246);
  
  for (int y = 10; y < 16; y++)
  mvhline(y, 40, ' ', 40);

  mvaddch(9, 39, ACS_ULCORNER); mvaddch(9, 80, ACS_URCORNER); mvaddch(16, 39, ACS_LLCORNER); mvaddch(16, 80, ACS_LRCORNER);
  mvhline(9, 40, ACS_HLINE, 40); mvhline(16, 40, ACS_HLINE, 40);
  mvvline(10, 39, ACS_VLINE, 6); mvvline(10, 80, ACS_VLINE, 6);

  mvprintw(12, 43, "EL PINGUINO TIENE MUCHA HAMBRE X_X"); mvprintw(13, 45, "¿VOLVER A INTENTARLO? (S/N)");
  


  int opcion = getch();

  if (opcion == 's' || opcion == 'S') { game_over = false; setup(); }
  else if (opcion == 'n' || opcion == 'N') { game_over = false; erase(); refresh(); inicio();
  }
}
