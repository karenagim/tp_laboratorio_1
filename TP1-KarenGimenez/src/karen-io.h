
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


#endif /* KAREN_IO_H_ */
