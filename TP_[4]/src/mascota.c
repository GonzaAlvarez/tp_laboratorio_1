#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "mascota.h"
#include "inputs.h"
#include "parser.h"

/** \brief Pide espacio en memoria para una nueva mascota y lo inicializa con datos estandar
 *
 * \return Mascota* Retorna un puntero con espacio en memoria de tipo Mascota*
 *
 */
Mascota* new_mascota()
{
    Mascota* nuevaMascota;
	nuevaMascota = (Mascota*) malloc(sizeof(Mascota));
	if(nuevaMascota != NULL)
	{
		nuevaMascota->id = 0;
	    strcpy(nuevaMascota->nombre, "nn");
	    nuevaMascota->edad = 0;
	}
	return nuevaMascota;
}

/** \brief Pide espacio memoria para una nueva mascota y setea los campos con los parametros ingresados
 *
 * \param idStr char* Id a setear
 * \param nombreStr char* Nombre a setear
 * \param edadStr char* Edad a setear
 * \return Mascota* Retorna un puntero con espacio en memoria de tipo Mascota* con los campos seteados
 *
 */
Mascota* newParam_mascota(char* idStr, char* nombreStr, char* edadStr)
{
    Mascota* nuevaMascota = new_mascota();
    int id;
    int edad;
    if(nuevaMascota != NULL)
    {
        if(!(mascota_setId(nuevaMascota, atoi(idStr))
           && mascota_setNombre(nuevaMascota, nombreStr)
           && mascota_setEdad(nuevaMascota, atoi(edadStr))))
        {
            free(nuevaMascota);
			nuevaMascota = NULL;
        }
        else
        {
            id = atoi(idStr);
            edad = atoi(edadStr);
            mascota_getId(nuevaMascota, &id);
		    mascota_getNombre(nuevaMascota, nombreStr);
		    mascota_getEdad(nuevaMascota, &edad);
        }
    }
    return nuevaMascota;
}

/** \brief Libera espacio en memoria de una mascota
 *
 * \param mascota Mascota* Puntero a mascota
 * \return void
 *
 */
void mascota_delete(Mascota* mascota)
{
    free(mascota);
}

/** \brief Setea id en el campo id de una estructura Mascota*
 *
 * \param mascota Mascota* Puntero a mascota
 * \param id int Id a setear
 * \return int Retorna: (0) = Si el puntero a Mascota* es NULL o el id no es valido
 *                      (1) = TodoOk
 *
 */
int mascota_setId(Mascota* mascota, int id)
{
    int todoOk = 0;
	if(mascota != NULL && id >= 1 && id <= 100)
	{
		mascota->id = id;
	    todoOk = 1;
	}
	return todoOk;
}

/** \brief Obtiene el id de una mascota
 *
 * \param mascota Mascota* Puntero a mascota
 * \param id int* Puntero donde se va a guardar el id obtenido
 * \return int Retorna: (0) = Si el puntero a Mascota* es NULL o el puntero a id es NULL
 *                      (1) = TodoOk
 *
 */
int mascota_getId(Mascota* mascota, int* id)
{
    int todoOk = 0;
	if(mascota != NULL && id != NULL)
	{
		*id = mascota->id;
	    todoOk = 1;
	}
	return todoOk;
}

/** \brief Setea nombre en el campo nombre de una estructura Mascota*
 *
 * \param mascota Mascota* Puntero a mascota
 * \param nombre char* Nombre a setear
 * \return int Retorna: (0) = Si el puntero a Mascota* es NULL o el nombre no es valido
 *                      (1) = TodoOk
 *
 */
int mascota_setNombre(Mascota* mascota, char* nombre)
{
    int todoOk = 0;
	if(mascota != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 20)
	    {
			strcpy(mascota->nombre, nombre);
	        strlwr(mascota->nombre);
	        mascota->nombre[0] = toupper(mascota->nombre[0]);
	        todoOk = 1;
	    }
	}
	return todoOk;
}

/** \brief Obtiene el nombre de una mascota
 *
 * \param mascota Mascota* Puntero a mascota
 * \param nombre char* Puntero donde se va a guardar el nombre obtenido
 * \return int Retorna: (0) = Si el puntero a Mascota* es NULL o el puntero a nombre es NULL
 *                      (1) = TodoOk
 *
 */
int mascota_getNombre(Mascota* mascota, char* nombre)
{
    int todoOk = 0;
	if(mascota != NULL && nombre != NULL)
	{
		nombre = mascota->nombre;
	    todoOk = 1;
	}
	return todoOk;
}

/** \brief Setea edad en el campo edad de una estructura Mascota*
 *
 * \param mascota Mascota* Puntero a mascota
 * \param edad int Edad a setear
 * \return int Retorna: (0) = Si el puntero a Mascota* es NULL o edad no es valido
 *                      (1) = TodoOk
 *
 */
