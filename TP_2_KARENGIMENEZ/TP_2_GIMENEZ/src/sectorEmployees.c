#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menues.h"
#include "ArrayEmployees.h"
#include "sectorEmployees.h"

#include "karen-io.h"

//#include "karen-io.h"

void sector_printOne(eSector oneSector)
{
   printf("\n|    %2d   |  %10s   |",oneSector.id ,oneSector.name);
   printf("\n|--------------------------|");
}

int sector_printList(eSector listaSec[], int lenSec)
{
    int isOk;

    isOk=-1;


    if(listaSec!= NULL && lenSec > 0)
    {
        Cartel("LISTA DE SECTORES");
        printf("\n|    ID    |     SECTOR    |");
        printf("\n----------------------------");
        for(int i=0; i<lenSec; i++)
        {
            sector_printOne(listaSec[i]);
            isOk=1;
        }
    }
    return isOk;
}

int loadASector(eSector listaSec[], int lenSec, char mensaje[],char mensajeError[],int min,int max,int limite)
{
    int sectorIngresado;

    sectorIngresado=-1;

     if(listaSec!= NULL && lenSec > 0)
     {
          sector_printList(listaSec, lenSec);
          sectorIngresado= PedirNumeroEnteroConMensajeConLimite(mensaje,mensajeError,min,max,limite);
     }
   return sectorIngresado;
}

int sector_PrintName(char descripcion[], int idSec, eSector listaSec[], int lenSec)
{
    int todoOk = -1;
    for(int i=0; i<lenSec; i++)
    {
        if(listaSec[i].id == idSec)
        {
            strcpy(descripcion, listaSec[i].name);
            todoOk = 1;
        }
    }
    return todoOk;
}
