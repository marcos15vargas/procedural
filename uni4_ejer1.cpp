#include<stdio.h>

void FuncionA (int n){
 if (n){ 
    printf ("%d", n%10);
    n = (int)n/10;
    FuncionA (n);
 }
}

int FuncionB (int n)
{
if (n==0)
 return n;
else
 return FuncionB (n/10) + (n%10);
}
int main(){

    int n = 6745;

    FuncionA(n);

    //2 MAIN 2

    int n2,resultado;
    printf("Ingrese numero(5679): ");
    scanf("%d",&n2);
    resultado = FuncionB(n2);



    getchar();
    getchar();
}