#ifndef SECTOREMPLOYEES_H_INCLUDED
#define SECTOREMPLOYEES_H_INCLUDED

typedef struct {
    int id;
    char name[51];
}eSector;

/** \brief Carga el nombre del sector que corresponde al id pasado por parametro*
 * \param descripcion[] char; es donde se guardara el nombre del sector
 * \param idSec int , corresponde al id del sector
 * \param listaSec[] Sector lista de sectores
 * \param len int , tamanio del array de sectores
 * \return retorna 1 si la operacion fue exitosa o -1 en caso de error * */
int sector_PrintName(char descripcion[], int idSec, eSector listaSec[], int lenSec);

/** \brief Muestra un menu de opciones y permite elegir un id sector de la lista pasada por parametro*
* \param listaSec[] Sector lista de sectores
* \param len sec, int tamanio del array
* \param mensaje,mensaje a ser mostrado para el usuario
* \param error mensaje, mensaje a ser mostrado en caso de error al usuario
* \param int minN; corresponde al minimo rango de ID empleado
* \param int maxN; corresponde al maximo rango de ID empleado
* \param int limite; corresponde al limite de intentos.
 * \return retorna el id sector si la operacion fue exitosa o -1 en caso de error * */
int loadASector(eSector listaSec[], int lenSec, char mensaje[],char mensajeError[],int minN,int maxN,int limite);

/** \brief Muestra un sector y sus campos
 * \param eSector un sector; struct*/

void sector_printOne(eSector oneSector);

/** \brief Carga el nombre del sector que corresponde al id pasado por parametro*
 * \param descripcion[] char; es donde se guardara el nombre del sector
 * \param idSec int , corresponde al id del sector
 * \param listaSec[] Sector lista de sectores
 * \param len int , tamanio del array de sectores
 * \return retorna 1 si la operacion fue exitosa o -1 en caso de error * */
int sector_printList(eSector listaSec[], int lenSec);







#endif // SECTOREMPLOYEES_H_INCLUDED
