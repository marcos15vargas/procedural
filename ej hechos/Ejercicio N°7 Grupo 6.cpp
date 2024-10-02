#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4

struct Nodo{
	char Nom[10];
	char Ape[10];
	char Pais[10];
	int Cant_G;
	struct Nodo *Siguiente;	
};
typedef struct Nodo * Puntero;

typedef struct{
	char Pais[10];
	int Cant_Estadios;
	int Ano;
	Puntero Nodo ;
}Datos;

void Crear(Datos Arre[N], Datos Arre2[N]) {
	int i;
	for(i=0;i<N;i++){
		Arre[i].Nodo = NULL;
		Arre2[i].Nodo = NULL;
	}
	Arre[0].Ano = 2010;
	strcpy(Arre[0].Pais, "ARG");
	Arre[0].Cant_Estadios = 2;

	Arre2[0].Ano = Arre[0].Ano;
	strcpy(Arre2[0].Pais, "ARG");
	Arre2[0].Cant_Estadios = 2;

	Arre[1].Ano = 2014;
	strcpy(Arre[1].Pais, "BR");
	Arre[1].Cant_Estadios = 4;

	Arre2[1].Ano = 2014;
	strcpy(Arre2[1].Pais, "BR");
	Arre2[1].Cant_Estadios = 4;

	Arre[2].Ano = 2018;
	strcpy(Arre[2].Pais, "BOL");
	Arre[2].Cant_Estadios = 6;

	Arre2[2].Ano = 2018;
	strcpy(Arre2[2].Pais, "BOL");
	Arre2[2].Cant_Estadios = 6;

	Arre[3].Ano = 2022;
	strcpy(Arre[3].Pais, "CHI");
	Arre[3].Cant_Estadios = 8;

	Arre2[3].Ano = 2022;
	strcpy(Arre2[3].Pais, "CHI");
	Arre2[3].Cant_Estadios = 8;
}

void Carga(Datos Arre[N]) {
	char Pais[10];
	Puntero Nuevo;
	int i;
	for(i=0;i<N;i++) {
		printf("CARGA DE LOS JUGADORES DEL ANO %d \n", Arre[i].Ano);
		printf("Ingrese pais del jugador (ARG,BR,BOL,CHI) o FIN para cambiar de ano \n");
		fflush(stdin);
		gets(Pais);
		while(strcmp(Pais,"FIN") != 0) {
			Nuevo = (Puntero)malloc(sizeof(struct Nodo));
			printf("Ingrese nombre del jugador \n");
			fflush(stdin);
			gets(Nuevo->Nom);

			printf("Ingrese apellido del jugador \n");
			fflush(stdin);
			gets(Nuevo->Ape);

			printf("Ingrese cantidad de goles del jugador \n");
			scanf("%d",&Nuevo->Cant_G);

			strcpy(Nuevo->Pais, Pais);

			Nuevo->Siguiente=Arre[i].Nodo;
			Arre[i].Nodo=Nuevo;

			printf("Ingrese pais del jugador (ARG,BR,BOL,CHI) o FIN para cambiar de ano \n");
			fflush(stdin);
			gets(Pais);
		}
	}
}

void Contar(Datos &Arre, int &J_Arg, int &G_5) {
	Puntero Nuevo;
	Nuevo= Arre.Nodo;
	while(Nuevo!=NULL) {
		if(strcmp(Nuevo->Pais,"ARG") == 0) {
			J_Arg++;
		}
		if(Nuevo->Cant_G>= 5) {
			G_5++;
		}
		Nuevo=Nuevo->Siguiente;
	}
}

void Eliminar_Jugador(Datos Arre[N],char *nombre,char *apellido) {
	Puntero actual, anterior;
	int i;
	for(i=0;i<N;i++){
		actual = Arre[i].Nodo;
		anterior = NULL;
		while(actual!=NULL) {
			if(strcmp(actual->Nom, nombre) == 0 && strcmp(actual->Ape, apellido) == 0) {
				if(anterior==NULL){
					Arre[i].Nodo = actual->Siguiente;
				}else {
					anterior->Siguiente = actual->Siguiente;
				}
				free(actual);
				printf("Jugador %s %s eliminado del mundial %d.\n", nombre, apellido, Arre[i].Ano);
				return;
			}
			anterior=actual;
			actual=actual->Siguiente;
		}
	}
	printf("Jugador no encontrado.\n");
}

void Generar_Estructura_Goleadores(Datos Arre[N], Datos Arre2[N]) {
	Puntero actual, nuevo, aux;
	int i;
	for (i=0;i<N;i++) {
		actual=Arre[i].Nodo;
		while(actual!=NULL) {
			if(actual->Cant_G>=3){
				nuevo = (Puntero)malloc(sizeof(struct Nodo));
				strcpy(nuevo->Nom,actual->Nom);
				strcpy(nuevo->Ape,actual->Ape);
				strcpy(nuevo->Pais,actual->Pais);
				nuevo->Cant_G=actual->Cant_G;
				nuevo->Siguiente=NULL;
				aux=Arre2[i].Nodo;
				nuevo->Siguiente=aux;
				Arre2[i].Nodo=nuevo;
			}
			actual=actual->Siguiente;
		}
	}
}

int main() {
	Datos Arre[N], Arre2[N];
	int J_Arg = 0, G_5 = 0;

	Crear(Arre, Arre2);
	Carga(Arre);

	for (int i = 0; i < N; i++) {
		Contar(Arre[i], J_Arg, G_5);
	}

	printf("Cantidad de jugadores argentinos: %d\n", J_Arg);
	printf("Cantidad de jugadores con más de 5 goles: %d\n", G_5);

	char nombre[10], apellido[10];
	printf("Ingrese el nombre del jugador a eliminar: ");
	gets(nombre);
	printf("Ingrese el apellido del jugador a eliminar: ");
	gets(apellido);
	Eliminar_Jugador(Arre, nombre, apellido);

	Generar_Estructura_Goleadores(Arre, Arre2);

	return 0;
}
