
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menues.h"
#include "karen-io.h"

void Cartel(char mensaje[])
{
	system("cls");
	printf("\n--------------------------------");
	printf("\n------  %s  --------",mensaje);
	printf("\n-------------------------------\n");
}

void PanelFields(char mensaje[])
{
	printf("----------------------------------------------------\n");
	printf("%s\n",mensaje);
	printf("-----------------------------------------------------\n");
}

void CartelABM(char mensaje[])
{
	system("cls");
	printf("\n####################################################################");
	printf("\n%5s",mensaje);
	printf("\n####################################################################\n");
}


/*-----------MENUES TP3 - ABM DINAMICO--------*/

void Menu_OptionABM()
{
	printf("\n*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//
	printf("\n[1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)]");
	printf("\n[2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)]");
	printf("\n[3- ALTA DE EMPLEADO]");
	printf("\n[4- MODIFICAR DATOS DE EMPLEADO]");
	printf("\n[5- BAJA DE EMPLEADO]");
	printf("\n[6- LISTAR EMPLEADOS]");
	printf("\n[7- ORDENAR EMPLEADOS]");
	printf("\n[8- Guardar los datos de los empleados en el archivo data.csv (modo texto)]");
	printf("\n[9- Guardar los datos de los empleados en el archivo data.csv (modo binario)]");
	printf("\n[10- SALIR]");
	printf("\n*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n_____________________[Gimenez Karen 1-F]_");
}

int Menu_MainABM()
{
    int opcion;
    Cartel("--MENU EMPLEADOS TP3---");
    Menu_OptionABM();

    opcion= PedirNumeroEnteroConMensaje("Ingrese una opcion del 1 al 10\n","ERROR, reingrese una opcion valida\n",1,10);

    return opcion;
}


void OpcionesMenuCampos()
{

	printf("\n=================================================\n");
	printf("\n---[ 1 - ID  ]---------------");
	printf("\n---[ 2 - NOMBRE  ]---------------");
	printf("\n---[ 3 - HORAS TRABAJADAS    ]---------------");
	printf("\n---[ 4 - SUELDO  ]---------------");
	printf("\n\n>>>[ 5 - REGRESAR AL MENU PRINCIPAL ]<<<<<<<<<<");
	printf("\n================================================\n");
}

int Menu_Modificar()
{
    int opcion;
    Cartel("MODIFICAR EMPLEADOS");
    OpcionesMenuCampos();
    opcion= PedirNumeroEnteroConMensaje("\nSeleccione la opcion correspondiente\n","ERROR, reingrese una opcion valida\n",1,5);
    return opcion;
}


int Menu_Ordenar()
{
    int opcion;
    Cartel("ORDENAR EMPLEADOS");
    OpcionesMenuCampos();
    opcion= PedirNumeroEnteroConMensaje("\nElija la opcion segun su criterio de ordenamiento \n","ERROR, reingrese una opcion valida\n",1,4);
    return opcion;
 }






/*---------MENUES TP2 ABM ESTATICO--------------------------- */





void OpcionesMenuABM()
{
	printf("\n*********************************************");
	printf("\n[1- ALTA]");
	printf("\n[2- BAJA]");
	printf("\n[3- MODIFICACION]");
	printf("\n[4- LISTADO PRODUCTOS]");
	printf("\n[5- LISTADO PRODUCTOS ORDENADOS POR PRECIO]");
	printf("\n[6- LISTADO PRODUCTOS ORDENADOS POR DESCRIPCION]");
	printf("\n[7- LISTADO PRODUCTO/S MAS CAROS]");
	printf("\n[8- Precio promedio por tipo de producto]");
	printf("\n[9- LISTA DE PRODUCTOS POR TIPO]");
	printf("\n[10- SALIR]");
	printf("\n*********************************************\n");
}


int MenuABM()
{
    int opcion;
    Cartel("ABM PRODUCTOS UTN");
    OpcionesMenuABM();
    opcion= PedirNumeroEnteroConMensaje("Ingrese una opcion del 1 al 10\n","ERROR, reingrese una opcion valida\n",1,13);

    return opcion;
}


/*---------MENUES TP1 CALCULADORA------------ */
int Menu(int flag1,int flag2,int numero1,int numero2)
{
    int opcion;
    Cartel("CALCULADORA UTN");
    OpcionesMenuConParametros(flag1,flag2,numero1,numero2);
    opcion= PedirNumeroEnteroConMensaje("Ingrese una opcion del 1 al 5\n","ERROR, reingrese una opcion valida\n",1,5);

    return opcion;
}

void mostrarIngresoOperando(int flag,char mensaje[],int numero,char mensajeAlternativo[])
{
	if(flag==1)
	{
		printf("%s",mensaje);
		printf(" = %d)]\n",numero);
	}
	else{
		printf("%s\n",mensajeAlternativo);
	}
}

void OpcionesMenuConParametros(int flag1,int flag2,int numero1,int numero2)
{
	mostrarIngresoOperando(flag1,"[1- Ingresar 1er operando (A",numero1,"[1- Ingresar 1er operando (A = X)]");
	mostrarIngresoOperando(flag2,"[2- Ingresar 2do operando (B",numero2,"[2- Ingresar 2do operando (B = Y)]");

	printf("[3- Calcular todas las operaciones]");
	printf("\n[4- Informar resultados]");
	printf("\n[5- Salir]");

	printf("\n---------------------------------------\n");
	printf("\n-----------------------Karen Gimenez 1F\n");
}
