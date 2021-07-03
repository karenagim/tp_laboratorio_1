
#include <stdio.h>
#include <stdlib.h>
#include "menues.h"
#include "karen-io.h"

void Cartel(char mensaje[])
{
	system("cls");
	printf("\n#############################################");
	printf("\n------  %s  --------",mensaje);
	printf("\n##############################################\n");
}

void CartelABM(char mensaje[])
{
	system("cls");
	printf("\n####################################################################");
	printf("\n%5s",mensaje);
	printf("\n####################################################################\n");
}

void PanelEmpleados(char mensaje[])
{
    system("cls");
    printf("\n////////////////////////////////////////////////////////////////////////////////\n");
    printf("%s",mensaje);
    printf("\n////////////////////////////////////////////////////////////////////////////////\n");

}


void OpcionesMenuABMEmpleados()
{
    Cartel("----ABM DE EMPLEADOS----");

	printf("\n       [ 1 - ALTA EMPLEADO      ]\n       --------------------------");
	printf("\n       [ 2 - MODIFICAR DATOS    ]\n       --------------------------");
	printf("\n       [ 3 - BAJA EMPLEADO      ]\n       --------------------------");
	printf("\n       [ 4 - INFORMES EMPLEADOS ]\n       --------------------------");
	printf("\n  >>>>>[ 5 -    SALIR           ]<<<<<<<<<<");
	printf("\n================================================\n");
	printf("\n------------------------------Gimenez Karen 1F--=\n");
}





///-------------------OTROS MENUES------------
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

void OpcionesMenuModificar()
{
	 Cartel("MODIFICAR EMPLEADO");
	printf("\n=================================================\n");
	printf("\n---[ 1 - NOMBRE   ]---------------");
	printf("\n---[ 2 - APELLIDO ]---------------");
	printf("\n---[ 3 - SALARIO  ]---------------");
	printf("\n---[ 4 - SECTOR   ]---------------");
	printf("\n\n>>>[ 5 - REGRESAR AL MENU PRINCIPAL ]<<<<<<<<<<");
	printf("\n================================================\n");
}

void OpcionesMenuInformes()
{
    Cartel("INFORMES DE EMPLEADOS");
	printf("\n=================================================\n");
	printf("\n---[ 1 - LISTADO DE LOS EMPLEADOS (APELLIDO-SECTOR)]---------------");
	printf("\n---[ 2 - BALANCES DE SUELDO DE LOS EMPLEADOS ]---------------");
	printf("\n\n>>>[ 3 - REGRESAR AL MENU PRINCIPAL ]<<<<<<<<<<");
	printf("\n================================================\n");
}

int menuABMEmpleados()
{
    int opcion;
    OpcionesMenuABMEmpleados();
    opcion= getValidIntLimite("\nSeleccione la opcion correspondiente\n","ERROR, reingrese una opcion valida\n",1,5,3);

    return opcion;

}


int Menu_Inicio()
{
    int opcion;
    OpcionesMenuModificar();
    opcion= PedirNumeroEnteroConMensaje("Seleccione la opcion correspondiente\n","ERROR, reingrese una opcion valida\n",1,5);

    return opcion;
}

int Menu_Modificar()
{
    int opcion;
    OpcionesMenuModificar();
    opcion= PedirNumeroEnteroConMensaje("Seleccione la opcion correspondiente\n","ERROR, reingrese una opcion valida\n",1,5);

    return opcion;
}

int Menu_Informes()
{
    int opcion;
    OpcionesMenuInformes();
    opcion= PedirNumeroEnteroConMensaje("Seleccione la opcion correspondiente\n","ERROR, reingrese una opcion valida\n",1,3);

    return opcion;
}

//-------------------------MENUES DE ABMS PRODUCTOS
int MenuABM()
{
    int opcion;
    Cartel("ABM PRODUCTOS UTN");
    OpcionesMenuABM();
    opcion= PedirNumeroEnteroConMensaje("Ingrese una opcion del 1 al 10\n","ERROR, reingrese una opcion valida\n",1,13);

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


int Menu(int flag1,int flag2,int numero1,int numero2)
{
    int opcion;
    Cartel("CALCULADORA UTN");
    OpcionesMenuConParametros(flag1,flag2,numero1,numero2);
    opcion= PedirNumeroEnteroConMensaje("Ingrese una opcion del 1 al 5\n","ERROR, reingrese una opcion valida\n",1,5);

    return opcion;
}
