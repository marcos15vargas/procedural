/* Ejercicio 2
Se tiene el archivo "CONFERENCIA.DAT" con la informacion de las conferencias que se daran en un congreso,de cada conferencia
se conoce: Codigo (a partir de 100), nombre y cantidad de asistentes. El archivo esta ordenado por codigo y permite acceso directo

Por otro lado se registran nuevos inscriptos en las distintas conferencias. De cada inscripto se registra: Codigo de conferencia

Hacer un programa en lenguaje c que usando funciones optimas permita: 
1)	Generar una lista implementada con punteros, que almacene por cada inscripto, el codigo de conferencia. Funcion recursiva
2)	Con la informacion en la lista, actualizar el archivo

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int codi;
	char nom[20];
	int cant;
}confe;

struct nodo{
	int codigo;
	int cant_nuevos=0;
	struct nodo *sig;
};

typedef struct nodo *puntero;

void crear(puntero &cbza){
	cbza=NULL;
	return;
}

void insertar(puntero &cbza, int cod, puntero xnuevo, puntero xp, puntero xanterior){
    if (cod != 0){
        if (cbza == NULL){
            xnuevo=(puntero)malloc(sizeof(struct nodo));
            xnuevo->codigo=cod;
            xnuevo->sig=cbza;
            cbza=xnuevo;
            xp=cbza;
            printf("\nIngrese nuevo codigo (termine con 0): ");
            scanf("%d", &cod);
            insertar(cbza,cod,xnuevo,xp,xanterior);
        }
        else{
            if((xp != NULL)&&(xp->codigo == cod)){
				xp->cant_nuevos+=1;
				xanterior=xp;
                xp=xp->sig;
                insertar(cbza,cod,xnuevo,xp,xanterior);
            }
            else{
            xnuevo=(puntero)malloc(sizeof(struct nodo));
            xnuevo->codigo=cod;
            xnuevo->sig=xp;
            xanterior->sig=xnuevo;
            xanterior=xanterior->sig;
            printf("\nIngrese nuevo codigo (termine con 0): ");
            scanf("%d", &cod);
            insertar(cbza,cod,xnuevo,xp,xanterior);
            }
        }
    }
    return;
}

void modificar(FILE *archi, puntero cbza){// cantidad de asistentes
	confe a;
		if(cbza != NULL){
			fseek(archi,(cbza->codigo-100)*sizeof(a),SEEK_SET);
			fread(&a,sizeof(a),1,archi);
			a.cant=cbza->cant_nuevos;
			fseek(archi,(cbza->codigo-100)*sizeof(a),SEEK_SET);
			fwrite(&a,sizeof(a),1,archi);
			modificar(archi,cbza->sig);
		}
		else{
			return;
		}
}

int main(){
	puntero cabeza,nuevo,p,anterior;
	int codig;
	confe datos;
	FILE *archivo;
	crear(cabeza);
	printf("Ingrese un codigo: ");
	scanf("%d",&codig);
	insertar(cabeza,codig,nuevo,p,anterior);
	archivo=fopen("CONFERENCIA.DAT","a+");
		if(archivo == NULL){
			printf("Error");
		}
		else{
			modificar(archivo,cabeza);
		}
	fclose(archivo);
	free(cabeza);
}