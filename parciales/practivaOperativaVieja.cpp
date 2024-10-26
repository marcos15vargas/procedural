/*ENUNCIADO
Se procesa los datos de los empleados de una tienda. De cada uno se conoce: nombre, DNI, sueldo.
Realizar un programa en lenguaje C, que usando funciones óptimas realice lo siguiente:
Generar una lista enlazada con punteros para cargar los datos de los empleados.
Mostrar los datos de los empleados sueldo mayor a $ 400.000. (Hacer una función recursiva)
Ingresar el DNI de un empleado y decir su nombre.
Eliminar los datos de los empleados con sueldo menor a $250.000 y mostrar la lista actualizada.*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct emp{
    int dni;
    float sueldo;
    char nom[20];
};

struct nodo{
    emp datos;
    struct nodo *sig;
};

typedef struct nodo * puntero;

//Generar una lista enlazada con punteros para cargar los datos de los empleados.
void inserta(puntero &xp){
    char aux[20];
    puntero nuevo;
    printf("Ingrese Nombre (o 'fin' para finalizar): ");gets(aux);
    while (aux != "fin"){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        strcpy(nuevo->datos.nom,aux);
        printf("\nIngrese DNI: ");scanf("%d",&nuevo->datos.dni);
        printf("\nIngrese sueldo: ");scanf("%f",&nuevo->datos.sueldo);
        nuevo->sig=xp;
        xp=nuevo;
        printf("Ingrese Nombre (o fin para finalizar): ");gets(aux);
    }
}
//Mostrar los datos de los empleados sueldo mayor a $ 400.000. (Hacer una función recursiva)
void muestra(puntero xp){
    if(xp!=NULL){
        if(xp->datos.sueldo>400000){
            printf("\n %s %d %.2f",xp->datos.nom,xp->datos.dni,xp->datos.sueldo);
            muestra(xp->sig);
        }
    }else{
        return;
    }
}

//Ingresar el DNI de un empleado y decir su nombre.
void bus(puntero xp, int elem){
    if(xp==NULL){
        printf("\nEl DNI no se encuentra en la lista");
    }else if(xp->datos.dni==elem){
        printf("\nSe encontro el DNI en la lista");
    }else{
        bus(xp->sig,elem);
    }
}

//Eliminar los datos de los empleados con sueldo menor a $250.000 y mostrar la lista actualizada.
void suprimir(puntero *xp) {
    puntero anterior, p;
    p=*xp;
    while ((p!=NULL)&&(p->datos.sueldo < 250000)){
        *xp=p->sig;
        free(p);
        p=*xp;
    }
    if(p!=NULL){
        anterior=p;
        while (p->sig!=NULL){
            if (p->sig->datos.sueldo<250000) {
                anterior=p;
                p=p->sig;
                anterior->sig=p->sig;
                free(p);
                p=anterior->sig;
            }else{
                anterior=p;
                p=p->sig;
            }
        }
    }
    printf("\n Lista actualizada");
    muestra(*xp);
}


int main(){
    puntero cab=NULL;
    inserta(cab);
    muestra(cab);
    int elem;
    printf("\nIngrese DNI a buscar: ");scanf("%d",&elem);
    bus(cab,elem);
    suprimir(&cab);
    free(cab);
}