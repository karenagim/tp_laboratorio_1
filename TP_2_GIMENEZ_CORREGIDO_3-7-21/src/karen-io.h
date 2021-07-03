
#ifndef KAREN_IO_H_
#define KAREN_IO_H_

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 */
char getChar(char mensaje[]);

/**
 * \brief Solicita un numero entero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 */
int PedirNumeroEntero(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param int minimo es el numero minimo que puede elegir el usuario
 * \param int maximo es el numero maximo que puede elegir el usuario
 * \return El numero ingresado por el usuario
 */
int PedirNumeroEnteroConMensaje(char mensaje[],char mensajeError[],int minimo,int maximo);

//static int esNumerica(char* cadena, int limite);

int PedirNumeroEnteroConMensajeConLimite(char mensaje[],char mensajeError[],int minimo,int maximo,int limite);


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos);
int getValidIntLimite(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int limite);




/*
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}*/


int esFlotante(char* cadena);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario * */
float getFloat(char mensaje[]);


float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario * */
int getInt(char mensaje[]);



/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
//static int getInt2(int* pResultado);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario * */
char getChar(char mensaje[]);


/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado * */
char getNumeroAleatorio(int desde , int hasta, int iniciar);


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es * */
int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es * */
int esNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es * */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

int getStringLong(char* cadena, int longitud);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene letras y numeros
 */
int getStringAlfaNumerico(char mensaje[],char input[]);



/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \param cantMaxCaracter indica la cantidad de caracteres maximo del array
 * \return 1 si el texto contiene solo letras
 */
int getStringLetrasLimitadas(char mensaje[],char input[],int cantMaxCaracter);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return - */
void getValidString(char requestMessage[],char errorMessage[], char input[]);



/**
 * \brief Solicita un string unicamente con letras para nombre/apellido
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \param maxCaracter es la cantidad maxima de letras del string
 * \return - * */
void getValidStringLimitada(char requestMessage[],char errorMessage[], char input[],int maxCaracter);







#endif /* KAREN_IO_H_ */
