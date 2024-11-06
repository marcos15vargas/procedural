#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodo{
	int codi;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &cbza){
	cbza=NULL;
	return;
}

void insertar(puntero &cbza){
	puntero nuevo;
	int cod;
	printf("Ingrese el codigo: ");
	scanf("%d",&cod);
		while(cod != 0){
			nuevo=(puntero)malloc(sizeof(struct nodo));
			nuevo->codi=cod;
			nuevo->sig=cbza;
			cbza=nuevo;
			printf("Ingrese el codigo: ");
			scanf("%d",&cod);
		}
	return;	
}		

void recorre(puntero cbza){
	while(cbza != NULL){
		printf("\n%d\n",cbza->codi);
		cbza=cbza->sig;
	}
	return;
}

void buscar(puntero cbza){
	int cod;
	printf("Ingrese codigo a buscar: ");
	scanf("%d",&cod);
	while((cbza != NULL)&&(cbza->codi != cod)){
		cbza=cbza->sig;
	}
	if(cbza == NULL){
		printf("No se encontro\n");
	}
	else{
		printf("Se encontro\n");
	}
}

void modificar(puntero &cbza){
	int nuevo,viejo;
	printf("Ingrese num viejo: \n");
	scanf("%d",&viejo);
	printf("Ingrese num nuevo: \n");
	scanf("%d",&nuevo);
	while((cbza != NULL)&&(cbza->codi != viejo)){ // corto por cortocircuito si cbza->codi == viejo va al if
		cbza=cbza->sig;
	}
	if(cbza != NULL){ // verifica que no llego al final y modifica
		cbza->codi=nuevo;
	}
	else{ // llego al final por lo tanto no esta ese numero viejo
		printf("Llego al final y el numero no esta \n");
	}
	return;	
}

void suprimir(puntero &cbza){
	puntero anterior;
	puntero p;
	int cod;
	printf("Ingrese el codigo a suprimir: ");
	scanf("%d",&cod);
	if(cbza->codi == cod){
		p=cbza;
		cbza=cbza->sig;
		free(p);
	}else{
		p=cbza;
		anterior=cbza;
		while((p != NULL)&&(p->codi != cod)){
			anterior=p;
			p=p->sig;
		}
		if(p != NULL){
			anterior->sig=p->sig;
			free(p);
			printf("El numero fue eliminado de la lista");
		}
		else{
			printf("El numero no se encontro");
		}
	}
	return;	
}

void mostrar(puntero cbza){
	while(cbza != NULL){
		printf("\n%d\n",cbza->codi);
		cbza=cbza->sig;
	}
	return;
}

int main(){
	puntero cabeza;
	crear(cabeza);
	insertar(cabeza);
	recorre(cabeza);
	buscar(cabeza);
	suprimir(cabeza);
	mostrar(cabeza);
}
