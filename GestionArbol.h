#ifndef GESTIONARBOL_H
#define GESTIONARBOL_H

#include "structs.h"



nodo *crearNodo(Libro* libro);
nodo *insertarNodo(nodo* raiz, Libro* libro);
nodo *inicializarArbol();
nodo *buscarNodo(nodo* raiz, int codigo);
nodo *eliminarNodo(nodo* raiz, int codigo);
nodo *modificarNodo(nodo* raiz, int codigo, Libro* nuevoLibro);
void recorrerInorden(nodo *raiz);
void recorrerPreorden(nodo *raiz);
void recorrerPosorden(nodo *raiz);
void liberarArbol(nodo *raiz);

#endif
