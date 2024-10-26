//JTP:Marcelo Mondre
//NYA:Marcos Vargas - Turno Tarde

#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Autos{
    int pat;
    char marca[50];
    char modelo[50];
    int year;
};

struct nodo{
    Autos datos;
    struct nodo *sig;
};

typedef struct nodo*puntero;


void crear(puntero &cbza){
    cbza = NULL;
}

void inserta(puntero &cbza){
    int aux;
    puntero nuevo;
    printf("Ingresa patente(termina con cero): ");
    scanf("%d",&aux);
    while(aux!=0){
        nuevo = (puntero)malloc(sizeof(struct nodo));
        nuevo->datos.pat = aux;
        printf("Ingrese Marca: ");fflush(stdin);
        gets(nuevo->datos.marca);
        printf("Ingrese Modelo: ");fflush(stdin);
        gets(nuevo->datos.modelo);
        printf("Ingrese a�o: ");fflush(stdin);
        scanf("%d",&nuevo->datos.year);
        nuevo->sig = cbza;
        cbza = nuevo;
        printf("Ingresa patente(termina con cero): ");
        scanf("%d",&aux);
    }
}

void busqueda(puntero cbza,Autos &item2,int patente){
    if(cbza == NULL){
        printf("No se encontro la patente.");
    }else if(cbza->datos.pat == patente){
        item2 = cbza->datos;
    }else{
        busqueda(cbza->sig,item2,patente);
    }
}

void listar(puntero cbza,char marca_b[50]){
    if(cbza == NULL){
        return;
    }else{
        if(strcmp(cbza->datos.marca,marca_b)==0){
            printf("Patente: %d ,Modelo: %s ,Año: %d\n",cbza->datos.pat,cbza->datos.modelo,cbza->datos.year);
            cbza = cbza->sig;
        }
        listar(cbza->sig,marca_b);
    }
}

void suprimir(puntero &cbza){
    puntero anterior,p;
    int patente;
    printf("Ingrese patente a eliminar: ");
    scanf("%d",&patente);
    if(cbza->datos.pat == patente){
        p=cbza;
        cbza = cbza->sig;
        free(p);
    }else{
        p = cbza;
        anterior = cbza;
        while((p!=NULL)&&(p->datos.pat != patente)){
            anterior = p;
            p = p->sig;
        }
        if(p!=NULL){
            anterior->sig=p->sig;
            free(p);
            printf("La patente fue eliminada..");
        }else{
            printf("No se encuentra la patente.");
        }
    }
}

void auto_antiguo(puntero cbza,int &min){
    if(cbza==NULL){
        return;
    }else{
        if(min > cbza->datos.year){
            min = cbza->datos.year;
        }
        auto_antiguo(cbza->sig,min);
    }
}

int main(){
    puntero cbza;
    Autos item2;
    int pat_item2,min=9999999;
    char marca_item3[50];

    crear(cbza);
    //item1
    inserta(cbza);
    //item2
    printf("Ingrese patente para saber su informacion: ");
    scanf("%d",&pat_item2);
    busqueda(cbza,item2,pat_item2);
    printf("Marca: %s \nModelo: %s \nAño: %d\n",item2.marca,item2.modelo,item2.year);
    //item3
    printf("Ingresar marca: ");
    fflush(stdin);
    gets(marca_item3);
    listar(cbza,marca_item3);
    //item4
    suprimir(cbza);
    //item5
    auto_antiguo(cbza,min);
    printf("\nEl auto mas antiguo es: %d",min);

    free(cbza);

    getchar();
    getchar();
}
