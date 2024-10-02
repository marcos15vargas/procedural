#include<stdio.h>
#include<malloc.h>

struct nodo{
    int nro;
    struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &cz){
    cz = NULL;
}

void carga_ordernada(puntero &cz){
    int dato;
    puntero nuevo,anterior,aux;

    printf("Ingrese un numero positivo: ");
    scanf("%d",&dato);

    if(dato){
        if(dato>0){
            nuevo = (puntero)malloc(sizeof(struct nodo));
            nuevo->nro = dato;
            if(cz == NULL){//Caso 1 --> Lista vacia
                cz = nuevo;
                nuevo->sig = NULL;
            }else{
                if(dato < cz->nro){//Caso 2 --> El dato es menor al primero
                    nuevo->sig = cz;
                    cz = nuevo;
                }else{//Caso 3 --> El dato es mayor o igual al primero
                    aux = cz->sig;
                    anterior = cz;
                    while((aux != NULL) && (aux->nro < nuevo->nro)){
                        anterior = aux;
                        aux = aux->sig;
                    }
                    anterior->sig = nuevo;
                    nuevo->sig = aux;
                }
            }
        }else{
            printf("Error: El dato debe ser positivo\n");
        }
        carga_ordernada(cz);
    }
}

void ultimo_par(puntero cz){
    if(cz != NULL){
        if(cz->sig != NULL){
            cz=cz->sig;
            ultimo_par(cz);
        }else if(((cz->nro)%2)==0){
            printf("El ultimo numero es par: %d\n",cz->nro);
        }else {
            printf("El ultimo numero es impar: %d\n",cz->nro);
        }
    }
}
void mostrar_inverso(puntero cabeza) {
  if (cabeza->sig == NULL){
    printf("%d ", cabeza->nro);
    return;
  }else{
    mostrar_inverso(cabeza->sig);
  }
  printf("%d ", cabeza->nro);
}

void mostrar(puntero cz){
    if(cz != NULL){
        printf("%d ",cz->nro);
        mostrar(cz->sig);
    }
}

int main(){
    puntero cabeza;

    crear(cabeza);

    carga_ordernada(cabeza);

    mostrar(cabeza);
    printf("\n");
    mostrar_inverso(cabeza);

    free(cabeza);
    getchar();
    getchar();
}