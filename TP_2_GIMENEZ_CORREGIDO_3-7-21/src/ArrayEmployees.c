#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#include "karen-io.h"

#include "menues.h"


void dataEmployee(Employee lsEmployees[],int len)
{
	int i;

	int idEmp[]={1000,1001,1002,1003,1004,1005,1006};
    char names[][51]={"KAREN","BIANCA","JULIAN","LEANDRO","PATRICIO","VICTOR","CRISTINA"};
    char lastNames[][51]={"GIMENEZ","GIMENEZ","LANZONI","OTEL","BARBAGALLO","GIMMNENEZ","SERRUDO"};
    float salary[]={100,150,150.99,100,600,500,1000};
    int idSectors[]={100,102,103,104,100,102,101};
	int estados[]={1,0,0,0,0,0,0};


    for(i=0; i<len; i++)
    {
    	lsEmployees[i].id= idEmp[i];
    	strcpy(lsEmployees[i].name,names[i]);
    	strcpy(lsEmployees[i].lastName, lastNames[i]);
    	lsEmployees[i].salary= salary[i];
    	lsEmployees[i].sector= idSectors[i];
    	lsEmployees[i].isEmpty= estados[i];
    }
}
int initEmployees(Employee lista[], int len)
{
    int espacioVacio;
    espacioVacio=-1;

    if( lista != NULL && len >0)
    {
        for( int i=0; i<len; i++)
        {
            lista[i].isEmpty=1;
        }
        espacioVacio=0;
    }

    return espacioVacio;
}

void mostrarEmpleado(Employee empleado, eSector sectores[], int tamSec)
{
    char nombreSector[20];

    sector_PrintName(nombreSector,empleado.sector,sectores,tamSec);
    printf("\n|  %1d  |  %-10s  |   %-10s  |       %2.2f       |   %-12s   |",empleado.id,
           empleado.name,
           empleado.lastName,
           empleado.salary,nombreSector);
    printf("\n|--------|--------------|---------------|----------------------|------------------|\n");


}
void mostrarEmpleadoConCampos(Employee empleado, eSector sectores[], int tamSec)
{
    char nombreSector[20];
    sector_PrintName(nombreSector,empleado.sector,sectores,tamSec);
    PanelEmpleados("|   ID   |    NOMBRE    |    APELLIDO    |         SALARIO       |     SECTOR       |");
    printf("\n|  %1d  |  %-10s  |   %-10s  |       %2.2f       |   %-12s   |",empleado.id,
           empleado.name,
           empleado.lastName,
           empleado.salary,nombreSector);
}

void printEmployees(Employee lista[],int tam, eSector sectores[], int tamSec)
{
   Cartel("LISTA DE EMPLEADOS");
   PanelEmpleados("|   ID   |    NOMBRE    |    APELLIDO   |      SALARIO        |    SECTOR       |");
    if(lista !=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty ==0)
            {
                mostrarEmpleado(lista[i],sectores,tamSec);
            }
        }
    }
    else
    {
        printf("\n No hay empleados que listar\n");
    }
}

int loadValidateId(char mensaje[],char mensajeError[],Employee lista[], int len,int minN,int maxN)
{
    int idIngresado;

    idIngresado=PedirNumeroEnteroConMensajeConLimite(mensaje,mensajeError,minN,maxN,2);


    if(findEmployeeById(lista,len,idIngresado,minN,maxN) == -1)
    {
        idIngresado=-1;
        system("pause");
    }

    return idIngresado;

}

int searchFreeLocation(Employee lista[], int len)
{
    int location=-1;
    if(lista !=NULL && len>0)
    {
        for(int i=0; i<len ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                location=i;
                break;
            }
        }
    }
    return location;
}


