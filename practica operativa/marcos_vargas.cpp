//jtp: Marcelo Mondre - Turno Tarde
//Nombre: Marcos Facundo Vargas Fredes

#include<stdio.h>
#define C 4
#define N 3

void cerear (int arr[C][N]){
    for(int i = 0; i < C; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = 0;
        }
    }
}

void carga (int arr[C][N]){
    int tipo,cant;
    for(int i = 0; i < N; i++){
        printf("Ingrese ventas de negocio %d\n",i+1);
        printf("Ingrese el tipo de cerveza: ");
        scanf("%d", &tipo);
        while (tipo != 0){
            printf("Ingrese cantidad de cervezas vendidas: ");
            scanf("%d", &cant);
            arr[tipo - 1][i] += cant;
            printf("Ingrese el tipo de cerveza: ");
            scanf("%d", &tipo);
        }
    }
}

void total_unidades (int arr[C][N]){
    for(int i = 0; i < C; i++){
        int total = 0;
        for(int j = 0; j < N; j++){
            total += arr[i][j];
        }
        printf("\nTotal de unidades vendidas de tipo %d: %d\n",i+1,total);
    }
}

int tipo_total (int arr[N]){
    int total = 0;
    for(int i = 0; i < N; i++){
        total += arr[i];
    }
    return total;
}

void mostrar_arreglo (int arr[C][N]){
    for(int i = 0; i < C; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int arr[C][N],tipo;

    cerear(arr);
    carga(arr);
    total_unidades(arr);

    printf("Ingrese un codigo de cerveza para saber la cantidad de cervezas vendidas: ");
    scanf("%d", &tipo);

    printf("La cantidad de cervezas vendidas del tipo %d es: %d\n",tipo,tipo_total(arr[tipo-1]));
    

    
    // mostrar_arreglo(arr); funcion para mostrar el arreglo
    getchar();
    getchar();
}