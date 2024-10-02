#include<stdio.h>
#include<malloc.h>

typedef struct{
    char nom[30];
    float prom;
    int anio;
}Alumno;

struct nodo{
    Alumno datos;
    struct nodo*sig;
};

typedef struct nodo * Puntero;

typedef struct{
    char nom[30];
    Puntero cabeza;
}facultad;


int main(){
    facultad *arr;
    

    getchar();
    getchar();
}