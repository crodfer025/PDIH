#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#define DELAY 40000 

void mostrar_bienvenida(int max_y, int max_x) {
    clear();
    box(stdscr, 0, 0); 
    
    mvprintw(max_y/2 - 3, max_x/2 - 15, " PONG ");
    mvprintw(max_y/2 - 1, max_x/2 - 20, "Desarrollado por: Carlos Alberto Rodríguez Ferreira");
    mvprintw(max_y/2 + 1, max_x/2 - 20, "Controles Jugador 1: 'w' (Arriba), 's' (Abajo)");
    mvprintw(max_y/2 + 2, max_x/2 - 20, "Controles Jugador 2: Flecha Arriba, Flecha Abajo");
    mvprintw(max_y/2 + 4, max_x/2 - 15, "Pulsa cualquier tecla para empezar el juego");
    
    refresh();
    
    nodelay(stdscr, FALSE); 
    getch();
    nodelay(stdscr, TRUE); 
}

void mostrar_despedida(int max_y, int max_x, int score1, int score2) {
    clear();
    box(stdscr, 0, 0);
    
    mvprintw(max_y/2 - 2, max_x/2 - 10, "=== FIN DEL JUEGO ===");
    mvprintw(max_y/2, max_x/2 - 12, "Marcador Final: J1 [%d] - [%d] J2", score1, score2);
    
    if (score1 > score2) {
        mvprintw(max_y/2 + 2, max_x/2 - 12, "¡Felicidades Jugador 1, has ganado!");
    } else if (score2 > score1) {
        mvprintw(max_y/2 + 2, max_x/2 - 12, "¡Felicidades Jugador 2, has ganado!");
    } else {
        mvprintw(max_y/2 + 2, max_x/2 - 6, "¡Es un empate!");
    }

    mvprintw(max_y/2 + 4, max_x/2 - 15, "Pulsa 'q' para salir o 'r' para revancha");
    
    refresh();
}

int main(int argc, char *argv[]) {

    initscr();            // Inicializar el modo curses
    noecho();             // No mostrar las teclas que se pulsan en pantalla 
    curs_set(FALSE);      // Ocultar el cursor parpadeante
    cbreak();             // Hacer que las teclas estén disponibles inmediatamente 
    keypad(stdscr, TRUE); // Permitir el uso de teclas especiales como las flechas 

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x); // Obtener tamaño de la terminal

    int jugar_de_nuevo = 1;

    while (jugar_de_nuevo) {
        // Variables del juego
        int x = max_x / 2, y = max_y / 2;
        int dir_x = 1, dir_y = 1;
        int pala1_y = max_y / 2, pala2_y = max_y / 2;
        int tamano_pala = 5;
        int score1 = 0, score2 = 0;
        int jugando = 1;

        mostrar_bienvenida(max_y, max_x);

        while (jugando) {
            clear(); // Limpiar pantalla antes de dibujar el nuevo fotograma 

            // Dibujar línea central y marcadores
            mvvline(0, max_x / 2, '|', max_y);
            mvprintw(2, max_x / 4, "Jugador 1: %d", score1);
            mvprintw(2, 3 * max_x / 4, "Jugador 2: %d", score2);

            // Dibujar Pelota
            mvprintw(y, x, "O");

            // Dibujar Palas
            for (int i = 0; i < tamano_pala; i++) {
                mvprintw(pala1_y + i, 2, "|");                 // Pala Izquierda
                mvprintw(pala2_y + i, max_x - 3, "|");         // Pala Derecha
            }

            refresh(); // Volcar todos los cambios a la pantalla 
            usleep(DELAY); // Pausa para que el juego no vaya a la velocidad de la CPU

            int tecla = getch();
            switch (tecla) {
                case 'w': if (pala1_y > 0) pala1_y--; break;
                case 's': if (pala1_y + tamano_pala < max_y) pala1_y++; break;
                case KEY_UP: if (pala2_y > 0) pala2_y--; break; // Tecla flecha arriba 
                case KEY_DOWN: if (pala2_y + tamano_pala < max_y) pala2_y++; break;
                case 'q': jugando = 0; break; // Salida de emergencia
            }

            // LÓGICA DE MOVIMIENTO Y COLISIONES
            x += dir_x;
            y += dir_y;

            // Rebote en paredes superior e inferior
            if (y >= max_y - 1 || y <= 0) {
                dir_y *= -1;
            }

            // Rebote en pala izquierda
            if (x == 3 && y >= pala1_y && y <= pala1_y + tamano_pala) {
                dir_x *= -1;
            }

            // Rebote en pala derecha
            if (x == max_x - 4 && y >= pala2_y && y <= pala2_y + tamano_pala) {
                dir_x *= -1;
            }

            // Punto para Jugador 2 (la pelota pasa el borde izquierdo)
            if (x < 0) {
                score2++;
                x = max_x / 2; y = max_y / 2; // Resetear posición
            }

            // Punto para Jugador 1 (la pelota pasa el borde derecho)
            if (x > max_x) {
                score1++;
                x = max_x / 2; y = max_y / 2; // Resetear posición
            }

            // Condición de fin de partida (por ejemplo, a los 5 puntos)
            if (score1 >= 5 || score2 >= 5) {
                jugando = 0;
            }
        }

        // Pantalla de fin de partida
        nodelay(stdscr, FALSE); 
        mostrar_despedida(max_y, max_x, score1, score2);
        
        int opcion_valida = 0;
        while (!opcion_valida) {
            int respuesta = getch();
            if (respuesta == 'q' || respuesta == 'Q') {
                jugar_de_nuevo = 0;
                opcion_valida = 1;
            } else if (respuesta == 'r' || respuesta == 'R') {
                jugar_de_nuevo = 1;
                opcion_valida = 1;
            }
        }
    }

    endwin();
    return 0;
}
