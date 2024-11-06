/* Parcial 2 2023

Ejercicio 1

Se tiene el archivo "SOCIOS.DAT" con la informacion de las personas afiliadas a un club. De cada uno se conoce nombre,dni y edad
Hacer un programa en lenguaje C que usando funciones optimas permita:

1)	Hacer un listado de los socios mayores a 50 años
2)	Generar un arreglo dinamico con la informacion de los socios mayores a 21
3)	Decir la edad promedio de los socios cargados en el arreglo. Resolver este item con al menos una funcion recursiva */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nombre[20];
	int dni;
	int edad;
}afiliados;

void carga(FILE *archi, afiliados xdatos){
	char nom[20];
	printf("Ingrese el nombre de la persona afiliada (FIN para finalizar): ");
	gets(nom);
		while(strcmp(nom, "FIN")){
			xdatos.nombre=nom;
			printf("Ingrese el dni: ");
			scanf("%d",&xdatos.dni);
			printf("Ingrese la edad: ");
			scanf("%d",&xdatos.edad);
			fwrite(&xdatos,sizeof(xdatos),1,archi);
			printf("Ingrese el nombre de la persona afiliada (FIN para finalizar): ");
			gets(nom);
		}
	return;
}

/* 1)	Hacer un listado de los socios mayores a 50 años */
void listado(FILE *archi,afiliados xdatos){
	rewind(archi);
		while(fread(&xdatos,sizeof(xdatos),1,archi)){
			if(xdatos.edad > 50){
				printf("El nombre es: %s",xdatos.nombre);
				printf("El dni es: %d",xdatos.dni);
				printf("La edad es: %d",xdatos.edad);
			}
		}
	return;	
}

// 2)	Generar un arreglo dinamico con la informacion de los socios mayores a 21

int contar(FILE *archi,*FILE *archi2, afiliados xdatos){
	int cont=0;
		while(fread(&xdatos,sizeof(xdatos),1,archi)){
			if(xdatos.edad > 21){
				cont++;
				fwrite(&xdatos,sizeof(xdatos),1,archi2);
			}
		}
	return cont;	
}

void generar(FILE *archi,FILE *archi2, afiliados xdatos, int xmayores){
	int i;
	afiliados *arre;
	arre=(*afiliados)malloc(sizeof(afiliados)*xmayores);
		for(i=0 ; i<mayores ; i++){
			fread(&arre[i],sizeof(xdatos),1,archi2);
		}
	return;
}

int main(){
	FILE *archi;
	FILE *archi2;
	afiliados datos;
	int mayores;
		if((archi=fopen("SOCIOS.DAT","w+") == NULL)&&(archi2=fopen("MAYOR.DAT","w+") == NULL)){
		printf("archivo: %s",archi);
		}
		else{
			carga(archi,datos);
			listado(archi,datos);
			mayores=contar(archi,archi2,datos);
			generar(archi,archi2,datos,mayores);
		}
}