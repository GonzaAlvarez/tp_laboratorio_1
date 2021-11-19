#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Controller.h"
#include "Inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta de la ubicacion del archivo de texto
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si la ruta es invalida, si el puntero a LinkedList es NULL o si no pudo abrir el archivo
 *                      (1) = Si pudo leer el archivo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			todoOk = parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char* Ruta de la ubicacion del archivo binario
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si la ruta es invalida, si el puntero a LinkedList es NULL o si no pudo abrir el archivo
 *                      (1) = Si pudo leer el archivo
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            todoOk = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList es NULL o si no pudo agregar un empleado
 *                      (1) = TodoOk y pudo agregar un empleado
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    if(pArrayListEmployee != NULL)
    {
        todoOk = add_employee(pArrayListEmployee);
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList es NULL o si no pudo modificar los datos de un empleado
 *                      (1) = TodoOk y  pudo modificar los datos de un empleado
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    if(pArrayListEmployee != NULL)
    {
        todoOk = adit_employee(pArrayListEmployee);
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList es NULL o si no pudo dar de baja un empleado
 *                      (1) = TodoOk y pudo dar de baja un empleado
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    if(pArrayListEmployee != NULL)
    {
        todoOk = remove_employee(pArrayListEmployee);
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList es NULL
 *                      (1) = TodoOk
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    if(pArrayListEmployee != NULL)
    {
        mostrarEmpleados(pArrayListEmployee);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (-1) = Si el puntero a LinkedList es NULL
 *                      (0) = TodoOk
 *                      (1) = Si se realizo algun ordenamiento
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    char seguir = 's';
	int criterio;
	int opcion;

	if(pArrayListEmployee != NULL)
	{
	    todoOk = 0;
		do
        {
            system("cls");
			printf("        MENU ORDENAMIENTO\n");
			printf("---------------------------------\n");
			printf(" 1.Ordenar por ID\n");
			printf(" 2.Ordenar por horas trabajadas\n");
			printf(" 3.Ordenar por sueldo\n");
			printf(" 4.Salir\n\n");

            printf("\nIngrese criterio con el que desea ordenar (1 = Ascendente / 0 = Descendente): ");
            scanf("%d", &criterio);
            while(!validarCriterio(criterio))
            {
                printf("Error, reingrese criterio con el que desea ordenar (1 = Ascendente / 0 = Descendente): ");
                scanf("%d", &criterio);
            }

            printf("Seleccione opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                ll_sort(pArrayListEmployee, employee_OrdenarPorId , criterio);
                todoOk = 1;
                seguir = 'n';
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_OrdenarPorHorasTrabajadas, criterio);
                todoOk = 1;
                seguir = 'n';
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_OrdenarPorSueldo, criterio);
                todoOk = 1;
                seguir = 'n';
                break;
            case 4:
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida\n");
            }
            system("pause");
		}while(seguir == 's');
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Ruta de la ubicacion del archivo de texto
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si la ruta es invalida, si el puntero a LinkedList es NULL o si no pudo escribir el archivo
 *                      (1) = Si pudo escribir el archivo
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	FILE* pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			todoOk = parser_EmployeeToText(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Ruta de la ubicacion del archivo binario
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si la ruta es invalida, si el puntero a LinkedList es NULL o si no pudo escribir el archivo
 *                      (1) = Si pudo escribir el archivo
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile != NULL)
		{
			todoOk = parser_EmployeeToBinary(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return todoOk;
}


