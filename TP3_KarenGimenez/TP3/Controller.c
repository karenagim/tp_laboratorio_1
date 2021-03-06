#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayEmployee)
{
	FILE* pFile;

	int isOk;
	pFile= fopen(path,"r");

	isOk = -1;

	if(pFile != NULL && pArrayEmployee != NULL)
	{
		//ll_clear(pArrayEmployee);
		if(parser_EmployeeFromText(pFile,pArrayEmployee)==1)
		{
			printf("Empleados cargados con exito desde %s\n",path);
			isOk=1;
			//fclose(pFile);
		}
	}
	fclose(pFile);
	return isOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayEmployee)
{
	int isOk;
	Employee* newEmp;

	newEmp = Employee_new();
	isOk= -1;

	if(newEmp != NULL && employee_Alta(pArrayEmployee, newEmp) != -1)
	{
		if(ll_add(pArrayEmployee, newEmp)==0)
		{
			Employee_PrintOne_Fields(newEmp);

			printf("Alta exitosa\n");
			isOk= 1;
		}
	}
	else{
		free(newEmp);
	}
	return isOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayEmployee)
{
	int isOk;

	isOk=0;
	if(pArrayEmployee != NULL && Employee_edit(pArrayEmployee) != -1)
	{
		printf("Modificacion exitosa\n");
		isOk= 1;
	}

	return isOk;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayEmployee)
{
	int isOk;

	isOk=0;
	if(pArrayEmployee != NULL && Employee_delete(pArrayEmployee) != 0)
	{
		printf("baja exitosa\n");
		isOk= 1;
	}

	return isOk;
}

/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayEmployee)
{
	int isOk;

	isOk=0;
	if(pArrayEmployee != NULL && Employee_PrintAll(pArrayEmployee) != 0)
	{
		isOk= 1;
	}
	return isOk;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayEmployee)
{
	int isOk;

	isOk=0;
	if(pArrayEmployee != NULL && Employee_Sort(pArrayEmployee) ==1)
	{
		printf("El ordenamiento fue realizado correctamente---\n");
		isOk= 1;
	}
	return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 1;

	FILE* pFile;
	Employee* pEmp;

	int len;

	int auxId;
	char auxNombre[128];
	int auxHT;
	float auxSueldo;

	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile, "id,nombre,horas trabajadas,sueldo\n");
			for(int i = 0; i < len ; i++)
			{

				pEmp = (Employee*)ll_get(pArrayListEmployee, i);
				if(employee_getAll_Getters(pEmp,auxId, auxNombre, auxHT, auxSueldo)==1)
				{
					fprintf(pFile,"%4d,%s,%d,%2.2f\n", auxId, auxNombre, auxHT, auxSueldo);
					isOk = 1;
				}
			}
			fclose(pFile);
		}
	}
    return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* pEmployee;
	int len;

	int isOk;

	isOk = 0;
	len=ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < len; i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		fclose(pFile);
		isOk = 1;
	}

    return isOk;
}


