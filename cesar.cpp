#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

#define BUFFER_SIZE 1024

using namespace std;

/**
 * Aplica el Cifrado Cesar extendido a todos los caracteres imprimibles ASCII (32-126).
 * @param c: Caracter a cifrar/descifrar.
 * @param shift: Desplazamiento (positivo para cifrar, negativo para descifrar).
 * @return Caracter cifrado/descifrado.
 */
char cesarCipherExtended(char c, int shift) {
    if (c >= 32 && c <= 126) {
        return (c - 32 + shift) % 95 + 32;
    }
    return c;
}

/**
 * Procesa un archivo con Cifrado César extendido (encriptar o desencriptar).
 * @param inputFile: Nombre del archivo de entrada.
 * @param outputFile: Nombre del archivo de salida.
 * @param shift: Desplazamiento del cifrado (positivo para cifrar, negativo para descifrar).
 */
void processFile(const char* inputFile, const char* outputFile, int shift) {
    int inputFd = open(inputFile, O_RDONLY);
    if (inputFd == -1) {
        perror("Error al abrir archivo de entrada");
        return;
    }

    int outputFd = open(outputFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outputFd == -1) {
        perror("Error al crear archivo de salida");
        close(inputFd);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(inputFd, buffer, BUFFER_SIZE)) > 0) {
        for (ssize_t i = 0; i < bytesRead; ++i) {
            buffer[i] = cesarCipherExtended(buffer[i], shift);
        }

        if (write(outputFd, buffer, bytesRead) != bytesRead) {
            perror("Error al escribir en el archivo de salida");
            close(inputFd);
            close(outputFd);
            return;
        }
    }

    if (bytesRead == -1) {
        perror("Error al leer el archivo de entrada");
    }

    close(inputFd);
    close(outputFd);
}

/**
 * Muestra las opciones de uso del programa.
 */
void showHelp() {
    cout << "Uso: ./cesar [opciones] <archivo>\n";
    cout << "Opciones:\n";
    cout << "  -h, --help            Muestra este mensaje\n";
    cout << "  -v, --version         Muestra la versión del programa\n";
    cout << "  -e, --encrypt <file>  Encripta el archivo\n";
    cout << "  -d, --decrypt <file>  Desencripta el archivo\n";
}

/**
 * Muestra la versión del programa.
 */
void showVersion() {
    cout << "Cifrado César - Versión 1.1 (Extendido a caracteres imprimibles)\n";
}

/**
 * Función principal que gestiona los argumentos de línea de comandos.
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Error: Argumentos insuficientes. Usa -h o --help para ver las opciones.\n";
        return 1;
    }

    string option = argv[1];

    if (option == "-h" || option == "--help") {
        showHelp();
    } else if (option == "-v" || option == "--version") {
        showVersion();
    } else if ((option == "-e" || option == "--encrypt") && argc == 3) {
        string inputFile = argv[2];
        string outputFile = inputFile + ".enc";
        processFile(inputFile.c_str(), outputFile.c_str(), 5);
        cout << "Archivo encriptado: " << outputFile << endl;
    } else if ((option == "-d" || option == "--decrypt") && argc == 3) {
        string inputFile = argv[2];
        string outputFile = inputFile + ".dec";
        processFile(inputFile.c_str(), outputFile.c_str(), -5);
        cout << "Archivo desencriptado: " << outputFile << endl;
    } else {
        cerr << "Error: Opción no válida. Usa -h o --help para ver las opciones.\n";
        return 1;
    }

    return 0;
}
