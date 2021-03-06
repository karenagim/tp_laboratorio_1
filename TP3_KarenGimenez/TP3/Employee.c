#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

#include "Employee.h"
#include "karen-io.h"
#include "menues.h"


int employee_setId(Employee* emp,int id)
{
	int isOk;
	isOk = 0;

	if(emp != NULL && id > 0 )
	{
		emp->id = id;
		isOk = 1;
	}
	return isOk;
}

int employee_setNombre(Employee* emp ,char* nombre)
{
	int error=0;           //validaciones de utn.h
	if(emp != NULL && (strlen (nombre)>=3 && strlen(nombre)<20))
	{
		strcpy( emp->nombre, nombre);
		error=1;
	}
	return error;
}

int employee_setHorasTrabajadas(Employee* pEmp,int horasTrabajadas)
{
	int isOk;

	isOk= 0;

	if(pEmp != NULL &&  horasTrabajadas>0) //&& (*idE > 0 &&  *idE<2000)
	{
		pEmp ->horasTrabajadas = horasTrabajadas;
		isOk =1;
	}
	return isOk;
}

int employee_setSueldo(Employee* pEmp, float sueldo)
{
	int isOk;

	isOk= 0;

	if(pEmp != NULL &&  sueldo> 0)
	{
		pEmp -> sueldo = sueldo;
		isOk =1;
	}
	return isOk;
}

// |||||| |||||||||| GETTERS |||||||||||||||||||||| GETTERS |||||||||||||||||| GETTERS |||||||||||||||||||||||||||||||
int employee_getId(Employee* pEmp, int* pId)
{
	int isOk;
									//Sinn validaciond  limite
	isOk= 0;
							//validacion funcion
	if(pEmp != NULL && pId != NULL ) //&& (*idE > 0 &&  *idE<2000)
	{
		*pId = pEmp-> id;
		isOk =1;
	}
	return isOk;
}
int employee_getHorasTrabajadas(Employee* pEmp,int* pHorasTrab)
{
	int isOk;

	isOk= 0;

	if(pEmp != NULL &&  pHorasTrab != NULL ) //&& (*idE > 0 &&  *idE<2000)
	{
		*pHorasTrab = pEmp->horasTrabajadas ;
		isOk =1;
	}
	return isOk;
}

int employee_getNombre(Employee* pEmp,char* pNombre)
{
	int error=0;           //validaciones de utn.h

	if( pEmp != NULL && pNombre != NULL)
	{
		strcpy(pNombre , pEmp->nombre);
		error=1;
	}
	return error;
}
int employee_getSueldo(Employee* pEmp ,float* pSueldo)
{
	int isOk;

	isOk= 0;

	if(pEmp != NULL &&  pSueldo != NULL) //&& (*idE > 0 &&  *idE<2000)
	{
		*pSueldo = pEmp->sueldo ;
		isOk =1;
	}
	return isOk;
}

//los void tengo que castearlos para tratarlos compo empleados dentro de la funcion

//-------------FUNCIONES PARA PEDIR Y REEMPLAZAR DATOS---------------
/***
 * @brief Pide un nombre al usuario y lo carga en el empleado pasado por parametro
 *
 * @param emp unEmpleado
 * @return 1 si pudo cargar el nombre, 0 si no fue posible.
 */
int employee_loadName(Employee* emp)
{
	char* newName;
	int isOk;
	int i;

	newName= (char*)malloc(sizeof(char)*128);
	isOk=0;

	if(newName != NULL)
	{
		getValidStringLimitada("\nINGRESE EL NOMBRE DEL EMPLEADO/A\n", "\nERROR,EL NOMBRE SOLO DEBE CONTENER LETRAS\n",newName,128);

		//for ( i = 0; newName[i] != '\0';i++)
		for ( i = 0 ; *(newName+i) != '\0' ; i++)
		{
			newName[i] = toupper(*(newName+i));
		}
		employee_setNombre(emp, newName);
		isOk= 1;
		free(newName);
	}
	return isOk;
}

