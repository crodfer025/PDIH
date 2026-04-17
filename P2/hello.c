#include <ncurses.h>
int main() {
  initscr();        //inicializamos el modo ncurses
  printw("Holiwi"); //Imprime un mensaje
  refresh();        //Mostrar el mensaje en pantalla
  getch();          //Esperar la pulsacion de la tecla
  endwin();         //Terminar el modo curses
  
  return 0;
}
