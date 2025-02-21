# Parcial-1-Sistemas-Operativos

Este proyecto se desarrolla como parte de la demostración de los temas vistos en las sesiones de clase orientadas a sistemas operativos. Se abordan conceptos fundamentales como:

- Llamadas al sistema en el contexto del sistema de archivos.
- Banderas de ejecución.

## Implementación del Cifrado César

Para la implementación y práctica de estos temas, se ha elegido el cifrado César, una técnica de criptografía que consiste en sustituir cada letra de un mensaje por otra que se encuentra a un número fijo de posiciones más adelante en el alfabeto.

A través del lenguaje C++ y los diferentes recursos dentro de este, se ejecutó y probó su funcionamiento. Se realizaron modificaciones al algoritmo original para permitir el cifrado no solo de letras, sino también de símbolos y números, utilizando su representación en la tabla de código ASCII. Se empleó el rango desde el ítem 32 (espacio) hasta el 126 (virgulilla ~).

## Uso

El programa cuenta con una serie de opciones para facilitar su ejecución:
- -h, --help             Muestra un mensaje con las opciones del programa
- -v, --version          Muestra la versión del programa
- -e, --encrypt <file>   Encripta el archivo
- -d, --decrypt <file>   Desencripta el archivo

## Requisitos

- Compilador de C++ (g++ recomendado).
- Sistema operativo basado en Linux.
- Conocimientos básicos en ejecución de programas desde la terminal.

## Compilación y Ejecución

Para compilar el programa, utilice:

```sh
g++ -o cesar cesar.cpp
```

Para ejecutar el programa con cifrado:

```sh
./cesar -e archivo.txt
```

Para descifrar:

```sh
./cesar -d archivo.txt
```

Tambien en nuestra maquina donde desarrollamos el programa podemos usar el programa como una funcion de sistema con:
```sh
cesar [opcion] <file>
```

## Autor
- Valentina Giraldo Noreña
- Juan Pablo Jimenez Quiroz
- Camilo Soto Reyes


