#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Libro {
int codigo;
char titulo[100];
char autor[80];
int anio;
char editorial[80];
int ejemplares;
} Libro;

typedef struct nodo {
    Libro* libro;
    struct nodo *izq;
    struct nodo *der;
} nodo;

#endif
