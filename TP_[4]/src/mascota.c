/*
 * mascota.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Alvarez Gonzalo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "mascota.h"
#include "inputs.h"
#include "parser.h"

Mascota* new_mascota()
{
    Mascota* nuevaMascota;
	nuevaMascota = (Mascota*) malloc(sizeof(Mascota));
	if(nuevaMascota != NULL)
	{
		nuevaMascota->id = 0;
	    strcpy(nuevaMascota->nombre, "nn");
	    nuevaMascota->edad = 0;
	}
	return nuevaMascota;
}

Mascota* newParam_mascota(char* idStr, char* nombreStr, char* edadStr)
{
    Mascota* nuevaMascota = new_mascota();
    int id;
    int edad;
    if(nuevaMascota != NULL)
    {
        if(!(mascota_setId(nuevaMascota, atoi(idStr))
           && mascota_setNombre(nuevaMascota, nombreStr)
           && mascota_setEdad(nuevaMascota, atoi(edadStr))))
        {
            free(nuevaMascota);
			nuevaMascota = NULL;
        }
        else
        {
            id = atoi(idStr);
            edad = atoi(edadStr);
            mascota_getId(nuevaMascota, &id);
		    mascota_getNombre(nuevaMascota, nombreStr);
		    mascota_getEdad(nuevaMascota, &edad);
        }
    }
    return nuevaMascota;
}

void mascota_delete(Mascota* mascota)
{
    free(mascota);
}

int mascota_setId(Mascota* mascota, int id)
{
    int todoOk = 0;
	if(mascota != NULL && id >= 1 && id <= 100)
	{
		mascota->id = id;
	    todoOk = 1;
	}
	return todoOk;
}
int mascota_getId(Mascota* mascota, int* id)
{
    int todoOk = 0;
	if(mascota != NULL && id != NULL)
	{
		*id = mascota->id;
	    todoOk = 1;
	}
	return todoOk;
}

int mascota_setNombre(Mascota* mascota, char* nombre)
{
    int todoOk = 0;
	if(mascota != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 20)
	    {
			strcpy(mascota->nombre, nombre);
	        strlwr(mascota->nombre);
	        mascota->nombre[0] = toupper(mascota->nombre[0]);
	        todoOk = 1;
	    }
	}
	return todoOk;
}
int mascota_getNombre(Mascota* mascota, char* nombre)
{
    int todoOk = 0;
	if(mascota != NULL && nombre != NULL)
	{
		nombre = mascota->nombre;
	    todoOk = 1;
	}
	return todoOk;
}

int mascota_setEdad(Mascota* mascota, int edad)
{
    int todoOk = 0;
	if(mascota != NULL && edad > 0)
	{
		mascota->edad = edad;
		todoOk = 1;
	}
	return todoOk;
}
int mascota_getEdad(Mascota* mascota, int* edad)
{
    int todoOk = 0;
	if(mascota != NULL && edad != NULL)
	{
		*edad = mascota->edad;
		todoOk = 1;
	}
	return todoOk;
}

int cargarMascotas(char* path , LinkedList* pListaMascotas)
{
    int todoOk = 0;
    FILE* f = NULL;

    if(pListaMascotas != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            parser_MascotasFromText(f, pListaMascotas);
            todoOk = 1;
        }
    }
    fclose(f);

    return todoOk;
}

int bajaMascota(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirmarBaja;
    if(pListaMascotas != NULL)
    {
        system("cls");
        printf("              MENU BAJA MASCOTA\n");
        printf("-----------------------------------------------\n");
        mostrarMascotas(pListaMascotas);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = getIndexById(pListaMascotas, id);
        if(indice < 0 || indice > ll_len(pListaMascotas) - 1)
        {
            printf("No existe ninguna mascota con ese indice\n");
        }
        else
        {
        	Mascota* mascota = (Mascota*) ll_get(pListaMascotas, indice);
        	printf("ID      Nombre     Edad\n");
        	mostrarMascota(mascota);
            printf("\nConfirmar la baja(s = si, n = no): ");
            fflush(stdin);
            scanf("%c", &confirmarBaja);
            if(confirmarBaja == 's')
            {
                ll_remove(pListaMascotas, indice);
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

int bajaMascotaGuardarElemento(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    char confirmarBaja;
    if(pListaMascotas != NULL)
    {
        system("cls");
        printf("      MENU BAJA MASCOTA GUARDANDO ELEMENTO\n");
        printf("-----------------------------------------------\n");
        printf("ID      Nombre     Edad\n");
        mostrarMascotas(pListaMascotas);
        printf("Ingrese ID: ");
        scanf("%d", &id);
        printf("\nConfirmar la baja(s = si, n = no): ");
        fflush(stdin);
        scanf("%c", &confirmarBaja);
        if(confirmarBaja == 's')
        {
            ll_pop(pListaMascotas, getIndexById(pListaMascotas, id));
            printf("Baja realizada con exito\n");
            todoOk = 1;
        }
        else
        {
            printf("Se ha cancelado la baja\n");
        }
    }
    return todoOk;
}

int modificarMascota(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    int indice;
    int opcion;
    char seguir = 's';
    if(pListaMascotas != NULL)
    {
    	system("cls");
    	printf("             MENU MODIFICAR MASCOTA\n");
    	printf("-----------------------------------------------\n");
    	mostrarMascotas(pListaMascotas);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = getIndexById(pListaMascotas, id);
        if(indice < 0 || indice > ll_len(pListaMascotas) - 1)
        {
        	printf("No existe ninguna mascota con ese indice\n");
        }
        else
        {
        	Mascota* mascota = (Mascota*) ll_get(pListaMascotas, indice);
        	do
        	{
        		system("cls");
        	    printf("             MENU MODIFICAR MASCOTA\n");
        	    printf("-----------------------------------------------\n");
        	    printf("ID      Nombre     Edad\n");
        	    mostrarMascota(mascota);

        	    printf("\n1.Modificar nombre\n");
        	    printf("2.Modificar edad\n");
        	    printf("3.Volver al menu principal\n\n");
                printf("Seleccionar opcion: ");
       	        scanf("%d", &opcion);

  	        	switch(opcion)
  	        	{
  	        	case 1:
  	        		printf("Ingrese nuevo nombre: ");
        	   		fflush(stdin);
             		gets(mascota->nombre);
             		while(validarString(mascota->nombre) || validarLargoString(mascota->nombre, 19))
             		{
             			printf("Error, reingrese nuevo nombre: ");
             			fflush(stdin);
             			gets(mascota->nombre);
             		}
             		ll_set(pListaMascotas, indice, mascota);
   	        		system("cls");
   	        		break;
        	   	case 2:
        	        printf("Ingrese nueva edad: ");
        	        scanf("%d", &mascota->edad);
        	        ll_set(pListaMascotas, indice, mascota);
        	        system("cls");
        	        break;
        	    case 3:
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

int getIndexById(LinkedList* pListaMascotas, int id)
{
    int indice = -1;
    int tam;
    int i;
    Mascota* mascota;

    if(pListaMascotas != NULL)
    {
        tam = ll_len(pListaMascotas);

        if(tam > 0)
        {
            for(i = 0; i < tam; i++)
            {
                mascota = ll_get(pListaMascotas, i);

                if(mascota != NULL && mascota->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }

    return indice;
}

int buscarMascota(LinkedList* pListaMascotas)
{
    int todoOk = -1;
    Mascota* mascota;
    if(pListaMascotas != NULL)
    {
        mascota = ll_get(pListaMascotas, 0);
        if(mascota != NULL)
        {
            if(ll_contains(pListaMascotas, mascota))
            {
                printf("Primer mascota de la lista:\n");
                printf("ID      Nombre     Edad\n");
                mostrarMascota(mascota);
            }
            todoOk = 1;
        }
        printf("\n\n");
    }
    return todoOk;
}

int listaCincoMascotas(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    if(pListaMascotas != NULL)
    {
        LinkedList* listaCincoMascotas = ll_subList(pListaMascotas, 0, 5);
        if(listaCincoMascotas == NULL)
        {
            printf("No se pudo conseguir memoria\n");
        }
        else
        {
            mostrarMascotas(listaCincoMascotas);
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarMascota(Mascota* mascota)
{
    printf("%d%12s       %d\n", mascota->id, mascota->nombre, mascota->edad);
}
int mostrarMascotas(LinkedList* pListaMascotas)
{
    int todoOk = 0;
	int tam;
	if(pListaMascotas != NULL)
	{
	    tam = ll_len(pListaMascotas);
		printf("     ***LISTADO***\n");
		printf("ID      Nombre     Edad\n");
		for(int i = 0; i < tam ; i++)
		{
			mostrarMascota((Mascota*) ll_get(pListaMascotas, i));
		}
		todoOk = 1;
		printf("\n\n");
	}
	return todoOk;
}

int ordenarMascotasEdad(void* pElement1, void* pElement2)
{
    int comparacion;
    int resultado;
    Mascota* mascota1 = (Mascota*)pElement1;
    Mascota* mascota2 = (Mascota*)pElement2;

    if(mascota1 != NULL && mascota2 != NULL)
    {
        resultado = mascota1->edad - mascota2->edad;

        if(resultado > 0)
        {
            comparacion = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparacion = -1;
            }
            else
            {
                comparacion = 0;
            }
        }
    }
    return comparacion;
}

int guardarMascotas(char* path , LinkedList* pListaMascotas)
{
	int todoOk = -1;
	FILE *pFile;

	if (path != NULL && pListaMascotas != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			todoOk = parser_MascotasToText(pFile, pListaMascotas);
		}
		else
		{
			todoOk = 0;
		}
		fclose(pFile);
	}
	return todoOk;
}
