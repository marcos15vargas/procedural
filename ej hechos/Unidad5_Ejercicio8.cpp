#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TUTORIALES 10

typedef struct {
    int numero;
    char titulo[100];
    int cantidadInscriptos;
} Tutorial;

typedef struct Inscripcion {
    int dni;
    int numTutorial;
    struct Inscripcion* siguiente;
} Inscripcion;

//Ingresar los datos de los tutoriales
void ingresarDatosTutorial(Tutorial* tutoriales, int i) {
    if (i >= MAX_TUTORIALES) return;

    printf("Ingrese el numero del tutorial (1-10): ");
    scanf("%d", &tutoriales[i].numero);
    getchar();

    printf("Ingrese el titulo del tutorial %d: ", tutoriales[i].numero);
    fgets(tutoriales[i].titulo, 100, stdin);
    tutoriales[i].titulo[strcspn(tutoriales[i].titulo, "\n")] = '\0';
    tutoriales[i].cantidadInscriptos = 0;

    ingresarDatosTutorial(tutoriales, i + 1);
}

//Registrar inscripciones
Inscripcion* registrarInscripcion(Inscripcion* lista, int dni, int numTutorial, Tutorial* tutoriales) {
    if (lista == NULL) {
        Inscripcion* nueva = (Inscripcion*)malloc(sizeof(Inscripcion));
        nueva->dni = dni;
        nueva->numTutorial = numTutorial;
        nueva->siguiente = NULL;

        tutoriales[numTutorial - 1].cantidadInscriptos++;
        return nueva;
    }
    lista->siguiente = registrarInscripcion(lista->siguiente, dni, numTutorial, tutoriales);
    return lista;
}

//Eliminar inscripcion
Inscripcion* eliminarInscripcion(Inscripcion* lista, int dni, int numTutorial, Tutorial* tutoriales) {
    if (lista == NULL) return NULL;

    if (lista->dni == dni && lista->numTutorial == numTutorial) {
        Inscripcion* temp = lista->siguiente;
        free(lista);
        tutoriales[numTutorial - 1].cantidadInscriptos--;
        return temp;
    }

    lista->siguiente = eliminarInscripcion(lista->siguiente, dni, numTutorial, tutoriales);
    return lista;
}

//Mostrar titulo y cantidad de inscriptos en un tutorial
void mostrarTutorial(Tutorial* tutoriales, int numTutorial) {
    if (numTutorial < 1 || numTutorial > MAX_TUTORIALES) {
        printf("Numero de tutorial invalido.\n");
        return;
    }
    printf("Tutorial %d: %s\n", tutoriales[numTutorial - 1].numero, tutoriales[numTutorial - 1].titulo);
    printf("Cantidad de inscriptos: %d\n", tutoriales[numTutorial - 1].cantidadInscriptos);
}

//Informar tutoriales de un inscripto
void mostrarInscripciones(Inscripcion* lista, int dni, Tutorial* tutoriales) {
    if (lista == NULL) return;

    if (lista->dni == dni) {
        printf("Inscripto en el tutorial %d: %s\n", lista->numTutorial, tutoriales[lista->numTutorial - 1].titulo);
    }
    mostrarInscripciones(lista->siguiente, dni, tutoriales);
}

int main() {
    Tutorial tutoriales[MAX_TUTORIALES];
    Inscripcion* listaInscripciones = NULL;
    int opcion, dni, numTutorial;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar datos de los tutoriales\n");
        printf("2. Registrar inscripcion\n");
        printf("3. Eliminar inscripcion\n");
        printf("4. Mostrar tutorial\n");
        printf("5. Mostrar inscripciones por DNI\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                ingresarDatosTutorial(tutoriales, 0);
                break;
            case 2:
                printf("Ingrese el DNI: ");
                scanf("%d", &dni);
                printf("Ingrese el numero de tutorial: ");
                scanf("%d", &numTutorial);
                listaInscripciones = registrarInscripcion(listaInscripciones, dni, numTutorial, tutoriales);
                break;
            case 3:
                printf("Ingrese el DNI: ");
                scanf("%d", &dni);
                printf("Ingrese el numero de tutorial: ");
                scanf("%d", &numTutorial);
                listaInscripciones = eliminarInscripcion(listaInscripciones, dni, numTutorial, tutoriales);
                break;
            case 4:
                printf("Ingrese el numero de tutorial: ");
                scanf("%d", &numTutorial);
                mostrarTutorial(tutoriales, numTutorial);
                break;
            case 5:
                printf("Ingrese el DNI: ");
                scanf("%d", &dni);
                mostrarInscripciones(listaInscripciones, dni, tutoriales);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 6);

    return 0;
}

