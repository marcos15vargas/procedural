#include<stdio.h>
#define L 6

void cerear(int arr[L],int &i){
    if(i<L){
        arr[i] = 0;
        i++;
        cerear(arr,i);
    }
}
void cargar(int arr[L],int num){
    if (num != 0){
        arr[num - 1] += 1;
        printf("Ingrese el lenguaje seleccionado(terminar con 0): ");
        scanf("%d",&num);
        cargar(arr,num);
    }
}

void lenguajes_menos_4000(int arr[L],int i){
    if(i<L){
        if (arr[i]<4000){
            printf("Lenguaje %d: %d\n",i+1,arr[i]);
        }
        i++;
        lenguajes_menos_4000(arr,i);
    }
}

void lenguaje_mas_elegido(int arr[L],int &i,int &max){
    if(i<L){
        if (arr[i]>arr[max]){
            max = i;
        }
        i++;
        lenguaje_mas_elegido(arr,i,max);
    }
}

void total_encuestados(int arr[L],int &i,int &total){
    if(i<L){
        total += arr[i];
        i+=1;
        total_encuestados(arr,i,total);
    }
}

void lenguaje_menos5000_mas9000(int arr[L],int &i,int &menos5000,int &mas9000){
    if(i<L){
        if (arr[i]<5000){
            menos5000 += 1;
        }
        if (arr[i]>9000){
            mas9000 += 1;
        }
        i++;
        lenguaje_menos5000_mas9000(arr,i,menos5000,mas9000);
    }
}

int main(){
    int arr[L],num,indice = 0,max=0,total=0,menos5000=0,mas9000=0;

    //inicializar arreglo
    cerear(arr,indice);

    //carga de informacion
    printf("Ingrese el lenguaje seleccionado(terminar con 0): ");
    scanf("%d",&num);
    cargar(arr,num);

    //item d
    indice = 0;
    printf("\nLenguajes menos de 4000\n");
    lenguajes_menos_4000(arr,0);

    //item e
    indice = 0;
    lenguaje_mas_elegido(arr,indice,max);
    printf("\nLenguaje mas elegido: %d\n",max+1);

    //item f
    indice = 0;
    total_encuestados(arr,indice,total);
    printf("\nTotal encuestados: %d\n",total);

    //item g
    indice = 0;
    lenguaje_menos5000_mas9000(arr,indice,menos5000,mas9000);
    printf("\nCantidad de lenguajes que fueron elegidos por menos de 5000 encuestados: %d\n",menos5000);
    printf("\nCantidad de lenguajes que fueron elegidos por mas de 9000 encuestados: %d\n",mas9000);

    getchar();
    getchar();
}