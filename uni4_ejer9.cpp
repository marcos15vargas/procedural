#include<stdio.h>

#define C 3
#define S 5

void carga(float arr[C][S],int f,int c){
    float valor;
    if(f==C){
        return;
    }else{
        if (c<S){
            printf("ingrese el valor de la tabla [%d][%d]\n",f,c);
            scanf("%f",&valor);
            arr[f][c]=valor;
            carga(arr,f,(c)+1);
        }else{
            carga(arr,(f)+1,0);  
        }
    }
}

void itemA(float arr[C],int c,float &total){
    if(c==S){
        return;
    }else{
        total = total + arr[c];
        itemA(arr,c+1,total);
    }
}

void itemB(float arr[C][S],int f,float &total){
    if(f==C){
        return;
    }else{
        total = total + arr[f][3];
        itemB(arr,f+1,total);
    }
}

void itemC(float arr[C][S],int f,int c,float &total){
    if(f==C){
        return;
    }else{
        if(c==S){
            itemC(arr,f+1,0,total);
        }else{
            total = total + arr[f][c];
            itemC(arr,f,c+1,total);
        }
    }
}

void itemD(float arr[C][S],int f,int c,float valor){
    if(f==C){
        return;
    }else{
        if(c==S){
            return;
        }else{
            if(arr[f][c]>valor){
                printf("Monto superior a $%.2f: $%.2f \n",valor,arr[f][c]);
                itemD(arr,f,c+1,valor);
            }
            itemD(arr,f+1,0,valor);
        }
    }
}


void mostrar(float arr[C][S],int f,int c){

    if(f==C){
        return;
    }else{
        if(c<S){
            printf("[%.2f]",arr[f][c]);
            mostrar(arr,f,(c)+1);
        }else{
            printf("\n");
            mostrar(arr,(f)+1,0);
        }
    }
}

int main(){
    float arr[C][S]{2,7.5,9,2.5,3.5,13,45.5,55,15,22.5,100,360,450,125,180},total=0,valorD;
    int f=0,c=0,valorA;

    // carga(arr,f,c);
    // mostrar(arr,f,c);

    printf("Ingrese categoria(1,2,3) para saber su total financiado: ");
    scanf("%d",&valorA);

    itemA(arr[valorA-1],c,total);
    printf("\nTotal financiado: $%.2f",total);
    total=0;

    itemB(arr,f,total);
    printf("\nTotal de sector servicios: $%.2f",total);
    total=0;


    itemC(arr,f,c,total);
    printf("\nTotal financiado: $%.2f",total);

    printf("\nIngrese el valor para saber si es superior o inferior: ");
    scanf("%f",&valorD);
    itemD(arr,f,c,valorD);


    getchar();
    getchar();
}

