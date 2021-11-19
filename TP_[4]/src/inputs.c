#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

/** \brief Crea un menu y lo muestra en pantalla
 *
 * \return int Retorna el valor de la opcion seleccionada
 *
 */
int menu()
{
	int opcion;

	system("cls");
	printf("                                  MENU PRINCIPAL\n");
	printf("---------------------------------------------------------------------------------\n");
	printf(" 1.Cargar Archivo de texto con mascotas\n");
	printf(" 2.Push ultima mascota a la primer fila\n");
	printf(" 3.Eliminar Mascota\n");
	printf(" 4.Eliminar todas las mascotas \n");
	printf(" 5.Eliminar mascota pero guardar el elemento\n");
	printf(" 6.Modificar mascota\n");
	printf(" 7.Clonar lista de mascotas y guardarla en un archivo nuevo\n");
	printf(" 8.Crear lista con las primeras 5 mascotas y mostrarla\n");
	printf(" 9.Comparar lista de mascotas con la clonada\n");
	printf(" 10.Mascotas en el sistema\n");
	printf(" 11.Verificar si la lista de mascotas principal esta vacia\n");
	printf(" 12.Buscar primer mascota de la lista\n");
	printf(" 13.Mostrar mascotas\n");
	printf(" 14.Ordenar mascotas por edad\n");
	printf(" 15.Guardar mascotas en un nuevo archivo de texto\n");
	printf(" 16.Salir\n\n");

	printf("Seleccione opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/** \brief Verifica el largo de un string recibiendo como parametro un tamaño
 *
 * \param string[] char String a validar
 * \param tam int Tamaño del string
 * \return int Retorna: (0) = Si no supera el tamaño ingresado
 *                      (1) = Si supera el tamaño ingresado
 *
 */
int validarLargoString(char string[], int tam)
{
    int todoOk = 0;
    if(strlen(string) > tam)
    {
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Verifica que un string este compuesto unicamente de letras
 *
 * \param string[] char String a validar
 * \return int Retorna: (0) = Si esta compuesto de letras
 *                      (1) = Si no esta compuesto de letras
 *
 */
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


/** \brief Convierte una cadena a entero
 *
 * \param strValor[] char Cadena a convertir
 * \param intValor int* Puntero a entero que va a ser guardado como cadena
 * \return int Retorna: (0) = Si la cadena es NULL o si el puntero a entero es NULL
 *                      (1) = Todo Ok
 *
 */
int strToInt(char strValor[], int* intValor)
{
    int todoOk = 0;
    int valor;

    if(strValor != NULL && intValor != NULL)
    {
        if(strcmp(strValor, "0") == 0)
        {
            *intValor = 0;
        }
        else
        {
            valor = atoi(strValor);
            if(valor != 0)
            {
                *intValor = valor;
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
