#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Extra.h"

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

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    int indice;
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
            while(!getStringLetters("Ingrese Nombre: ", name))
            {
                printf("El nombre solo puede contener letras!!\n");
            }
            while(strlen(name) > 50)
            {
                while(!getStringLetters("Nombre demasiado largo, reingrese nombre: ", name))
                {
                    printf("El nombre solo puede contener letras!!\n");
                }
            }

            while(!getStringLetters("Ingrese Apellido: ", lastName))
            {
                printf("El apellido solo puede contener letras!!\n");
            }
            while(strlen(lastName) > 50)
            {
                while(!getStringLetters("Apellido demasiado largo, reingrese apellido: ", lastName))
                {
                    printf("El apellido solo puede contener letras!!\n");
                }
            }

            salary = getFloat("Ingrese salario: ");
            sector = getInt("Ingrese sector: ");

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
                    if(list[i].sector > list[j].sector && strcmp(list[i].lastName, list[j].lastName))
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
                else
                {
                    if(list[i].sector < list[j].sector && strcmp(list[i].lastName, list[j].lastName))
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
        printf("ID\t\tNombre\t\tApellido\tSalario\t\tSector\n");
        for(int i = 0 ; i < len ; i++)
        {
            if(!list[i].isEmpty)
            {
                printf("%04d\t\t%s\t\t%s\t\t%.2f\t\t%d\n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
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



