#include <stdio.h>

#include "Estadisticas.h"
#include "Utils.h"

int calcularAltura(nodo *raiz) {
    int alturaIzq;
    int alturaDer;

    if (raiz == NULL) {
        return 0;
    }

    alturaIzq = calcularAltura(raiz->izq);
    alturaDer = calcularAltura(raiz->der);

    return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
}

int contarNodos(nodo *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
}

int contarHojas(nodo *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->izq == NULL && raiz->der == NULL) {
        return 1;
    }

    return contarHojas(raiz->izq) + contarHojas(raiz->der);
}

static int obtenerNivelDesde(nodo *raiz, int codigo, int nivel) {
    if (raiz == NULL) {
        return -1;
    }

    if (raiz->libro->codigo == codigo) {
        return nivel;
    }

    if (codigo < raiz->libro->codigo) {
        return obtenerNivelDesde(raiz->izq, codigo, nivel + 1);
    }

    return obtenerNivelDesde(raiz->der, codigo, nivel + 1);
}

int obtenerNivel(nodo *raiz, int codigo) {
    return obtenerNivelDesde(raiz, codigo, 0);
}

void mostrarEstadisticas(nodo *raiz) {
    int codigo;
    int nivel;

    printf("Altura del arbol: %d\n", calcularAltura(raiz));
    printf("Numero total de nodos: %d\n", contarNodos(raiz));
    printf("Numero de hojas: %d\n", contarHojas(raiz));

    printf("Ingrese el codigo del libro para consultar su nivel: ");
    codigo = leerNumero();
    if (codigo == -1) {
        printf("Codigo invalido.\n");
        return;
    }

    nivel = obtenerNivel(raiz, codigo);
    if (nivel == -1) {
        printf("El libro no existe en el arbol.\n");
    } else {
        printf("Nivel del libro %d: %d\n", codigo, nivel);
    }
}
