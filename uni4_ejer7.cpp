#include<stdio.h>
#define N 10

void carga(int arr[N],int i){
    if(i==N){
        return;
    }else{
        printf("Ingrese valor: ");
        scanf("%d",&arr[i]);
        carga(arr,(i)+1);
    }
}
void mayor(int arr[N],int i, int &may){
    // if(i<N){
    //     if(arr[i] > may){
    //         may = arr[i];
    //     }
    //     mayor(arr,(i)+1,may);
    // }
    // if(arr[i]==may){
    //     printf("\nComponente %d es igual al valor mayor",i);
    // }

    if(i==N){
        return;
    }else{
        if(arr[i] > may){
            may = arr[i];
        }
        mayor(arr,(i)+1,may);
    }
    if(arr[i]==may){
        printf("\nComponente %d es igual al valor mayor",i);
    }
    
}

int main(){
    int arr[N],i=0,may=0;

    carga(arr,i);
    mayor(arr,i,may);

    getchar();
    getchar();
}