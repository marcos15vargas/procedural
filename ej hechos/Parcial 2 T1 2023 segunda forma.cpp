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

void generar(FILE *archi, afiliados xdatos, afiliados &arre){
	rewind(archi);
	arre=(*afiliados)malloc(sizeof(afiliados)*xmayores);
		while(fread(&xdatos,sizeof(&xdatos),1,archi){
			if(xdatos.edad > 21){
			arre[i]=xdatos;
			}
		}		
	return;
}

// 3)	Decir la edad promedio de los socios cargados en el arreglo. Resolver este item con al menos una funcion recursiva

void prom(afiliados arre, int xcont, int xacum, int i){
	if(i < xcont){
		xacum+=arre[i].edad;
		prom(arre,xcont,xacum,i+1);
	}
	else{
		return;
	}
}
int main(){
	FILE *archi;
	FILE *archi2;
	afiliados datos;
	int i=0;
	afiliados *arre;
	int mayores;
	int acum=0;
		if((archi=fopen("SOCIOS.DAT","w+") == NULL)&&(archi2=fopen("MAYOR.DAT","w+") == NULL)){
		printf("archivo: %s",archi);
		}
		else{
			carga(archi,datos);
			listado(archi,datos);
			while(fread(&xdatos,sizeof(xdatos),1,archi)){
				if(xdatos.edad > 21){
				cont++;
				}
			}
		arre=(*afiliados)malloc(sizeof(afiliados)*cont);
		//mayores=contar(archi,archi2,datos);
		generar(archi,datos,arre);
		prom(arre,cont,acum,i);
		}	
}