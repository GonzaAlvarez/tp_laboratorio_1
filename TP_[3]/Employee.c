#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Inputs.h"
#include "Employee.h"

/** \brief Pide espacio en memoria para un nuevo empleado y lo inicializa con datos estandar
 *
 * \return Employee* Retorna un puntero con espacio en memoria de tipo Employee*
 *
 */
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

/** \brief Pide espacio memoria para un nuevo empleado y setea los campos con los parametros ingresados
 *
 * \param idStr char* Id a setear
 * \param nombreStr char* Nombre a setear
 * \param horasTrabajadasStr char* horas trabajadas a setear
 * \param sueldoStr char* sueldo a setear
 * \return Employee* Retorna un puntero con espacio en memoria de tipo Employee* con los campos seteados
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr))
           && employee_setNombre(nuevoEmpleado, nombreStr)
		   && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
           && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
        {
            free(nuevoEmpleado);
			nuevoEmpleado = NULL;
        }
        else
        {
            id = atoi(idStr);
            horasTrabajadas = atoi(horasTrabajadasStr);
            sueldo = atoi(sueldoStr);
            employee_getId(nuevoEmpleado, &id);
		    employee_getNombre(nuevoEmpleado, nombreStr);
		    employee_getHorasTrabajadas(nuevoEmpleado, &horasTrabajadas);
		    employee_getSueldo(nuevoEmpleado, &sueldo);
        }
    }
    return nuevoEmpleado;
}

/** \brief Libera espacio en memoria de un empleado
 *
 * \param empleado Employee* Puntero a empleado
 * \return void
 *
 */
void employee_delete(Employee* empleado)
{
	free(empleado);
}

/** \brief Setea id en el campo id de una estructura Employee*
 *
 * \param this Employee* Puntero a empleado
 * \param id int Id a setear
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o el id no es valido
 *                      (1) = TodoOk
 *
 */
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

/** \brief Obtiene el id de un empleado
 *
 * \param this Employee* Puntero a empleado
 * \param id int* Puntero donde se va a guardar el id obtenido
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o el puntero a id es NULL
 *                      (1) = TodoOk
 */
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

/** \brief Setea nombre en el campo nombre de una estructura Employee*
 *
 * \param this Employee* Puntero a empleado
 * \param nombre char* Nombre a setear
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o el nombre no es valido
 *                      (1) = TodoOk
 */
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

/** \brief Obtiene el nombre de un empleado
 *
 * \param this Employee* Puntero a empleado
 * \param nombre char* Puntero donde se va a guardar el nombre obtenido
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o el puntero a nombre es NULL
 *                      (1) = TodoOk
 */
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


/** \brief Setea horas trabajadas en el campo horasTrabajadas de una estructura Employee*
 *
 * \param this Employee* Puntero a empleado
 * \param horasTrabajadas int horas trabajadas a setear
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o horasTrabajadas no es valido
 *                      (1) = TodoOk
 */
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

/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* Puntero a empleado
 * \param horasTrabajadas int* Puntero donde se van a guardar las horas trabajdas obtenidas
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o el puntero a horasTrabajadas es NULL
 *                      (1) = TodoOk
 */
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

/** \brief Setea sueldo en el campo sueldo de una estructura Employee*
 *
 * \param this Employee* Puntero a empleado
 * \param sueldo int sueldo a setear
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o sueldo no es valido
 *                      (1) = TodoOk
 */
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

/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee* Puntero a empleado
 * \param sueldo int* Puntero donde se va a guardar el sueldo obtenido
 * \return int Retorna: (0) = Si el puntero a Employee* es NULL o el puntero a sueldo es NULL
 *                      (1) = TodoOk
 */
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

/** \brief Imprime en pantalla los datos de un empleado
 *
 * \param empleado Employee* Puntero a empleado
 * \return void
 *
 */
void mostrarEmpleado(Employee* empleado)
{
	printf("%d%15s       %d        %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
}

/** \brief Imprime en pantalla en pantalla la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 */
int mostrarEmpleados(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam;
	if(pArrayListEmployee != NULL)
	{
	    tam = ll_len(pArrayListEmployee);
		printf("                ***LISTADO***\n");
		printf("ID        Nombre      Horas     Sueldo\n");
		for(int i = 0; i < tam ; i++)
		{
			mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, i));
		}
		todoOk = 1;
		printf("\n\n");
	}
	return todoOk;
}

