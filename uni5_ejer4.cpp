#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
    int plan;
    int dni;
    char nya[50];
    int cuotas;
}Plan;

struct nodo{
    Plan nro;
	struct nodo *sig;
};

typedef struct nodo*puntero;

void crear(puntero *cz){
    *cz = NULL;
}

void insertar(puntero *cz){
    puntero nuevo;
    int num;
    printf("Ingrese el plan(termina con 0): ");
    scanf("%d",&num);
    while(num != 0){
        nuevo = (puntero)malloc(sizeof(struct nodo));
        nuevo->nro.plan = num;
        printf("Ingrese el dni: ");
        scanf("%d",&nuevo->nro.dni);
        fflush(stdin);
        printf("Ingrese el nombre: ");
        gets(nuevo->nro.nya);
        printf("Ingrese el numero de cuotas: ");
        scanf("%d",&nuevo->nro.cuotas);

        nuevo->sig = *cz;
        *cz = nuevo;

        printf("Ingrese el plan(termina con 0): ");
        scanf("%d",&num);

        //insertar(cz); --> para recursividad
    }
}

void licitar(puntero cz,puntero cz2){
    puntero nuevo;

    while(cz != NULL){
        if(cz->nro.cuotas>30){
            nuevo = (puntero)malloc(sizeof(struct nodo));
            nuevo->nro.plan = cz->nro.plan;
            strcpy(nuevo->nro.nya,cz->nro.nya);
            nuevo->nro.dni = cz->nro.dni;
            nuevo->nro.cuotas = cz->nro.cuotas;

            nuevo->sig = cz2;
            cz2 = nuevo;
        }
        cz = cz->sig;
    }
}

void recorrer(puntero cz){
    while(cz != NULL){
        printf("Plan: %d\n",cz->nro.plan);
        printf("DNI: %d\n",cz->nro.dni);
        printf("Nya: %s\n",cz->nro.nya);
        printf("Cuotas: %d\n\n",cz->nro.cuotas);
        cz = cz->sig;
    }
}

int main(){
    puntero cabeza,cabeza2;
    crear(&cabeza);
    crear(&cabeza2);
    insertar(&cabeza);

    licitar(cabeza,cabeza2);

    recorrer(cabeza);
    recorrer(cabeza2);

    getchar();
    getchar();
}