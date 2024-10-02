#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(int arre[5][4]){
    int i, j;
    srand(time(NULL));
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            arre[i][j] = rand() % 200; // rango para incluir números mayores a 100
            printf("%d ", arre[i][j]);
        }
        printf("\n");    
    }
}

void sumaF(int arre[5][4]){
    int i, j, acum;
    for(i=0; i<5; i++){
        acum = 0;
        for(j=0; j<4; j++){
            acum+=arre[i][j];
        }
        printf("La suma de la fila %d es: %d\n",i+1,acum);
    }
}

void promedio(int arre[5][4]){
    int i, sum=0;
    float promedio;
    for(i=0; i<5; i++){
        sum+=arre[i][2];
    }
    promedio=sum/5.0; // se pone .0 para que sea division flotante
    printf("El promedio de la tercera columna es: %.2f\n",promedio);
}

void contMayores(int arre[5][4]){
    int i, j, contador = 0;
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if(arre[i][j] > 100){
                contador++;
            }
        }
    }
    printf("Cantidad de numeros mayores a 100: %d\n",contador);
}

int main(){
    int arre[5][4];
    carga(arre);
    sumaF(arre);
    promedio(arre);
    contMayores(arre);

    return 0;
}