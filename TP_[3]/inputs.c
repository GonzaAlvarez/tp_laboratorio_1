#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "LinkedList.h"

/** \brief Crea un menu y lo muestra en pantalla
 *
 * \return int Retorna el valor de la opcion seleccionada
 *
 */
int menu()
{
	int opcion;

	system("cls");
	printf("                                  MENU PRINCIPAL\n");
	printf("---------------------------------------------------------------------------------\n");
	printf(" 1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf(" 2.Cargar los datos de los empleados desde el archivo datos.bin (modo binario)\n");
	printf(" 3.Alta de empleado\n");
	printf(" 4.Modificar datos de empleado\n");
	printf(" 5.Baja de empleado\n");
	printf(" 6.Listar empleados\n");
	printf(" 7.Ordenar empleados\n");
	printf(" 8.Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf(" 9.Guardar los datos de los empleados en el archivo datos.bin (modo binario)\n");
	printf(" 10.Salir\n\n");

	printf("Seleccione opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/** \brief Verifica el largo de un string recibiendo como parametro un tamaño
 *
 * \param string[] char String a validar
 * \param tam int Tamaño del string
 * \return int Retorna: (0) = Si no supera el tamaño ingresado
 *                      (1) = Si supera el tamaño ingresado
 *
 */
int validarLargoString(char string[], int tam)
{
    int todoOk = 0;
    if(strlen(string) > tam)
    {
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Verifica que un string este compuesto unicamente de letras
 *
 * \param string[] char String a validar
 * \return int Retorna: (0) = Si esta compuesto de letras
 *                      (1) = Si no esta compuesto de letras
 *
 */
int validarString(char string[])
{
    int todoOk = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        todoOk = 1;
        i++;
    }
    if((strlen(string) == 0))
    {
    	todoOk = 1;
    }
    return todoOk;
}

/** \brief Verifica que el sueldo ingresado sea correcto
 *
 * \param sueldo int Sueldo a validar
 * \return int Retorna: (0) = Si es mayor a 0
 *                      (1) = Si es menor a 0
 *
 */
int validarSueldo(int sueldo)
{
	int todoOk = 0;
	if(sueldo < 0)
	{
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Verifica que el criterio ingresado sea correcto
 *
 * \param criterio int Criterio a validar
 * \return int Retorna: (0) = Si es distinto a 0 o 1
 *                      (1) = Si es igual a 0 o 1
 *
 */
int validarCriterio(int criterio)
{
    int todoOk = 0;
	if(criterio == 0 || criterio == 1)
	{
		todoOk = 1;
	}
	return todoOk;
}
