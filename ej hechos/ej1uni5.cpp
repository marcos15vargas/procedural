/* Ejercicio 1
Escribir un programa en lenguaje C que usando funciones permita:
a) Crear y cargar 2 arreglos dinámicos de componentes enteras MxM (mismo tamaño) ingresada por teclado.
b) Calcular el producto escalar.
El producto escalar es una operación donde al multiplicar dos arreglos se obtiene un único valor.
A * B = A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1]
c) Generar una nueva estructura con los valores pares contenidos en uno de los arreglos (realizar un subprograma
que solicite memoria para la nueva estructura y la devuelva cargada).
d) Realizar el mapa de memoria con el siguiente lote de prueba, específicamente al momento de la carga de un
vector, creación y carga de la nueva estructura.
Arreglo A={1, 2, 3}
Arreglo B={4, 5, 6} */

#include <stdio.h>
#include <malloc.h>

void carga(int *arreglo, int m,int i) {
    for (i=0; i<m; i++) {
    	printf("Ingrese el arreglo A y B: ");
        printf("Elemento %d: ", i);
        scanf("%d",&arreglo[i]);
    }
}

int escalar(int *A, int *B, int m) {
    int i,producto=0;
    for (i=0; i<m; i++) {
        producto+=A[i]*B[i];
    }
    return producto;
}

int val_pares(int *arreglo, int m, int *&n_pares) {
	int tamanio;
    int i,j=0;
    printf("Ingrese el tamanio de los arreglos: ");
    scanf("%d",&tamanio);
    printf("\n"); 
    n_pares=(int*) malloc(sizeof(int)*tamanio);
    for (i=0; i<m; i++) {
        if (arreglo[i] % 2 == 0) {
            n_pares[j]=arreglo[i];
            j++;
        }
    }
    return j;
}

int main(){
    int i,m, producto;
    int *A;
    int *B;
    int *n_pares;
    int c=0;
    printf("Ingrese el tamanio de los arreglos: ");
    scanf("%d",&m);
    A=(int*) malloc(sizeof(int)*m);
    B=(int*) malloc(sizeof(int)*m);
    carga(A,m,i);
    carga(B,m,i);
    
    producto=escalar(A,B,m);
    printf("El producto escalar de A y B es: %d\n",producto);
    printf("\n"); 
    
    c=val_pares(A,m,n_pares);
	for(i=0; i<c ; i++){
	printf("Valores pares en el arreglo A: %d\n",n_pares[i]);   	
	}
    free(A);
    free(B);
    free(n_pares);
}
