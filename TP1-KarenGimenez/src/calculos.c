#include <stdio.h>
#include <stdlib.h>
#include "menues.h"

#include "calculos.h"

 int sumar(int num1, int num2)
 {
     return  num1+ num2;
 }

 int restar(int num1, int num2)
 {
     return num1- num2;
 }
 int multiplicar(int num1, int num2)
 {
     return num1* num2;
 }

  float dividir(int num1, int num2)
 {
    float resultado;
   resultado= (float) num1/num2;
    return resultado;
 }


  unsigned long long int factorial(int numero)
{
	unsigned long long int fact;

        if(numero >= 0 )
        {
            if (numero == 1 || numero==0)
            {
                fact=1;
            }
            else
            {
                fact= numero*factorial(numero-1);
            }
        }
        return fact;
}


int calcularOperaciones(int flagX, int flagY)
{
    int flagCalculo =0;
        if( flagX ==1 && flagY==1)
        {
        	system("cls");
            flagCalculo=1;
        }
    return flagCalculo;
}


void mostrarSumaResta(int numeroUno, int numeroDos,int criterio)
{
    if(criterio ==1){
         printf("\n| El resultado de  A+B es | %5d|",sumar(numeroUno,numeroDos));
    }else{
    printf("\n| El resultado de  A-B es | %5d|",restar(numeroUno,numeroDos));
    }
}

void mostrarDivision(int numeroUno, int numeroDos)
{
    if(numeroDos==0)
    {
        printf("\n| No es posible dividir por cero	|\n");
    }
    else
    {
        printf("\n| El resultado de  A/B es | %5.2f|",dividir(numeroUno,numeroDos));
    }
}

void mostrarMultiplicacion(int numeroUno, int numeroDos)
{
    printf("\n| El resultado de  A*B es | %5d|", multiplicar(numeroUno, numeroDos));
}

void mostrarFactorial(int numero)
{
    if(numero<0)
    {
       printf("\n|>> No es posible realizar el factorial de %d es un numeros negativo <<|\n",numero);
    }else if (numero>20)
        {
            printf("\n|>>Error. No es posible realizar el factorial de %d, ingrese un numero menor a 20<<|",numero);
        }
        else{

           printf("\n| El factorial de  %d ! es | %5llu|",numero, factorial(numero) );

        }
}
void mostrarTodasLasOperaciones(int numeroUno, int numeroDos)
{
   Cartel("RESULTADOS DE LAS OPERACIONES");
   printf(" ====================================\n");
   printf("\n| Operando A = %d | Operando B = %d |",numeroUno,numeroDos);
   printf("\n --------------------------------");
   mostrarSumaResta(numeroUno,numeroDos,1);
   printf("\n --------------------------------");
   mostrarSumaResta(numeroUno,numeroDos,0);
   printf("\n --------------------------------");
   mostrarDivision(numeroUno,numeroDos);
   printf("\n --------------------------------");
   mostrarMultiplicacion(numeroUno,numeroDos);
   printf("\n --------------------------------");
   mostrarFactorial(numeroUno);
   printf("\n --------------------------------");
   mostrarFactorial(numeroDos);
   printf("\n --------------------------------\n");
}
