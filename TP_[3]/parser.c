#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int cant;
	Employee* auxEmp;
	while(!feof(pFile))
	{
		auxEmp = employee_new();
		if(auxEmp != NULL)
		{
			cant = fread(auxEmp, sizeof(Employee), 1, pFile);
			if(cant == 1)
			{
				ll_add(pArrayListEmployee, auxEmp);
				todoOk = 1;
			}
			else
			{
				free(auxEmp);
			}
		}
		else
		{
			break;
		}
	}
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int cant;
	Employee* auxEmp;
	while(!feof(pFile))
	{
		auxEmp = employee_new();
		if(auxEmp != NULL)
		{
			cant = fread(auxEmp, sizeof(Employee), 1, pFile);
			if(cant == 1)
			{
				ll_add(pArrayListEmployee, auxEmp);
				auxEmp = NULL;
				todoOk = 1;
			}
			else
			{
				free(auxEmp);
			}
		}
		else
		{
			break;
		}
	}
    return todoOk;
}
