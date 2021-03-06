#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* Employee_new();


//Employee* Employee_LoadWParameters(char* id,char* nombre,char* horasTrabajadas,char* sueldo);

void employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

//int employee_CompareByName(Employee*, Employee*);






//los void tengo que castearlos para tratarlos compo empleados dentro de la funcion

//-------------FUNCIONES PARA PEDIR Y REEMPLAZAR DATOS---------------
/***
 * @brief Pide un nombre al usuario y lo carga en el empleado pasado por parametro
 *
 * @param emp unEmpleado
 * @return 1 si pudo cargar el nombre, 0 si no fue posible.
 */
int employee_loadName(Employee* emp);

/***
 * @brief Pide una cantidad de horas trabajadas al usuario y lo carga en el empleado pasado por parametro
 *
 * @param emp unEmpleado
 * @return 1 si pudo cargar el nombre, 0 si no fue posible.
 */
int employee_loadHoursW(Employee* pEmp);


/***
 * @brief Pide un sueldo al usuario y lo carga en el empleado pasado por parametro
 *
 * @param emp unEmpleado
 * @return 1 si pudo cargar el nombre, 0 si no fue posible.
 */
int employee_loadSalary(Employee* pEmp);


// ||||||||||| FUNCIONES DE COMPARACION DE CAMPOS |||||||||||||| FUNCIONES DE COMPARACION DE CAMPOS |||||||||||||||||||||||||

/** \brief compara el valor del campo nombre entre dos empleados
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * \return retorna 1 si el nombre del primero es mayor o -1 si el nombre del segundo es mayor o 0 si son iguales
 *
 */
int employee_CompareByName(void* e1, void* e2);

/**
 * @brief Compara el ID de dos empleados y devuelve un entero segun la comparacion
 *
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * @return devuelve 1 si id Emp1 es mayor al id Emp2/
 *                  0 si id Emp1 es menor al id Emp2/
 *                  2 si id Emp1 es igual al id Emp2/
 */
int employee_CompareById(void* e1, void* e2);

/**
 * @brief Compara la cantidad de horas trabajadas entre dos ID empleados y devuelve un entero segun la comparacion
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * @return devuelve 1 si horas trabajadas Emp1 es mayor al de  horas trabajadas Emp2/
 *                  0 si horas trabajadas Emp1 es menor al de  horas trabajadas Emp2/
 *                  2 si horas trabajadas Emp1 es igual al de horas trabajadas Emp2/
 */

int employee_CompareByHoursW2(void* e1, void* e2);


int employee_CompareByHoursW(void* e1, void* e2);


/**
 * @brief Compara el sueldo entre dos ID empleados y devuelve un entero segun la comparacion
 * @param e1 corresponde al  empleado1
 * @param e2 corresponde al  empleado2
 * @return devuelve 1 si sueldo Emp1 es mayor al Emp2/
 *                  0 si sueldo Emp1 es menor al Emp2/
 *                  2 si sueldo Emp1 es igual al Emp2/
 */
int employee_CompareBySalary(void* e1, void* e2);






//------------------------------------FUNCIONES PARA MOSTRAR EN PANTALLA------------------------------------
/**
 * @brief Muestra el empleado que se encuentra en el indice Index
 *
 * @param lista, lista de empleados
 * @param index, indice donde se entra el empleado a mostrar
 */
void Employee_PrintOneIndex( LinkedList* lista, int index);

/**
 * @brief Muestra un empleado por pantalla
 *
 * @param pEmp puntero a un empleado
 */
void Employee_PrintOne(Employee* pEmp);


/**
 * @brief Muestra un empleado con sus campos
 *
 * @param pEmp un empleado.
 */
void Employee_PrintOne_Fields(Employee* pEmp);

/* Brief: Reserva espacio en memoria para un empleado-
 *
 * return: la direccion de memoria para ubicar a un empleado-
 * */
Employee* Employee_new();


/* Brief: Carga/ settea los datos pasados por parametros
 *param int id : id de empleado del empleado pEmp
 *param char* nombre: nombre del empleado pEmp
 *param int horasTrabajadas: horas trabajadas por el empleado pEmp
 *param float sueldo : sueldo del empleado pEmp
 * return: 1 si se pudo pasar los datos correctamente , 0 en caso contrario.
 * */
