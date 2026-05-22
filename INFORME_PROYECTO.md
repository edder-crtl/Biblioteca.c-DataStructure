# Informe del proyecto

## Titulo

Sistema de Gestion de Biblioteca Digital utilizando Arboles Binarios de Busqueda en lenguaje C.

## Descripcion general

El proyecto implementa un sistema de biblioteca digital por consola. La informacion de los libros se organiza en un arbol binario de busqueda usando el codigo/ISBN como clave principal. Esta estructura permite registrar, buscar, modificar, eliminar y listar libros de forma ordenada.

## Estructura de datos

Se usa la estructura `Libro` para almacenar los datos bibliograficos:

- Codigo o ISBN.
- Titulo.
- Autor.
- Anio de publicacion.
- Editorial.
- Numero de ejemplares.

El arbol se representa con nodos dinamicos que apuntan a un `Libro` y a sus hijos izquierdo y derecho.

## Modulos implementados

### Gestion de arbol

Archivos: `GestionArbol.c` y `GestionArbol.h`.

Funciones principales:

- Crear nodo.
- Insertar libro por codigo.
- Buscar nodo por codigo.
- Eliminar nodo considerando los casos de hoja, un hijo y dos hijos.
- Recorrido inorden.
- Recorrido preorden.
- Recorrido posorden.
- Liberacion completa del arbol.

### Gestion de biblioteca

Archivos: `GestionBiblioteca.c` y `GestionBiblioteca.h`.

Funciones principales:

- Crear libro.
- Registrar datos de un libro.
- Buscar libro.
- Mostrar informacion completa.
- Modificar datos bibliograficos sin cambiar la clave principal.

### Persistencia

Archivos: `Persistencia.c` y `persistencia.h`.

Funciones principales:

- Guardar el arbol en `libros.txt`.
- Cargar libros desde `libros.txt`.
- Reconstruir el arbol a partir del archivo.
- Conectar automaticamente la base al iniciar el programa.
- Guardar automaticamente los cambios al salir.

Formato usado:

```txt
codigo|titulo|autor|anio|editorial|ejemplares
```

### Estadisticas

Archivos: `Estadisticas.c` y `Estadisticas.h`.

Funciones principales:

- Calcular altura del arbol.
- Contar nodos.
- Contar hojas.
- Consultar el nivel de un libro especifico.

### Utilidades

Archivos: `Utils.c` y `Utils.h`.

Funciones principales:

- Leer numeros con validacion.
- Leer cadenas con limite de tamano.
- Limpiar el resto de linea cuando una entrada es demasiado larga.

## Requerimientos funcionales cubiertos

- RF1: Registrar libro.
- RF2: Buscar libro por codigo.
- RF3: Eliminar libro del arbol.
- RF4: Modificar libro existente.
- RF5: Listar libros en inorden.
- RF6: Mostrar recorridos preorden, inorden y posorden.
- RF7: Mostrar estadisticas del arbol.
- RF8: Guardar informacion en archivo.
- RF9: Cargar informacion desde archivo.

## Validacion de entradas

Se eliminaron las lecturas con `scanf` en el flujo principal para evitar problemas de bufer. Ahora las entradas se manejan con `fgets`, validando numeros con `strtol` y cadenas con limite de tamano. Esto evita saltos de linea pendientes, desbordamientos de arreglos y lecturas inconsistentes.

## Compilacion

Comando usado:

```powershell
gcc -std=c99 -Wall -Wextra main.c Estadisticas.c GestionBiblioteca.c GestionArbol.c Persistencia.c Utils.c -o biblioteca.exe
```

El proyecto compila sin errores ni advertencias.

## Pruebas realizadas

Se probaron las siguientes operaciones:

- Cargar libros desde `libros.txt`.
- Buscar un libro por codigo.
- Listar libros en orden ascendente por codigo.
- Mostrar estadisticas del arbol.
- Registrar un libro.
- Modificar un libro.
- Eliminar un libro.
- Guardar informacion en archivo.
- Salir liberando memoria del arbol.
- Verificar que el programa cargue automaticamente 30 registros al iniciar.

## Observacion

La version implementada usa arbol binario de busqueda. Si el archivo se carga ya ordenado por codigo, el arbol puede quedar desbalanceado. Esto es correcto para BST, aunque una extension futura seria implementar AVL para mejorar la altura del arbol en cargas ordenadas.
