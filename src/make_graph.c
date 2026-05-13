
#include "../includes/make_graph.h"
#include <ncurses.h>
#include <stdlib.h>


void init_graph() {
#ifdef _WIN32

    initwindow(800,600,"Graphe");

#else
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
#endif
}

/*close*/
void close_grap() {
#ifdef _WIN32
    closegraph();
#else
    getch();
    endwin();  
#endif
}

/*drawing the vertex part*/

void draw_circle(int cx, int cy, char *name) {
#ifdef _WIN32

    circle(cx, cy, 20);
    outtextxy(cx, cy, name);

#else

    attron(COLOR_PAIR(1));
    mvprintw(cy, cx, "(%s)", name);
    attroff(COLOR_PAIR(1));

#endif
}

/*drawing the edge part*/
void draw_edge(int x1, int y1, int x2, int y2) {

#ifdef _WIN32
    line(x1, y1, x2, y2);
#else
    attron(COLOR_PAIR(2));
    // Bresenham algorithim implementation
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    while (1) {
        mvaddch(y1, x1, '*');
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    attroff(COLOR_PAIR(2));
#endif  
  
}
