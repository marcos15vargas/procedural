#include<stdio.h>
#define F 3
#define C 3

void carga(int arr[F][C],int fil,int col,int &filC,int &colC){
    if (filC == fil && colC == col){
        return;
    }else{
        printf("\nIngrese componente: ");
        scanf("%d",&arr[filC][colC]);
        if(colC = col){
            carga(arr,fil,col,filC+=1,colC=0);
        }else{
            carga(arr,fil,col,filC,colC+=1);
        }
    }
}

int main(){
    int fil,col,filC=0,colC=0;

    printf("Ingresa la cantidad de filas: ");
    scanf("%d",&fil);
    printf("Ingresa la cantidad de columnas: ");
    scanf("%d",&col);

    int arr[fil][col];

    carga(arr,fil,col,filC,colC);

    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
    

    getchar();
    getchar();
}