int addEmployee( Employee lista[],int len, int idAux, char nameAux[],char lastNameAux[],float salaryAux,int sectorAux)
{
    int isOk= -1;
    int lugarDisponible = searchFreeLocation(lista,len);

    if(lista != NULL && len >0 && lugarDisponible!= -1)
    {
        lista[lugarDisponible].id = idAux;
        strcpy( lista[lugarDisponible].name,nameAux);
        strcpy( lista[lugarDisponible].lastName,lastNameAux);
        lista[lugarDisponible].salary = salaryAux;
        lista[lugarDisponible].sector = sectorAux;
        lista[lugarDisponible].isEmpty = 1;
        // lista[lugarDisponible].isEmpty = 0;
        isOk=0;
    }
    return isOk;
}

Employee loadDataEmployee(eSector lsSect[],int lenSec)
{
    Employee newEmployee;

    char auxName[51];
    char auxLastName[51];


    getValidStringLimitada("\nINGRESE EL NOMBRE DEL EMPLEADO/A\n", "\nERROR,EL NOMBRE SOLO DEBE CONTENER LETRAS\n",auxName,51);

    	for (int i = 0; auxName[i] != '\0';i++)
    	{
    		if(i== 0)
    		{
    			auxName[i] = toupper(auxName[i]);
    		}else{
    			auxName[i] = tolower(auxName[i]);
    		}

    	}

    	strcpy(newEmployee.name,auxName);

    	getValidStringLimitada("\nINGRESE EL APELLIDO DEL EMPLEADO/A\n", "\nERROR,EL APELLIDO SOLO DEBE CONTENER LETRAS\n",auxLastName,51);

		for (int i = 0; auxLastName[i] != '\0';i++)
		{
			if(i== 0)
			{
				auxLastName[i] = toupper(auxLastName[i]);
			}else{
				auxLastName[i] = tolower(auxLastName[i]);
			}

		}

		strcpy(newEmployee.lastName,auxLastName);

    utn_getNumeroFlotante(&newEmployee.salary,"\nINGRESE SALARIO: \n","\nError, Ingrese un sueldo valido: \n", 0,999999999,3);

    newEmployee.sector=loadASector(lsSect, lenSec,"\nINGRESE UN SECTOR: \n"," \nERROR, Ingrese un sector valido: \n",99,105);

    if( newEmployee.sector == -1)
    {
    	newEmployee.isEmpty=1;
    }else{
    	newEmployee.isEmpty=0;
    }

    return newEmployee;
}

int employee_Alta(Employee lista[],int idAutoincremental,int len, eSector sectores[], int tamSec)
{
    Employee auxEmpleado;

    int altaExitosa;
    int locacionDisponible;


    altaExitosa=-1;

    locacionDisponible= searchFreeLocation(lista,len);

    if(locacionDisponible!= -1 && addEmployee(lista,len,idAutoincremental,auxEmpleado.name,auxEmpleado.lastName,auxEmpleado.salary,auxEmpleado.sector)==0)
    {
        Cartel("ALTA EMPLEADOS");

		auxEmpleado= loadDataEmployee(sectores,tamSec);

		if(auxEmpleado.isEmpty != 1)
		{
			auxEmpleado.id = idAutoincremental+1;
			lista[locacionDisponible]=auxEmpleado;
			mostrarEmpleadoConCampos(lista[locacionDisponible],sectores,tamSec);
			altaExitosa=0;
		}else{
			printf("Error en la carga de datos \n");
		}

    }
    else
    {
        printf("SISTEMA COMPLETO !!!\n\n");
    }
    return altaExitosa;
}




int findEmployeeById(Employee lista[], int len,int id,int minN,int maxN)
{
    int locationEmpleado=-1;

    if(lista !=NULL && len>0 && id>=minN && id<=maxN)
    {
        for(int i=0; i<len ; i++)
        {
            if(lista[i].id == id)
            {
                locationEmpleado=i;
                break;
            }
        }
    }
    return locationEmpleado;
}


