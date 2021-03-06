/*
 * menues.h
 *
 *  Created on: 8 abr. 2021
 *      Author: Compu casa
 */

#ifndef MENUES_H_
#define MENUES_H_

/** \brief Muestra un mensaje pasado por parametro para indicar los "carteles" de la calculadora
 * \param mensaje[] es el mensaje indicador para mostrarle al usuario donde esta parado*/
void Cartel(char mensaje[]);


/** \brief Muestra un mensaje dependiendo de los flags pasados por parametro
 *
 * \param flag es el flag de X operando; 1- si existe operando, 0 en caso contrario.
 * \param mensaje[] : Contiene el mensaje a ser mostrado en caso de flag sea igual a 1.
 * \param numero es el operando a ser mostrado.
 * \param mensajeAlternativo[] : Contiene el mensaje a ser mostrado en caso de flag sea igual a 0.
 * \return un mensaje a ser mostrado */
void mostrarIngresoOperando(int flag,char mensaje[],int numero,char mensajeAlternativo[]);


/** \brief Muestra un menu por pantalla dependiendo de los flags pasados por parametro
 *
 * \param flag1: Vale 1 si existe el operando "numero1", 0 en caso contrario.
 * \param flag2: Vale 1 si existe el operando "numero2", 0 en caso contrario.
 * \param numero1: Es el primer Operando.
 * \param numero2: Es el segundo Operando.
 * \return muestra un menu de opciones */
void OpcionesMenuConParametros(int flag1,int flag2,int numero1, int numero2);


/** \brief Muestra un menu de opciones por pantalla dependiendo de los flags pasados por parametro y retona la opcion elegida
 * \param flag1: Vale 1 si existe el operando "numero1", 0 en caso contrario.
 * \param flag2: Vale 1 si existe el operando "numero2", 0 en caso contrario.
 * \param numero1: Es el primer Operando.
 * \param numero2: Es el segundo Operando.
 * \return un numero/opcion elegido por el usuario */
int Menu(int flag1,int flag2,int numero1, int numero2);


#endif /* MENUES_H_ */
