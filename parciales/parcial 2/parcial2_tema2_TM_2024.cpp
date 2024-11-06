#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
    int code;
    char titulo[30];
    int categoria;
    float precio;
    int cant;
}Libros;


struct nodo{
    Libros datos;
    struct nodo*sig;
};

typedef struct nodo*puntero;

void crear(puntero &cbza){
    cbza=NULL;
}
void carga_ventas(puntero &cbza){
    puntero nuevo;
    int cod;
    printf("Ingresa codigo de libro: ");
    scanf("%d",&cod);
    while(cod!=0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->datos.code = cod;
        printf("Ingrese Titulo: ");
        gets(nuevo->datos.titulo);
        printf("Ingrese categoria: ");
        scanf("%d",&nuevo->datos.categoria);
        printf("Ingrese precio: ");
        scanf("%f",&nuevo->datos.precio);
        printf("Ingrese cantidad: ");
        scanf("%d",&nuevo->datos.cant);
        nuevo->sig=cbza;
        cbza=nuevo;
        printf("Ingresa codigo de libro: ");
        scanf("%d",&cod);
    }
}

puntero busqueda_libro(puntero cbza){
    char aux[30];
    printf("Ingrese titulo para buscar libro: ");
    gets(aux);

    while((cbza!=NULL)&&(strcmp(aux,cbza->datos.titulo))){
        cbza = cbza->sig;
    }
    return(cbza);
}

void total_inv(puntero cbza,float &total){
    if(cbza==NULL){
        return;
    }else{
        total = total + (cbza->datos.cant * cbza->datos.precio);
        total_inv(cbza->sig,total);
    }
}
int generar_arreglo(puntero cbza,int *arr[5]){
    while(cbza!=NULL){
        *arr[cbza->datos.categoria-1]+= cbza->datos.cant;
        cbza=cbza->sig;
    }
}
void mostrar_arreglo(int *arr[5]){
    for (int i = 0; i < 5; i++){
        printf("Categoria %d: %d libros vendidos\n",i+1,arr[i]);
    }
}

void actualizar_archivo(FILE *archi,puntero cbza){
    Libros c;
    rewind(archi);
    while(cbza!=NULL){
        fseek(archi,(cbza->datos.code-1)*sizeof(Libros),SEEK_SET);
        fread(&c,sizeof(c),1,archi);
        c.cant-=cbza->datos.cant;
        fseek(archi,-sizeof(Libros),SEEK_CUR);
        fwrite(&c,sizeof(c),1,archi);
    }
}

int main(){
    puntero cbza,busq;
    FILE *archi;
    float total=0;
    int *arr[5];


    crear(cbza);
    carga_ventas(cbza);
    busq = busqueda_libro(cbza);
    if(busq==NULL){
        printf("El libro no existe.");
    }else{
        printf("Codigo: %d\nTitulo: %s\nCategoria: %d\nPrecio: %.2f\nCantidad: %d",busq->datos.code,busq->datos.titulo,busq->datos.categoria,busq->datos.precio,busq->datos.cant);
    }

    total_inv(cbza,total);
    printf("Valor total del inventario: %.2f",total);

    generar_arreglo(cbza,arr);
    mostrar_arreglo(arr);

    if((archi=fopen("catalogo.dat","a+"))==NULL){
        printf("Error al abrir el archivo");
    }else{
        actualizar_archivo(archi,cbza);
        fclose(archi);
    }

    free(busq);
    free(cbza);

    getchar();
    getchar();
}