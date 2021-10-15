#ifndef EXTRA_H_
#define EXTRA_H_



#endif /* EXTRA_H_ */

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \return retorna el número aleatorio generado
 *
 */
char getIdAleatorio(int desde , int hasta);

/** \brief Busca en un array la primer posicion libre
 *
 * \param list Employee*
 * \param len int
 * \return int Retorna (-1) si no encuentra ninguna posicion libre, o el indice de la primer posicion libre
 *
 */
int findEmpty(Employee* list, int len);

/** \brief Permite modificar el array de empleados recibiendo como parametro el id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo o no encuentra empleado - (0) si esta todo ok
 *
 */
int modifyEmployee(Employee* list, int len, int id);

/** \brief Calcula el promedio y el total de los salarios de un array. Muestra que empleados del array supera el promedio
 *
 * \param list Employee*
 * \param len int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo - (0) si esta todo ok
 *
 */
int promedioYTotalSalarios(Employee* list, int len);

/** \brief Valida que los id no se repitan
 *
 * \param id int
 * \return int Retorna el valor del id ingresado, o un nuevo valor en caso de que sea repetido
 *
 */
int validarId(Employee* list, int len, int id);
