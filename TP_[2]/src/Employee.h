/*
 * Employee.h
 *
 *  Created on: 26 nov. 2021
 *      Author: Alvarez Gonzalo
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif /* EMPLOYEE_H_ */

/** \brief Para indicar que todas las posiciones del array están vacías,
 *         esta función pone la bandera (isEmpty) en TRUE
 *         en todas las posiciones del array.
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo - (0) si esta todo ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Busca en un array la primer posicion libre
 *
 * \param list Employee*
 * \param len int
 * \return int Retorna (-1) si no encuentra ninguna posicion libre, o el indice de la primer posicion libre
 *
 */
int findEmpty(Employee* list, int len);

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro
 *         en la primer posición libre.
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param charlastName[]
 * \param salary float
 * \param sector int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo - (0) si esta todo ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Retorna la posicion del indice o (-1) si la longitud no es valida o el puntero es nulo o no encuentra empleado
 *
 */
int findEmployeeById(Employee* list, int len, int id);

/** \brief Permite modificar el array de empleados recibiendo como parametro el id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo o no encuentra empleado - (0) si esta todo ok
 *
 */
int modifyEmployee(Employee* list, int len, int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo o no encuentra empleado - (0) si esta todo ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] Ascendente - [0] Descendente
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo - (0) si esta todo ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Imprime el array de empleados de forma encolumnada.
 *
 * \param list Employee*
 * \param len int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo - (0) si esta todo ok
 *
 */
int printEmployees(Employee* list, int len);

/** \brief Calcula el promedio y el total de los salarios de un array. Muestra que empleados del array supera el promedio
 *
 * \param list Employee*
 * \param len int
 * \return int Retorna (-1) si la longitud no es valida o el puntero es nulo - (0) si esta todo ok
 *
 */
int promedioYTotalSalarios(Employee* list, int len);

