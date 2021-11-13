#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado;
	nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
	if(nuevoEmpleado != NULL)
	{
		nuevoEmpleado->id = 0;
	    strcpy(nuevoEmpleado->nombre, "nn");
	    nuevoEmpleado->horasTrabajadas = 0;
	    nuevoEmpleado->sueldo = 0;
	}
	return nuevoEmpleado;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo)
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = employee_new();
	if(nuevoEmpleado != NULL)
	{
		if(!(employee_setId(nuevoEmpleado, id) && employee_setNombre(nuevoEmpleado, nombre)
		   && employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas) && employee_setSueldo(nuevoEmpleado, sueldo)))
		{
			free(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
		else
		{
			employee_getId(nuevoEmpleado, &id);
		    employee_getNombre(nuevoEmpleado, nombre);
		    employee_getHorasTrabajadas(nuevoEmpleado, &horasTrabajadas);
		    employee_getSueldo(nuevoEmpleado, &sueldo);
		}
	}
	return nuevoEmpleado;
}

void employee_delete(Employee* empleado)
{
	free(empleado);
}

int employee_setId(Employee* this,int id)
{
	int todoOk = 0;
	if(this != NULL && id >= 1 && id <= 1000)
	{
		this->id = id;
	    todoOk = 1;
	}
	return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
	    todoOk = 1;
	}
	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 128)
	    {
			strcpy(this->nombre, nombre);
	        strlwr(this->nombre);
	        this->nombre[0] = toupper(this->nombre[0]);
	        todoOk = 1;
	    }
	}
	return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		nombre = this->nombre;
	    todoOk = 1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk = 0;
	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int todoOk = 0;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
	    todoOk = 1;
	}
	return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk = 0;
	    if(this != NULL && sueldo != NULL)
	    {
	        *sueldo = this->sueldo;
	        todoOk = 1;
	    }
	    return todoOk;
}

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

void mostrarEmpleado(Employee* empleado)
{
	printf("%d     %15s      %d      %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
}

int mostrarEmpleados(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee* auxEmp;
	auxEmp = employee_new();
	if(pArrayListEmployee != NULL && auxEmp != NULL)
	{
		system("cls");
		printf("                ***LISTADO***\n");
		printf("ID                Nombre     Horas   Sueldo\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
			mostrarEmpleado(auxEmp);
		}
		todoOk = 1;
		printf("\n\n");
	}
	return todoOk;
}

int validarLargoString(char string[], int tam)
{
    int todoOk = 0;
    if(strlen(string) > tam)
    {
        todoOk = 1;
    }
    return todoOk;
}

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

int validarSueldo(int sueldo)
{
	int todoOk = 0;
	if(sueldo < 0)
	{
		todoOk = 1;
	}
	return todoOk;
}

int funcionCriterio(void* item1, void* item2)
{
	int todoOk = 0;
	Employee* aux1;
	Employee* aux2;
	aux1 = (Employee*)item1;
	aux2 = (Employee*)item2;
	int sueldo1;
	int sueldo2;

	if(employee_getSueldo(aux1, &sueldo1) == 0 && employee_getSueldo(aux2, &sueldo2) == 0)
	{
		if(sueldo1 > sueldo2)
		{
			todoOk = 1;
		}
		else
		{
			todoOk = -1;
		}
	}
	return todoOk;
}