/** \brief Alta de un empleado
 *
 * \param listaEmpleados LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL o nuevoEmpleado es NULL
 *                      (1) = TodoOk
 */
int add_employee(LinkedList* listaEmpleados)
{
    int todoOk = 0;
    Employee* nuevoEmpleado = NULL;
	if(listaEmpleados != NULL)
	{
		system("cls");
		printf("  MENU ALTA EMPLEADO\n");
		printf("-------------------------\n");

		nuevoEmpleado = employee_new();
		if(nuevoEmpleado != NULL)
        {
            nuevoEmpleado->id = generarNuevoId(listaEmpleados);

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

            ll_add(listaEmpleados, (Employee*)nuevoEmpleado);
            todoOk = 1;
        }
	}
    return todoOk;
}

/** \brief Modificar un empleado
 *
 * \param listaEmpleados LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 */
int adit_employee(LinkedList* listaEmpleados)
{
    int todoOk = 0;
    int id;
    int indice;
    int opcion;
    char seguir = 's';
    if(listaEmpleados != NULL)
    {
    	system("cls");
    	printf("             MENU MODIFICAR EMPLEADO\n");
    	printf("-----------------------------------------------\n");
    	mostrarEmpleados(listaEmpleados);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = getIndexById(listaEmpleados, id);
        if(indice < 0 || indice > ll_len(listaEmpleados) - 1)
        {
        	printf("No existe ningun empleado con ese indice\n");
        }
        else
        {
        	Employee* empleado = (Employee*) ll_get(listaEmpleados, indice);
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
             		ll_set(listaEmpleados, indice, empleado);
   	        		system("cls");
   	        		break;
        	   	case 2:
        	        printf("Ingrese nuevas horas trabajadas: ");
        	        scanf("%d", &empleado->horasTrabajadas);
        	        ll_set(listaEmpleados, indice, empleado);
        	        system("cls");
        	        break;
        	    case 3:
        	        printf("Ingrese nuevo sueldo: ");
        	        scanf("%d", &empleado->sueldo);
        	        ll_set(listaEmpleados, indice, empleado);
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

/** \brief Baja de un empleado
 *
 * \param listaEmpleados LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 */
int remove_employee(LinkedList* listaEmpleados)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirmarBaja;
    if(listaEmpleados != NULL)
    {
        system("cls");
        printf("              MENU BAJA EMPLEADO\n");
        printf("-----------------------------------------------\n");
        mostrarEmpleados(listaEmpleados);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = getIndexById(listaEmpleados, id);
        if(indice < 0 || indice > ll_len(listaEmpleados) - 1)
        {
            printf("No existe ningun empleado con ese indice\n");
        }
        else
        {
        	Employee* empleado = (Employee*) ll_get(listaEmpleados, indice);
        	printf("ID                Nombre     Horas   Sueldo\n");
        	mostrarEmpleado(empleado);
            printf("\nConfirmar la baja(s = si, n = no): ");
            fflush(stdin);
            scanf("%c", &confirmarBaja);
            if(confirmarBaja == 's')
            {
                ll_remove(listaEmpleados, indice);
                printf("Baja realizada con exito\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtiene el indice de un empleado recibiendo como parametro su id
 *
 * \param listaEmpleados LinkedList* Puntero a LinkedList
 * \param id int id del empleado a buscar
 * \return int Retorna: (-1) = Si el puntero a LinkedList* es NULL
 *                      Indice donde se encuentra el empleado si Todo Ok
 */
int getIndexById(LinkedList* listaEmpleados, int id)
{
    int indice = -1;
    int tam;
    int i;
    Employee* aux;

    if(listaEmpleados != NULL)
    {
        tam = ll_len(listaEmpleados);

        if(tam > 0)
        {
            for(i = 0; i < tam; i++)
            {
                aux = ll_get(listaEmpleados, i);

                if(aux != NULL && aux->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

/** \brief Busca el id mas alto de la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (-1) = Si el puntero a LinkedList* es NULL
 *                      Id mas alto si Todo Ok
 */
int buscarMaxId(LinkedList* pArrayListEmployee)
{
    int id = -1;
	Employee* aux;
	int tam;
	int max;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for(int i = 0 ; i < tam ; i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			employee_getId(aux,&id);
			if (i == 0 || id > max)
			{
				max = id;
			}
		}
		id = max;
	}
	return id;
}

/** \brief Genera un nuevo id
 *
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int Retorna: (-1) = Si el puntero a LinkedList* es NULL
 *                      Id si Todo Ok
 */
int generarNuevoId(LinkedList* pArrayListEmployee)
{
    int id = -1;
    int flag = 1;

    if(pArrayListEmployee != NULL)
    {
    	if(!ll_isEmpty(pArrayListEmployee) && flag)
    	{
    		id = buscarMaxId(pArrayListEmployee);
    		flag = 0;
    	}
    	id++;
    }
    return id;
}


/** \brief Compara los id de dos empleados
 *
 * \param emp1 void* Puntero al primer empleado a comparar
 * \param emp2 void* Puntero al segundo empleado a comparar
 * \return int Retorna: (-2) = Si el puntero al primer empleado es NULL o el puntero al segundo empleado es NULL
 *                      (-1) = Si el id del primer empleado es menor al segundo
 *                      (0)  = Si los id son iguales
 *                      (1)  = Si el id del primer empleado es mayor al segundo
 *
 */
int employee_OrdenarPorId(void* emp1, void* emp2)
{
	int todoOk = -2;
	int bufferEmp1;
	int bufferEmp2;

	if(emp1 != NULL && emp2 != NULL)
	{
		employee_getId((Employee*) emp1, &bufferEmp1);
		employee_getId((Employee*) emp2, &bufferEmp2);
		if(bufferEmp1 > bufferEmp2)
		{
			todoOk = 1;
		}
		else
		{
            if (bufferEmp1 < bufferEmp2)
            {
                todoOk = -1;
            }
            else
            {
                todoOk = 0;
            }
		}
	}
	return todoOk;
}

/** \brief Compara las horas trabajadas de dos empleados
 *
 * \param emp1 void* Puntero al primer empleado a comparar
 * \param emp2 void* Puntero al segundo empleado a comparar
 * \return int Retorna: (-2) = Si el puntero al primer empleado es NULL o el puntero al segundo empleado es NULL
 *                      (-1) = Si las horas trabajadas del primer empleado es menor al segundo
 *                      (0)  = Si las horas trabajadas son iguales
 *                      (1)  = Si las horas trabajadas del primer empleado es mayor al segundo
 *
 */
int employee_OrdenarPorHorasTrabajadas(void* emp1, void* emp2)
{
    int todoOk = -2;
	int bufferEmp1;
	int bufferEmp2;

	if(emp1 != NULL && emp2 != NULL)
	{
		employee_getHorasTrabajadas((Employee*) emp1, &bufferEmp1);
		employee_getHorasTrabajadas((Employee*) emp2, &bufferEmp2);
		if(bufferEmp1 > bufferEmp2)
		{
			todoOk = 1;
		}
		else
		{
            if (bufferEmp1 < bufferEmp2)
            {
                todoOk = -1;
            }
            else
            {
                todoOk = 0;
            }
		}
	}
	return todoOk;
}

/** \brief Compara el sueldo de dos empleados
 *
 * \param emp1 void* Puntero al primer empleado a comparar
 * \param emp2 void* Puntero al segundo empleado a comparar
 * \return int Retorna: (-2) = Si el puntero al primer empleado es NULL o el puntero al segundo empleado es NULL
 *                      (-1) = Si el sueldo del primer empleado es menor al segundo
 *                      (0)  = Si los sueldos son iguales
 *                      (1)  = Si el sueldo del primer empleado es mayor al segundo
 *
 */
int employee_OrdenarPorSueldo(void* emp1, void* emp2)
{
	int todoOk = -2;
	int bufferEmp1;
	int bufferEmp2;

	if(emp1 != NULL && emp2 != NULL)
	{
		employee_getSueldo((Employee*) emp1, &bufferEmp1);
		employee_getSueldo((Employee*) emp2, &bufferEmp2);
		if(bufferEmp1 > bufferEmp2)
		{
			todoOk = 1;
		}
		else
		{
            if (bufferEmp1 < bufferEmp2)
            {
                todoOk = -1;
            }
            else
            {
                todoOk = 0;
            }
		}
	}
	return todoOk;
}


