#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persistencia.h"
#include "GestionArbol.h"
#include "GestionBiblioteca.h"

static void guardarNodoInorden(nodo *raiz, FILE *archivo) {
    if (raiz == NULL) {
        return;
    }

    guardarNodoInorden(raiz->izq, archivo);
    fprintf(archivo, "%d|%s|%s|%d|%s|%d\n",
            raiz->libro->codigo,
            raiz->libro->titulo,
            raiz->libro->autor,
            raiz->libro->anio,
            raiz->libro->editorial,
            raiz->libro->ejemplares);
    guardarNodoInorden(raiz->der, archivo);
}

int guardarArbolEnArchivo(nodo *raiz, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar.\n");
        return 0;
    }

    guardarNodoInorden(raiz, archivo);
    fclose(archivo);
    return 1;
}

static int parsearLibro(char *linea, Libro **libro) {
    char *codigo;
    char *titulo;
    char *autor;
    char *anio;
    char *editorial;
    char *ejemplares;

    codigo = strtok(linea, "|");
    titulo = strtok(NULL, "|");
    autor = strtok(NULL, "|");
    anio = strtok(NULL, "|");
    editorial = strtok(NULL, "|");
    ejemplares = strtok(NULL, "|\n");

    if (codigo == NULL || titulo == NULL || autor == NULL ||
        anio == NULL || editorial == NULL || ejemplares == NULL) {
        return 0;
    }

    *libro = crearLibro(atoi(codigo), titulo, autor, atoi(anio), editorial, atoi(ejemplares));
    return *libro != NULL;
}

nodo *cargarArbolDesdeArchivo(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    char linea[512];
    nodo *raiz = NULL;

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para cargar.\n");
        return NULL;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        Libro *libro = NULL;

        if (parsearLibro(linea, &libro)) {
            if (buscarNodo(raiz, libro->codigo) == NULL) {
                raiz = insertarNodo(raiz, libro);
            } else {
                free(libro);
            }
        }
    }

    fclose(archivo);
    return raiz;
}
