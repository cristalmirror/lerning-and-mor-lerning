#include "../includes/linker.h"
#include <stdlib.h>

void init_struct_GDT(struct vertex **v) {
    *v = NULL;
}

void construction_GDT(struct vertex **v, char ***matrix,int file, int colums) {
    struct vertex **aux = (struct vertex **)malloc(sizeof(struct vertex *));
    struct vertex *vert = (struct vertex *)malloc(sizeof(struct vertex ));
    //initial state null
    vert->vertex_name = "vertex 1";
    vert->edge = NULL;
    if(*v == NULL) {
        *v = vert;
    } else {
    int cont = 0;//linker process
        for (int i = 0; i < file; i++) {
            for (int j = 0; j < colums; j++) {
                for (int k = 0; k < file; k++){
                    if (((*matrix)[i][j] == '1') && ((*matrix)[k][j] == '1')) {
                        aux[cont]=*v;
                        sprintf(aux[cont]->vertex_name, "vertex %d", i);
                        cont++;
                    }
                    *v=*aux;
                }
            }
        
        }
    }
    
}

void printing_GDT(struct vertex **v) {
    struct vertex *aux;
    aux = *v;
        while (aux->edge != NULL) {
            printf("(%s) → ",aux->vertex_name);
            aux = *aux->edge;
        }
    printf("\n");
}
