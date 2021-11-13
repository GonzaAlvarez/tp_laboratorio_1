#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    int nextId = 1001;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
    	exit(1);
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
    		controller_addEmployee(listaEmpleados, &nextId);
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
    			controller_ListEmployee(listaEmpleados);
    		}
    	    break;
    	case 8:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    			controller_saveAsText("data.csv", listaEmpleados);
    		}
    	    break;
    	case 9:
    		if(ll_len(listaEmpleados) == 0)
    		{
    			printf("Primero deben cargarse empleados!\n\n");
    		}
    		else
    		{
    			controller_saveAsBinary("datos.bin", listaEmpleados);
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
