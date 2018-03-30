#include <stdio.h>
#include <string.h>

int main() {
    FILE* archivo = fopen("demo.txt","w+b");
    char cadena[25];
    int i=0;
    while(cadena[i])
        fwrite(&cadena[i++],sizeof(char),1, archivo);
    fclose(archivo);
    printf("Programa finalizado");
    return 0;
}

// c = '[';
// fwrite(&c, sizeof(char),1,archivo);
