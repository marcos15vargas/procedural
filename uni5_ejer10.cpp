#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
    char nom[30];
    float prom;
    int year;
}Alumno;

struct nodo{
    Alumno datos;
    struct nodo*sig;
};

typedef struct nodo * Puntero;

typedef struct{
    char nom_f[30];
    Puntero cabeza;
}Facultad;

//item a
void carga(Puntero *cz){
        Puntero p, nuevo, anterior;
        int cant;
        printf("Cantidad de alumnos a ingresar: ");
        scanf("%d",&cant);

        for (int i = 0; i < cant; i++){    
            nuevo=(Puntero)malloc(sizeof(struct nodo));
            printf("ingrese el nombre del estudiante \n");
            scanf("%s",&nuevo->datos.nom);
            printf("ingrese el promedio\n");
            scanf("%f",&nuevo->datos.prom);
            printf("ingrese el año \n");
            scanf("%d",&nuevo->datos.year);
            
            if(*cz==NULL){
                *cz=nuevo;
                nuevo->sig=NULL;
            }else{
                if((*cz)->datos.prom==nuevo->datos.prom){
                        nuevo->sig= *cz;
                        *cz =nuevo;
                }
                else{
                    p=*cz;
                    anterior=*cz;
                    while((p!=NULL)&&(nuevo->datos.prom>p->datos.prom)){
                        anterior=p;
                        p=p->sig;
                    }
                    anterior->sig=nuevo;
                    nuevo->sig=p;
                    
                }
            }   
        }
        
}

void mostrar(Puntero cz){
    while (cz != NULL) {
        printf("Alumno: %s, Promedio: %.2f, Año: %d\n", cz->datos.nom, cz->datos.prom, cz->datos.year);
        cz = cz->sig;
    }
}
void carga_f(Facultad *ar, int n){
        int i;
        for(i=0;i<n;i++){
            printf("ingrese el nombre de facultad \n");
            scanf("%s",&ar[i].nom_f);
            ar[i].cabeza=NULL;
            carga(&ar[i].cabeza);
            mostrar(ar[i].cabeza);
        }
}
//item b
int InscriptosCant(Puntero cz){
    int c=0;
    while(cz != NULL){
        c++;
        cz = cz -> sig;
    }
    return c;
}

void inscriptosMin(Facultad *ar,int n){
    int min=99999, i, ci, nfc;
    for(i=0;i<n;i++){
        ci=InscriptosCant(ar[i].cabeza);
        if(ci<min){
            min=ci;
            nfc=i;
        }
    }
    printf("%s: ", ar[nfc].nom_f);
    printf("La cantidad de inscriptos es: %d \n", min);
}

//item c
void recorrerLista(int *cont,Puntero P){ //Recursiva
    if(P==NULL){
        //caso base
        return;
    }else{
        //caso general
        if((P->datos.year>= 2) &&  (P->datos.prom>=7)){
                *cont=*cont+1;
                
        }
        P=P->sig;
        recorrerLista(cont,P);
    }     
}
void recorrerArre(Facultad arre[],int i,int *cont,int T,Puntero P){ //Recursiva
    if (i>=T){
        //caso base
        return;
    }else{
        //caso general
        P=arre[i].cabeza;
        recorrerLista(cont,P);
        printf("la cantidad de alumnos inscriptos a la facultad %s es de %d",arre[i].nom_f,*cont);
        *cont=0;
        recorrerArre(arre,i=i+1,cont,T,P);
    }
}



int main(){
    Facultad *arr;
    Puntero P;
    int T,i=0,cont=0;

    printf("Ingrese la cantidad de facultades: ");
    scanf("%d",&T);
    arr=(Facultad*)malloc(sizeof(Facultad)*T);

    //item a
    carga_f(arr,T);
    //item b
    inscriptosMin(arr,T);
    //item c
    recorrerArre(arr,i,&cont,T,P);

    free(arr);
    getchar();
    getchar();
}