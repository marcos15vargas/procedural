#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
    int cod;
    char nom[30];
    int rubro;
    float precio;
    int stock;
}Productos;

struct nodo{
    Productos datos;
    struct nodo*sig;
};

typedef struct nodo*puntero;

void crear(puntero &cbza){
    cbza=NULL;
}

void insertar(puntero &cbza){
    puntero nuevo;
    int codigo;
    printf("Ingrese codigo de producto(teremina con 0): ");
    scanf("%d",&codigo);
    while(codigo!=0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->datos.cod=codigo;
        printf("Ingrese nombre del producto: ");
        gets(nuevo->datos.nom);
        printf("Ingrese rubro: ");
        scanf("%d",&nuevo->datos.rubro);
        printf("Ingrese precio: ");
        scanf("%f",&nuevo->datos.precio);
        printf("Ingrese stock: ");
        scanf("%d",&nuevo->datos.stock);
        nuevo->sig = cbza;
        cbza=nuevo;
        printf("Ingrese codigo de producto(teremina con 0): ");
        scanf("%d",&codigo);
    }
}

puntero bus_prod(puntero cbza,char elem[30]){
    while((cbza!=NULL)&&(strcmp(cbza->datos.nom,elem))){
        cbza= cbza->sig;
    }
    return(cbza);
}

void total_inv(puntero cbza, float &total){
    if(cbza==NULL){
        return;
    }else{
        total = total + (cbza->datos.precio*cbza->datos.stock);
        total_inv(cbza->sig,total);
    }
}
void cerear_arr(int *arr[6]){
    for (int i = 0; i < 6; i++){
        *arr[i]=0;
    }
}
void generar_arr(puntero cbza,int *arr[6]){
    while (cbza!=NULL){
        *arr[cbza->datos.rubro-1]+=cbza->datos.stock;
        cbza=cbza->sig;
    }
}
void mostrar_arreglo(int *arr[6]){
    for (int i = 0; i < 6; i++){
        printf("cantidad de productos vendidos en el rubro %d: %d",i+1,*arr[i]);
    }
}

void actualizar_archivo(FILE *archi,puntero cbza){
    Productos c;
    while(cbza!=NULL){
        fseek(archi,(cbza->datos.cod-100)*sizeof(Productos),SEEK_SET);
        fread(&c,sizeof(c),1,archi);
        c.stock-=cbza->datos.stock;
        fseek(archi,-sizeof(Productos),SEEK_CUR);
        fwrite(&c,sizeof(c),1,archi);
        cbza=cbza->sig;
    }
    
}

int main(){
    puntero cbza,busq;
    FILE *archi;
    float total=0;
    int *arr[6];
    char elem[30];

    crear(cbza);
    insertar(cbza);
    printf("Ingrese nombre del producto para saber su info: ");
    gets(elem);
    busq = bus_prod(cbza,elem);
    if(busq==NULL){
        printf("El producto no existe");
    }else{
        printf("Codigo: %d,Nombre: %s,Rubro: %d,Precio: %.2f,Stock: %d",busq->datos.cod,busq->datos.nom,busq->datos.rubro,busq->datos.precio,busq->datos.stock);
    }

    cerear_arr(arr);
    generar_arr(cbza,arr);
    mostrar_arreglo(arr);

    if((archi=fopen("inventario.dat","a+"))==NULL){
        printf("Error al abrir el archivo.");
    }else{
        actualizar_archivo(archi,cbza);
        fclose(archi);
    }
    free(cbza);
    free(busq);
    getchar();
    getchar();
}