
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "karen-io.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int PedirNumeroEntero(char mensaje[])
{
    int numeroEntero;

    printf("%s",mensaje);
    scanf("%d", &numeroEntero);

    return numeroEntero;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


int PedirNumeroEnteroConMensaje(char mensaje[],char mensajeError[],int minimo,int maximo)
{

     int numeroIngresado;

    printf("%s",mensaje);
    scanf("%d", &numeroIngresado);
    while(numeroIngresado<minimo|| numeroIngresado>maximo)
    {
        printf("%s", mensaje);
        scanf("%d",&numeroIngresado);

    }
    return numeroIngresado;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena, int limite){
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++){
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = 0;
			break;
		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt2(int* pResultado){
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getStringLong(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString))){
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getInt2(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}


static int getFloatInput(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getStringLong(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}



int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,	float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloatInput(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


int PedirNumeroEnteroConMensajeConLimite(char mensaje[],char mensajeError[],int minimo,int maximo,int limite)
{
	int numeroIngresado;
	numeroIngresado = getInt(mensaje);

	while(limite ==0)
	{
		numeroIngresado=getValidInt(mensaje, mensajeError, minimo, maximo);
		limite--;
	}


    return numeroIngresado;
}




float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit)
{

    float auxFloat= getFloat(requestMessage);
    while( auxFloat<=lowLimit)
    {
            printf ("%s\n",errorMessage);
            auxFloat= getFloat(requestMessage);
    }
        return auxFloat;
}






/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}




/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es * */
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


int getStringLong(char* cadena, int longitud){
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene letras y numeros
 */
int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    int retorno;

    retorno = 0;
    getString(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        retorno= 1;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \param cantMaxCaracter indica la cantidad de caracteres maximo del array
 * \return 1 si el texto contiene solo letras
 */
int getStringLetrasLimitadas(char mensaje[],char input[],int cantMaxCaracter)
{
    char aux[cantMaxCaracter];
    getString(mensaje,aux);
    if(esSoloLetras(aux)&& strlen(aux)<cantMaxCaracter-1)
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

int getValidIntLimite(char msj[],char error[],int min, int max, int limit)
{
	int num;
	int acum=0;
	printf("%s",msj);
	while(acum!=2)
	{
		acum=0;
		if (scanf("%d",&num)!=1)
		{
			fflush(stdin);
			printf("%s",error);
		}
		else
		{
			acum++;
			if(limit==1)
			{
				if(num<min || num >max)
				{
					fflush(stdin);
					printf("%s",error);
				}
				else
				{
					acum++;
				}
			}
			else
			{
				acum++;
			}
		}
	fflush(stdin);
	}
	fflush(stdin);
	return num;
}



/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{
    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}



/**
 * \brief Solicita un string unicamente con letras para nombre/apellido
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \param maxCaracter es la cantidad maxima de letras del string
 * \return -
 *
 */
void getValidStringLimitada(char requestMessage[],char errorMessage[], char input[],int maxCaracter)
{

    while(1)
    {
        if (!getStringLetrasLimitadas(requestMessage,input,maxCaracter) )
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}
