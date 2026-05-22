#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include "structs.h"

int calcularAltura(nodo *raiz);
int contarNodos(nodo *raiz);
int contarHojas(nodo *raiz);
int obtenerNivel(nodo *raiz, int codigo);
void mostrarEstadisticas(nodo *raiz);

#endif
