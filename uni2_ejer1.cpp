#include<stdio.h>

void carga (int arr[]){
    for (int i = 0; i < 20; i++){
        printf("Ingrese un valor: ");
        scanf("%d",&arr[i]);
    }
}
void mostrar_ceros (int arr[]){
    for (int i = 0; i < 20; i++){
        if (arr[i] == 0){
            printf("\nNumero en la posicion %d es cero ",i);
        }
    }
}
void mostrar_pares (int arr[]){
    printf("\nLos numeros en posiciones pares son: ");
    for (int i = 0; i < 20; i++){
        if (i % 2 == 0){
            printf("%d - ",arr[i]);
        }
    }
}
void contador_pares (int arr[]){
    int pares = 0;
    for (int i = 0; i < 20; i++){
        if (arr[i] % 2 == 0){
            pares++;
        }
    }
    printf("\nLa cantidad de numeros pares es: %d",pares);
}

int main(){
    int arr[20];

    carga(arr);
    mostrar_ceros(arr);
    mostrar_pares(arr);
    contador_pares(arr);

    getchar();
    getchar();
}