/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Gonzalo Alvarez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
	setbuf(stdout, NULL);
    int opcion;
    char seguir = 's';
    int x;
    int y;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorialX;
    int factorialY;
    int flagX = 0;
    int flagY = 0;
    int flagCalculos = 0;

    do
    {
        system("cls");
        printf("Menu de Opciones\n\n");

        if(flagX)
        {
            printf("1. Ingresar 1er operando (A = %d)\n", x);
        }
        else
        {
            printf("1. Ingresar 1er operando (A = )\n");
        }
        if(flagY)
        {
            printf("2. Ingresar 2do operando (B = %d)\n", y);
        }
        else
        {
            printf("2. Ingresar 2do operando (B = )\n");
        }
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");

        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        printf("\n");
        switch(opcion)
        {
        case 1:
            printf("Ingresar 1er operando: ");
            scanf("%d", &x);
            flagX = 1;
            break;
        case 2:
            printf("Ingresar 2do operando: ");
            scanf("%d", &y);
            flagY = 1;
            break;
        case 3:
            if(flagX && flagY)
            {
                sumar(x, y, &suma);
                restar(x, y, &resta);
                if(y != 0)
                {
                    dividir(x, y, &division);
                }
                else
                {
                    printf("No se pudo realizar la division debido a que B = 0\n");
                }
                multiplicar(x, y, &multiplicacion);
                if(x > -1)
                {
                    factorial(x, &factorialX);
                }
                else
                {
                   printf("No se pudo realizar el factorial de A debido a que es menor a cero\n");
                }
                if(y > -1)
                {
                    factorial(y, &factorialY);
                }
                else
                {
                   printf("No se pudo realizar el factorial de B debido a que es menor a cero\n");
                }
                flagCalculos = 1;
                printf("Las operaciones se realizaron correctamente!\n");
            }
            else
            {
                printf("Primero se deben ingresar operandos!\n");
            }
            break;
        case 4:
            if(flagCalculos)
            {
                printf("El resultado de %d + %d es: %d\n", x, y, suma);
                printf("El resultado de %d - %d es: %d\n", x, y, resta);
                if(y != 0)
                {
                    printf("El resultado de %d / %d es: %.2f\n", x, y, division);
                }
                else
                {
                    printf("No es posible dividir por cero\n");
                }
                printf("El resultado de %d * %d es: %d\n", x, y, multiplicacion);
                if(x > -1)
                {
                    printf("El factorial de %d es: %d\n", x, factorialX);
                }
                else
                {
                    printf("No se pudo resolver el factorial de A debido a que es menor a cero!\n");
                }
                if(y > -1)
                {
                    printf("El factorial de %d es: %d\n", y, factorialY);
                }
                else
                {
                    printf("No se pudo resolver el factorial de B debido a que es menor a cero!\n");
                }
            }
            else
            {
                printf("Primero se deben realizar las operaciones!\n");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        printf("\n");

        system("pause");
    }while(seguir == 's');

    return 0;
}
