

#ifndef CALCULOS_H_
#define CALCULOS_H_

/** \brief Suma dos valores
 *
 * \param num1 es el primer operando.
 * \param num2 es el segundo operando.
 * \return retorna el resultado de la suma entre num1 y num2.
 */
int sumar(int num1, int num2);

/** \brief Resta dos valores.
 *
 * \param num1 es el primer operando.
 * \param num2 es el segundo operando.
 * \return retorna el resultado de la resta entre num1 y num2.
 */
int restar(int num1, int num2);

/** \brief multiplica dos valores.
 *
 * \param num1 es el primer operando.
 * \param num2 es el segundo operando.
 * \return retorna el resultado de la multiplicacion entre num1 y num2.
 */
int multiplicar(int num1, int num2);

/** \brief divide dos valores.
 *
 * \param num1 es el primer operando.
 * \param num2 es el primer operando.
 * \return retorna el resultado de la división y 0 si num2 es 0. * */
float dividir(int num1, int num2);

/** \brief calcula el factorial de un operando(num1).
 *
 * \param num1 unico operando, debe ser un numero entero,
 * \return devuelve el resultado del factorial de num1, si se ingresa 0 devuelve 1. */
unsigned long long int factorial(int num1);


/** \brief retorna 1 si se realizan correctamente los calculos, 0 en caso contrario.
 * \param flagX es la bandera que marca al primer operando.
 * \param flagY es la bandera que marca al primer operando
 * \return retorna el flagCalculo en 1 si se realizaron correctamente los calculos o 0(CERO) si no se pudo ealizar por falta de algun operando
 *
 */
int calcularOperaciones(int flagX, int flagY);


/** \brief Muestra el resultado de la operacion suma o resta
 * \param int numeroUno es el primer Operando.
 * \param int numeroDos es el segundo Operando
 * \param int criterio si es 1 realiza la Suma, si no Resta.
 * \return muestra un mensaje con el resultado de la operacion suma o resta */
void mostrarSumaResta(int numeroUno, int numeroDos,int criterio);


/** \brief Muestra el resultado de la operacion Division
 * \param int numeroUno es el primer Operando.
 * \param int numeroDos es el segundo Operando
 * \return muestra un mensaje con el resultado de la operacion division.*/
void mostrarDivision(int numeroUno, int numeroDos);

/** \brief Muestra el resultado de la operacion Multiplicacion
 * \param int numeroUno es el primer Operando.
 * \param int numeroDos es el segundo Operando
 * \return muestra un mensaje con el resultado de la operacion multiplicacion.*/
void mostrarMultiplicacion(int numeroUno, int numeroDos);

/** \brief Muestra el resultado de la operacion factorial.
 * \param int numeroUno es el primer Operando.
 * \return muestra un mensaje con el resultado de la operacion factorial , si sus valores son validos, sino muesta un mensaje de error.*/
void mostrarFactorial(int numero);

/** \brief Muestra un mensaje con el resultado de todas las operaciones
 * \param int numeroUno es el primer Operando.
 * \param int numeroDos es el segundo Operando
 * \return muestra los resultados con todas las operaciones matematicas*/
void mostrarTodasLasOperaciones(int numeroUno, int numeroDos);




#endif /* CALCULOS_H_ */
