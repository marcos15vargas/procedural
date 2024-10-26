//Marcos Vargas
//jtp: Marcelo Mondre grupo 6

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int cod;
    char titulo[50];
    char aut[50];
    float precio;
    int stock;
}Libros;

struct nodo{
    Libros datos;
    struct nodo *sig;
};

typedef struct nodo * puntero;



void crear(puntero &xp){
    xp=NULL;
}

void insertar (puntero &cz){
    puntero nuevo;
    int cod;
    printf("Ingrese el codigo del libro: ");
    scanf("%d",&cod);
    while(cod !=0){
        nuevo=(puntero) malloc(sizeof(struct nodo));
        nuevo->datos.cod=cod;
        printf("Ingrese el titulo del libro: ");
        fflush(stdin);
        gets(nuevo->datos.titulo);
        printf("Ingrese el autor del libro: ");
        fflush(stdin);
        gets(nuevo->datos.aut);
        printf("Ingrese el precio del libro: $");
        scanf("%f",&nuevo->datos.precio);
        printf("Ingrese la cantidad del libro: ");
        scanf("%d",&nuevo->datos.stock);
        nuevo->sig=cz;
        cz=nuevo;
        printf("Ingrese el codigo del libro: ");
        scanf("%d",&cod);
    }
}

void busqueda(puntero &cz,int code,char* autor,char* titulo,float* precio){
    if(cz==NULL){
        printf("El codigo no se encuentra en la lista.");
    }else if(cz->datos.cod == code){
        strcpy(autor,cz->datos.aut);
        strcpy(titulo,cz->datos.titulo);
        *precio = cz->datos.precio;
    }else{
        busqueda(cz->sig,code,autor,titulo,precio);
    }
}


void listar(puntero cz){
    if(cz==NULL){
        return;
    }else{
        printf("Codigo: %d\nTitlo: %s\nAutor: %s\nPrecio: $%.2f\nStock: %d\n\n",cz->datos.cod,cz->datos.titulo,cz->datos.aut,cz->datos.precio,cz->datos.stock);
        cz=cz->sig;
        listar(cz);
    }
}
void suprimir(puntero &cz){
    puntero anterior,p;
    int code;
    printf("Ingrese codigo de libro para borrarlo: ");
    scanf("%d",&code);
    if(cz->datos.cod == code){
        p=cz;
        cz=cz->sig;
        free(p);
    }else{
        p=cz;
        anterior=cz;
        while((p!=NULL)&&(p->datos.cod!=code)){
            anterior=p;
            p=p->sig;
        }
        if(p!=NULL){
            anterior->sig = p->sig;
            free(p);
            printf("\nEl libro fue borrado correctamente.\n");
        }else{
            printf("\nNo se encontro Libro en la lista.\n");
        }
    }
}

float total(puntero cz){
    float total=0;
    while(cz!=NULL){
        total += cz->datos.precio * cz->datos.stock;
        cz=cz->sig;
    }
    return(total);
}


int main(){
    puntero arr;
    char autor[50],titulo[50];
    int item2;
    float total_libros,precio;


    crear(arr);
    insertar(arr);

    printf("Ingrese codigo de libro para saber su informacion: ");
    scanf("%d",&item2);
    busqueda(arr,item2,autor,titulo,&precio);
    printf("Autor: %s, Titulo: %s, Precio: %.2f\n\n",autor,titulo,precio);


    listar(arr);

    suprimir(arr);

    total_libros = total(arr);
    printf("\nTotal de importe de libros: $%.2f",total_libros);

    getchar();
    getchar();
}