/***
 * @brief Pide una cantidad de horas trabajadas al usuario y lo carga en el empleado pasado por parametro
 *
 * @param emp unEmpleado
 * @return 1 si pudo cargar el nombre, 0 si no fue posible.
 */
int employee_loadHoursW(Employee* pEmp)
{
	int newHoursW;
	int isOk;

	isOk=0;

	if(pEmp != NULL)
	{

		newHoursW=getValidInt("INGRESE LA CANTIDAD DE HORAS TRABAJADAS\n", "Error, Ingrese una cantidad de horas validas", 1, 999999);

		employee_setHorasTrabajadas(pEmp, newHoursW);
		isOk= 1;
	}
	return isOk;
}

/***
 * @brief Pide un sueldo al usuario y lo carga en el empleado pasado por parametro
 *
 * @param emp unEmpleado
 * @return 1 si pudo cargar el nombre, 0 si no fue posible.
 */
int employee_loadSalary(Employee* pEmp)
{
	int newSalary;
	int isOk;

	isOk=0;

	if(pEmp != NULL)
	{
		newSalary=getValidFloat("\nIngrese nuevo Sueldo\n", "\nError, Ingrese un sueldo valido\n", 1);

		employee_setSueldo(pEmp, newSalary);
		isOk= 1;
	}
	return isOk;
}




// ||||||||||| FUNCIONES DE COMPARACION DE CAMPOS |||||||||||||| FUNCIONES DE COMPARACION DE CAMPOS |||||||||||||||||||||||||

/** \brief compara el valor del campo nombre entre dos empleados
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * \return retorna 1 si el nombre del primero es mayor o -1 si el nombre del segundo es mayor o 0 si son iguales
 *
 */
int employee_CompareByName(void* e1, void* e2)
{
	int comp;

	Employee* emp1;
	Employee* emp2;

	emp1 =(Employee*) e1;
	emp2 =(Employee*) e2;

	//verificar que no sean nulo etc

	comp = strcmp(emp1->nombre,emp2->nombre);

	return comp;
}
/**
 * @brief Compara el ID de dos empleados y devuelve un entero segun la comparacion
 *
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * @return devuelve 1 si id Emp1 es mayor al id Emp2/
 *                  0 si id Emp1 es menor al id Emp2/
 *                  2 si id Emp1 es igual al id Emp2/
 */
int employee_CompareById(void* e1, void* e2)
{
		int retorno;
	    Employee* a=(Employee*) e1;
	    Employee* b=(Employee*) e2;
	    int auxIdA;
	    int auxIdB;

	    employee_getId(a,&auxIdA);
	    employee_getId(b,&auxIdB);

	    if(auxIdA>auxIdB)
	    {
	        retorno=1;

	    }else if(auxIdA==auxIdB)
	    {
	        retorno=0;
	    }else
	    {
	        retorno=-1;
	    }
	    //auxIdA-auxIdB

	    return retorno;
	}




/**
 * @brief Compara la cantidad de horas trabajadas entre dos ID empleados y devuelve un entero segun la comparacion
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * @return devuelve 1 si horas trabajadas Emp1 es mayor al de  horas trabajadas Emp2/
 *                  0 si horas trabajadas Emp1 es menor al de  horas trabajadas Emp2/
 *                  2 si horas trabajadas Emp1 es igual al de horas trabajadas Emp2/
 */

int employee_CompareByHoursW(void* e1, void* e2)
{
	int comp;

	Employee* emp1;
	Employee* emp2;

	int horasT1;
	int horasT2;

	emp1 =(Employee*) e1;
	emp2 =(Employee*) e2;

	if(emp1 != NULL && emp2 != NULL)
	{
		employee_getHorasTrabajadas(emp1, &horasT1);
		employee_getHorasTrabajadas(emp2, &horasT2);

			if(horasT1 > horasT2)
			{
				comp=1;
			}else if(horasT1 == horasT2)
			{
				comp=0;
			}else
			{
				comp=-1;
			}
	}
	return comp;
}

