#include "Utils.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static void descartarRestoLinea(void) {
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }
}

int leerNumero() {
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int soloEspacios = 1;
        char *endptr;
        int numero;

        if (strchr(buffer, '\n') == NULL && strlen(buffer) == sizeof(buffer) - 1) {
            descartarRestoLinea();
            printf("Entrada demasiado larga. Intente nuevamente.\n");
            return -1;
        }

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isspace((unsigned char)buffer[i])) {
                soloEspacios = 0;
                break;
            }
        }

        if (soloEspacios) {
            continue;
        }

        numero = (int)strtol(buffer, &endptr, 10);
        while (isspace((unsigned char)*endptr)) {
            endptr++;
        }

        if (endptr == buffer || *endptr != '\0') {
            printf("Entrada no valida. Por favor, ingrese un numero entero.\n");
            return -1;
        }

        return numero;
    }

    printf("Error al leer la entrada.\n");
    return -1;
}

int LeerNumero() {
    return leerNumero();
}

int leerCadena(char *destino, size_t tamanio) {
    size_t longitud;

    if (destino == NULL || tamanio == 0) {
        return 0;
    }

    if (fgets(destino, tamanio, stdin) == NULL) {
        printf("Error al leer la entrada.\n");
        destino[0] = '\0';
        return 0;
    }

    longitud = strlen(destino);
    if (longitud > 0 && destino[longitud - 1] == '\n') {
        destino[longitud - 1] = '\0';
    } else if (longitud == tamanio - 1) {
        descartarRestoLinea();
        printf("Texto demasiado largo. Maximo permitido: %lu caracteres.\n", (unsigned long)(tamanio - 1));
        destino[0] = '\0';
        return 0;
    }

    return 1;
}
