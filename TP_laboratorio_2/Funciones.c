#include <stdio.h>
#include <string.h>
#include "Funciones.h"



int menu(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}



void confirmacion (int espacio)
{

    switch(espacio)
    {

    case -1:

        printf("Error\n\n");
        break;
    case 0:

        printf ("Ejecucion exitosa!\n\n");
        break;
    }
}

int intDeValidacion(char mensaje[], char error[], int minimo, int maximo)
{
    int validacion;

    printf("%s", mensaje);
    scanf("%d", &validacion);
    while (validacion < minimo || validacion > maximo)
    {
        printf("%s", error);
        scanf("%d", &validacion);
    }

    return validacion;
}


void getS(char mensaje[], char string[])
{


    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", string);
}

