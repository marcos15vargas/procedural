#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define N 12

//inciso A grupo 1//
typedef struct{
        int dni;
        int numero;     
}paciente;
struct nodo{
        paciente datos;
        struct nodo*sig; 
}   
typedef struct nodo*puntero;  
typedef struct {
        int esp;
        char nombre[20];
        puntero cabeza;
}Datos;
void carga (int i,Datos ar[N]){
        if(i<N){
                ar[i].esp=+1;
                printf ("ingrese el nombre se la especialidad \n");
                scanf ("%s",&ar[i].nombre);
                ar[i].cabeza = NULL;
                carga(i+1,ar);
        }
}  

/* Inciso B grupo2*/

void Carga_Turnos(Datos Arre[N]){
    Puntero Nuevo;
    int DNI, Num_E;
    printf("Ingrese numero de DNI o 0 para finalizar\n");
    scanf("%d", &DNI);
    
    if (DNI != 0) {
        printf("Ingrese numero de especialidad entre 1 y %d \n", N);
        scanf("%d",&Num_E);
        Nuevo = (Puntero)malloc(sizeof(struct Nodo));
        
        Nuevo->DNI = DNI;
        Nuevo->Num_E = Num_E;

        Nuevo->sig = Arre[Num_E-1].Nodo;
        Arre[Num_E-1].Nodo = Nuevo;
        Carga_Turnos(Arre);
        }
    }

 printf("-----------------------------------------------------------------------------\n");
 
 /* Inciso C */
void EliminarTurno (Datos Arre[]){
    puntero anterior, p, cab;
    int DNI;
    int NumEspecial;

    printf("\n Ingrese la especialidad del turno");
    scanf("%d",&NumEspecial);
    printf("\n Ingrese el DNI del paciente");
    scanf("%d",&DNI);

    cab=arre[NumEspecialidad-1].Puntero; // iguala el puntero cab a cabeza de la especialidad ingresada.

    if (cab->nodos->datos.dni == DNI){ // si el turno es la Cabeza
        p=cab;
        cab=cab->sig;
        free (p); /*eliminación de la cabeza de la lista */
    }else{
        p=cab;
        anterior=cab;
        while ((p != NULL) && (p->nodos->datos.dni != DNI)){
            anterior = p;
            p=p->sig:
        }
        if (p != NULL){
            anterior->sig = p->sig;
            free(p);
            printf("\n El turno fue eliminado correctamente");
        }else{
            printf("\n No se encuentra un turno con esas caracteristicas");
        }
    }
 return;
}

/*inciso D grupo 4*/
int DatosEspecia (puntero &cab, int c){
        if(cab != NULL)
        {
                c++;
                return DatosEspecia(cab->sig, c);
        } else{
                return c;
        }
}

//Inciso E grupo 5

void busca_dni (Datos arre[N], int i, int dni){
    if(arre[i].cabeza==NULL)
            printf ("El dni no se encuentra en la lista");
    else if (arre[i].cabeza->dni == dni)
            printf ("El dni ingresado se encuentra en la especialidad %d, cuyo nombre es %s", i+1, esp[i].nom);
        else
             busca_dni (esp[i].cabeza->sig, i, dni);
} 


int main(){
Datos arre[N];
int op, num, dni=0, i=0;
do 
{
printf("1: Realizar carga de especialidades");
printf("2: Registrar turno");
printf("3: Eliminar turno");
printf("4: Mostrar nombre y cantidad de pacientes de especiaidad");
printf("5: Informar especialidades en las que se anoto un paciente");
printf("0: SALIR");
scanf("%d",&op);
switch(op){
case 1: carga(0,arre);
break;
case 2: Carga_Turnos(arre);
break;
case 3: EliminarTurno(arre);
break;
case 4:{
printf("Ingrese numero de una especialidad");
scanf("%d",&numE);
c=DatosEspecia(arre[numE-1].cabeza, cont);
}
break;
case 5: scanf("%d", &dni);//lee el dni a buscar
             for (i=0; i<N; i++)
             busca_dni (arre, i, dni);
}
} while (op!=0);
}