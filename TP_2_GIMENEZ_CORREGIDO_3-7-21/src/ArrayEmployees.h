#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "ArrayEmployees.h"
#include "sectorEmployees.h"

typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


void dataEmployee(Employee lsEmployees[],int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee lista[], int len);

/** \brief muestra cada uno de los valores de los campos de un empleado
           y a que campo corresponde cada valor
 *
 * \param empleado Employee , corresponde a un empleado
 * \param sectores[] Sector, array de sectores
 * \param tamSec int, tamanio del array de sectores
 * \return void
 *
 */
void mostrarEmpleadoConCampos(Employee empleado, eSector sectores[], int tamSec);

/** \brief muestra cada uno de los valores de los campos de un empleado
 *
 * \param empleado Employee , corresponde a un empleado
 * \param sectores[] Sector, array de sectores
 * \param tamSec int, tamanio del array de sectores
 * \return void
 *
 */
void mostrarEmpleado(Employee empleado, eSector sectores[], int tamSec);

void mostrarEmpleadoSalarios(Employee lista[],int len,eSector lsSec[], int lenSec);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printEmployees(Employee lista[],int tam,eSector sectores[], int tamSec);

/** \brief busca una posicion libre en el array
 *
 * \param lista[] Employee lista de empleados
 * \param len int tamanio del array de empleados
 * \return int retorna -1 en caso de no encontrar un espacio libre o el indice del espacio libre
 *
 */
int searchFreeLocation(Employee lista[], int len);


/** \brief Carga y valida un ID empleado
* \param char mensaje[] mensaje a ser mostrado al usuario
* \param char mensajeError[] mensaje a ser mostrado al usuario en caso de error
* \param lista[] Employee lista de empleados
* \param len int tamanio del array de empleados
* \param minN int rango id empleado
* \param maxNrango idEmpleados
* \return int retorna -1 en caso de no poder cargar el id o el id cargado en caso correcto
 *
 */
int loadValidateId(char mensaje[],char mensajeError[],Employee lista[], int len,int minN,int maxN);


/** \brief Hardcodea los datos de empleados en el array pasado por parametro

* \param lista[] Employee lista de empleados

* \param len int tamanio del array de empleados

 *
 */
Employee loadDataEmployee(eSector lsSect[],int lenSec);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int addEmployee( Employee lista[],int len, int idAux, char nameAux[],char lastNameAux[],float salaryAux,int sectorAux);


/** \brief Agrega a un empleado al sistema
 *
 * \param lista[] Employee, array de empleados
 * \param idAutoincremental int, id no incluido por el usuario
 * \param len int tamanio del array empleados
  * \param lista[] Sector, array de sectores
 * \param tamsec int es el tamanio del array de sectores
 * \return //int devuelve 1 si fue un alta correcta o -1 en caso de que haya error
 *
 */
int employee_Alta(Employee lista[],int idAutoincremental,int len,eSector sectores[],int tamSec);


/* FUNCIONES PARA MODIFICAR EMPLEADO*/
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param lista Employee[]
 * \param len int
 * \param id int
* \param minN int ; Es el rango minimo
 * \param maxN int  Es el rango maximo
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee lista[], int len,int id,int minN,int maxN);


/** \brief , Es el menu para cambiar el nombre, apellido, salario,sector del empleado
 *
 * \param [] Employee lista
 * \param tam int tamanio array lista de empleados
 * \param sectores[] Sector, array lista de sectores
 * \param tamSec int, tamanio/cant sectores
 * \return void
 *
 */
int employee_Modify(Employee lista [],int tam,eSector sectores[],int tamSec,int maxN,int minN);


/* funciones PARA BAJA EMPLEADO*/
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
//int removeEmployee(Employee lista[], int len, int id);

/** \brief elimina de manera logica a un empleado pedido por el usuario
 *
 * \param lista[] Employee , array de empleados
 * \param idAutoincremental int, id autoincremental
 * \param len int , tamanio del array de empleados
 * \param sectores[] Sector, array de sectores
 * \param tamSec int, tamanio de array de sectores
 * \return int, devuelve -1 si no se pudo remover o 0 en caso contrario
 *
 */
int removeEmployee(Employee lista[], int len, int id,int minN,int maxN);

/** \brief remove in a existing list of employees the value received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param sectores[] array estructura
* \param tamSec int; tamanio array sectores
* \param minN int rango id empleado
* \param maxN rango idEmpleados
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int employee_Baja(Employee lista[],int len, eSector sectores[], int tamSec,int minN,int maxN);

/* funciones para INFORMAR EMPLEADOS*/
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee lista[],int len,int criterio);

/** \brief calcula el salario de todos los empleados activos
 *
 * \param lista[] Employee, lista de empleados
 * \param len int tamanio de empleados
 * \return float retorna la cantidad total de sueldos
 *
 */
float employee_TotalSalarios(Employee lista[],int len);

/** \brief calcula el salario promedio de todos los empleados activos
 *
 * \param lista[] Employee, lista de empleados
 * \param len int, tamanio de la lista empleados
 * \return int, retorna el promedio de salarios entre los empleados activos
 *
 */
float employee_SalarioPromedio(Employee lista[],int len);

/** \brief Cuenta la cantidad de empleados que el valor de su campo sueldo supera el promedio
 *
 * \param lista[] Employee,lista/array de empleados
 * \param len int, tamanio lista/array de empleados
 * \return int, la cantidad de empleados que superan el promedio
 *
 */
int employee_cantSuperaSalarioPromedio(Employee lista[],int len);

/** \brief Realiza el ordenamiento asc y dsc de los empleados y realiza promedios de sueldo
 *
 * \param lista[] Employee, lista de empleados
 * \param len int   , tamanio lista de empleados
 * \param sectores[] Sector lista de sectores
 * \param tamSec int, tamanio lista de sectores
 * \return void
 *
 */
void employee_Informes(Employee lista[],int len,eSector sectores[], int tamSec);
#endif // ARRAYEMPLOYEES_H_INCLUDED
