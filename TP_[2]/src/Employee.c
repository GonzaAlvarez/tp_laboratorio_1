/*
 * Employee.c
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

int initEmployees(Employee* list, int len)
{
    int todoOk = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0 ; i < len ; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 0;
    }
    return todoOk;
}

int findEmpty(Employee* list, int len)
{
    int empty = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0 ; i < len ; i++)
        {
            if(list[i].isEmpty == 1)
            {
                empty = i;
                break;
            }
        }
    }
    return empty;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    int indice;
    char bufferSalary[20];
    char bufferSector[20];

    if(list != NULL && len > 0 && name != NULL && lastName != NULL)
    {
        system("cls");
        printf("   MENU ALTA EMPLEADO\n");
        printf("------------------------\n");
        indice = findEmpty(list, len);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(name);
            while(validarString(name) || validarLargoString(name, 51))
            {
                printf("Error, reingrese Nombre: ");
                fflush(stdin);
                gets(name);
            }

            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(lastName);
            while(validarString(lastName) || validarLargoString(lastName, 51))
            {
                printf("Error, reingrese Apellido: ");
                fflush(stdin);
                gets(lastName);
            }

            printf("Ingrese salario: ");
            fflush(stdin);
            gets(bufferSalary);
            while(validarFloat(bufferSalary) || atof(bufferSalary) < 0)
            {
                printf("Error, reingrese salario: ");
                fflush(stdin);
                gets(bufferSalary);
            }
            salary = atof(bufferSalary);

            printf("Ingrese sector: ");
            fflush(stdin);
            gets(bufferSector);
            while(validarInt(bufferSector))
            {
                printf("Error, reingrese sector: ");
                fflush(stdin);
                gets(bufferSector);
            }
            sector = atoi(bufferSector);

            if(id < 0)
            {
                id = id * -1;
            }

            list[indice].id = id;
            strcpy(list[indice].name, name);
            strcpy(list[indice].lastName, lastName);
            list[indice].salary = salary;
            list[indice].sector = sector;
            list[indice].isEmpty = 0;
            sortEmployees(list, len, 1);

            todoOk = 0;
        }
    }
    return todoOk;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int indice = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0 ; i < len ; i++)
        {
            if(list[i].isEmpty == 0 && list[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int modifyEmployee(Employee* list, int len, int id)
{
    int todoOk = -1;
    int indice;
    int seguir = 's';
    char bufferSalary[20];
    char bufferSector[20];
    if(list != NULL && len > 0)
    {
        indice = findEmployeeById(list, len, id);
        if(indice > -1)
        {
            do
            {
                switch(menuModify(list, len, id))
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(list[indice].name);
                    while(validarString(list[indice].name) || validarLargoString(list[indice].name, 51))
                    {
                        printf("Error, reingrese Nombre: ");
                        fflush(stdin);
                        gets(list[indice].name);
                    }
                    system("cls");
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(list[indice].lastName);
                    while(validarString(list[indice].lastName) || validarLargoString(list[indice].lastName, 51))
                    {
                        printf("Error, reingrese Nombre: ");
                        fflush(stdin);
                        gets(list[indice].lastName);
                    }
                    system("cls");
                    break;
                case 3:
                    printf("Ingrese salario: ");
                    fflush(stdin);
                    gets(bufferSalary);
                    while(validarFloat(bufferSalary) || atof(bufferSalary) < 0)
                    {
                        printf("Error, reingrese salario: ");
                        fflush(stdin);
                        gets(bufferSalary);
                    }
                    list[indice].salary = atof(bufferSalary);
                    system("cls");
                    break;
                case 4:
                    printf("Ingrese sector: ");
                    fflush(stdin);
                    gets(bufferSector);
                    while(validarInt(bufferSector))
                    {
                        printf("Error, reingrese sector: ");
                        fflush(stdin);
                        gets(bufferSector);
                    }
                    list[indice].sector = atoi(bufferSector);
                    system("cls");
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
            }
            while(seguir == 's');
        }
        else
        {
            printf("No existe ningun empleado con ese ID\n");
        }
    }
    return todoOk;
}

int removeEmployee(Employee* list, int len, int id)
{
    int todoOk = -1;
    int indice;
    char confirmarBaja;
    if(list != NULL && len > 0)
    {
        indice = findEmployeeById(list, len, id);
        if(indice == -1)
        {
            printf("No existe ninguna persona con ese ID\n");
        }
        else
        {
            confirmarBaja = getChar("\nConfirmar la baja(s = si, n = no): ");
            while(confirmarBaja != 's' && confirmarBaja != 'n')
            {
                printf("Error, confirmar la baja(s = si, n = no): ");
                fflush(stdin);
                scanf("%c", &confirmarBaja);
            }
            if(confirmarBaja == 's')
            {
                list[indice].isEmpty = 1;
                todoOk = 1;
                printf("Baja realizada con exito!\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
    }
    return todoOk;
}

int sortEmployees(Employee* list, int len, int order)
{
    int todoOk = -1;
    Employee auxEmployee;
    if(list != NULL && len > 0 && (order == 0 || order == 1))
    {
        for(int i = 0 ; i < len - 1 ; i++)
        {
            for(int j = i + 1 ; j < len ; j++)
            {
                if(order)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].sector > list[j].sector)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
                else
                {
                    if(strcmp(list[i].lastName, list[j].lastName) < 0 && list[i].sector > list[j].sector)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
        }
        todoOk = 0;
    }
    return todoOk;
}

int printEmployees(Employee* list, int len)
{
    int todoOk = -1;
    int flag = 1;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("LISTADO DE EMPLEADOS\n");
        printf("ID       Nombre       Apellido      Salario      Sector\n");
        for(int i = 0 ; i < len ; i++)
        {
            if(!list[i].isEmpty)
            {
                printf("%04d%12s%12s         %.2f      %d\n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay empleados para mostrar\n");
        }
        todoOk = 0;
    }
    return todoOk;
}

int promedioYTotalSalarios(Employee* list, int len)
{
    int todoOk = -1;
    int acumSalario = 0;
    int contSalario = 0;
    int contSupPromedio = 0;
    float promedio = 0;
    if(list != NULL && len > 0)
    {
        for(int i = 0 ; i < len ; i++)
        {
            if(!list[i].isEmpty)
            {
                acumSalario += list[i].salary;
                contSalario++;
            }
        }
        if(contSalario != 0)
        {
            promedio = (float)acumSalario / contSalario;
        }
        for(int j = 0 ; j < len ; j++)
        {
            if(!list[j].isEmpty && list[j].salary > promedio)
            {
                contSupPromedio++;
            }
        }
        printf("El promedio de los salarios es: %.2f\n", promedio);
        printf("El total de los salarios es: %d\n", acumSalario);
        printf("La cantidad de empleados que superan el salario promedio es: %d\n", contSupPromedio);

        todoOk = 0;
    }
    return todoOk;
}

