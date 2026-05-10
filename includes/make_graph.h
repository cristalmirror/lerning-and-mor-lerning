#pragma once
#ifdef _WIN32

#include <graphics.h>

#else
#include <ncurses.h>
#include <math.h>

#endif

void draw_circle(int cx, int cy, int radio, char *name);
void draw_edge(int x1, int y1, int x2, int y2);
void init_graph();
void close_grap();
