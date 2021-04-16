
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "karen-io.h"


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int PedirNumeroEntero(char mensaje[])
{
    int numeroEntero;

    printf("%s",mensaje);
    scanf("%d", &numeroEntero);

    return numeroEntero;
}


int PedirNumeroEnteroConMensaje(char mensaje[],char mensajeError[],int minimo,int maximo)
{

     int numeroIngresado;

    printf("%s",mensaje);
    scanf("%d", &numeroIngresado);
    while(numeroIngresado<minimo|| numeroIngresado>maximo)
    {
        printf("%s", mensaje);
        scanf("%d",&numeroIngresado);

    }
    return numeroIngresado;
}
