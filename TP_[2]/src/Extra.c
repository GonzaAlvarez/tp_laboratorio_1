#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Extra.h"

char getIdAleatorio(int desde , int hasta)
{
    srand(time(NULL));

    return desde + (rand() % (hasta + 1 - desde));
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

int modifyEmployee(Employee* list, int len, int id)
{
    int todoOk = -1;
    int indice;
    int seguir = 's';
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
                    while(!getStringLetters("Ingrese nuevo nombre: ", list[indice].name))
                    {
                        printf("El nombre solo puede contener letras!!\n");
                    }
                    while(strlen(list[indice].name) > 50)
                    {
                        while(!getStringLetters("Nombre demasiado largo, reingrese nombre: ", list[indice].name))
                        {
                            printf("El nombre solo puede contener letras!!\n");
                        }
                    }
                    system("cls");
                    break;
                case 2:
                    while(!getStringLetters("Ingrese nuevo apellido: ", list[indice].lastName))
                    {
                        printf("El apellido solo puede contener letras!!\n");
                    }
                    while(strlen(list[indice].lastName) > 50)
                    {
                        while(!getStringLetters("Apellido demasiado largo, reingrese apellido: ", list[indice].lastName))
                        {
                            printf("El apellido solo puede contener letras!!\n");
                        }
                    }
                    system("cls");
                    break;
                case 3:
                    list[indice].salary = getFloat("Ingrese nuevo salario: ");
                    system("cls");
                    break;
                case 4:
                    list[indice].sector = getInt("Ingrese nuevo sector: ");
                    system("cls");
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
            }while(seguir == 's');
        }
        else
        {
            printf("No existe ningun empleado con ese ID\n");
        }
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
