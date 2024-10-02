#include<stdio.h>
#include<malloc.h>

typedef struct{
    int dni;
    int cod;
    float monto;
}adj;

void carga(adj *a, int cant){
    for (int i = 0; i < cant; i++){
        printf("Ingres el dni: ");
        scanf("%d",&a[i].dni);
        printf("Ingres el codigo: ");
        scanf("%d",&a[i].cod);
        printf("Ingres el monto: ");
        scanf("%f",&a[i].monto);
    }
}
void mostrar_adj(adj *a,int cant){
    int num;
    printf("Ingrese dni para mostrar el plan y monto: ");
    scanf("%d",&num);
    for (int i = 0; i < cant; i++){
        if (a[i].dni == num){
            printf("DNI: %d\n",a[i].dni);
            printf("CODIGO: %d\n",a[i].cod);
            printf("MONTO: %.2f\n",a[i].monto);
        }
    }
}
int cont_plan(adj *a,int cant,int plan){
    int cont=0;
    for(int i = 0; i < cant; i++){
        if(a[i].cod == plan){
            cont++;
        }
    }
    return cont;
}

int main(){

    adj *a;
    int cant;

    printf("Ingres la cantidad de adjudicatarios: ");
    scanf("%d",&cant);

    a = (adj*)malloc(cant*sizeof(adj));

    carga(a,cant);

    mostrar_adj(a,cant);

    printf("\nEl plan %d tiene %d personas\n",1,cont_plan(a,cant,1));
    printf("\nEl plan %d tiene %d personas\n",2,cont_plan(a,cant,2));
    printf("\nEl plan %d tiene %d personas\n",3,cont_plan(a,cant,3));
    printf("\nEl plan %d tiene %d personas\n",4,cont_plan(a,cant,4));
    printf("\nEl plan %d tiene %d personas\n",5,cont_plan(a,cant,5));

    free(a);

    getchar();
    getchar();
}