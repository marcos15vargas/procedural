// Ejercicio 2
// Dado un arreglo de N componentes enteras hacer en forma recursiva:
// a) Cargar el arreglo.
// b) Mostrar el arreglo en forma invertida.
// c) Decir cuántas componentes son positivas y cuantas negativas. (hacer una función que devuelva ambos
// resultados).
// Nota: Hacer mapa de memoria para un subprograma
// Lote de prueba usado en el mapa de memoria: 3(cantidad de componentes), 2,-2,3


#include<stdio.h>

void carga(int arr[],int cant,int &i){
    if(i!=cant){
        printf("\nIngrese el valor de la componente %d: ",i+1);
        scanf("%d",&arr[i]);
        i++;
        carga(arr,cant,i);
    }
}

void invertido(int arr[],int cant){
    if(cant != 0){
        printf(" %d",arr[cant - 1]);
        cant-= 1;
        invertido(arr,cant);
    }
}

void pos_neg(int arr[],int cant, int &pos,int &neg,int &cont){
    if(cont != cant){
        cont++;
        if(arr[cont]>=0){
            pos++;
        }else{
            neg++;
        }
        pos_neg(arr,cant,pos,neg,cont);
    }
}

int main(){
    int cant,pos = 0,neg = 0,i = 0,cont = 0;

    printf("Ingresa la cantidad de componentes: ");
    scanf("%d",&cant);

    int arr[cant];

    carga(arr,cant,i);
    invertido(arr,cant);
    pos_neg(arr,cant,pos,neg,cont);

    printf("\nLa cantidad de componentes positivos son: %d",pos);
    printf("\nLa cantidad de componentes negativos son: %d",neg);

    getchar();
    getchar();
}