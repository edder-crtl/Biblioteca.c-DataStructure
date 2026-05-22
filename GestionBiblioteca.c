#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Utils.h"
#include "structs.h"

Libro *llenadoLibro() {
    Libro* nuevoLibro = (Libro*)malloc(sizeof(Libro));
    if (nuevoLibro != NULL) {
        printf("Ingrese el codigo del libro: ");
        scanf("%d", &nuevoLibro->codigo);
        printf("Ingrese el titulo del libro: ");
        scanf(" %[^\n]", nuevoLibro->titulo);
        printf("Ingrese el autor del libro: ");
        scanf(" %[^\n]", nuevoLibro->autor);
        printf("Ingrese el año de publicación del libro: ");
        nuevoLibro->anio = leerNumero();
        if (nuevoLibro->anio == -1) {
            free(nuevoLibro);
            return NULL; // Indica error
        }
        printf("Ingrese la editorial del libro: ");
        scanf(" %[^\n]", nuevoLibro->editorial);
        printf("Ingrese el número de ejemplares disponibles: ");
        nuevoLibro->ejemplares = leerNumero();
        if (nuevoLibro->ejemplares == -1) {
            free(nuevoLibro);
            return NULL; // Indica error
        }
    }
    return nuevoLibro;
}



Libro *crearLibro(int codigo, const char* titulo, const char* autor, int anio, const char* editorial, int ejemplares) {
    Libro* nuevoLibro = (Libro*)malloc(sizeof(Libro));
    if (nuevoLibro != NULL) {
        nuevoLibro->codigo = codigo;
        strncpy(nuevoLibro->titulo, titulo, sizeof(nuevoLibro->titulo) - 1);
        nuevoLibro->titulo[sizeof(nuevoLibro->titulo) - 1] = '\0';
        strncpy(nuevoLibro->autor, autor, sizeof(nuevoLibro->autor) - 1);
        nuevoLibro->autor[sizeof(nuevoLibro->autor) - 1] = '\0';
        nuevoLibro->anio = anio;
        strncpy(nuevoLibro->editorial, editorial, sizeof(nuevoLibro->editorial) - 1);
        nuevoLibro->editorial[sizeof(nuevoLibro->editorial) - 1] = '\0';
        nuevoLibro->ejemplares = ejemplares;
    }
    return nuevoLibro;
}



Libro *modificarLibro(Libro* libro, int codigo, const char* titulo, const char* autor, int anio, const char* editorial, int ejemplares) {
    if (libro != NULL) {
        libro->codigo = codigo;
        strncpy(libro->titulo, titulo, sizeof(libro->titulo) - 1);
        libro->titulo[sizeof(libro->titulo) - 1] = '\0';
        strncpy(libro->autor, autor, sizeof(libro->autor) - 1);
        libro->autor[sizeof(libro->autor) - 1] = '\0';
        libro->anio = anio;
        strncpy(libro->editorial, editorial, sizeof(libro->editorial) - 1);
        libro->editorial[sizeof(libro->editorial) - 1] = '\0';
        libro->ejemplares = ejemplares;
    }
    return libro;
}


Libro *buscarLibro(nodo* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    printf("Ingrese el codigo del libro a buscar: ");
    int code=leerNumero();
    if (code==-1)
    {
        printf("Error al leer el código. Por favor, ingrese un número entero válido.\n");
        return NULL; // Indica error
    }
    
    if (raiz->libro->codigo == code) {
        return raiz->libro;
    }
    if (code < raiz->libro->codigo) {
        return buscarLibro(raiz->izq);
    }
    return buscarLibro(raiz->der);
}

Libro *eliminarLibro(nodo* raiz, int codigo) {
    nodo* nodoAEliminar = buscarNodo(raiz, codigo);
    if (nodoAEliminar != NULL) {
        Libro* libroEliminado = nodoAEliminar->libro;
        nodoAEliminar->libro = NULL; // Desvincular el libro del nodo
        return libroEliminado;
    }
    return NULL;
}




