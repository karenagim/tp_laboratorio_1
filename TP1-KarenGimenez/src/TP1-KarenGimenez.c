/*
 ============================================================================
ALUMNA: GIMENEZ,KAREN ANTONELLA 1F
TP_1: CALCULADORA UTN

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menues.h"
#include "karen-io.h"
#include "calculos.h"

int main(void) {

	setbuf(stdout,NULL);

	int primerOperando=0;
	int segundoOperando=0;

	int flagX= 0;
	int flagY= 0;
	int flagCalculo=0;

	char salir ='n';

	do{
		switch(Menu(flagX, flagY, primerOperando, segundoOperando))
		{

			case 1 :
				Cartel("PRIMER OPERANDO");
				primerOperando= PedirNumeroEntero("Ingrese el primer Operando\n");

				flagX=1;
				break;

			case 2 :
				if(flagX ==1)
				{
					Cartel("SEGUNDO OPERANDO");
					segundoOperando= PedirNumeroEntero("Ingrese el segundo Operando\n");
					flagY=1;
				}else{
					printf("\n\n Primero debes cargar el primer operando\n\n");
				}
				break;
			case 3 :
				if(calcularOperaciones(flagX, flagY)== 1)
				{
					printf("\n\n Las operaciones fueron calculadas correctamente \n\n");
					system("pause");
					flagCalculo=1;
				}else{
					printf("\n\n Calcular las operaciones primero debes cargar los operandos\n\n");
				}
				break;

			case 4 :

				if(flagCalculo ==1)
				{
					mostrarTodasLasOperaciones(primerOperando, segundoOperando);
					system("pause");

				}else{
						printf(" \n\nPara mostrar las operaciones antes debemos calcularlas \n\n");
					}
				break;

			case 5 :
				Cartel("CALCULADORA UTN-----------\n----------SALIR---------");

				salir=getChar("Desea salir? s/n");
				system("pause");
				break;

			default:

				printf("\nIngrese una opcion del 1 al 5\n");
				break;
			}
	}while( salir != 's');



	return EXIT_SUCCESS;
}



