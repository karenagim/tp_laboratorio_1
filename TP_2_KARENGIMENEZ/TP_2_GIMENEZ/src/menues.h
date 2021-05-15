#ifndef MENUES_H_
#define MENUES_H_

/** \brief muestra un mensaje/header del programa
 *
 * \return void muestra un msj en pantalla
 *
 */
void Cartel(char mensaje[]);

/** \brief muestra un mensaje/header del programa
 *
 * \return void muestra un msj en pantalla
 *
 */
void cartelInicioGestion();

 /** \brief muestra las opciones del menu
  *
  * \return int retorna la opcion(numero) elegido
  *
  */
int opcionMenuInicio();

/** \brief muestra un panel mensaje con los campos descriptivos de la estructura empleados
 param: mensaje es el titulo a mostrar
 **/
void PanelEmpleados(char mensaje[]);

/** \brief Muestra el menu de opciones DEL ABM EMPLEADOS"
 *
 * \return int retorna la opcion elegida por el usuario*/
int menuABMEmpleados();

/** \brief Muestra un mensaje "alta empleados"
 *
 * \return retorna un mensaje
 *
 */
void menuAlta();

/** \brief Muestra un mensaje "BAJA empleados"
 *
 * \return retorna un mensaje
 */
void menuBaja();



/** \brief Muestra el menu de opciones de "INFORMAR EMPLEADOS"
 *
 * \return int retorna la opcion elegida por el usuario
 *
 */
int Menu_Modificar();

/** \brief Muestra el menu de opciones de "INFORMAR EMPLEADOS"
 *
 * \return int, la opcion elegida por el usuario
 *
 */
int Menu_Informes();



#endif /* MENUES_H_ */
