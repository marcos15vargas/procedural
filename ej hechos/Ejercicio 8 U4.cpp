#include <stdio.h>
#include <string.h>
#define L 100



int palindromo(char p[L], int let, int i, int a){
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
	char palabra[L]; 
	int letras, i, aux = 0, es;
	printf("Ingrese una palabra: ");
	scanf("%s", &palabra);
	letras = strlen(palabra);
	i = letras/2;
	if (letras % 2 != 0){
		i++;
	}
	es = palindromo(palabra, letras, i, aux);
	if (es == 1){
		printf("La palabra ingresada es palindromo.");
	} else {
		printf("La palabra ingresada no es palindromo.");
	}
}
