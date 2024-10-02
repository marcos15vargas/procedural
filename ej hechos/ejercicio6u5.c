#include <stdio.h>
#include <malloc.h>

struct Nodo {
  int num;
  struct Nodo *sig;
};

typedef struct Nodo *puntero;

void insertar(puntero *cabeza, int *input, int *latest) {
  printf("Ingrese el valor del nuevo nodo (-1 para salir): ");
  scanf("%d", input);
  if (*input != -1) {
    if (*input > *latest) {
      puntero nuevo; // Creación de un nuevo nodo
      nuevo = (puntero) malloc (sizeof(struct Nodo)); // Solicitud de memoria
      nuevo->num = *input; // Asignación de valor
      nuevo->sig = *cabeza; // La cabeza ahora es el último elemento de la lista
      *cabeza = nuevo;
      *latest = *input;
      insertar(cabeza, input, latest);
    }
    else {
      printf("Error: El número insertado no es mayor al anterior (ascendente).\n");
    }
  }
}

void ultimo_par(puntero cabeza) {
  if (cabeza->sig != NULL) {
    ultimo_par(cabeza->sig);
  }
  else {
    if (cabeza->num % 2 == 0) {
      printf("El último nodo es par.\n");
    }
    else {
      printf("El último nodo no es par.\n");
    }
  }
}

void mostrar_inverso(puntero cabeza) {
  if (cabeza->sig != NULL) {
    printf("%d\n", cabeza->num);
    mostrar_inverso(cabeza->sig);
  }
  else if (cabeza->sig == NULL) {
    printf("%d\n", cabeza->num);
  }
}

void buscar_numero(puntero cabeza, int *buscar, int *i, int *j) {
  if (cabeza->sig != NULL) {
    if (*buscar != cabeza->num) {
      *j = *j + 1;
      buscar_numero(cabeza->sig, buscar, i, j);
    }
    else {
      *i = *j;
    }
  }
  else {
    if (*buscar == cabeza->num) {
      *i = *j;
    }
  }
}

int main() {
  int input = 0, latest = -1, buscar, i = -1, j = 0;
  puntero cabeza = NULL;
  insertar(&cabeza, &input, &latest);
  if (cabeza != NULL) {
    ultimo_par(cabeza);
    mostrar_inverso(cabeza);
  }
  printf("Ingrese el número que busca: ");
  scanf("%d", &buscar);
  buscar_numero(cabeza, &buscar, &i, &j);
  if (i != -1) {
    printf("Se encontró el número en la posición %d.\n", i);
  }
  else {
    printf("No se encontró el elemento buscado.\n");
  }
  return 0;
}
