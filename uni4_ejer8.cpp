#include<stdio.h>
#include<malloc.h>
#include<string.h>

int palindromo(char p[20], int let, int i, int a){
	if (a == i + 1){
		return (1);
	} else {
		if (p[a] == p[let-1]){
			palindromo(p, let-1, i, a+1);
		} else{
			return(0);
		}
	}
}

int main(){
    char p[20];
    int tam,i,es,aux=0;

    printf("Ingrese palabra para verificar si es un palindromo: ");
    scanf("%s",&p);

    tam = strlen(p);

    es = palindromo(p, tam, i, aux);

    if (es == 1){
		printf("La palabra ingresada es palindromo.");
	} else {
		printf("La palabra ingresada no es palindromo.");
	}

    getchar();
    getchar();
}