int employee_setAll_Setters(Employee* pEmp,int id,char* nombre,int horasTrabajadas,float sueldo);


/* Brief: obtiene los datos pasados por parametros
 *param int* id : id de empleado del empleado pEmp
 *param char* nombre: nombre del empleado pEmp
 *param int* horasTrabajadas: horas trabajadas por el empleado pEmp
 *param float* sueldo : sueldo del empleado pEmp
 * return: 1 si se pudo pasar los datos correctamente , 0 en caso contrario.
 * */
int employee_getAll_Getters(Employee* pEmp,int id,char* nombre,int horasTrabajadas,float sueldo);


/***
 * @brief Carga los datos parseados pasados por parametro y los carga a un empleado
 *
 * @param id (char*)
 * @param nombre (char*)
 * @param horasTrabajadas(char*)
 * @param sueldo(char*)
 * @return retorna el puntero a empleado con los datos cargados si pudo realizarlo o NULL en caso contrario
 */
Employee* Employee_LoadWParameters(char* id,char* nombre,char* horasTrabajadas,char* sueldo);


/*----------------------------*/
/***
 * @brief Devuelve el ultimo id de la lista
 *
 * @param pArrayEmployee (Linkedlist*)
 * @return El id maximo de la lista si pudo encontrarlo, 0 en caso contrario
 */
int employee_MaxId(LinkedList* pArrayEmployee);

/***
 * @brief Imprime la lista completa de empleados
 *
 * @param pArrayEmployee ( linkedlist*)
 * @return retorna 1 si pudo mostrarlos correctamente , 0 en caso de error
 */
int Employee_PrintAll(LinkedList* pArrayEmployee);

/***
 * @brief pide y carga los datos a un empleado auxiliar y lo devuelve
 * @param  pEmp(Employee*)
 * @param pArrayEmployee ( linkedlist*)
 *
 * @return retorna 1 si pudo dar de alta correctamente , 0 en caso de error
 */
Employee* loadDataEmployee(Employee* pEmp,LinkedList* pArrayEmployee);


/***
 * @brief Agrega , da de alta un empleado a la lista de empleados
 * @param  pEmp(Employee*)
 * @param pArrayEmployee ( linkedlist*)
 *
 * @return retorna 1 si pudo dar de alta correctamente , 0 en caso de error
 */

int employee_Alta(LinkedList* pArrayEmployee,Employee* pEmp);

/***
 * @brief Busca en la lista si existe un empleado con el ID idABuscar pasado por parametro
 *
 * @param pArrayEmployee lista de empleados
 * @param idABuscar , id empleado a buscar
 * @return 0 si no existe el id, , si existe devuelve el (indice) donde se encuentra el id-
 */
int employee_searchId(LinkedList* pArrayEmployee, int idABuscar);

/***
 * @brief Busca en la lista si existe un empleado con el ID idABuscar pasado por parametro
 *
 * @param pArrayEmployee lista de empleados
 * @param idABuscar , id empleado a buscar
 * @return 0 si no existe el id, 1 si existe el id.
 */
int employee_idExist(LinkedList* pArrayEmployee, int idABuscar);

/***
 * @brief Modifica  datos (nombre,horas trabajadas,sueldo) del empleado elegido por el usuario
 *
 * @param pArrayEmployee( Linkedlist*) Lista de empleados.
 * @return retorna 1 si pudo realizar la modificacion, 0 en caso contrario.
 */
int Employee_edit(LinkedList* pArrayEmployee);

/***
 * @brief Elimina a un empleado a la lista de empleados
 * @param  pEmp(Employee*)
 * @param pArrayEmployee ( linkedlist*)
 *
 * @return retorna 1 si pudo dar de eliminar correctamente , 0 en caso de error
 */
int Employee_delete(LinkedList* pArrayEmployee);


int Employee_Sort(LinkedList* pArrayEmployee);

















#endif // employee_H_INCLUDED
