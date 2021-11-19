#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Inputs.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a pFile es NULL o el puntero a LinkedList es NULL
 *                      (1) = Todo Ok
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	Employee* empleado;
	char leerEncabezado[128];
	char bufferId[128];
	char bufferNombre[128];
	char bufferHorasTrabajadas[128];
	char bufferSueldo[128];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^\n]\n", leerEncabezado);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo) == 4)
			{
				empleado = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
				if(empleado != NULL)
				{
					ll_add(pArrayListEmployee, empleado);
					todoOk = 1;
				}
			}
			else
            {
                break;
			}
		}while(!feof(pFile));
	}
	return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param pFile FILE* Puntero al archivo
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a pFile es NULL o el puntero a LinkedList es NULL
 *                      (1) = Todo Ok
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[3][128];
    Employee auxEstatico;
    Employee* auxDinamico = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((Employee*)&auxEstatico, sizeof(Employee), 1, pFile) == 1)
            {
                sprintf(buffer[0], "%d", auxEstatico.id);
                sprintf(buffer[1], "%d", auxEstatico.horasTrabajadas);
                sprintf(buffer[2], "%d", auxEstatico.sueldo);
                auxDinamico = employee_newParametros(buffer[0], auxEstatico.nombre, buffer[1], buffer[2]);
                if(auxDinamico != NULL && ll_add(pArrayListEmployee, (Employee*)auxDinamico) == 0)
                {
                    todoOk = 1;
                }
            }
        }
    }

    return todoOk;
}

/** \brief Parsea los datos de los empleados al archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a pFile es NULL o el puntero a LinkedList es NULL
 *                      (1) = Todo Ok
 *
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	Employee* aux;
	int tam;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		fprintf(pFile, "ID,Nombre,HorasTrabajadas,Sueldo\n");
		for (int i = 0 ; i < tam ; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			if (aux != NULL)
			{
				fprintf(pFile, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas ,aux->sueldo);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

/** \brief Parsea los datos de los empleados al archivo datos.bin (modo binario).
 *
 * \param pFile FILE* Puntero al archivo
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a pFile es NULL o el puntero a LinkedList es NULL
 *                      (1) = Todo Ok
 *
 */
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee* aux;
	int tam;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			if (aux != NULL)
			{
				fwrite(aux, sizeof(Employee), 1, pFile);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
