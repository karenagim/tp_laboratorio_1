/*
 ============================================================================
 Name        : TP_2_GIMENEZ.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menues.h"
#include "ArrayEmployees.h"
#include "sectorEmployees.h"

#include "karen-io.h"

#define TAMSEC 5
#define CANT_DATA 7

#define TAM 10
int main()
{
	setbuf(stdout,NULL);

    Employee empleados[TAM];

    eSector sectores[TAMSEC] =
    {
        {100, "SISTEMAS"},
        {101, "RRHH"},
        {102, "VENTAS"},
        {103, "COMPRAS"},
        {104, "CONTABLE"}
    };

    int proximoId =999;
    char respuesta;
    int flagAlta =0;

    respuesta='s';

    initEmployees(empleados,TAM);
    dataEmployee(empleados,CANT_DATA);

    proximoId+= CANT_DATA;

    do
    {
        switch(menuABMEmpleados())
        {
        case 1:
            if(employee_Alta(empleados,proximoId,TAM,sectores,TAMSEC)==0)
            {
                proximoId+=1;
                //flagAlta=1;
            }
            if(proximoId >999)
            {
                flagAlta=1;
            }
            break;

        case 2:
            if(proximoId<999 && flagAlta != 1 )
            {
                printf("\n\n ERROR, DEBE EXISTIR AL MENOS UN EMPLEADO!!!\n\n");
            }
            else
            {
                employee_Modify(empleados,TAM,sectores,TAMSEC,1000,2000);
               // break;
            }
            break;

        case 3:
            if(proximoId<999 && flagAlta != 1 )
            {
                printf("\n\nERROR, DEBE EXISTIR AL MENOS UN EMPLEADO!!!\n\n");
                break;
            }
            else
            {
                employee_Baja(empleados,TAM,sectores,TAMSEC,1000,2000);
                 break;
            }


        case 4:
            if(proximoId<999 && flagAlta != 1 )
            {
                printf("\n\n NO HAY EMPLEADOS QUE MOSTRAR!!!\n\n");
            }
            else
            {
                employee_Informes(empleados,TAM,sectores,TAMSEC);
            }
            break;

        case 5:
            respuesta = 'n';
            break;

        default:

            printf("\n\n Ingrese una opcion valida\n\n");
            break;
        }

        system("\n\n pause");
        system("cls");

    }
    while(respuesta=='s');

	return EXIT_SUCCESS;

}
