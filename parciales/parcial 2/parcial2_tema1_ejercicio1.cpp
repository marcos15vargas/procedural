#include<stdio.h>
#include<malloc.h>

typedef struct{
    char nom[20];
    int dni;
    int edad;
}Socios;

void listar(FILE *archi,int cont){
    Socios c;
    rewind(archi);
    while(fread(&c,sizeof(Socios),1,archi)){
        if(c.edad>50){
            printf("Nombre: %s, DNI: %d, Edad: %d\n",c.nom,c.dni,c.edad);
        }
        if(c.edad>21){
            cont++;
        }
    }
}

void mayores_21(FILE *archi, Socios *ar){
    Socios c;
    rewind(archi);
    int i;
    while(fread(&c,sizeof(Socios),1,archi)){
        if(c.edad>21){
            ar[i] = c;
            i++;
        }   
    }
}

void promedio(Socios *arr,int &total,int cont, int i){
    if(i==cont){
        return;
    }else{
        total+=arr->edad;
        promedio(arr,total,cont,i+1);
    }
}


int main(){
    Socios *arr;
    FILE *archi;
    int cont,total,i=0;
    float prom;

    if ((archi == fopen("SOCIOS.DAT","r")==NULL)){
        printf("Error al abrir el archivo");
    }else{
        listar(archi,cont);
        arr = (Socios*)malloc(sizeof(Socios)*cont);
        mayores_21(archi,arr);
        promedio(arr,total,cont,i);
        prom = total/cont;
        printf("Edad promedio del arreglo dinamico: %f",prom);
        fclose(archi);
    }
    free(arr);
    getchar();
    getchar();
}