#include<stdio.h>
#include <malloc.h>

void carga(int *arr, int cant){
    for(int i = 0; i < cant; i++){

        printf("Ingrese el valor de la componente %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

int main(){

    int *b;

    b = (int *)malloc(sizeof(int)*10);
    carga(b,10);
    free(b);
    getchar();
    getchar();
}