int mascota_setEdad(Mascota* mascota, int edad)
{
    int todoOk = 0;
	if(mascota != NULL && edad > 0)
	{
		mascota->edad = edad;
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Obtiene la edad de una mascota
 *
 * \param mascota Mascota* Puntero a mascota
 * \param edad int* Puntero donde se va a guardar la edad obtenida
 * \return int Retorna: (0) = Si el puntero a Mascota* es NULL o el puntero a edad es NULL
 *                      (1) = TodoOk
 *
 */
int mascota_getEdad(Mascota* mascota, int* edad)
{
    int todoOk = 0;
	if(mascota != NULL && edad != NULL)
	{
		*edad = mascota->edad;
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Carga los datos de las mascotas desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta de la ubicacion del archivo de texto
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si la ruta es invalida, si el puntero a LinkedList es NULL o si no pudo abrir el archivo
 *                      (1) = Si pudo leer el archivo
 *
 */
int cargarMascotas(char* path , LinkedList* pListaMascotas)
{
    int todoOk = 0;
    FILE* f = NULL;

    if(pListaMascotas != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            todoOk = parser_MascotasFromText(f, pListaMascotas);
        }
    }
    fclose(f);

    return todoOk;
}

/** \brief Baja de una mascota
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 *
 */
int bajaMascota(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirmarBaja;
    if(pListaMascotas != NULL)
    {
        system("cls");
        printf("              MENU BAJA MASCOTA\n");
        printf("-----------------------------------------------\n");
        mostrarMascotas(pListaMascotas);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = getIndexById(pListaMascotas, id);
        if(indice < 0 || indice > ll_len(pListaMascotas) - 1)
        {
            printf("No existe ninguna mascota con ese indice\n");
        }
        else
        {
        	Mascota* mascota = (Mascota*) ll_get(pListaMascotas, indice);
        	printf("ID      Nombre     Edad\n");
        	mostrarMascota(mascota);
            printf("\nConfirmar la baja(s = si, n = no): ");
            fflush(stdin);
            scanf("%c", &confirmarBaja);
            if(confirmarBaja == 's')
            {
                ll_remove(pListaMascotas, indice);
                printf("Baja realizada con exito\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Baja de una mascota pero conservando el elemento
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 *
 */
int bajaMascotaGuardarElemento(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    char confirmarBaja;
    if(pListaMascotas != NULL)
    {
        system("cls");
        printf("      MENU BAJA MASCOTA GUARDANDO ELEMENTO\n");
        printf("-----------------------------------------------\n");
        printf("ID      Nombre     Edad\n");
        mostrarMascotas(pListaMascotas);
        printf("Ingrese ID: ");
        scanf("%d", &id);
        printf("\nConfirmar la baja(s = si, n = no): ");
        fflush(stdin);
        scanf("%c", &confirmarBaja);
        if(confirmarBaja == 's')
        {
            ll_pop(pListaMascotas, getIndexById(pListaMascotas, id));
            printf("Baja realizada con exito\n");
        }
        else
        {
            printf("Se ha cancelado la baja\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Modificar una mascota
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 *
 */
int modificarMascota(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    int id;
    int indice;
    int opcion;
    char seguir = 's';
    if(pListaMascotas != NULL)
    {
    	system("cls");
    	printf("             MENU MODIFICAR MASCOTA\n");
    	printf("-----------------------------------------------\n");
    	mostrarMascotas(pListaMascotas);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = getIndexById(pListaMascotas, id);
        if(indice < 0 || indice > ll_len(pListaMascotas) - 1)
        {
        	printf("No existe ninguna mascota con ese indice\n");
        }
        else
        {
        	Mascota* mascota = (Mascota*) ll_get(pListaMascotas, indice);
        	do
        	{
        		system("cls");
        	    printf("             MENU MODIFICAR MASCOTA\n");
        	    printf("-----------------------------------------------\n");
        	    printf("ID      Nombre     Edad\n");
        	    mostrarMascota(mascota);

        	    printf("\n1.Modificar nombre\n");
        	    printf("2.Modificar edad\n");
        	    printf("3.Volver al menu principal\n\n");
                printf("Seleccionar opcion: ");
       	        scanf("%d", &opcion);

  	        	switch(opcion)
  	        	{
  	        	case 1:
  	        		printf("Ingrese nuevo nombre: ");
        	   		fflush(stdin);
             		gets(mascota->nombre);
             		while(validarString(mascota->nombre) || validarLargoString(mascota->nombre, 19))
             		{
             			printf("Error, reingrese nuevo nombre: ");
             			fflush(stdin);
             			gets(mascota->nombre);
             		}
             		ll_set(pListaMascotas, indice, mascota);
   	        		system("cls");
   	        		break;
        	   	case 2:
        	        printf("Ingrese nueva edad: ");
        	        scanf("%d", &mascota->edad);
        	        ll_set(pListaMascotas, indice, mascota);
        	        system("cls");
        	        break;
        	    case 3:
        	        seguir = 'n';
        	        break;
        	    default:
        	        printf("Opcion invalida\n\n");
        	        break;
        	    }
        	}while(seguir == 's');
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtiene el indice de una mascota recibiendo como parametro su id
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \param id int Id de la mascota a buscar
 * \return int Retorna: (-1) = Si el puntero a LinkedList* es NULL
 *                      Indice donde se encuentra la mascota si esta todo Ok
 *
 */
int getIndexById(LinkedList* pListaMascotas, int id)
{
    int indice = -1;
    int tam;
    int i;
    Mascota* mascota;

    if(pListaMascotas != NULL)
    {
        tam = ll_len(pListaMascotas);

        if(tam > 0)
        {
            for(i = 0; i < tam; i++)
            {
                mascota = ll_get(pListaMascotas, i);

                if(mascota != NULL && mascota->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

/** \brief Permite buscar una mascota
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = Todo Ok
 *
 */
int buscarMascota(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    Mascota* mascota;
    if(pListaMascotas != NULL)
    {
        mascota = ll_get(pListaMascotas, 0);
        if(mascota != NULL)
        {
            if(ll_contains(pListaMascotas, mascota))
            {
                printf("Primer mascota de la lista:\n");
                printf("ID      Nombre     Edad\n");
                mostrarMascota(mascota);
            }
            todoOk = 1;
        }
        printf("\n\n");
    }
    return todoOk;
}

/** \brief Crea una sublista de la lista principal pero solo tomando los primeros 5 elementos de la misma y los muestra en pantalla
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = Todo Ok
 *
 */
int listaCincoMascotas(LinkedList* pListaMascotas)
{
    int todoOk = 0;
    if(pListaMascotas != NULL)
    {
        LinkedList* listaCincoMascotas = ll_subList(pListaMascotas, 0, 5);
        if(listaCincoMascotas == NULL)
        {
            printf("No se pudo conseguir memoria\n");
        }
        else
        {
            mostrarMascotas(listaCincoMascotas);
            todoOk = 1;
        }
    }
    return todoOk;
}

/** \brief Imprime en pantalla los datos de una mascota
 *
 * \param mascota Mascota* Puntero a mascota
 * \return void
 *
 */
void mostrarMascota(Mascota* mascota)
{
    printf("%d%12s       %d\n", mascota->id, mascota->nombre, mascota->edad);
}

/** \brief Imprime en pantalla la lista de mascotas
 *
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si el puntero a LinkedList* es NULL
 *                      (1) = TodoOk
 *
 */
int mostrarMascotas(LinkedList* pListaMascotas)
{
    int todoOk = 0;
	int tam;
	if(pListaMascotas != NULL)
	{
	    tam = ll_len(pListaMascotas);
		printf("     ***LISTADO***\n");
		printf("ID      Nombre     Edad\n");
		for(int i = 0; i < tam ; i++)
		{
			mostrarMascota((Mascota*) ll_get(pListaMascotas, i));
		}
		todoOk = 1;
		printf("\n\n");
	}
	return todoOk;
}

/** \brief Compara la edad de dos mascotas
 *
 * \param pElement1 void* Puntero a la primer mascota a comparar
 * \param pElement2 void* Puntero a la segunda mascota a comparar
 * \return int Retorna: (-2) = Si el puntero a la primer mascota es NULL o el puntero a la segunda mascota es NULL
 *                      (-1) = Si la edad de la primer mascota es menor a la segunda
 *                      (0)  = Si las edades son iguales
 *                      (1)  = Si la edad de la primer mascota es mayor a la segunda
 *
 */
int ordenarMascotasEdad(void* pElement1, void* pElement2)
{
    int comparacion = -2;
    int resultado;
    Mascota* mascota1 = (Mascota*)pElement1;
    Mascota* mascota2 = (Mascota*)pElement2;

    if(mascota1 != NULL && mascota2 != NULL)
    {
        resultado = mascota1->edad - mascota2->edad;

        if(resultado > 0)
        {
            comparacion = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparacion = -1;
            }
            else
            {
                comparacion = 0;
            }
        }
    }
    return comparacion;
}

/** \brief Guarda los datos de los empleados en el archivo listaMascotas.csv (modo texto).
 *
 * \param path char* Ruta de la ubicacion del archivo de texto
 * \param pListaMascotas LinkedList* Puntero a LinkedList
 * \return int Retorna: (0) = Si la ruta es invalida, si el puntero a LinkedList es NULL o si no pudo escribir el archivo
 *                      (1) = Si pudo escribir el archivo
 *
 */
int guardarMascotas(char* path , LinkedList* pListaMascotas)
{
    int todoOk = 0;
	FILE* f;

	if (path != NULL && pListaMascotas != NULL)
	{
		f = fopen(path, "w");
		if (f != NULL)
		{
			todoOk = parser_MascotasToText(f, pListaMascotas);
		}
		fclose(f);
	}
	return todoOk;
}


