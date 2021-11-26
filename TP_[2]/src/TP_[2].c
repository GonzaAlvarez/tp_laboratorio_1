/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alvarez Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Employee.h"
#include "Inputs.h"

#define ELEMENTS 1000

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    char seguirInforme = 's';
    Employee list[ELEMENTS];
    int id;
    int idIngresado;
    char bufferIdIngresado[20];
    int flagAdd = 0;

    initEmployees(list, ELEMENTS);
    do
    {
        switch(menu())
        {
        case 1:
            id = getIdAleatorio(1, ELEMENTS);
            id = validarId(list, ELEMENTS, id);
            if(!addEmployee(list, ELEMENTS, id, list->name, list->lastName, list->salary, list->sector))
            {
                printf("Alta realizada correctamente!\n");
                flagAdd = 1;
            }
            else
            {
                printf("Hubo un problema al realizar el alta\n");
            }
            break;
        case 2:
            if(flagAdd)
            {
                printf("MENU MODIFICACION EMPLEADO\n");
                printf("----------------------------\n");
                printEmployees(list, ELEMENTS);
                printf("Ingrese ID: ");
                fflush(stdin);
                gets(bufferIdIngresado);
                while(validarInt(bufferIdIngresado))
                {
                    printf("Error, reingrese ID: ");
                    fflush(stdin);
                    gets(bufferIdIngresado);
                }
                idIngresado = atoi(bufferIdIngresado);
                modifyEmployee(list, ELEMENTS, idIngresado);
            }
            else
            {
                printf("Primero se debe realizar la carga de un empleado.\n");
            }
            break;
        case 3:
            if(flagAdd)
            {
                system("cls");
                printf("MENU BAJA EMPLEADO\n");
                printf("------------------------\n");
                printEmployees(list, ELEMENTS);
                printf("Ingrese ID: ");
                fflush(stdin);
                gets(bufferIdIngresado);
                while(validarInt(bufferIdIngresado))
                {
                    printf("Error, reingrese ID: ");
                    fflush(stdin);
                    gets(bufferIdIngresado);
                }
                idIngresado = atoi(bufferIdIngresado);
                removeEmployee(list, ELEMENTS, idIngresado);
            }
            else
            {
                printf("Primero se debe realizar la carga de un empleado.\n");
            }
            break;
        case 4:
            if(flagAdd)
            {
                do
                {
                    switch(menuInformes())
                    {
                    case 1:
                        system("cls");
                        sortEmployees(list, ELEMENTS, 1);
                        printEmployees(list, ELEMENTS);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        promedioYTotalSalarios(list, ELEMENTS);
                        system("pause");
                        break;
                    case 3:
                        seguirInforme = 'n';
                        break;
                    default:
                        printf("Opcion invalida");
                        break;
                    }
                }
                while(seguirInforme == 's');
            }
            else
            {
                printf("Primero se debe realizar la carga de un empleado.\n");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida");
            break;
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}
