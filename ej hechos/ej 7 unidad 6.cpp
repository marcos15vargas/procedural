#include<stdio.h>
#include<string.h>


typedef struct {
	char nom[30];
	char nom_emp[30];
	int dni;
	float neto;	
}empleado;


typedef struct {
	char nombre[30];
	int empleados;
	float pagado;
}empresa;

void listar(FILE *arch){
	empleado e;
	int i=1;
	char anterior[30];
	float total=0;
	rewind(arch);
	fread(&e,sizeof(e),1,arch);
	strcpy(anterior,e.nom_emp);
	while(feof(arch)==0){
		printf("\nLista de empleados de %s",e.nom_emp);
		printf("	DNI: 	Nombre: 	Sueldo: \n");
		while(strcmp(e.nom_emp,anterior)==0){
			printf("%d. 	%d.		%s.		%f. ",i,e.dni,e.nom,e.neto);
			total+=e.neto;
			i++;
		}
		printf("Total pagado por %s es $%f",anterior,total);
		i=1;
		total=0;
		strcpy(anterior,e.nom_emp);
	}
}

void generar_arch(FILE *arch1,FILE *arch2){
	empleado e;
	empresa c;
	int cant=0;
	char anterior[30];
	float total=0;
	rewind(arch1);
	fread(&e,sizeof(e),1,arch1);
	strcpy(anterior,e.nom_emp);
	strcpy(c.nombre,e.nom_emp);
	while(feof(arch1)==0){
		while(strcmp(e.nom_emp,anterior)==0){
			cant++;
			total+=e.neto;
		}
		c.empleados=cant;
		c.pagado=total;
		fwrite(&c,sizeof(c),1,arch2);
		cant=0;
		total=0;
		strcpy(anterior,e.nom_emp);
		strcpy(c.nombre,e.nom_emp);
	}
}

int main(){
	FILE *archivo_1,*archivo_2;
	if((archivo_1=fopen("empleados.dat","wb"))==NULL){
		printf("\nhubo error en la escritura");
	}else{
		fclose(archivo_1);
	}
	
	
	printf("\n******************* LISTADO DE LIQUIDACION *********************\n");
	if((archivo_1=fopen("empleados.dat","rb"))==NULL){
		printf("\nhubo error en la lectura");
	}else{
		listar(archivo_1);
		fclose(archivo_1);
	}
	
	printf("\ncarga de archivo 'empresas.dat'\n");
	
	if((archivo_2=fopen("EMPRESAS.dat","wb"))==NULL){		
		printf("\nhubo error en la escritura");
	}else{
		if((archivo_1=fopen("empleados.dat","rb"))==NULL){
			printf("\nhubo error en la lectura");
		}else{
			generar_arch(archivo_1,archivo_2);
			fclose(archivo_1);
			fclose(archivo_2);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
}