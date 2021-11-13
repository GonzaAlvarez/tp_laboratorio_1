#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	//char fantasma[200];
	FILE* f = fopen(path, "r");
	if(f == NULL && pArrayListEmployee == NULL)
	{
		system("cls");
		printf("No se pudo abrir el archivo\n");
	}
	else
	{
		//fscanf(f, "%s", fantasma); //Lectura fantasma del encabezado
		parser_EmployeeFromText(f, pArrayListEmployee);
		fclose(f);
		todoOk = 1;
	}
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* f = fopen(path, "rb");
	if(f == NULL && pArrayListEmployee == NULL)
	{
		system("cls");
		printf("No se pudo abrir el archivo\n");
	}
	else
	{
		parser_EmployeeFromBinary(f, pArrayListEmployee);
		fclose(f);
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
	int todoOk = 0;
	if(pArrayListEmployee != NULL && pId != NULL)
	{
		system("cls");
		printf("  MENU ALTA EMPLEADO\n");
		printf("-------------------------\n");

		Employee* nuevoEmpleado;
		nuevoEmpleado = NULL;
		nuevoEmpleado = employee_new();

		nuevoEmpleado->id = *pId;
		(*pId)++;

		printf("Ingrese nombre del empleado: ");
		fflush(stdin);
		gets(nuevoEmpleado->nombre);
		while(validarString(nuevoEmpleado->nombre) || validarLargoString(nuevoEmpleado->nombre, 19))
		{
			printf("Error, reingrese nombre del empleado: ");
			fflush(stdin);
			gets(nuevoEmpleado->nombre);
		}

		printf("Ingrese las horas trabajadas del empleado: ");
		scanf("%d", &nuevoEmpleado->horasTrabajadas);

		printf("Ingrese el sueldo del empleado: ");
		scanf("%d", &nuevoEmpleado->sueldo);
		while(validarSueldo(nuevoEmpleado->sueldo))
		{
			printf("Error, reingrese el sueldo del empleado: ");
			scanf("%d", &nuevoEmpleado->sueldo);
		}

		ll_add(pArrayListEmployee, nuevoEmpleado);
		todoOk = 1;
	}
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int indice;
    int opcion;
    char seguir = 's';
    if(pArrayListEmployee != NULL)
    {
    	system("cls");
    	printf("             MENU MODIFICAR EMPLEADO\n");
    	printf("-----------------------------------------------\n");
    	mostrarEmpleados(pArrayListEmployee);

        printf("Ingrese indice: ");
        scanf("%d", &indice);
        if(indice < 0 || indice > ll_len(pArrayListEmployee) - 1)
        {
        	printf("No existe ningun empleado con ese indice\n");
        }
        else
        {
        	Employee* empleado = (Employee*) ll_get(pArrayListEmployee, indice);
        	do
        	{
        		system("cls");
        	    printf("             MENU MODIFICAR EMPLEADO\n");
        	    printf("-----------------------------------------------\n");
        	    printf("ID                Nombre     Horas   Sueldo\n");
        	    mostrarEmpleado(empleado);

        	    printf("\n1.Modificar nombre\n");
        	    printf("2.Modificar Horas trabajadas\n");
        	    printf("3.Modificar Sueldo\n");
        	    printf("4.Volver al menu principal\n\n");

                printf("Seleccionar opcion: ");
       	        scanf("%d", &opcion);

  	        	switch(opcion)
  	        	{
  	        	case 1:
  	        		printf("Ingrese nuevo nombre: ");
        	   		fflush(stdin);
             		gets(empleado->nombre);
             		while(validarString(empleado->nombre) || validarLargoString(empleado->nombre, 19))
             		{
             			printf("Error, reingrese nuevo nombre: ");
             			fflush(stdin);
             			gets(empleado->nombre);
             		}
   	        		system("cls");
   	        		break;
        	   	case 2:
        	        printf("Ingrese nuevas horas trabajadas: ");
        	        scanf("%d", &empleado->horasTrabajadas);
        	        system("cls");
        	        break;
        	    case 3:
        	        printf("Ingrese nuevo sueldo: ");
        	        scanf("%d", &empleado->sueldo);
        	        system("cls");
        	        break;
        	    case 4:
        	        seguir = 'n';
        	        break;
        	    default:
        	        printf("Opcion invalida\n\n");
        	        break;
        	    }
        	}while(seguir == 's');
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int indice;
    char confirmarBaja;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("              MENU BAJA EMPLEADO\n");
        printf("-----------------------------------------------\n");
        mostrarEmpleados(pArrayListEmployee);
        printf("Ingrese indice: ");
        scanf("%d", &indice);

        if(indice < 0 || indice > ll_len(pArrayListEmployee) - 1)
        {
            printf("No existe ningun empleado con ese indice\n");
        }
        else
        {
        	Employee* empleado = (Employee*) ll_get(pArrayListEmployee, indice);
        	printf("ID                Nombre     Horas   Sueldo\n");
        	mostrarEmpleado(empleado);
            printf("\nConfirmar la baja(s = si, n = no): ");
            fflush(stdin);
            scanf("%c", &confirmarBaja);
            if(confirmarBaja == 's')
            {
                ll_remove(pArrayListEmployee, indice);
                printf("Baja realizada con exito\n");
                todoOk = 1;
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	if(pArrayListEmployee != NULL)
	{
		ll_sort(pArrayListEmployee, funcionCriterio, 0);
		todoOk = 1;
	}
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam;
	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		FILE* f = fopen(path, "w");
		if(f == NULL)
		{
			system("cls");
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			fprintf(f, "ID  Nombre  Horas  Sueldo\n");
			for(int i = 0 ; i < tam ; i++)
			{
				Employee* empleado = (Employee*) ll_get(pArrayListEmployee, i);
				fprintf(f, "%d,%s,%d,%d", empleado[i].id, empleado[i].nombre, empleado[i].horasTrabajadas, empleado[i].sueldo);
			}
			fclose(f);
		}
		todoOk = 1;
	}
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam;
	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		FILE* f = fopen(path, "wb");
		if(f == NULL)
		{
			system("cls");
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			for(int i = 0 ; i < tam ; i++)
			{
				fwrite(&pArrayListEmployee[i], sizeof(Employee), 1, f);
			}
			fclose(f);
		}
		todoOk = 1;
	}
    return todoOk;
}

