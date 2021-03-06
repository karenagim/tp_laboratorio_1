#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"

#include "Controller.h"
#include "Employee.h"
#include "menues.h"
#include "karen-io.h"

/****************************************************
 *
 * Gimenez, Karen Antonella 1F
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

	char seguir = 's';
	char confirma;
	int flagIngreso=0;
	int flagIngresoB=0;
	LinkedList* lista = ll_newLinkedList();

	    do
	    {
	        switch(Menu_MainABM())
	        {
	       case 1:
	           if(!flagIngreso)
	           {
	               if(controller_loadFromText("data.csv",lista)==1)
	                {
	                    printf("\nSe cargaron los datos con exito\n\n");
	                    flagIngreso=1;
	                }
	                else
	                {
	                    printf("Nose pudieron cargar los datos\n\n");
	                }
	           }
	           else
	           {
	               printf("Los datos ya han sido sido cargados\n\n");
	           }

	        break;
	       case 2:
	           if(!flagIngresoB)
	           {
	                if(controller_loadFromBinary("data.bin",lista)==1)
	                {
	                    if(flagIngreso==0)
	                    {
	                        printf("\nSe cargaron los datos con exito\n\n");
	                        flagIngresoB=1;
	                    }
	                    else
	                    {
	                        printf("Se sustituyeron los datos del texto por el binario\n\n");
	                        flagIngresoB=1;
	                    }
	                }
	                else
	                {
	                    printf("Nose pudieron cargar los datos\n\n");
	                }
	           }
	           else
	           {
	                printf("Los datos ya han sido sido cargados\n\n");
	           }

	        break;
	       case 3:
	           if(flagIngreso || flagIngresoB)
	           {
	               controller_addEmployee(lista);
	           }
	           else
	           {
	               printf("Primero debe cargar los datos del archivo\n\n");
	           }

	        break;
	       case 4:
	           if(flagIngreso || flagIngresoB)
	           {
	               controller_editEmployee(lista);
	           }
	           else
	           {
	               printf("Primero debe cargar los datos del archivo\n\n");
	           }

	        break;
	       case 5:
	           if(flagIngreso || flagIngresoB)
	           {
	               controller_removeEmployee(lista);
	           }
	           else
	           {
	               printf("Primero debe cargar los datos del archivo\n\n");
	           }

	        break;
	       case 6:
	           if(flagIngreso || flagIngresoB)
	           {
	               controller_ListEmployee(lista);
	           }
	           else
	           {
	               printf("Primero debe cargar los datos del archivo\n\n");
	           }
	            printf("\n");
	        break;
	       case 7:
	           if(flagIngreso || flagIngresoB)
	           {
	               controller_sortEmployee(lista);
	           }
	           else
	           {
	               printf("Primero debe cargar los datos del archivo\n\n");
	           }

	        break;
	       case 8:
	           if(flagIngreso || flagIngresoB)
	           {
	               if(controller_saveAsText("data.csv",lista)==1)
	               {
	                   printf("Se guardaron los datos con exito\n\n");
	               }
	               else
	               {
	                   printf("No se pudieron guardar los datos\n\n");
	               }
	           }
	           else
	           {
	               printf("Antes de guardar primero debe cargar los datos\n\n");
	           }

	        break;
	       case 9:
	           if(flagIngreso || flagIngresoB)
	           {
	               if(controller_saveAsBinary("data.bin",lista)==1)
	               {
	                   printf("Se guardaron los datos con exito\n\n");
	               }
	               else
	               {
	                   printf("No se pudieron guardar los datos\n\n");
	               }
	           }
	           else
	           {
	               printf("Antes de guardar primero debe cargar los datos\n\n");
	           }

	        break;
	       case 10:
	            confirma = tolower(getChar("\nconfirma salida? S / N\n"));
	            if(confirma=='s')
	            {
	                seguir='n';
	            }
	        break;
	       default:
	        printf("Ingrese una opcion valida\n");
	        }
	        system("pause");
	    }while(seguir=='s');

	    ll_deleteLinkedList(lista);

	    return EXIT_SUCCESS;
	}

