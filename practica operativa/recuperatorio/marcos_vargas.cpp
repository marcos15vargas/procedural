//jtp: Marcelo Mondre
//nombre: Marcos Facundo Vargas Fredes
#include<stdio.h>
#define M 4
#define A 3

void cereo(int arr[M][A]){
    int f,c;
    for (f = 0; f < M; f++){
        for (c = 0; c < A; c++){
            arr[f][c] = 0;
        }
    }
}
void carga(int arr[M][A]){
    int nm,ac;
    printf("Ingresar Ano de cursado: ");
    scanf("%d",&ac);
    while (ac!=0){
        printf("Ingresar numero de materia: ");
        scanf("%d",&nm);
        arr[nm-1][ac-1]+=1;
        printf("Ingresar Ano de cursado: ");
        scanf("%d",&ac);
    }
}
void total_por_materia(int arr[M][A]){
    int f,c,total;
    for (f = 0; f < M; f++){
        total=0;
        for (c = 0; c < A; c++){
            total+=arr[f][c];
        }
        printf("\nTotal inscriptos en materia %d : %d",f+1,total);
    }
}

int tpa(int arr[M][A],int an){
    int f,tot=0;
    for (f = 0; f < M; f++){
        tot += arr[f][an];
    }
    return tot;
}


int main(){

    int ins[M][A],anio,total_anio;
    cereo(ins);
    carga(ins);
    total_por_materia(ins);

    printf("\nIngrese un ano de cursado para saber su total de inscriptos: ");
    scanf("%d",&anio);

    total_anio = tpa(ins,anio-1);

    printf("\nLa cantidad total de inscriptos en el ano cursado %d es : %d",anio,total_anio);
    
    getchar();
    getchar();
}
