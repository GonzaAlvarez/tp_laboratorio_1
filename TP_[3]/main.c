#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Inputs.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Autor: Alvarez Gonzalo

    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    int tam;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No se pudo conseguir memoria\n");
    }

    do
    {
    	switch(menu())
    	{
    	case 1:
    		if(!controller_loadFromText("data.csv", listaEmpleados))
    		{
    			printf("Ha ocurrido un problema para cargar los empleados\n");
    		}
    		else
    		{
    			printf("Empleados cargados correctamente\n");
    			tam = ll_len(listaEmpleados);
    			printf("Empleados cargados %d\n\n", tam);
    		}
    		break;
    	case 2:
    		if(!controller_loadFromBinary("datos.bin", listaEmpleados))
    		{
    			printf("Ha ocurrido un problema para cargar los empleados\n");
    		}
    		else
    		{
    			printf("Empleados cargados correctamente\n");
    		}
    	    break;
    	case 3:
    		if(controller_addEmployee(listaEmpleados))
            {
                printf("\nEmpleado agregado correctamente\n\n");
            }
            else
            {
                printf("\nHa ocurrido un error al agregar al empleado\n\n");
            }
    	    break;
    	case 4:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    			controller_editEmployee(listaEmpleados);
    		}
    	    break;
    	case 5:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    			controller_removeEmployee(listaEmpleados);
    		}
    	    break;
    	case 6:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    		    system("cls");
    			controller_ListEmployee(listaEmpleados);
    		}
    	    break;
    	case 7:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    			controller_sortEmployee(listaEmpleados);
    			printf("Empleados ordenados correctamente!\n");
    		}
    	    break;
    	case 8:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    		    if(!controller_saveAsText("prueba.csv", listaEmpleados))
                {
                    printf("No se pudo guardar el archivo de texto\n");
                }
                else
                {
                    printf("Archivo de texto guardado correctamente\n");
                }
    		}
    	    break;
    	case 9:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    			if(!controller_saveAsBinary("datos.bin", listaEmpleados))
                {
                    printf("No se pudo guardar el archivo binario\n");
                }
                else
                {
                    printf("Archivo binario guardado correctamente\n");
                }
    		}
    	    break;
    	case 10:
    		seguir = 'n';
    		ll_deleteLinkedList(listaEmpleados);
    	    break;
    	default:
    		printf("Opcion invalida\n\n");
    		break;
    	}

    	system("pause");
    }while(seguir == 's');
    return 0;
}
