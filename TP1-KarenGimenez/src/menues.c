
#include <stdio.h>
#include <stdlib.h>
#include "menues.h"
#include "karen-io.h"

void Cartel(char mensaje[])
{
	system("cls");
	printf("\n########################################");
	printf("\n------  %s  --------",mensaje);
	printf("\n########################################\n");
}

void OpcionesMenu()
{
	printf("\n*********************************************");
	printf("\n[1- Ingresar 1er operando (A=x)]");
	printf("\n[2- Ingresar 2do operando (B=y)]");
	printf("\n[3- Calcular todas las operaciones]");
	printf("\n[4- Informar resultados]");
	printf("\n[5- Salir]");
	printf("\n*********************************************\n");
}


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
