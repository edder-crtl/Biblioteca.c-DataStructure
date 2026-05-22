#ifndef GESTIONBIBLIOTECA_H
#define GESTIONBIBLIOTECA_H

#include "structs.h"
#include "GestionArbol.h"

Libro *crearLibro(int codigo, const char* titulo, const char* autor, int anio, const char* editorial, int ejemplares);

Libro *modificarLibro(Libro* libro, int codigo, const char* titulo, const char* autor, int anio, const char* editorial, int ejemplares);
Libro *buscarLibro(nodo* raiz, int codigo);
Libro *eliminarLibro(nodo* raiz, int codigo);
Libro *llenadoLibro();
void mostrarLibro(const Libro *libro);
int actualizarDatosLibro(Libro *libro);

#endif
