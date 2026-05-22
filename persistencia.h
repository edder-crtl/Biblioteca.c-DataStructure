#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "structs.h"

int guardarArbolEnArchivo(nodo *raiz, const char *nombreArchivo);
nodo *cargarArbolDesdeArchivo(const char *nombreArchivo);

#endif
