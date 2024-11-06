#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct socio{
    char nombre[40];
    int dni;
    int edad;
};

void carga(FILE *archi){
    socio a;
    printf("Ingrese nombre:\n");
    fflush(stdin);
    gets(a.nombre);
    while(stricmp(a.nombre,"FIN")!=0){
        printf("Ingrese edad:\n");
        scanf("%d",&a.edad);
        printf("Ingrese dni:\n");
        scanf("%d",&a.dni);
        fwrite(&a,sizeof(a),1,archi);
        printf("Ingrese nombre:\n");
        fflush(stdin);
        gets(a.nombre);
    }
}

//Tema 1 inciso 1
void listar(FILE *archi,int &cont){
    socio a;
    rewind(archi);
    while(fread(&a,sizeof(a),1,archi)){
        if(a.edad>50){
            printf("Nombre: %s\t Dni: %d\t Edad: %d\n",a.nombre,a.dni,a.edad);
        }
        if(a.edad>21){
            cont++;//cuenta los socios que cumplen la condicion para luego almacenarlos en el arreglo dinamico
        }
    }
}

//Tema 2 inciso 1
void listar2(FILE *archi, int &cont){
    socio a;
    rewind(archi);
    while(fread(&a,sizeof(a),1,archi)){
        if(a.dni<20000000){
            printf("Nombre: %s\t Dni: %d\t Edad: %d\n",a.nombre,a.dni,a.edad);
        }
        if(a.edad>40){
            cont++;//cuenta los socios que cumplen la condicion para luego almacenarlos en el arreglo dinamico
        }
    }
}

//Tema 1 inciso 2
void cargaArre(FILE *archi,socio *a){
    socio aux;
    rewind(archi);
    int i=0;
    while(fread(&aux,sizeof(aux),1,archi)){
        if(aux.edad>21){
            a[i]=aux;
            i++;
        }
    }
}

//Tema 2 inciso 2
void cargaArre2(FILE *archi,socio *a){
    socio aux;
    rewind(archi);
    int i=0;
    while(fread(&aux,sizeof(aux),1,archi)){
        if(aux.edad>40){
            a[i]=aux;
            i++;
        }
    }
}
void mostrar(socio *a,int N){
    for(int i=0;i<N;i++){
        printf("Nombre: %s\t Dni: %d\t Edad: %d\n",a[i].nombre,a[i].dni,a[i].edad);
    }
}

void prom(socio *a, int N,int i,int suma){
    if(i==N){
        printf("Edad promedio: %d",suma/N);
        return;
    }else{
        suma+=a[i].edad;
        prom(a,N,i+1,suma);
    }
}


int main(){
    FILE *archi=fopen("SOCIOS.DAT","a+");
    socio *arre1,*arre2;
    int cont1=0, cont2=0;
    if(archi==NULL){
        printf("Error al abrir el archivo");
    }else{
        //Tema1
        carga(archi);
        listar(archi,cont1);
        arre1=(socio*)malloc(sizeof(socio)*cont1);
        if(arre1==NULL){
            printf("Error generando arreglo\n");
        }else{
            cargaArre(archi,arre1);
            mostrar(arre1,cont1);
            prom(arre1,cont1,0,0);
            fclose(archi);
        }
        //Tema2
        listar2(archi,cont2);
        arre2=(socio*)malloc(sizeof(socio)*cont2);
        if(arre2==NULL){
            printf("Error generando arreglo\n");
        }else{
            cargaArre2(archi,arre2);
            mostrar(arre2,cont2);
            prom(arre2,cont2,0,0);
        }
        fclose(archi);
    }
}

/*Lote de prueba
Juan
70
12542235
Luana
15
49526582
Mariano
22
40568952
Maria
44
22568984
Karina
45
21999845
Fin
*/
