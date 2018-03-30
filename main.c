/*
* Creado por José Armando Gutiérrez Núñez
* 30 de Marzo de 2018
*/
#include <stdio.h>
#include <string.h>

void capturaFila(char *cadena);
void enviarAlArchivo(FILE* archivo, char *cadenaP1, char *cadenaDeDatos);
void rowToFile(FILE* archivo, char *cadena);

int main() {
    FILE* archivo = fopen("demo.txt","w+b");
    char nombreMatriz[20];
    char cadenaDatos[50];//Dode se captura los datos en linea de comando
    char cadena[50];//Parte inicia de la cadena que se colocará en el archivo
    int i=0;

    printf("Nombre de la matriz: ");
    scanf("%s", nombreMatriz);
    do {
        sprintf(cadena, "%s[%d]", nombreMatriz, i++);
        capturaFila(cadenaDatos);
        enviarAlArchivo(archivo, cadena, cadenaDatos);
        printf("\nCapturar otra: s=SI, ENTER=terminar\n");
    } while(getch()=='s');
    fclose(archivo);
    return 0;
}

void capturaFila(char *cadena)
{
    printf("\nIngresa los valores se parados por comas, Ejemplo: 0,1,2,a,b,f,23,7\nValores: ");
    scanf("%s", cadena);
}


void enviarAlArchivo(FILE* archivo, char *cadenaP1, char *cadenaDatos){

    int i=0;
    int valor=0, ultimoValor=0;
    char lineOnFile[50];
    while (*cadenaDatos) {
        if(*cadenaDatos!=','){
            if(valor){
                valor*=10;
                valor+=(*cadenaDatos) - '0';
            }
            else
                valor = (*cadenaDatos) - '0';
            ultimoValor= valor;
        }
        else
        {
            sprintf(lineOnFile,"%s[%d]=%d\n", cadenaP1,i++, valor);
            rowToFile(archivo, lineOnFile);
            valor=0;
        }
        *cadenaDatos++;
    }
    sprintf(lineOnFile, "%s[%d]=%d\n", cadenaP1,i++, ultimoValor);
    rowToFile(archivo, lineOnFile);
}

void rowToFile(FILE* archivo, char *cadena){
    int i=0;
    while(cadena[i])
        fwrite(&cadena[i++],sizeof(char),1, archivo);
}
