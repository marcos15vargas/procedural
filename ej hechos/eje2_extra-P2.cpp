/*Ejercicio 2
Una Aseguradora registra en un archivo "SEGUROS.DAT" con la información de los seguros vendidos en el último semestre. 
De cada seguro se tiene registrado: Código de cliente (a partir de 1000), DNI, Tipo de seguro (1..9) e Importe El archivo 
esta ordenado por código de cliente y permite su acceso directo.
Hacer un programa en lenguaje C que usando funciones óptimas permita:
1. Ingresar un código de cliente y modificar el tipo de seguro.
2. Generar una lista implementada con punteros, que almacene los importes de los seguros del tipo 3 y 7.De cada seguro 
se registra Código de cliente, importe y tipo. Hacerlo con una función recursiva.
3. Con la información contenida en la lista decir el importe recaudado por los seguros del tipo 3 y la cantidad de seguros 
del tipo 7. Hacer una función que devuelva ambos resultados.*/
#include "stdio.h"
#include "stdlib.h"

struct seg{
    int cod,dni,ts;
    float imp;
};

struct nodo{
    seg datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void modi(FILE *xarchi){
    seg c;int codi=0;
    printf("\nIngrese codigo de cliente: ");scanf("%d",&codi);
    fseek(xarchi,(codi-1000)*sizeof(c),SEEK_SET);
    fread(&c,sizeof(c),1,xarchi);
    printf("\nEl cliente tiene el seguro %d",c.ts);
    printf("\nIngrese nuevo tipo de seguro: ");scanf("%d",&c.ts);
    fseek(xarchi,(codi-1000)*sizeof(c),SEEK_SET);
    fwrite(&c,sizeof(c),1,xarchi);
}

void inserta(puntero &xp, FILE *xarchi){
    puntero nuevo; int dato; seg c;
    rewind(xarchi);
    fread(&c,sizeof(c),1,xarchi);
    if((xp==NULL)&&((c.ts==3)||(c.ts==7))) {
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->datos=c;
        nuevo->sig=xp;
        xp=nuevo;
        inserta(xp,xarchi);
    }else if((xp!=NULL)&&((c.ts==3)||(c.ts==7))){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->datos=c;
        nuevo->sig=xp;
        xp=nuevo;
        inserta(xp,xarchi);
    }else{
        return;
    }
}

void sumatoria(puntero xp, float *sum3, float &sum7){ //ESTE
    if(xp!=NULL){
        if(xp->datos.ts==3){
            *(sum3)+=xp->datos.imp;
        }else if(xp->datos.ts==7){
            sum7+=xp->datos.imp;
        }
        sumatoria(xp->sig,sum3,sum7);
    }else{
        return;
    }
}

int main(){
    FILE *archi=fopen("SEGUROS.dat","a+");
    if(archi==NULL){
        printf("ERROR");
    }else{
        modi(archi);
        fclose(archi);
        puntero cab=NULL;
        inserta(cab,archi);
        float sum3=0,sum7=0;
        sumatoria(cab,&sum3,sum7);
        printf("\nEl importe recaudado por el tipo de seguro 3 es: %.2f",sum3);
        printf("\nEl importe recaudado por el tipo de seguro 7 es: %.2f",sum7);
    }
}