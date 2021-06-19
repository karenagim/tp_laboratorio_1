#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pListEmployee)
{
	Employee* auxEmployee;
	int cant_fields;

	int isOk;

	char* idStr;
	char* nameStr;
	char* hoursWorkedStr;
	char* salaryStr;

	idStr = (char*)malloc(sizeof(char)*100);

	nameStr = (char*)malloc(sizeof(char)*100);

	hoursWorkedStr = (char*)malloc(sizeof(char)*100);

	salaryStr = (char*)malloc(sizeof(char)*100);

	auxEmployee=Employee_new();

	cant_fields=0;
	isOk= 0;

	if(pFile== NULL && pListEmployee == NULL)
	{
		ll_clear(pListEmployee);
	}else{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr, nameStr, hoursWorkedStr, salaryStr);

		while( !feof(pFile))
		{

			cant_fields= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr, nameStr, hoursWorkedStr, salaryStr);
			if(cant_fields==4)
			{
				auxEmployee= Employee_LoadWParameters(idStr, nameStr, hoursWorkedStr, salaryStr);
				if(auxEmployee != NULL)
				{
					ll_add(pListEmployee, auxEmployee);
					isOk=1;
				}
			}
			else
			{
				printf("no pudo cargar todos los campos\n");
			}
		}

	}
	 return isOk;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
