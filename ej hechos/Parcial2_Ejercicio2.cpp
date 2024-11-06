#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct producto{
    int cod,stock;
    float precio;
};
struct nodo{
    int cod,cant;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void carga(FILE *archi){
    producto a;
    fpos_t x;
    printf("Ingrese stock:\n");
    scanf("%d",&a.stock);
    while(a.stock!=0){
        fgetpos(archi,&x);
        int cod=(int)(x/sizeof(producto))+100;
        a.cod=cod;
        printf("Ingrese precio:\n");
        scanf("%f",&a.precio);
        fwrite(&a,sizeof(a),1,archi);
        printf("Ingrese stock:\n");
        scanf("%d",&a.stock);
    }
}

void crear(puntero &xp){
    xp=NULL;
}

void insetar(puntero &xp){
    int c;
    puntero nuevo;
    printf("Ingrese codigo (Mayor a 100):\n");
    scanf("%d",&c);
    if(c!=0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->cod=c;
        printf("Ingrese cantidad vendida:\n");
        scanf("%d",&nuevo->cant);
        nuevo->sig=xp;
        xp=nuevo;
        insetar(xp);
    }
}

void actualizar(puntero xp,FILE *archi){
    producto a;
    while(xp!=NULL){
        fseek(archi,(xp->cod-100)*sizeof(producto),SEEK_SET);
        fread(&a,sizeof(a),1,archi);
        a.stock-=xp->cant;
        fseek(archi,(xp->cod-100)*sizeof(producto),SEEK_SET);
        fwrite(&a,sizeof(a),1,archi);
        xp=xp->sig;
    }
}

void mostrar(FILE *archi){
    producto a;
    rewind(archi);
    while(fread(&a,sizeof(a),1,archi)){
        printf("Cod: %d\t Stock: %d\t Precio: %.2f\n",a.cod,a.stock,a.precio);
    }
}

int main(){
    puntero cab;
    FILE *archi=fopen("PRODUCTO.DAT","a+");
    crear(cab);
    insetar(cab);
    if(archi==NULL){
        printf("Error al abrir el archivo\n");
    }else{
        carga(archi);
        mostrar(archi);
        actualizar(cab,archi);
        mostrar(archi);
        fclose(archi);

    }
}
/*Lote de prueba
100
5
101
1
100
2
102
3
103
1
101
2


50
1000
20
450
10
1000
9
2000
*/
