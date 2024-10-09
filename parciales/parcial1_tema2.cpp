#include<stdio.h>

#define L 100
#define Q 15

struct Libros{
    int cod;
    char nom[50];
    float precio;
    int stock;
};

void cerear(int ar[L][Q]){
    for (int i = 0; i < L; i++){
        for (int j = 0; j < Q; j++){
            ar[i][j]=0;
        }

    }
}
void carga_libros(Libros ar[L],int ind){
    int code = 0;
    if(ind == L){
        return;
    }else{
        printf("\nIngresar Codigo de libro: ");
        scanf("%d",&code);
        ar[ind].cod = code;
        fflush(stdin);
        printf("Ingresar nombre del libro: ");
        gets(ar[ind].nom);
        fflush(stdin);
        printf("Ingresa precio de venta: $");
        scanf("%f",&ar[ind].precio);
        fflush(stdin);
        printf("Ingresa stock del libro: ");
        scanf("%d",&ar[ind].stock);

        carga_libros(ar,ind+1);
    }
}
void carga_venta(Libros ar[L],int ven[L][Q]){
    int code=0,dia,cant;
    printf("Ingresa codigo de libro(terimnar con 0): ");
    scanf("%d",&code);
    if(code == 0){
        return;
    }else{
        if(ar[code-1].stock > 0){
            printf("Ingrese dia que se vendio el libro: ");
            scanf("%d",&dia);
            printf("Ingresar cantidad de libros se vendio: ");
            scanf("%d",&cant);
            ven[code-1][dia-1] += cant;
            ar[code-1].stock-=1;
            carga_venta(ar,ven);
        }else{
            printf("Libro sin stock.\n");
            carga_venta(ar,ven);
        }
    }
}

void listado_libros(Libros ar[L],int ind){
    if(ind == L){
        return;
    }else{
        printf("\nNombre del libro: %s\n",ar[ind].nom);
        printf("Precio de venta: $%.2f\n",ar[ind].precio);
        printf("Stock: %d\n",ar[ind].stock);
        listado_libros(ar,ind+1);
    }
}

void info_venta_libro(int ven[Q],Libros ar[L],int code){
    int total_vend=0;
    float total;
    for(int c = 0; c < Q; c++){
        total_vend += ven[c];
    }
    total= total_vend * ar[code-1].precio;
    printf("\nInfo de venta de: %s\n",ar[code-1].nom);
    printf("Cantidad de libros vendidos: %d\n",total_vend);
    printf("Total recaudado : $%f\n",total);
}

int info_venta_dia(int ven[L][Q],int dia){
    int total=0;
    for (int i = 0; i < L; i++){
        total += ven[i][dia];
    }
    return total;
}

void total_vendidos(int ven[L][Q],int &total){
    for (int f = 0; f < L; f++){
        for (int c = 0; c < Q; c++){
            total += ven[f][c];
        }
    }
}

int main(){
    Libros lib[L];
    int vent[L][Q], i=0,item3,item4,total_item4,total=0;


    carga_libros(lib,i);
    cerear(vent);
    carga_venta(lib,vent);

    //item2
    listado_libros(lib,i);

    //item3
    printf("Ingrese codigo de libro para saber info de venta: ");
    scanf("%d",&item3);
    info_venta_libro(vent[item3-1],lib,item3);

    //item4
    printf("Ingrese dia para saber info de venta(1-15): ");
    scanf("%d",&item4);
    total_item4 = info_venta_dia(vent,item4);
    printf("\nTotal de libros vendidos el dia %d: %d",item4,total_item4);

    //item5
    total_vendidos(vent,total);
    printf("\nTotal de libros vendidos: %d",total);



    getchar();
    getchar();
}