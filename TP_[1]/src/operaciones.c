/*
 * operaciones.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Gonzalo Alvarez
 */
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int sumar(int x, int y, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL)
    {
        *resultado = x + y;
        todoOk = 1;
    }

    return todoOk;
}

int restar(int x, int y, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL)
    {
        *resultado = x - y;
        todoOk = 1;
    }

    return todoOk;
}

int dividir(float x, float y, float* resultado)
{
    int todoOk = 0;

    if(y != 0)
    {
        *resultado = x / y;
        todoOk = 1;
    }

    return todoOk;
}

int multiplicar(int x, int y, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL)
    {
       *resultado = x * y;
       todoOk = 1;
    }

    return todoOk;
}

int factorial(int x, int* resultado)
{
    int todoOk = 0;
    *resultado = 1;

    if(x > -1 && resultado != NULL)
    {
        for(; 0 < x ; x--)
        {
            *resultado = *resultado * x;
            todoOk = 1;
        }
    }

    return todoOk;
}

