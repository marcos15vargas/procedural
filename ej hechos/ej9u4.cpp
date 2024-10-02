#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define C 3
#define S 5


void carga (float tab[C][S], int i, int j){
    if (i<C){
        if (j<S){
            printf("\n Ingrese monto categoria %d Sector %d: ", i+1, j+1);
            scanf ("%f", &tab[i][j]);
            carga(tab, i, j+1);
        }
        carga(tab, i+1, j);
    }
}

void totalCategoria(float &(tab[S]), int j, float &tot){
    if(j<S)
        tot+=tab[j];
        totalCategoria(tab, j+1, tot);
}

void totalSector(float tab[C][S], int i, int j, float &tot){
    if(j<C)
        tot+=tab[i][j-1];
        totalCategoria(tab, i+1, j, tot);
}

void totalFinanciado(float tab[C][S], int i, int j, float &tot){

    if(i<C)
        if(j<S)
            tot+=tab[i][j];
            totalFinanciado(tab, i, j+1, tot);
        totalFinanciado(tab,i+1, j, tot);
}

int main (){

float tabla [C][S], tot=0;
int i=0, j=0, cat;

printf("\nIngrese un numero de categoria categoria (1-3):  ");
fflush(stdin);
scanf("%d", &cat);
    totalCategoria(tabla[cat-1], j, tot);
printf ("\nMonto total de la categoria: %2f", tot );
    tot=0;
    totalSector(tabla, i, 4, tot);
printf("\nMonto total financiado para el Sector Servicio: %2f", tot);
    tot=0;
    totalFinanciado(tabla, i, j,tot);
printf("\nTotal Financiado: %2f", tot);

return 0;
}
