#include "../includes/linker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init_struct_GDT(struct vertex ***v) {
    *v = NULL;
}

void construction_GDT(struct vertex ***v, int * size, char ***matrix, int file, int colums) {
    struct vertex **aux = (struct vertex **)malloc(file * sizeof(struct vertex *));
    
    //make vertex
    for (int i = 0; i < file; i++) {
        aux[i] = malloc(sizeof(struct vertex));
        aux[i]->vertex_name = malloc(20 * sizeof(char));
        sprintf(aux[i]->vertex_name,"vertex %d",i+1);
        aux[i]->edge=NULL;
        aux[i]->edge_count = 0;
    }
    
    //count edge for each vertex
    for (int i = 0; i < file; i++) {
        int count = 0;
        for (int j = 0; j < colums; j++) {
            if ((*matrix)[i][j]) count++;
        }
        aux[i]->edge_count = count;
        aux[i]->edge = malloc(count *sizeof(struct vertex*));
    }
    int pos[file];// array of independent position
    for (int i = 0; i < file; i++) pos[i] = 0;

    //connection for colums (edges)
    for (int j = 0; j < colums; j++) {
        int p[2],count = 0;
        //whats vertex is part of the edge
        for (int i = 0; i < file; i++) {
            char val = (*matrix)[i][j];
            printf("  matrix[%d][%d]=%c=%d\n", i, j, val, val);
            if((*matrix)[i][j] == '1') {
                if (count <2) p[count] = i;
                count++;//correction to don't generate memory overflow and 
            }
        }
       
        // antes del if — imprime siempre
        printf("j=%d count=%d\n", j, count);
        for (int x = 0; x <= count; x++) {
            printf("  p[%d]=%d\n", x, p[x]);
        }

        if (count == 1) {
            /*loop points to self*/
            aux[p[0]]->edge[pos[p[0]]] = aux[p[0]];
            pos[p[0]]++;
        } else if (count == 2) {
            /*Edge betwend two vertex*/
            //p[0] points to p[1] y viceverse
            aux[p[0]]->edge[pos[p[0]]] = aux[p[1]];
            aux[p[1]]->edge[pos[p[1]]] = aux[p[0]];
            pos[p[0]]++; 
            pos[p[1]]++; 
        }
    }
    *v = aux;
    *size = file;
}

void printing_GDT(struct vertex **v, int size) {

    if (v == NULL) return;//base validation

    for (int i = 0; i < size; i++) {
        if (v[i] == NULL || v[i]->vertex_name == NULL) continue;

        printf("(%s) → ",v[i]->vertex_name);
        for (int j = 0; j < v[i]->edge_count; j++) {
            if (v[i]->edge[j] != NULL && v[i]->edge[j]->vertex_name != NULL) {
                printf("(%s) ", v[i]->edge[j]->vertex_name);
            } else {
                printf("(error_prt)\n");
            }
        }
        printf("\n");
    }
}
