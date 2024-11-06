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
    int codi;				
	if(cod == 0){
		return;
	}
    if(cbza == NULL){// inserta el primer nodo si esta vacia
		xnuevo=(puntero)malloc(sizeof(struct nodo));
		xnuevo->cant_nuevos+=1;
		xnuevo->codigo=cod;
		xnuevo->sig=NULL;
		cbza=xnuevo;// cbza guarda la direccion del primer nodo
		xp=cbza;// actualiza xp
	}else{
        if((xp != NULL)&&(xp->codigo != cod)){// verifica si el codigo es distinto, avanza al sig nodo
			xanterior=xp;
			xp=xp->sig;
        }
        if((xp == NULL)&&(xp->codigo != cod)){// llego al final y el codigo es distinto, crea otro nodo
            xnuevo=(puntero)malloc(sizeof(struct nodo));
            xnuevo->cant_nuevos+=1;
            xnuevo->codigo=cod;
            xnuevo->sig=xp;// apunta al nodo sig (NULL si es el fin)
			if(xanterior != NULL){// conecta el nuevo nodo
				xanterior->sig=xnuevo;
			}else{
				cbza=xnuevo;// inserta al inicio
			}
        }else{// busca y encuentra un nodo ya creado y solamente incrementa
            xp->cant_nuevos+=1;
        }
    }
    // llamada recursiva
    printf("Ingrese nuevo codigo (finaliza con 0): ");
    scanf("%d",&codi);
    cod=codi;
    insertar(cbza,cod,xnuevo,xp,xanterior);
}


void modificar(FILE *archi, puntero cbza){ // cantidad de asistentes
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