/**
 * @brief Compara el sueldo entre dos ID empleados y devuelve un entero segun la comparacion
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * @return devuelve 1 si sueldo Emp1 es mayor al Emp2/
 *                  0 si sueldo Emp1 es menor al Emp2/
 *                  -1 si sueldo Emp1 es igual al Emp2/
 *                  2 si ambos empleados son NULL
 */
int employee_CompareBySalary(void* e1, void* e2)
{
	int comp;

	Employee* emp1;
	Employee* emp2;

	float salaryE1;
	float salaryE2;

	emp1 =(Employee*) e1;
	emp2 =(Employee*) e2;

	comp=2;

	if(emp1 != NULL && emp2 != NULL)
	{
		employee_getSueldo(emp1, &salaryE1);
		employee_getSueldo(emp2, &salaryE2);

		if(salaryE1 > salaryE2)
		{
			comp=1;
		}else if(salaryE1 == salaryE2)
		{
			comp=0;
		}else
		{
			comp=-1;
		}
	}

	return comp;
}



//------------------------------------FUNCIONES PARA MOSTRAR EN PANTALLA------------------------------------

void Employee_PrintOneIndex( LinkedList* lista, int index)
{
   Employee* pEmp;
   pEmp = (Employee*)ll_get(lista, index);
   Employee_PrintOne_Fields(pEmp);
}


void Employee_PrintOne(Employee* pEmp)
{
    int id;
    char nombre[128];
    int horasTrab;
    float sueldo;

    employee_getId(pEmp, &id);
    employee_getNombre(pEmp, nombre);
    employee_getHorasTrabajadas(pEmp, &horasTrab);
    employee_getSueldo(pEmp, &sueldo);


    printf("%4d 	%-10s   %4d 	      %4.2f \n",id,nombre,horasTrab,sueldo);
}


void Employee_PrintOne_Fields(Employee* pEmp)
{
	PanelFields("| ID  |   NOMBRE | HORAS TRABAJADAS|   SALARIO  |");
	Employee_PrintOne(pEmp);
}


Employee* Employee_new()
{
	Employee* pEmp;
	pEmp= (Employee*)malloc(sizeof(Employee));

	return pEmp;
}


int employee_setAll_Setters(Employee* pEmp,int id,char* nombre,int horasTrabajadas,float sueldo)
{
	int isOk;

	int set_id;
	int set_nombre;
	int set_horasTrab;
	int set_sueldo;

	isOk =0;
	if(pEmp != NULL)
	{
		set_id= employee_setId(pEmp,id);
		set_nombre=employee_setNombre(pEmp, nombre);
		set_horasTrab = employee_setHorasTrabajadas(pEmp, horasTrabajadas);
		set_sueldo=employee_setSueldo(pEmp, sueldo);

		if(set_id==1  && set_nombre==1 && set_horasTrab==1 && set_sueldo==1)
		{
			isOk=1; // Parametros cargados correctamente
		}
	}

	return isOk;
}

int employee_getAll_Getters(Employee* pEmp,int id,char* nombre,int horasTrabajadas,float sueldo)
{
	int isOk;

	int get_id;
	int get_nombre;
	int get_horasTrab;
	int get_sueldo;

	isOk = 0;
	if(pEmp != NULL)
	{

		get_id= employee_getId(pEmp, &id);
		get_nombre= employee_getNombre(pEmp, nombre);
		get_horasTrab= employee_getHorasTrabajadas(pEmp, &horasTrabajadas);
		get_sueldo= employee_getSueldo(pEmp, &sueldo);

		if( get_id==1 && get_nombre==1 && get_horasTrab==1 && get_sueldo==1)
		{
			isOk = 1;
		}
	}
	return isOk;
}


