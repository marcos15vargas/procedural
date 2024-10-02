#include<stdio.h>
#include <string.h>
#define P 50
#define O 22

struct productos{
    int cod;
    float costo;
    int stock;
};
struct proveedores{
    char nombre[20];
    int num;
    int cant;
};

void carga_info(productos p[P],proveedores o[O]){
    printf("Carga de Productos\n");
    for(int i=0;i<P;i++){
        p[i].cod = i+1;
        printf("Ingrese el costo del producto %d: ",i+1);
        scanf("%f",&p[i].costo);
        p[i].stock = 0;
    }
    printf("Carga de Proveedores\n");
    for(int i=0;i<O;i++){
        o[i].num = i + 1000;
        printf("Ingrese el nombre del proveedor %d: ",i+1000);
        scanf("%s",&o[i].nombre);
        o[i].cant = 0;
    }
}

void carga(productos p[P],proveedores o[O]){
   int num,cod,uni;
   printf("Ingrese numero de proveedor: ");
   scanf("%d",&num);
   while (num!=0){
        printf("Ingrese codigo de producto: ");
        scanf("%d",&cod);
        printf("Ingrese cantidad de unidades: ");
        scanf("%d",&uni);
        p[cod].stock = p[cod].stock + uni;
        o[num - 1000].cant = o[num - 1000].cant + uni;
        printf("Ingrese numero de proveedor(terminar con 0): ");
        scanf("%d",&num);
   }
}

void mostrar_inv(productos p[P]){
    float total = 0;
    for(int i=0;i<P;i++){
        total = p[i].stock * p[i].costo;
        printf("Invertido en el producto %d: $%.2f\n",i+1,total);
        total = 0;
    }
}

void mostrar(productos p[P],proveedores o[O]){
    for(int i=0;i<P;i++){
        printf("Info de producto %d\n",i+1);
        printf("Costo: $%.2f\n",p[i].costo);
        printf("Stock: %d\n\n",p[i].stock);
    }
    for(int i=0;i<O;i++){
        printf("Info de Proveedor %d\n",i+1);
        printf("Numero de proveedor: %d\n",o[i].num);
        printf("Nombre: %s\n",o[i].nombre);
        printf("cantidad de unidades: %d\n\n",o[i].cant);
    }
}

int generar_sub(proveedores o[O],proveedores sub[O]){
    int cont = 0;
    for(int i=0;i<O;i++){
        if(o[i].cant > 10){
            sub[cont] = o[i];
            cont++;
        }
    }
    return cont;
}
void ordenamiento(proveedores sub[O],int cont){
    int k,cota;
    proveedores aux;
    cota=cont-1;
    k = 1;
    while (k!=-1){
        k=-1;
        for(int i=0;i<=cota-1;i++){
            if(strcmp(sub[i].nombre, sub[i+1].nombre) > 0){
                aux = sub[i];
                sub[i] = sub[i+1];
                sub[i+1] = aux;
                k = i;
            }
        }
        cota = k;
    }
}

void mostrar_sub(proveedores sub[O],int cont){
    printf("Proveedores con mas de 10 unidades\n");
    for(int i=0;i<cont;i++){
        if(sub[i].cant > 10){
            printf("Numero de proveedor: %d\n",sub[i].num);
            printf("Nombre: %s\n",sub[i].nombre);
            printf("cantidad de unidades: %d\n\n",sub[i].cant);
        }
    }
}
void cerear_sub(proveedores sub[O]){
    for(int i=0;i<O;i++){
        sub[i].cant = 0;
        sub[i].num = 0;
        strcpy(sub[i].nombre,"");
    }
}
void mostrar_prov(proveedores o[O],int pos){
    printf("Info de Proveedor %d\n",pos+1);
    printf("Numero de proveedor: %d\n",o[pos].num);
    printf("Nombre: %s\n",o[pos].nombre);
    printf("cantidad de unidades: %d\n\n",o[pos].cant);  
}

int buscar(proveedores arr[O], int size, char elem[]) {
    int inf = 0, sup = size - 1, medio;
    while (inf <= sup) {
        medio = (inf + sup) / 2;
        int cmp = strcmp(elem, arr[medio].nombre);
        if (cmp == 0) {
            return medio;
        } else if (cmp < 0) {
            sup = medio - 1;
        } else {
            inf = medio + 1;
        }
    }
    return -1;  // No encontrado
}

int main(){
    productos p[P];
    proveedores o[O];
    proveedores sub[O];

    int cant_sub,pos;
    char elem[20];

    carga_info(p,o);
    carga(p,o);
    mostrar_inv(p);
    cant_sub = generar_sub(o,sub);
    ordenamiento(sub,cant_sub);
    mostrar_sub(sub,cant_sub);


    printf("\n\nIngresa el nombre de un proveedor para mostrar sus datos: ");
    scanf("%s",&elem);

    pos = buscar(sub,cant_sub,elem);
    if(pos != -1){
        mostrar_prov(sub,pos);
    }else{
        printf("No se encontro el proveedor");
    }

    getchar();
    getchar();
}