#include <stdio.h>
#include <stdlib.h>

#include "Estadisticas.h"
#include "GestionArbol.h"
#include "GestionBiblioteca.h"
#include "Utils.h"
#include "persistencia.h"

#define ARCHIVO_BIBLIOTECA "libros.txt"

static int leerCodigo(const char *mensaje) {
    int codigo;

    printf("%s", mensaje);
    codigo = leerNumero();
    if (codigo == -1) {
        printf("Codigo invalido.\n");
    }

    return codigo;
}

int main(int argc, char **argv) {
    nodo *raiz = inicializarArbol();
    nodo *arbolCargado;
    int opcion = 0;

    (void)argc;
    (void)argv;

    printf("Bienvenido a la Biblioteca\n");
    arbolCargado = cargarArbolDesdeArchivo(ARCHIVO_BIBLIOTECA);
    if (arbolCargado != NULL) {
        raiz = arbolCargado;
        printf("Base de datos conectada: %s (%d libros cargados).\n",
               ARCHIVO_BIBLIOTECA,
               contarNodos(raiz));
    } else {
        printf("No se cargo una base existente. Se iniciara una biblioteca vacia.\n");
    }

    do {
        printf("========== BIBLIOTECA DIGITAL ==========\n");
        printf("1. Registrar libro\n");
        printf("2. Buscar libro\n");
        printf("3. Modificar libro\n");
        printf("4. Eliminar libro\n");
        printf("5. Listar libros en inorden\n");
        printf("6. Mostrar recorrido preorden\n");
        printf("7. Mostrar recorrido posorden\n");
        printf("8. Mostrar estadisticas del arbol\n");
        printf("9. Guardar en archivo\n");
        printf("10. Cargar desde archivo\n");
        printf("0. Salir\n");
        printf("=======================================\n");
        printf("Seleccione una opcion: ");
        opcion = leerNumero();

        switch (opcion) {
        case 1: {
            Libro *nuevoLibro;

            printf("Registrar libro\n");
            nuevoLibro = llenadoLibro();
            if (nuevoLibro == NULL) {
                printf("Error al registrar el libro.\n");
                break;
            }

            if (buscarNodo(raiz, nuevoLibro->codigo) != NULL) {
                printf("Ya existe un libro con ese codigo.\n");
                free(nuevoLibro);
                break;
            }

            raiz = insertarNodo(raiz, nuevoLibro);
            printf("Libro registrado con exito.\n");
            break;
        }
        case 2: {
            int codigo = leerCodigo("Ingrese el codigo del libro a buscar: ");
            Libro *libro;

            if (codigo == -1) {
                break;
            }

            libro = buscarLibro(raiz, codigo);
            mostrarLibro(libro);
            break;
        }
        case 3: {
            int codigo = leerCodigo("Ingrese el codigo del libro a modificar: ");
            Libro *libro;

            if (codigo == -1) {
                break;
            }

            libro = buscarLibro(raiz, codigo);
            if (libro == NULL) {
                printf("No existe un libro con ese codigo.\n");
                break;
            }

            if (actualizarDatosLibro(libro)) {
                printf("Libro modificado con exito.\n");
            } else {
                printf("No se pudo modificar el libro.\n");
            }
            break;
        }
        case 4: {
            int codigo = leerCodigo("Ingrese el codigo del libro a eliminar: ");

            if (codigo == -1) {
                break;
            }

            if (buscarNodo(raiz, codigo) == NULL) {
                printf("No existe un libro con ese codigo.\n");
                break;
            }

            raiz = eliminarNodo(raiz, codigo);
            printf("Libro eliminado con exito.\n");
            break;
        }
        case 5:
            if (raiz == NULL) {
                printf("No hay libros registrados.\n");
            } else {
                recorrerInorden(raiz);
            }
            break;
        case 6:
            if (raiz == NULL) {
                printf("No hay libros registrados.\n");
            } else {
                recorrerPreorden(raiz);
            }
            break;
        case 7:
            if (raiz == NULL) {
                printf("No hay libros registrados.\n");
            } else {
                recorrerPosorden(raiz);
            }
            break;
        case 8:
            mostrarEstadisticas(raiz);
            break;
        case 9:
            if (guardarArbolEnArchivo(raiz, ARCHIVO_BIBLIOTECA)) {
                printf("Informacion guardada en %s.\n", ARCHIVO_BIBLIOTECA);
            }
            break;
        case 10: {
            arbolCargado = cargarArbolDesdeArchivo(ARCHIVO_BIBLIOTECA);

            if (arbolCargado != NULL) {
                liberarArbol(raiz);
                raiz = arbolCargado;
                printf("Informacion cargada desde %s.\n", ARCHIVO_BIBLIOTECA);
            }
            break;
        }
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (opcion != 0);

    if (guardarArbolEnArchivo(raiz, ARCHIVO_BIBLIOTECA)) {
        printf("Cambios guardados en la base de datos %s.\n", ARCHIVO_BIBLIOTECA);
    }

    liberarArbol(raiz);
    return 0;
}
