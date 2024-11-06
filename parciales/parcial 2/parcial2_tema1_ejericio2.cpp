#include<stdio.h>
#include<malloc.h>

typedef struct{
    int cod;
    int stock;
    float precio;
}Productos;

typedef struct{
    int codigo;
    int cant;
}Ventas;

struct nodo{
    Ventas dato;
    struct nodo*sig; 
};

typedef struct nodo*puntero;

void crear(puntero &cbza){
    cbza=NULL;
}
void carga_venta(puntero &cbza,int &aux){
    puntero nuevo;
    printf("Ingrese codigo de producto vendido: ");
    scanf("%d",&aux);
    if(aux==0){
        return;
    }else{
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->dato.codigo = aux;
        printf("Ingrese la cantidad: ");
        scanf("%d",&nuevo->dato.cant);
        nuevo->sig = cbza;
        cbza=nuevo;
        carga_venta(cbza,aux);
    }
}

void actualizar(FILE *archi,puntero cbza){
    Productos c;
    while(cbza!=NULL){
        fseek(archi,(cbza->dato.codigo-100)*sizeof(Productos),SEEK_SET);
        fread(&c,sizeof(c),1,archi);
        c.stock = c.stock - cbza->dato.cant;

        fseek(archi,-sizeof(Productos),SEEK_CUR);
        fwrite(&c,sizeof(c),1,archi);
        cbza=cbza->sig;
    }
    printf("archivo actualizado");
}


int main(){
    puntero cbza;
    FILE *archi;
    int aux;
    crear(cbza);
    carga_venta(cbza,aux);

    if((archi=fopen("PRODUCTOS.DAT","a+"))==NULL){
        printf("Error en el archivo.");
    }else{
        actualizar(archi,cbza);
        fclose(archi);
    }
    free(cbza);

    getchar();
    getchar();
}