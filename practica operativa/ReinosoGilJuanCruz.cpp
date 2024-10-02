#include "stdio.h"
#define N 4
#define M 3

void cereo(int v[N][M]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            v[i][j]=0;
        }
    }
}

void carga(int v[N][M]){
    int cerv;
    int neg;
    int vent;
    for(int j=0; j<M; j++){
        printf("ingrese tipo de cerveza: ");
        scanf("%d",&cerv);
        while(cerv!=0){
            printf("\nIngrese cantidad de ventas: ");
            scanf("%d",&vent);
            v[cerv-1][j]+=vent;
            printf("ingrese tipo de cerveza: ");
            scanf("%d",&cerv);
        }
    }
}

void cantotal(int v[N][M]){
    int acum=0;
    for(int i=0; i<N; i++){
        acum=0;
        for(int j=0; j<M; j++){
            acum+=v[i][j];
        }
        printf("\nEl total de unidades vendidas de la cerveza %d es: %d", i+1, acum);
    }
}

int item4(int v[M]){
    int uvs=0;
    for(int j=0; j<M; j++){
        uvs+=v[j];
    }
    return uvs;
}

int main(){
    int v[N][M];
    cereo(v);
    carga(v);
    cantotal(v);
    int tc=0;
    printf("\nIngrese tipo de cerveza que desea saber el total: ");
    scanf("%d", &tc);
    int total=item4(v[tc]);
    printf("el total de unidades vendidas de la cerveza %d es: %d",tc, total);
}
//JTP: Malena Paez