Employee* Employee_LoadWParameters(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
	Employee* pNewEmployee;

	int idEmp;
	int hoursWorkedEmp;
	float salaryEmp;

	pNewEmployee= Employee_new();

	idEmp = atoi(id);
	hoursWorkedEmp = atoi(horasTrabajadas);
	salaryEmp = atof(sueldo);

	if(pNewEmployee != NULL)
	{
		if(!(employee_setAll_Setters(pNewEmployee, idEmp, nombre, hoursWorkedEmp, salaryEmp) ))
		{
			free(pNewEmployee);
			pNewEmployee=NULL;
		}
	}
	return pNewEmployee;
}

/*----------------------------*/

int employee_MaxId(LinkedList* pArrayEmployee)
{
	Employee* pEmployee;
	int len;
	int auxId;
	int maxId;
	int flagMaxId;

	int i;

	len = ll_len(pArrayEmployee);
	maxId = 0;
	flagMaxId= 0;

	if(pArrayEmployee != NULL)
	{
		for(i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayEmployee, i);
			employee_getId(pEmployee, &auxId);

			if(auxId > maxId || flagMaxId == 0)
			{
				maxId = auxId;
				flagMaxId = 1;
			}
		}
	}
	return maxId;
}

int Employee_PrintAll(LinkedList* pArrayEmployee)
{
	Employee* pEmp;
	int i;
	int len;
	int isOk;

	len= ll_len(pArrayEmployee);
	isOk= 0;

	if(pArrayEmployee!= NULL && len>0)
	{
		PanelFields("| ID  |   NOMBRE | HORAS TRABAJADAS|   SALARIO  |");
		for(i = 0 ; i< len ; i++)
		{
			pEmp=(Employee*)ll_get(pArrayEmployee, i);
			Employee_PrintOne(pEmp);
		}
		isOk=1;
	}
	return isOk;
}


Employee* loadDataEmployee(Employee* pEmp,LinkedList* pArrayEmployee)
{
   // Employee newEmployee;
    int id;
    char auxName[128];
    int hoursWork;
    float salary;

    id=(employee_MaxId(pArrayEmployee)+1);

    getValidStringLimitada("\nINGRESE EL NOMBRE DEL EMPLEADO/A\n", "\nERROR,EL NOMBRE SOLO DEBE CONTENER LETRAS\n",auxName,128);

	for (int i = 0; auxName[i] != '\0';i++)
	{
		auxName[i] = toupper(auxName[i]);
	}

	hoursWork=getValidInt("Ingrese la cantidad de horas trabajadas\n", "Error,  ingrese una cantidad de horas valida\n", 0,10000);

	salary= getValidFloat("\nINGRESE SALARIO: \n","\nError, Ingrese un sueldo valido: \n", 0);

	if(!(employee_setAll_Setters(pEmp, id, auxName, hoursWork, salary)))
	{
		free(pEmp);
	}

    return pEmp;
}


int employee_Alta(LinkedList* pArrayEmployee,Employee* pEmp)
{

    int lastId;
    int isOk;

    lastId=(employee_MaxId(pArrayEmployee))+1;

    isOk=-1;

    Cartel("ALTA EMPLEADOS");
    if(pEmp != NULL && loadDataEmployee(pEmp,pArrayEmployee)!= NULL )
    {
    	employee_setId(pEmp, lastId);

    	isOk= 1;
    }
    else
    {
        printf("SISTEMA COMPLETO !!!\n\n");
        free(pEmp);
    }
    return isOk;
}


int employee_searchId(LinkedList* pArrayEmployee, int idABuscar)
{
	Employee* pEmp;
	int auxId;
	int len;
	int isOk;
	int i;

	isOk= 0;

	len = ll_len(pArrayEmployee);
	if(pArrayEmployee != NULL && len>0)
	{
		for(i= 0 ; i< len ; i++)
		{
			pEmp= ll_get(pArrayEmployee, i);
			employee_getId(pEmp, &auxId);

			if(	auxId == idABuscar)
			{
				isOk=i;
				break;
			}
		}
	}
	return isOk;
}