int employee_Modify(Employee listaEmp [],int lenEmp,eSector lsSect[],int lenSec,int minId,int maxId)
{
    Employee auxEmpleado;

    int retorno;
    int idEmpleadoEditable;
    int locacionEmpleado;
    char confirma;
    char respuesta;

    confirma ='n';
    respuesta='n';
    retorno =-1;


    Cartel(" MODIFICAR EMPLEADO ");
    printEmployees(listaEmp,lenEmp,lsSect,lenSec);

    idEmpleadoEditable= getValidInt("\n\nINGRESE ID EMPLEADO A MODIFICAR\n","ERROR, INGRESE UN ID VALIDO",1000,2000);
    locacionEmpleado= findEmployeeById(listaEmp,lenEmp,idEmpleadoEditable, minId, maxId);

    if(locacionEmpleado ==-1)
    {
        printf("NO EXISTE EL EMPLEADO CON ID %d\n", idEmpleadoEditable);
    }
    else
    {
        do
        {
           // system("cls");
            switch(Menu_Modificar())
            {
                case 1:
                    system("cls");
                    printf("MODIFICAR NOMBRE\n");
                    mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);

                    getValidStringLimitada("\nINGRESE NUEVO NOMBRE\n","ERROR, REINGRESE UN NOMBRE VALIDO, SOLO LETRAS HASTA 50 CARACTERES\n\n",auxEmpleado.name,51);
                    printf("Nombre Anterior [ %s ] ====> Nombre Actualizado [ %s ] \n",listaEmp[locacionEmpleado].name,auxEmpleado.name);

                    confirma=getChar("\n Confirma el nuevo nombre del empleado? s/n");

                    if(confirma =='s')
                    {
                        strcpy(listaEmp[locacionEmpleado].name,auxEmpleado.name);
                        mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);
                        retorno=1;

                        printf("\n\n >>> Se ha cambiado el nombre con exito <<< \n\n");
						respuesta ='s';
                        system("pause");
                    }
                    else
                    {
                        printf("\n LA OPERACION FUE CANCELADA POR EL USUARIO\n");
                    }
                    break;

                case 2:
                	system("cls");
                   Cartel("MODIFICAR APELLIDO\n");
                    mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);

                    getValidStringLimitada("\nINGRESE NUEVO APELLIDO\n","ERROR, REINGRESE UN APELLIDO VALIDO, SOLO LETRAS HASTA 50 CARACTERES\n",auxEmpleado.lastName,51);
                    printf("Apellido Anterior [ %s ] ====> Apellido Actualizado [ %s ] \n",listaEmp[locacionEmpleado].lastName,auxEmpleado.lastName);
                    confirma = tolower(getChar("\n Confirma el nuevo apellido del empleado? s/n"));

                    if(confirma =='s')
                    {
                        strcpy(listaEmp[locacionEmpleado].lastName,auxEmpleado.lastName);
                        mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);
                        retorno=1;

                        printf("\n\n >>> Se ha cambiado el apellido con exito <<< \n\n");
						respuesta ='s';
                        system("pause");
                    }
                    else
                    {
                        printf("\nLA OPERACION FUE CANCELADA POR EL USUARIO\n");
                    }
                    break;
                case 3:
                	system("cls");
                    Cartel("MODIFICAR SUELDO");
                    mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);
                    utn_getNumeroFlotante(&auxEmpleado.salary,"\nINGRESE SALARIO: \n","\nError, Ingrese un sueldo valido: \n", 0,999999999,3);

                    printf("Sueldo Anterior [ $%.2f ] ====> Sueldo Actualizado [ $%.2f ] \n",listaEmp[locacionEmpleado].salary,auxEmpleado.salary);
                    confirma=tolower(getChar("Desea cambiar el sueldo del empleado/a? s/n \n\n"));

                    if(tolower(confirma) =='s')
                    {
                    	listaEmp[locacionEmpleado].salary = auxEmpleado.salary;
                    	mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);
                    	retorno=1;

                       printf("\nSe ha cambiado el sueldo con exito\n\n");
                       respuesta ='s';
                       system("pause");
                    }
                    else
                    {
                        printf("\n LA OPERACION FUE CANCELADA POR EL USUARIO\n");
                    }
                    break;

                case 4:
                    system("cls");
                    Cartel("MODIFICAR SECTOR");
                    mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);
                    auxEmpleado.sector=loadASector(lsSect,lenSec,"\nINGRESE NUEVO SECTOR : \n","\nERROR,INGRESE UN SECTOR VALIDO \n", 100,104);


                    printf("Sector Anterior [ %d ] ====> Sector Actualizado [ %d ] \n",listaEmp[locacionEmpleado].sector,auxEmpleado.sector);

                    confirma=getChar("\nDesea cambiar el sector del empleado/a? s/n \n\n");
                    if(confirma =='s')
                    {
                        listaEmp[locacionEmpleado].sector=auxEmpleado.sector;
                        mostrarEmpleadoConCampos(listaEmp[locacionEmpleado],lsSect,lenSec);
                        retorno=1;
                        printf("\nSe ha cambiado el sector con exito\n\n");
                        //break;
                        respuesta ='s';
                        system("pause");
                    }
                    else
                    {
                        printf("\n LA OPERACION FUE CANCELADA POR EL USUARIO\n");
                    }
                    break;

                case 5:
                     Cartel(">>> SALIDA MODIFICACION<<< ");
                     system("pause");
                    respuesta = 'n';
                    break;
                default:

                    printf("\n\n Ingrese una opcion valida\n\n");
                    break;
                }

               //system("\n\n pause");
                system("cls");
        }
        while(respuesta=='s');
    }
    return retorno;
}

