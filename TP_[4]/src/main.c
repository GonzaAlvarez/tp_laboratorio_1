/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "inputs.h"
#include "mascota.h"

int main(void)
{
	setbuf(stdout, NULL);
    /*startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort*/

    char seguir = 's';
    int tam;
    int flagListaCargada = 0;

    LinkedList* listaMascotas = ll_newLinkedList();
    LinkedList* listaMascotasClonada = ll_newLinkedList();
    if(listaMascotas == NULL)
    {
        printf("No se pudo conseguir memoria\n");
    }

    do
    {
        switch(menu())
        {
        case 1:
            if(!cargarMascotas("data.csv", listaMascotas))
    		{
    			printf("Ha ocurrido un problema para cargar las mascotas\n");
    		}
    		else
    		{
    			printf("Mascotas cargadas correctamente\n");
    			flagListaCargada = 1;
    		}
            break;
        case 2:
            if(flagListaCargada)
            {
                if(!ll_push(listaMascotas, 0, ll_get(listaMascotas, 9)))
                {
                    printf("Push realizado con exito!\n");
                }
                else
                {
                    printf("Ocurrio un problema al realizar el push\n");
                }
            }
            else
            {
                printf("Primero hay cargar las mascotas desde el archivo!\n");
            }
            break;
        case 3:
            bajaMascota(listaMascotas);
            break;
        case 4:
            tam = ll_len(listaMascotas);
            printf("Mascotas antes del clear: %d\n", tam);
            if(!ll_clear(listaMascotas))
            {
                printf("Mascotas eliminadas correctamente!\n");
                tam = ll_len(listaMascotas);
                printf("Mascotas despues del clear: %d\n\n", tam);
            }
            else
            {
                printf("Ocurrio un problema a eliminar las mascotas\n\n");
            }
            break;
        case 5:
            bajaMascotaGuardarElemento(listaMascotas);
            break;
        case 6:
            modificarMascota(listaMascotas);
            break;
        case 7:
            listaMascotasClonada = ll_clone(listaMascotas);
            if(listaMascotasClonada == NULL)
            {
                printf("No se pudo conseguir memoria\n");
            }
            else
            {
                printf("Lista creada con exito!\n");
                if(guardarMascotas("ListaMascotasClonadas.csv", listaMascotasClonada))
                {
                    printf("Lista guardada en el archivo con exito!\n");
                }
                else
                {
                    printf("Ocurrio un problema al guardar la lista en el archivo\n");
                }
            }
            break;
        case 8:
            if(listaCincoMascotas(listaMascotas))
            {
                printf("Lista creada correctamente!\n");
            }
            break;
        case 9:
            if(ll_containsAll(listaMascotas, listaMascotasClonada))
            {
                printf("Las listas de mascotas son iguales!\n");
            }
            else
            {
                printf("Las listas de mascotas son diferentes!\n");
            }
            break;
        case 10:
            tam = ll_len(listaMascotas);
            printf("Las mascotas que existen en el sistema son: %d\n\n", tam);
            break;
        case 11:
            if(ll_isEmpty(listaMascotas))
            {
                printf("La lista esta vacia\n\n");
            }
            else
            {
               printf("La lista no esta vacia\n\n");
            }
            break;
        case 12:
            buscarMascota(listaMascotas);
            if(ll_len(listaMascotas) == 0)
            {
                printf("No hay mascotas para buscar\n\n");
            }
            break;
        case 13:
            system("cls");
            mostrarMascotas(listaMascotas);
            if(ll_len(listaMascotas) == 0)
            {
                printf("No hay mascotas para mostrar\n\n");
            }
            break;
        case 14:
            if(!ll_sort(listaMascotas, ordenarMascotasEdad, 0))
            {
                printf("Lista ordenada con exito!\n");
            }
            else
            {
                printf("Ocurrio un problema al ordenar\n");
            }
            break;
        case 15:
            if(guardarMascotas("ListaDeMascotas.csv", listaMascotas))
            {
                printf("Lista guardada en el archivo con exito!\n");
            }
            else
            {
                printf("Ocurrio un problema al guardar la lista en el archivo\n");
            }
            break;
        case 16:
            seguir = 'n';
            ll_deleteLinkedList(listaMascotas);
            ll_deleteLinkedList(listaMascotasClonada);
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}
