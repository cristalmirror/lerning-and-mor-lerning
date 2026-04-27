#include "../includes/linker.h"
#include <stdlib.h>

void init_struct_GDT(struct vertex **v) {
    *v = NULL;
}

void construction_GDT(struct vertex **v, char ***matrix,int file, int colums) {
    struct vertex *aux[file];//create all vertex necesary
    for (int i = 0; i < file; i++) {
        
        /*
            linker
        */
        /*make the first vertex*/
        aux[i] = (struct vertex*)malloc(sizeof(struct vertex));
        aux[i]->vertex_name = (char*)malloc(20 * sizeof(char));//set size of name
        aux[i]->edge = NULL;//null pointer to next vertex
        /*
            set the name of vertex
        */
        sprintf(aux[i]->vertex_name, "vertex %d", i);/*name vertex*/
    }    

    //connect edges 
    for (int i = 0; i < file; i++) {
        int count = 0;
        for (int j = 0; j < colums; j++) {//define the size of the next vetexs that are needed
            
            if ((*matrix)[i][j] == '1') {
                count++;
            }   
        }
    
        /*reserb memory for vetexs size needed*/
        aux[i]->edge = (struct vertex**)malloc(count * sizeof(struct vertex*));

        int pos = 0;//numbers of edges in this vertex
        for (int k = 0; k < colums; k++) {
            if ((*matrix)[i][k] == '1') {
                /* code */
                aux[i]->edge[pos] = aux[k];
                pos++;
            }
            
        }
    }
    *v = aux[0]; 
    
}