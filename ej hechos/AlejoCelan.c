/*JTP: Silvina Balmaceda.
Alumno: Celán Alejo.
Registro: E010-488.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
   int codigo;
   char titulo[50];
   char autor[50];
   int precio;
   int cantidad;
} libro;

struct nodo {
   libro datos;
   struct nodo *siguiente;
};
typedef struct nodo *puntero;

void cargar(puntero *cabeza)
{
   int cod, cant, precio;
   char titulo[50], autor[50];
   printf("Ingrese el codigo del libro. -1 para detener\n");
   scanf("%d", &cod);
   while (cod != -1)
   {
      printf("Ingrese el titulo del libro\n");
      fflush(stdin);
      gets(titulo);
      printf("Ingrese el autor del libro\n");
      gets(autor);
      printf("Ingrese el precio del libro\n");
      scanf("%d", &precio);
      printf("Ingrese la cantidad de libros\n");
      scanf("%d", &cant);
      puntero nuevo;
      nuevo = (puntero)malloc(sizeof(struct nodo));
      nuevo->datos.codigo = cod;
      strcpy(nuevo->datos.titulo, titulo);
      strcpy(nuevo->datos.autor, autor);
      nuevo->datos.precio = precio;
      nuevo->datos.cantidad = cant;
      nuevo->siguiente = *cabeza;
      *cabeza = nuevo;
      printf("Ingrese el codigo del libro. -1 para detener\n");
      scanf("%d", &cod);
   }  
}

libro buscar(puntero actual, int cod)
{
   if (actual == NULL)
   {
      libro aux;
      aux.codigo = -1;
      return aux;
   }
   if (actual->datos.codigo == cod)
      return actual->datos;
   return buscar(actual->siguiente, cod);
}

void mostrar(puntero actual)
{
   if (actual != NULL)
   {
      printf("El libro es %s, escrito por %s, tiene un precio de %d y hay %d disponibles\n", actual->datos.titulo, actual->datos.autor, actual->datos.precio, actual->datos.cantidad);
      mostrar(actual->siguiente);
   }
}

void eliminar(puntero *cabeza, int cod)
{
   puntero anterior = NULL;
   puntero actual = *cabeza;
   while (actual != NULL && actual->datos.codigo != cod)
   {
      anterior = actual;
      actual = actual->siguiente;
   }
   if (actual != NULL)
   {
      if (anterior == NULL)
         *cabeza = actual->siguiente;
      else
         anterior->siguiente = actual->siguiente;
      free(actual);
   }
   else
   {
      printf("No se encontro el libro\n");
   }
}

int importeTotal(puntero cabeza)
{
   int total = 0;
   puntero actual = cabeza;
   while (actual != NULL)
   {
      total += actual->datos.precio * actual->datos.cantidad;
      actual = actual->siguiente;
   }
   return total;
}

int main()
{
   puntero cabeza = NULL;
   cargar(&cabeza);
   int cod;
   printf("Ingrese el codigo del libro que desea buscar\n");
   scanf("%d", &cod);
   libro aux = buscar(cabeza, cod);
   if (aux.codigo == -1)
      printf("No se encontro el libro\n");
   else
      printf("El libro es %s, escrito por %s, tiene un precio de %d\n", aux.titulo, aux.autor, aux.precio);
   mostrar(cabeza);
   printf("Ingrese el codigo del libro que desea eliminar\n");
   scanf("%d", &cod);
   eliminar(&cabeza, cod);
   mostrar(cabeza);
   printf("El importe total de los libros es %d\n", importeTotal(cabeza));
   return 0;
}


/*Lote de prueba
215
Rebelion en la granja
George Orwell
4000
25
132
El viejo y el mar
Ernest Hemingway
2800
10
48
Las cuatro estaciones
Stephen King
1500
5
-1
*/
