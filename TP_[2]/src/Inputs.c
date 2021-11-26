/*
 * Inputs.c
 *
 *  Created on: 26 nov. 2021
 *      Author: Alvarez Gonzalo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Employee.h"
#include "Inputs.h"

int menu()
{
    int opcion;

    system("cls");
    printf("   MENU PRINCIPAL\n");
    printf("--------------------\n");

    printf(" 1.Alta Empleado\n");
    printf(" 2.Modificar Empleado\n");
    printf(" 3.Baja Empleado\n");
    printf(" 4.Informar\n");
    printf(" 5.Salir\n\n");

    opcion = getInt("Ingrese opcion: ");
    return opcion;
}

int menuModify(Employee* list, int len, int id)
{
    int opcion;

    system("cls");
    printf("   MENU MODIFICACION EMPLEADO\n");
    printf("--------------------------------\n");
    printEmployees(list, len);
    printf("Esta modificando al ID %04d\n", id);
    printf("\n1.Modificar nombre\n");
    printf("2.Modificar apellido\n");
    printf("3.Modificar salario\n");
    printf("4.Modificar sector\n");
    printf("5.Volver al menu principal\n\n");

    opcion = getInt("Ingrese opcion: ");
    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("                               MENU DE INFORMES\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("1.Listado empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
    printf("3.Volver al menu principal\n\n");

    opcion = getInt("Ingrese opcion: ");
    return opcion;
}

char getIdAleatorio(int desde , int hasta)
{
    srand(time(NULL));

    return desde + (rand() % (hasta + 1 - desde));
}

int validarId(Employee* list, int len, int id)
{
    for(int i = 0 ; i < len ; i++)
    {
        if(!list[i].isEmpty && list[i].id == id)
        {
            while(list[i].id == id)
            {
                id = getIdAleatorio(1, len);
            }
        }
    }
    return id;
}

int getInt(char mensaje[])
{
    int aux;
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}

float getFloat(char mensaje[])
{
    float aux;
    printf("%s", mensaje);
    scanf("%f", &aux);
    return aux;
}

char getChar(char mensaje[])
{
    char aux;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf ("%s", input);
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

int validarInt(char* num)
{
    int todoOk = 0;
    int i = 0;

    while(num[i] != '\0')
    {
        if((num[i] == ' ') && (num[i] < '0' || num[i] > '9'))
        todoOk = 1;
        i++;
    }
    if((strlen(num) == 0))
    {
    	todoOk = 1;
    }
    for(int i = 0; i < strlen(num) ; i++)
    {
        if(!(isdigit(num[i])))
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int validarFloat(char* num)
{
    int todoOk = 0;
    int i = 0;

    while(num[i] != '\0')
    {
        if((num[i] == ' ') && (num[i] < '0' || num[i] > '9'))
        todoOk = 1;

        i++;
    }
    if((strlen(num) == 0))
    {
    	todoOk = 1;
    }
    for(int i = 0; i < strlen(num) ; i++)
    {
        if(!(isdigit(num[i])))
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