int removeEmployee(Employee lista[], int len, int id,int minN,int maxN)
{
    int isOk;

    int locacionEmpleado;

    isOk = -1;

    locacionEmpleado= findEmployeeById(lista,len,id, minN, maxN);

    if(locacionEmpleado != -1)
    {
        lista[locacionEmpleado].isEmpty=1;
        isOk=0;
    }
    return isOk;
}

int employee_Baja(Employee lista[],int len, eSector sectores[], int tamSec,int minN,int maxN)
{
    int empleadoARemover;
    int locacionEmpleadoARemover;
    char confirma;
    int bajaExitosa=-1;


    confirma='n';
    system("cls");

    Cartel("BAJA EMPLEADOS");
    printEmployees(lista,len,sectores,tamSec);

    empleadoARemover= loadValidateId("\n INGRESE EL ID EMPLEADO A REMOVER: \n","\nERROR, INGRESE UN ID VALIDO\n",lista,len,minN,maxN);
    locacionEmpleadoARemover= findEmployeeById(lista,len,empleadoARemover,minN,maxN);

    if(empleadoARemover==-1)
    {
        printf("\nERROR, El empleado con ID %d no existe!!!\n\n",empleadoARemover);
        bajaExitosa= -1;
    }
    else
    {
        mostrarEmpleadoConCampos(lista[locacionEmpleadoARemover],sectores,tamSec);
        confirma=tolower(getChar("\nDesea dar de baja al empleado? s/n\n\n"));

        if(confirma =='s'&& removeEmployee(lista,len,empleadoARemover,minN,maxN)==0)
        {

            printf("\n El EMPLEADO/A FUE DE DADO DE BAJA EXITOSAMENTE \n");

            bajaExitosa=0;
            system("pause");
        }
        else
        {
            printf("\n LA OPERACION FUE CANCELADA POR EL USUARIO\n");
            bajaExitosa=1;
            system("pause");
        }
    }
    return bajaExitosa;
}

