/*Requisitos:
1. Creación de una lista enlazada: Crea una función que reciba una cabeza de lista y genere una lista
enlazada en la cual registre información de libros: código de libro, titulo, autor, precio y cantidad.
2. Búsqueda recursiva de un elemento: Crea una función recursiva que reciba un código de libro y retorne
el autor, titulo y precio del mismo si está en la lista enlazada. Mostrar el resultado en el principal.
3. Impresión recursiva de la lista: Crea una función recursiva que imprima todos los elementos de la lista
enlazada en orden inverso al ingresado.
4. Eliminación de un elemento por valor: Crea una función que, dado un código de libro elimine el nodo
que contiene dicho valor en la lista enlazada.
5. Procesamiento de la lista: Crea una función que calcule el importe total que hay en libros. Mostrar el
resultado en el principal.*/
//JTP Malena Paez
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct lis{
    int cod;
    char tit[20];
    char aut[20];
    float pre;
    int cant;
};

struct nodo{
    lis datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void inserta(puntero &xp){
    int aux;
    puntero nuevo;
    printf("Ingrese codigo de libro (o 0 para finalizar): ");
    scanf("%d",&aux);
    while (aux!=0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->datos.cod=aux;
        printf("\nIngrese Titulo: ");fflush(stdin);
        gets(nuevo->datos.tit);
        printf("\nIngrese Autor: ");fflush(stdin);gets(nuevo->datos.aut);
        printf("\nIngrese precio: ");scanf("%f",&nuevo->datos.pre);
        printf("\nIngrese cantidad: ");scanf("%d",&nuevo->datos.cant);
        nuevo->sig=xp;
        xp=nuevo;
        printf("Ingrese codigo de libro (o 0 para finalizar): ");scanf("%d",&aux);
    }
}

void busca(puntero xp, int xcod, char* tit, char* aut, float* pre){
    if(xp==NULL){
        printf("\nEl libro no se encuentra.");
    }else if(xp->datos.cod==xcod){
        strcpy(tit, xp->datos.tit);
        strcpy(aut, xp->datos.aut);
        *pre = xp->datos.pre;
    }else{
        busca(xp->sig,xcod,tit,aut,pre);
    }
}

void listar(puntero xp){
    if(xp!=NULL){
        printf("\n%s %s %d %.2f %d",xp->datos.tit,xp->datos.aut,xp->datos.cant,xp->datos.pre,xp->datos.cod);
        xp=xp->sig;
        listar(xp);
    }else{
        return;
    }
}

void suprimir (puntero &xp){
    puntero anterior, p;
    int dato;
    printf("\n Ingrese el codigo a suprimir: ");scanf("%d",&dato);
    if (xp->datos.cod==dato){
        p=xp;
        xp=xp->sig;
        free (p);
    }else{
        p=xp;
        anterior=xp;
        while((p!=NULL)&&(p->datos.cod!=dato)){
            anterior=p;
            p=p->sig;
        }
        if(p!=NULL){
            anterior->sig=p->sig;
            free(p);
            printf("\n El libro fue eliminado de la lista");
        }else{
            printf("\n No se encuentra el libro en la lista");
            return;
        }
    }
}
/*Procesamiento de la lista: Crea una función que calcule el importe total que hay en libros. Mostrar el
resultado en el principal.*/
float imptot(puntero xp){
    float total=0;
    while(xp!=NULL){
        total+=xp->datos.pre * xp->datos.cant;
        xp=xp->sig;
    }
    return total;
}

int main(){
    puntero cab=NULL;
    inserta(cab);
    char tit[20];
    char aut[20];
    float pre; int cod;
    busca(cab,cod,tit,aut,&pre);
    listar(cab);
    int cod2;
    printf("\nIngrese codigo para eliminar el libro: ");scanf("%d",&cod2);
    suprimir(cab);
    float tot=imptot(cab);
    printf("\nEl total es: %.2f",tot);
}