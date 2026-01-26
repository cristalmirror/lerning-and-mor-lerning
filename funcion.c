#include<stdio.h>
#include<unistd.h>
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