int employee_idExist(LinkedList* pArrayEmployee, int idABuscar)
{
	int isOk;

	isOk=0;

	if(employee_searchId(pArrayEmployee, idABuscar)!=0 )
	{
		isOk=1;
	}
	return isOk;
}


int Employee_edit(LinkedList* pArrayEmployee)
{
	Employee* pEmp;
	Employee* auxEmployee;

	int idEmployeeEditable;
	int index;

	char auxChar[128];
	int newHoursW;
	float newSalary;

	int retorno;

	char respuesta;
	char confirma;

	auxEmployee = Employee_new();

	retorno = 0;
	confirma='n';
	respuesta = 'n';

	Cartel(" MODIFICAR EMPLEADO ");
	Employee_PrintAll(pArrayEmployee);

	idEmployeeEditable= getValidInt("Ingrese el id del empleado a modificar","ERROR, INGRESE UN ID VALIDO",0,2000);

	if(employee_idExist(pArrayEmployee, idEmployeeEditable )==0)
	{
		printf("El empleado con id %d no existe\n",idEmployeeEditable);

	}else{
			index=employee_searchId( pArrayEmployee, idEmployeeEditable); // busco el id a modificar
			pEmp= (Employee*)ll_get(pArrayEmployee,index); // obtengo el empleado ubicado en ese id
			 do
			   {	// system("cls");
		            switch(Menu_Modificar())   // abro menu
		            {
		                case 1:
		                    //system("cls");
		                    printf("MODIFICAR NOMBRE\n");
		                    Employee_PrintOneIndex(pArrayEmployee, index); //muestro el empleado

		                    employee_loadName(auxEmployee); //Pido el nombre y lo guardo en auxEmployee
		                    printf("\n %s ===> %s \n",pEmp->nombre, auxEmployee ->nombre); // muestro los posibles cambios
		                    confirma=getChar("\n Confirma el nuevo nombre del empleado? s/n"); // confirmo?

		                    if(confirma =='s')
		                    {
		                    	employee_getNombre(auxEmployee, auxChar); //copio el valor de nombre de auxEmp en  var auxChar

		                    	employee_setNombre(pEmp ,auxChar);// copio el valor de auxChar en el pEmp original
		                    	Employee_PrintOneIndex(pArrayEmployee, index);
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
						Cartel("MODIFICAR HORAS TRABAJADAS");
						Employee_PrintOneIndex(pArrayEmployee, index);
						employee_loadHoursW(auxEmployee);

						printf("\n %4d ===> %4d\n",pEmp->horasTrabajadas, auxEmployee ->horasTrabajadas); // muestro los posibles cambios

						confirma=getChar("Desea cambiar las horas trabajadas del empleado/a? s/n \n\n");

						if(tolower(confirma) =='s')
						{

							employee_getHorasTrabajadas(auxEmployee, &newHoursW); //copio el valor de nombre de auxEmp en  var auxChar
							employee_setHorasTrabajadas(pEmp ,newHoursW);// copio el valor de auxChar en el pEmp original
							Employee_PrintOneIndex(pArrayEmployee, index);
							retorno=1;

							printf("\n\n >>> Se ha cambiado las horas con exito <<< \n\n");
							respuesta ='s';
							system("pause");
						}
						else
						{
							printf("\n LA OPERACION FUE CANCELADA POR EL USUARIO\n");
						}
						break;

		                case 3:
		                    Cartel("MODIFICAR SUELDO");
		                    Employee_PrintOneIndex(pArrayEmployee, index);
		                    employee_loadSalary(auxEmployee);

		                    printf("\n %.2f ===> %.2f \n",pEmp->sueldo, auxEmployee->sueldo); // muestro los posibles cambios

		                    confirma=getChar("Desea cambiar el sueldo del empleado/a? s/n \n\n");

		                    if(tolower(confirma) =='s')
		                    {
		                        //employee_loadSalary(AuxEmployee);
		                    	employee_getSueldo(auxEmployee, &newSalary); //copio el valor de nombre de auxEmp en  var auxChar

		                    	employee_setSueldo(pEmp ,newSalary);// copio el valor de auxChar en el pEmp original
								Employee_PrintOneIndex(pArrayEmployee, index);
								retorno=1;

								printf("\n\n >>> Se ha cambiado el sueldo con exito <<< \n\n");
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

		                system("cls");
		        }
		        while(respuesta=='s');
  }
	free(auxEmployee);
	return retorno;
}


int Employee_delete(LinkedList* pArrayEmployee)
{
     int index;
     int idEmployeeEditable;

     char confirma;

     int isOk;

     confirma='n';
     isOk=0;

    Cartel(" BAJA EMPLEADO ");
    Employee_PrintAll(pArrayEmployee);

    idEmployeeEditable= getValidInt("Ingrese el id del empleado a dar de baja\n","ERROR, INGRESE UN ID VALIDO\n",0,2000);

	if(employee_idExist(pArrayEmployee, idEmployeeEditable )==0)
	{
		printf("El empleado con id %d no existe\n",idEmployeeEditable);

	}else{
			index=employee_searchId( pArrayEmployee, idEmployeeEditable); // busco el id del empleado a eliminar
			system("cls");
			Employee_PrintOneIndex(pArrayEmployee,index);

			confirma = tolower(getChar("\nconfirma la baja ? S / N\n"));
            if(confirma=='s')
            {
				if(ll_remove(pArrayEmployee,index)==0)
				{
					printf("\nSe ha realizado la baja con exito\n\n");
					isOk=1;
				}
				else
				{
					printf("\nNo se pudo realizar la baja\n\n");
				}
			}
			else
			{
				printf("Se cancelo la operacion\n\n");
			}
    }
	return isOk;
}


int Employee_Sort(LinkedList* pArrayEmployee)
{
    int criterio;
    int todoOk;

    todoOk=0;

    if(pArrayEmployee!=NULL)
    {
        system("cls");
        Cartel( "ORDENAR EMPLEADOS");

		criterio=PedirNumeroEnteroConMensaje("\nIngrese 0 para ordenar en forma DSC\nIngrese 1 para ordenar en forma ASC", "\nError, Ingrese una opcion valida\n", 0, 1);

		system("cls");
		switch(Menu_Ordenar())
		{
			case 1:
			  Cartel("ORDENAR POR ID");
			  printf("\n\n...Ordenamiento en proceso...\n\n");
			  ll_sort(pArrayEmployee,employee_CompareById,criterio);
			  printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
			  system("pause");

			  todoOk=1;
			  break;

			case 2:
				Cartel("ORDENAR POR NOMBRE");
				printf("\n\n...Ordenamiento en proceso...\n\n");
				ll_sort(pArrayEmployee,employee_CompareByName,criterio);
				printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
				system("pause");

				todoOk=1;
				break;

		   case 3:
			   Cartel("ORDENAR POR CANTIDAD DE HORAS TRABAJADAS");
			   printf("\n\n...Ordenamiento en proceso...\n\n");
			   ll_sort(pArrayEmployee,employee_CompareByHoursW,criterio);

			   printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
			   system("pause");
			   todoOk=1;
				break;

		   case 4:
			   Cartel("ORDENAR POR SUELDO");
			   printf("\n\n...Ordenamiento en proceso...\n\n");
			   ll_sort(pArrayEmployee,employee_CompareBySalary,criterio);

			   printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
			   system("pause");
				todoOk=1;
				break;

		   default:
				printf("\n<<<<<<<<<<<<<< VOLVIENDO A MENU <<<<<<<<<<<<\n");
				system("pause");
				break;
		}
    }
    return todoOk;
}

