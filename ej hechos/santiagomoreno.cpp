//Nombre: Santiago Alejandro Moreno Sanchez | JTP: Maria Jose Sarmiento
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo{
	int cod; 
	char tit[50]; 
	char aut[50]; 
	float pre; 
	int cant;
	struct nodo* sig;
};
typedef struct nodo* libro;

void crear(libro &xp){
	xp=NULL;
}

void insertar(libro &xp){
	libro nuevo;
	nuevo=(libro)malloc(sizeof(struct nodo));
	printf("Ingrese el Codigo del Libro: ");
	scanf("%d",&nuevo->cod);
	fflush(stdin);
	printf("Ingrese el Titulo del Libro: ");
	gets(nuevo->tit);
	fflush(stdin);
	printf("Ingrese el Nombre del Autor: ");
	gets(nuevo->aut);
	fflush(stdin);
	printf("Ingrese el Precio del Libro: ");
	scanf("%f",&nuevo->pre);
	printf("Ingrese la Cantidad de Libros: ");
	scanf("%d",&nuevo->cant);
	nuevo->sig=xp;
	xp=nuevo;
}

float buscar(libro xp,int xcod,char *xtit,char *xaut){
	if(xp!=NULL){
		if(xp->cod==xcod){
			strcpy(xtit,xp->tit);
			strcpy(xaut,xp->aut);
			return (xp->pre);
		}
		else{
			buscar(xp->sig,xcod,xtit,xaut);
		}
	}else{
		printf("El Codigo Ingresado no Corresponde a Ningun Libro.\n");
		return();
	}
}

/*void busca(puntero xp, int xcod, char* tit, char* aut, float* pre){
    if(xp==NULL){
        printf("\nEl libro no se encuentra.");
    }else if(xp->datos.cod==xcod){
        strcpy(tit, xp->datos.tit);
        strcpy(aut, xp->datos.aut);
        *pre = xp->datos.pre;
    }else{
        busca(xp->sig,xcod,tit,aut,pre);
    }
} */
void mostrar(libro xp){
	if(xp!=NULL){
		printf("Titulo: ");
		puts(xp->tit);
		printf("Codigo: %d\n",xp->cod);
		printf("Autor: ");
		puts(xp->aut);
		printf("Cantidad: %d\n",xp->cant);
		printf("Precio: %.2f\n",xp->pre);
		printf("\n");
		mostrar(xp->sig);
	}
}

void eliminar(libro &xp,int xcod){
	libro anterior,p;
	if(xp!=NULL){
		if(xp->cod==xcod){
			p=xp;
			xp=xp->sig;
			free(p);
			printf("Se Elimino el Libro.\n");
		}
		else{
			anterior=xp;
			p=xp;
			while((p!=NULL)&&(p->cod!=xcod)){
				anterior=p;
				p=p->sig;
			}
			anterior->sig=p->sig;
			free(p);
			printf("Se Elimino el Libro.\n");
		}
	}
	else{
		printf("La lista esta vacia.\n");
	}
}

float contar(libro xp){
	float tot=0;
	while(xp!=NULL){
		tot+=xp->pre*xp->cant;
		xp=xp->sig;
	}
	return(tot);
}

int main(){
	libro L;
	int opcion, codigo;
	char titulo[50], autor[50];
	float precio, total;
	crear(L);
	printf("* Menu de opciones *\n");
		printf("1. Agregar Libro a la Lista\n");
		printf("2. Buscar un Libro en la Lista\n");
		printf("3. Mostrar Lista Invertida\n");
		printf("4. Eliminar un Libro de la Lista\n");
		printf("5. Calcular Importe total\n");
		printf("6. Salir\n");
		printf("Seleccione su Opcion: ");
		scanf("%d",&opcion);
		printf("\n");
	while(opcion!=6){
		switch(opcion){
			case 1: 
				insertar(L);
				break;
			case 2:
				printf("Ingrese el Codigo del Libro que Desea Buscar: ");
				scanf("%d",&codigo);
				precio=buscar(L, codigo, titulo, autor);
				if(precio!=0){
					printf("Para el Libro con Codigo %d:\n", codigo);
					printf("Nombre: ");
					puts(titulo);
					printf("Autor: ");
					puts(autor);
					printf("Precio: %.2f\n",precio);
	}
				break;
			case 3:
				mostrar(L);
				break;
			case 4:
				printf("Ingrese el Codigo del Libro que Desea Eliminar: ");
				scanf("%d",&codigo);
				eliminar(L, codigo);
				break;
			case 5:
				total=contar(L);
				printf("El Importe Total de los Libros es de: %.2f", total);
				break;
			case 6:
				printf("Saliendo...");
				break;
		}
		printf("\n");
		printf("* Menu de opciones *\n");
		printf("1. Agregar Libro a la Lista\n");
		printf("2. Buscar un Libro en la Lista\n");
		printf("3. Mostrar Lista Invertida\n");
		printf("4. Eliminar un Libro de la Lista\n");
		printf("5. Calcular Importe total\n");
		printf("6. Salir\n");
		printf("Seleccione su Opcion: ");
		scanf("%d",&opcion);
		printf("\n");
	}
}
