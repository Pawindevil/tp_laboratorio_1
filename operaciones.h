#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED



#endif // OPERACIONES_H_INCLUDED

float opSuma (float a, float b);
/** \brief Realiza la operacion suma
 *
 * \param float a  operador a ingresado
 * \param float b  operador b ingresado
 * \return devuelve float resultado de la suma
 *
 */
float opResta(float a, float b);
/** \brief Realiza la operacion resta
 *
 * \param float a operador a ingresado
 * \param float b operador a ingresado
 * \return devuelve float resultado de la resta
 *
 */
 float opMulti (float a, float b);
 /** \brief Realiza la operacion multiplicacion
  *
  * \param float a operador a ingresado
  * \param float b operador b ingresado
  * \return devuelve float resultado de la multiplicacion
  *
  */
 float opDiv (float a, float b);
 /** \brief Si el operador b no es 0, realiza la operacion division
  *
  * \param float a operador a ingresado
  * \param float b operador b ingresado
  * \return devuelve float resultado de la division validado.
  *
  */
 long long int factorizacion (float a);
  /** \brief valida si el dato ingresado es posible hacer factorial, si lo es, realizará la operación.
  *          Si no se puede devolverá -1 si es negativo.
  *
  * \param float a operador (a o b) ingresado
  *
  * \return long long int resultado operacion factorizacion
  */

  void mostrarResultados(float suma, float resta, float producto, float division, int flag, long long int factoreoA, long long int factoreoB);
  /** \brief Muestra en consola los resultados de las operaciones si se realizaron.
   *
   * \param float suma, muestra resultado de la suma
   * \param float resta, muestra resultado de la resta
   * \param float producto, muestra producto de la multiplicacion
   * \param float division, muestra resultado de division si se pudo realizar
   * \param int flag valida si se realizaron los calculos
   * \param long long int factoreoA muestra el factorial del primer numero
   * \param long long int factoreoB muestra el resultado del segundo numero

   *
   */


   int menu(char mensaje[]);
   /** \brief Ingreso de opcion al menu
    *

    * \param char [] muestra mensaje de ingreso

    * \return float muestra la opcion elegida
    *
    */

    float getFloat (char mensaje[]);
    /** \brief Ingreso de un numero flotante
     *
     * \param char[] muestra mensaje de ingreso

     * \return float muestra el numero ingresado
     *
     */



