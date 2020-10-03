#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



int menu(char mensaje[]);
/** \brief Ingreso de una opcion del menu
 *
 * \param char mensaje[] ingreso de mensaje
 * \return int opcion seleccionada
 *
 */




void confirmacion (int espacio);
/** \brief valida si la ejecucion fue exitosa o no
 *
 * \param int espacio
 *
 */

int intDeValidacion(char mensaje[], char error[], int minimo, int maximo);
/** \brief ingreso de un dato entero
 *
 * \param char mensaje[]
 * \param char error[]
 * \param int minimo
 * \param int maximo
 * \return int el dato ingresado por el usuario
 *
 */
 void getS(char mensaje[], char string[]);
 /** \brief ingreso de dato tipo cadena
  *
  * \param char mensaje[]
  * \param char string[]
  * \return void
  *
  */


#endif // FUNCIONES_H_INCLUDED
