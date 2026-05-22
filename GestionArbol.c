#include <stdio.h>
#include <stdlib.h>

#include "GestionArbol.h"
#include "GestionBiblioteca.h"

nodo *crearNodo(Libro *libro) {
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));

    if (nuevoNodo != NULL) {
        nuevoNodo->libro = libro;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
    }

    return nuevoNodo;
}

nodo *insertarNodo(nodo *raiz, Libro *libro) {
    if (raiz == NULL) {
        return crearNodo(libro);
    }

    if (libro->codigo < raiz->libro->codigo) {
        raiz->izq = insertarNodo(raiz->izq, libro);
    } else if (libro->codigo > raiz->libro->codigo) {
        raiz->der = insertarNodo(raiz->der, libro);
    }

    return raiz;
}

nodo *inicializarArbol() {
    return NULL;
}

nodo *buscarNodo(nodo *raiz, int codigo) {
    if (raiz == NULL || raiz->libro->codigo == codigo) {
        return raiz;
    }

    if (codigo < raiz->libro->codigo) {
        return buscarNodo(raiz->izq, codigo);
    }

    return buscarNodo(raiz->der, codigo);
}

static nodo *buscarMinimo(nodo *raiz) {
    while (raiz != NULL && raiz->izq != NULL) {
        raiz = raiz->izq;
    }

    return raiz;
}

nodo *eliminarNodo(nodo *raiz, int codigo) {
    if (raiz == NULL) {
        return NULL;
    }

    if (codigo < raiz->libro->codigo) {
        raiz->izq = eliminarNodo(raiz->izq, codigo);
    } else if (codigo > raiz->libro->codigo) {
        raiz->der = eliminarNodo(raiz->der, codigo);
    } else {
        if (raiz->izq == NULL) {
            nodo *temp = raiz->der;
            free(raiz->libro);
            free(raiz);
            return temp;
        }

        if (raiz->der == NULL) {
            nodo *temp = raiz->izq;
            free(raiz->libro);
            free(raiz);
            return temp;
        }

        nodo *sucesor = buscarMinimo(raiz->der);
        Libro *libroOriginal = raiz->libro;

        raiz->libro = sucesor->libro;
        sucesor->libro = libroOriginal;
        raiz->der = eliminarNodo(raiz->der, codigo);
    }

    return raiz;
}

nodo *modificarNodo(nodo *raiz, int codigo, Libro *nuevoLibro) {
    nodo *nodoExistente = buscarNodo(raiz, codigo);

    if (nodoExistente != NULL) {
        free(nodoExistente->libro);
        nodoExistente->libro = nuevoLibro;
    }

    return raiz;
}

void recorrerInorden(nodo *raiz) {
    if (raiz == NULL) {
        return;
    }

    recorrerInorden(raiz->izq);
    mostrarLibro(raiz->libro);
    recorrerInorden(raiz->der);
}

void recorrerPreorden(nodo *raiz) {
    if (raiz == NULL) {
        return;
    }

    mostrarLibro(raiz->libro);
    recorrerPreorden(raiz->izq);
    recorrerPreorden(raiz->der);
}

void recorrerPosorden(nodo *raiz) {
    if (raiz == NULL) {
        return;
    }

    recorrerPosorden(raiz->izq);
    recorrerPosorden(raiz->der);
    mostrarLibro(raiz->libro);
}

void liberarArbol(nodo *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    free(raiz->libro);
    free(raiz);
}