/*-----------ORDENAR EMPLEADOS -------------*/
int sortEmployees(Employee lista[],int len,int criterio)
{
    int error= -1;
    Employee auxEmpleado;

    if( lista != NULL && len >0 && criterio>=1 &&criterio <=2)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(!lista[i].isEmpty && !lista[j].isEmpty)
                {
                     //ordenados por orden alfabetico                 //criterio==1
                    if( (strcmp(lista[i].lastName,lista[j].lastName) >0 && criterio==1) ||
                            (strcmp(lista[i].lastName,lista[j].lastName)< 0 && criterio==2) )
                    {
                        auxEmpleado =lista[i];
                        lista[i]= lista[j];
                        lista[j]= auxEmpleado;
                    }
                    else if (lista[i].lastName == lista[j].lastName && lista[i].sector > lista[j].sector )
                    {
                        auxEmpleado =lista[i];
                        lista[i]= lista[j];
                        lista[j]= auxEmpleado;
                    }
                    else if(  lista[i].lastName == lista[j].lastName && lista[i].sector < lista[j].sector )
                    {
                        auxEmpleado =lista[i];
                        lista[i]= lista[j];
                        lista[j]= auxEmpleado;
                    }
                }
            }
            error=0;
        }
    }
    return error;
}

float employee_TotalSalarios(Employee lista[],int len)
{
    float sumatoria=0;

    if(lista != NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0)
            {
                 sumatoria= sumatoria + lista[i].salary;
            }
        }
    }
    return sumatoria;
}

float employee_SalarioPromedio(Employee lista[],int len)
{
    int cantEmpleados;
    float salarioTotal;
    float salarioPromedio;

    cantEmpleados=0;

    salarioPromedio=0;

    salarioTotal = employee_TotalSalarios(lista,len);

    if(lista!= NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0)
            {
                cantEmpleados+=1;
            }
        }
        salarioPromedio= (float)(salarioTotal/cantEmpleados);
    }
    else
    {
        salarioPromedio=-1;
    }
    return salarioPromedio;
}

int employee_cantSuperaSalarioPromedio(Employee lista[],int len)
{
    int cantEmpMaxSueldo =0;
    if( lista != NULL && len >0 )
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0 && lista[i].salary >= employee_SalarioPromedio(lista,len))
            {
                cantEmpMaxSueldo+=1;
            }
        }
    }

    return cantEmpMaxSueldo;
}

void mostrarEmpleadoSalarios(Employee lista[],int len,eSector lsSec[], int lenSec)
{
    float salarioPromedio;

    printEmployees(lista,len,lsSec,lenSec);

    salarioPromedio=employee_SalarioPromedio(lista,len);

    printf("\nTOTAL DE SALARIOS -------------> $ %.2f\n\n",employee_TotalSalarios(lista,len));
    printf(" PROMEDIOS TOTAL DE SALARIOS ----> $ %.2f\n\n",salarioPromedio);
    printf("CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO ----> %d\n\n",employee_cantSuperaSalarioPromedio(lista,len));
}

void employee_Informes(Employee lista[],int len,eSector sectores[], int tamSec)
{
    int criterio;
    char salir ='n';
    char respuesta ='s';
    do
    {
        switch(Menu_Informes() )
        {

        case 1:

            criterio= getInt("\n Ingrese criterio de Ordenamiento \n\n 1- ASCENDENTE, 2- DESCENDENTE");
            sortEmployees(lista,len,criterio);
            if(sortEmployees( lista, len, criterio)==-1)
            {
                printf("\nNo se pudo realizar el ordenamiento\n\n");
                break;
            }
            else
            {
                printf("\n Empleados ordenados con exito!!!\n\n");
                printEmployees(lista,len,sectores,tamSec);
                break;

            }

        case 2:
            Cartel("SUELDOS ");
            mostrarEmpleadoSalarios(lista,len,sectores,tamSec);
            break;

        case 3:
            respuesta = tolower(getChar("Desea continuar con el programa? S/N\n"));
            if(respuesta =='n')
            {
                salir ='s';
            }
            break;
         //   system("pause");
        }
    }
    while(salir=='s');
}

