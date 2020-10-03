#ifndef EMPLOYEESARRAYS_H_INCLUDED
#define EMPLOYEESARRAYS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LEN 1000
#define VACIO 1
#define LLENO 0
#define REMOVIDO -1
#define ASC 1
#define DESC 2

#endif // EMPLOYEESARRAYS_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} unEmpleado;

int inItEmployees(unEmpleado list[], int len);
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param Empleado list[]
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int buscarEspacio (unEmpleado list[], int len);
/** \brief busca si hay espacio en el array
 *
 * \param Empleado list[]
 * \param int len
 * \return espacio -1 si no hay espacio y 1 si hay espacio
 *
 */

void mostrarEmpleado(unEmpleado list);
/** \brief muestra los datos del empleado ingresado
 *
 * \param Empleado list[]
 *
 */



int altaEmpleado(unEmpleado list[], int len, int espacio);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param Empleado list
 * \param len int
 * \param espacio int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

void confirmarAlta(unEmpleado list[]);
/** \brief agrega valores el array de alta
 *
 * \param Empleado list[]
 */


int mostrarEmpleados(unEmpleado list[], int len);
/** \brief muestra el array de los empleados
 *
 * \param Empleado list[]
 * \param int len largo del array
 * \return int
 *
 */


int generarID(unEmpleado list[], int len);

/** \brief va a generar un id para cada empleado ingresado
 *
 * \param Empleado list[]
 * \param int len
 * \return aux+1 se le suma 1 al proximo id de empleado
 *
 */

int validarId(unEmpleado list[], int len, int auxId);
    /** \brief  funcion para validar  el id ingresado por el usuario
     *
     * \param unEmpleado list[]
     * \param int len
     * \param int auxId
     * \return que se pudo o no validar
     *
     */







int bajaEmpleado(unEmpleado list[], int len );

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list[] Empleado
 * \param len int
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't
find a employee] - (1) if Ok
 *
 */
void confirmarBaja(unEmpleado list[]);
/** \brief agrega los datos al array de baja
 *
 * \param Empleado list []
 *
 */

int modificarEmpleado(unEmpleado list[], int len, int id, int opcion);
/** \brief  elige empleado por id
 *
 * \param Empleado list []
 * \param int len
 * \param int id
 * \param int opcion
 * \return int empleado modificado
 *
 */

void confirmarModificacion(unEmpleado list[]);
/** \brief el usuario puede modificar empleados en sus 4 parametros
 *
 * \param Empleado list []
 *
 */


void sueldoPromedioEmpleados(unEmpleado list[]);
/** \brief funcion que calcula promedio de los sueldos de los empleados
 *
 * \param Empleado list[]
 */


void preguntarOrdenEmpleados(unEmpleado list[]);
/** \brief funcion para saber si quiere y como quiere ordenar el array el usuario
 *
 * \param  Empleado list[]
 *
 */


int ordenEmpleados(unEmpleado list[], int len, int criterio);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list[] Empleado
 * \param len int
 * \param criterio int [2] indicate UP - [1] indicate DOWN
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */



int informarEmpleados(unEmpleado list[], int length);

/** \brief print the content of employees array
*
* \param list[] Empleado
* \param len int
* \return int
*
*/

int cantidadEmpleados(unEmpleado list[], int len);
/** \brief funcion para saber cantidad de empleados ingresados
 *
 * \param Empleado list []
 * \param int len
 * \return devuelve cantidad de empleados ingresados
 *
 */

float sumaSueldos (unEmpleado list[], int len);
/** \brief realiza la suma de los sueldos
 *
 * \param Empleado list[]
 * \param int len
 * \return float devuelve la suma de todos los sueldos
 *
 */



float promedioSueldos (unEmpleado list[]);
/** \brief resuelve la operacion de promedios
 *
 * \param Empleado list[]
 * \return float devuelve el promedio de  sueldos de los empleados
 *
 */


float masQueElPromedio(unEmpleado list[], int len, int promedio);
/** \brief funcion para mostrar cuantos empleados ganan mas que el promedio
 *
 * \param Empleado list[]
 * \param int len
 * \param int promedio
 * \return int devuelve cuantos empleados tienen mayor sueldo que el promedio
 *
 */

 void ordenSectorSueldos(unEmpleado list[]);
 /** \brief muestro array de empleados ordenado
  *
  * \param Empleado list[]
  *
  */


