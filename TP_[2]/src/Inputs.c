#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Extra.h"

int menu()
{
    int opcion;

    system("cls");
    printf("   MENU PRINCIPAL\n");
    printf("--------------------\n");

    printf(" 1.ALTA\n");
    printf(" 2.MODIFICAR\n");
    printf(" 3.BAJA\n");
    printf(" 4.INFORMAR\n");
    printf(" 5.SALIR\n\n");

    opcion = getInt("Ingrese opcion: ");
    return opcion;
}

int menuModify(Employee* list, int len, int id)
{
    int opcion;

    system("cls");
    printf("MENU MODIFICACION EMPLEADO\n");
    printf("----------------------------\n");
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
    printf("MENU DE INFORMES\n");
    printf("----------------------------\n");
    printf("1.Listado empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
    printf("3.Volver al menu principal\n\n");

    opcion = getInt("Ingrese opcion: ");
    return opcion;
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

int onlyLetters(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf ("%s", input);
}

int getStringLetters(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(onlyLetters(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

