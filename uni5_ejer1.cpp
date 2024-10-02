#include<stdio.h>
#include<malloc.h>
#define N 3

void carga(int *arr, int cant){
    for (int i = 0; i < cant; i++){
        printf("Ingrese el valor de la componente %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

int pro_esc(int *a, int *b, int cant,int i){
    if(i==cant){
        return 0;
    }else{
        return (a[i]*b[i]) + pro_esc(a,b,cant,(i+1));
    }
}


int busc_par(int *arr, int cant){
    int cont = 0;
    for (int i = 0; i < cant; i++){
        if(arr[i]%2 == 0){
            cont++;
        }
    }
    return cont;
}

void pares(int *arr,int *sub, int cant){
    for (int i = 0; i < cant; i++){
        if(arr[i]%2 == 0){
            sub[i] = arr[i];
        }
    }
}


int main(){
    int *a, *b,*sub, cant_par,total_esc,ind=0;

    a = (int *)malloc(sizeof(int)*N);
    b = (int *)malloc(sizeof(int)*N);

    carga(a,N);
    carga(b,N);

    total_esc = pro_esc(a,b,N,ind);
    printf("El producto escalar es: %d\n",total_esc);

    cant_par = busc_par(a,N);

    sub = (int *)malloc(sizeof(int)*cant_par);
    pares(a,sub,N);

    printf("Los valores pares son: ");
    for(int i=0;i<cant_par;i++){
        printf("%d ",sub[i]);
    }

    free(a);
    free(b);


    getchar();
    getchar();
}