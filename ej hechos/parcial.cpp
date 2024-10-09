#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 15

typedef struct{
	int numero;
	char nombre[10];
	float precio;
	char estado;
}herramientas;

void carga(herramientos arre[]){
	int i;
		for(i=0 ; i<N; i++){
			printf("Ingrese el numero de la herramienta que pertenece al codigo %d: ",i+1)
			gets(arre[i].nombre);
			printf("Ingrese el precio de la herramienta: ");
			scanf("%f",&arre[i].precio);
			printf("Ingrese el estado de la herramienta (S para alquilada o N para no alquilada): ");
			scanf("%c",&arre[i].estado);
		}
	return;
}

void cereo(int tabla[][]){
	int i,j;
		for (i=0 ; i < N; i++){
			for(j=0 ; j < M ; j++){
				tabla[i][j]=0;
			}
		}
	return;	
}

void procesa(int tabla[][], herramientas arre[]){
	int cant_h;
	int num,dia;
	print("Ingrese el numero de herramienta (0 para finalizar): ");
	scanf("%d",&num);
		while(num != 0){
			printf("Ingrese el dia en el que se alquilo: ");
			scanf("%d",&dia);
			printf("Ingrese la cantidad de horas alquilada: ");
			scanf("%d",&cant_h);
			
				if(arre[num-1].estado == 'N' ){
					tabla[num][dia]=cant_h;
					arre[num-1].estado='S';
				}
			print("Ingrese el numero de herramienta (0 para finalizar): ");
			scanf("%d",&num);
		}
	return;	
}

void listado(herramientas arre[]){
	int i;
		if(i < N){
			printf("El nombre de la herramienta %d es: %s",i+1,arre[i].nombre);
			printf("El precio de alquiler por hora es: %f",arre[i].precio);
			printf("El estado de la herramienta es: %c",arre[i].estado);
			i=i+1;
			listado(arre,i);
		}
	return;	
}

void mostrar(int tabla[M],herramientas arre[],int num_herr){
	int i;
	int acum_h=0;
	float precio_final;
		if(arre[num_herr-1].estado == 'S'){
			for(i=0 ; i<M ; i++){
				acum_h+=tabla[i];
			}
			precio_final=acum_h * arre[num_herr-1].precio;
			printf("La cantidad total de horas en la quincena son: %d",acum_h);
			printf("El importe total a cobrar es de: %f",precio_final);
		}
	return;
}

int muestra(int tabla[][], herramientas arr[],int xdia, int *acum){
	int i;
	int cont=0;
		for(i=0 ; i < N ; i++){
			*acum+=tabla[i][xdia-1];
			if(arre[i].estado == 'S')
				cont++;
		}
	return (cont);
}

void alq_quincena(int tabla[][]){
	int i,j,acum=0;
		for(i=0 ; i < N ; i++){
			for(j=0 ; j < M ; j++){
				acum+=tabla[i][j];
			}
		}
	printf("El total de horas alquiladas en toda la quincena es de: %d",acum);
	return;
}

int main(){
	herramientas arreglo[N];
	carga(arreglo);
	int tabla[N][M];
	cereo(tabla);
	procesa(tabla,arreglo);
	listado(arreglo);
	int num_herra;
	printf("Ingrese un numero de herramienta: ");
	scanf("%d",&num_herra);
	mostrar(tabla[num_herra-1],arreglo,num_herra);
	int dia;
	int total_alquiladas;
	int acumulador=0;
	printf("Ingrese un dia: ");
	scanf("%d",&dia);
	total_alquiladas=muestra(tabla,arreglo,dia,&acumulador);
	printf("El total de herramientas alquiladas es de : %d",total_alquiladas);
	printf("El total de horas en alquiler es de: %d",acumulador);
	alq_quincena(tabla);
}