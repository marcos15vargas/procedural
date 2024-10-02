/*El Ministerio de Producción ha lanzado un Plan de Promoción de Capacitación de Empleados (PPCE) para las PYMES
(Pequeñas y Medianas Empresas). La siguiente tabla detalla los montos financiados para el año actual (expresados
en millones de pesos) según las distintas categorías/sectores, lo que permite clasificar cada una de las empresas.

		 |								Sector							|
		 |	Agropecuario| Industria y |Comercio |Servicios |Construcción|
Categoría|					     	 Minería							|
Micro 	 |	$2 				$7,5 		$9 			$2,5 		$3,5	|
Pequeña  |	$13 			$45,5 		$55 		$15 		$22,5	|
Mediana  |	$100 			$360 		$450 		$125 		$180	|

a) Indicar el monto total financiado para una categoría ingresada por teclado.
b) Indicar el monto total financiado para el sector de Servicios, sin importar la categoría de la empresa.
c) Emitir un listado con el total financiado, sin importar la categoría/ sector.
d) Emitir un listado con los montos superiores a uno ingresado por teclado, y a continuación los inferiores e iguales,
indicando sector y categoría.*/ 
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 5

void cargar(float arre[N][M], int i,int j){
	float valor;
	if (i<N){
		if(j<M){
			printf("ingrese el valor de la tabla [%d][%d]\n",i,j);
			scanf("%f",&valor);
			fflush(stdin);
			arre[i][j] = valor;
			return cargar(arre,i,j+1);
		}
		return cargar(arre,i+1,0);
	}
}
void incisoA(float arre[M],float &total, int i){
	if(i<M){
		total = total + arre[i];
		incisoA(arre,total,i+1);
	}
}
void incisoB(float arre[N][M],int i, float &total){
	if(i<N){
		total = total + arre[i][3];
		incisoB(arre,i+1,total);
	}	
}
void incisoC(float arre[N][M], int i,int j,float &total2){
	if(i<N){
		if(j<M){
			total2 = total2 + arre[i][j];
			incisoC(arre,i,j+1,total2);
		}
		incisoC(arre,i+1,0,total2);
	}
}
void incisoD(float arre[N][M],int i, int j, float num){
	//printf("numero: %.2f",num);
	if(i<N){
		if(j<M){
			if(arre[i][j] > num){
				printf("monto superior: %.2f [%d][%d] \n",arre[i][j],i,j);
			}else{
				printf("---monto inferior o igual: %.2f [%d][%d]\n",arre[i][j],i,j);
			}
			incisoD(arre,i,j+1,num);
		}else{
			incisoD(arre,i+1,0,num);
		}
	}else{
		printf("fin de la recursividad \n");
	}
}
void mostrar(float arre[N][M]){
	int i=0,j=0;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("[%.2f]",arre[i][j]);
		}
		printf("\n");
	}
}
main(){
	int i=0,j=0,cate;
	float arre[N][M],total=0,total2=0.0,total3=0.0,num=0.0;
	cargar(arre,i,j);
	//incisoA(arre[N],i);
	mostrar(arre);
	printf("ingrese aqui la categoria:(1.micro,2.peque,3.mediano)\n");
	scanf("%d",&cate);
	fflush(stdin);
	incisoA(arre[cate-1],total,i);	
	printf("el monto total financiado para la categoria %d es: %.2f",cate,total);
	incisoB(arre,i,total2);	
	printf("el monto total financiado para el sector Servicios es %.2f \n",total2);
	incisoC(arre,i,j,total3);
	printf("ingrese un numero para comparar: \n");
	scanf("%f",&num);
	fflush(stdin);
	incisoD(arre,i,j,num);
}




