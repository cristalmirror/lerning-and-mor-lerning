#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

/*vertex*/
struct vertex {
    struct vertex **edge; //this pointer is a representation of a edge
    char *vertex_name; //name of vertex type data
};


void saludar() {
    printf("¡Hola desde la función C!\n");
}

void despedir() {
    for(int i = 5; i >= 1; i--) {
        printf("[==================]\n");
        printf("Adios desde C en %i\n",i);
        sleep(1);
    }
    printf("Adios a todos desde C, este ingerto de lenguajes los quiere\n\n");
}

//option to process the degree form of input args
void degree_option(char ***element) {
    printf("Degree option runing now...\n");
}

void matrix_option(char ***element) {
    printf("Matix option runing now...\n");
}

/*theory of graphes*/
void graph_function(char **data_graph, char **opt_graph) {
    printf("GRAPH FUNCTION RUN\n");
    printf("G=(V;A;\u03C6)\n");
    char text[]= "texto partido en partes con C";

    //checking the repherense is NULL or not to charger the text
    if (data_graph != NULL && *data_graph != NULL && **data_graph != '\0') { 
        strcpy(text, *data_graph);
    }

    char *token = strtok(text,",");
    while (token) {
        printf("%s\n",token);
        token = strtok(NULL,",");
    }
    
}

void digraph_function(char **data_graph, char **opt_graph) {
    printf("DIGRAPH FUNCTION RUN\n");
    char text[]= "texto partido en partes con C";

    //checking the repherense is NULL or not to charger the text
    if (data_graph != NULL && *data_graph != NULL && **data_graph != '\0') { 
        strcpy(text, *data_graph);
    }

    char *token = strtok(text,",");
    while (token) {
        printf("%s\n",token);
        token = strtok(NULL,",");
    }
}

void tree_function(char **data_graph, char **opt_graph) {
    printf("TREE FUNCTION RUN\n");
    char text[]= "texto partido en partes con C";

    //checking the repherense is NULL or not to charger the text
    if (data_graph != NULL && *data_graph != NULL && **data_graph != '\0') { 
        strcpy(text, *data_graph);
    }

    char *token = strtok(text,",");
    while (token) {
        printf("%s\n",token);
        token = strtok(NULL,",");
    }
}
