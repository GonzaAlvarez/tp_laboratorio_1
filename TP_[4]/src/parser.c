#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "mascota.h"
#include "parser.h"
#include "inputs.h"

/** \brief Parsea los datos de las mascotas desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a pFile es NULL o el puntero a LinkedList es NULL
 *                      (1) = Todo Ok
 *
 */
int parser_MascotasFromText(FILE* pFile , LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    int edad;
    char buffer[3][128];
    Mascota* aux;

    if(pFile != NULL && pListaMascotas != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]) == 3 && strToInt(buffer[0], &id) && buffer[1] != NULL
               && strToInt(buffer[2], &edad))
            {
                aux = newParam_mascota(buffer[0], buffer[1], buffer[2]);
                if(aux != NULL && ll_add(pListaMascotas, (Mascota*)aux) == 0)
                {
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}

/** \brief Parsea los datos de las mascotas al archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a pFile es NULL o el puntero a LinkedList es NULL
 *                      (1) = Todo Ok
 *
 */
int parser_MascotasToText(FILE* pFile , LinkedList* pListaMascotas)
{
	int todoOk = 0;
	Mascota* mascota;
	int tam;

	if (pFile != NULL && pListaMascotas != NULL)
	{
		tam = ll_len(pListaMascotas);
		fprintf(pFile, "ID,Nombre,Edad\n");
		for (int i = 0 ; i < tam ; i++)
		{
			mascota = (Mascota*)ll_get(pListaMascotas, i);
			if (mascota != NULL)
			{
				fprintf(pFile, "%d,%s,%d\n", mascota->id, mascota->nombre, mascota->edad);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
