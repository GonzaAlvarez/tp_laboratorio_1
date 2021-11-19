/*
 * mascota.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Alvarez Gonzalo
 */

#ifndef SRC_MASCOTA_H_
#define SRC_MASCOTA_H_

typedef struct
{
    int id;
    char nombre[20];
    int edad;
}Mascota;

#endif /* SRC_MASCOTA_H_ */

Mascota* new_mascota();
Mascota* newParam_mascota(char* idStr, char* nombreStr, char* edadStr);
void mascota_delete(Mascota* mascota);

int mascota_setId(Mascota* mascota, int id);
int mascota_getId(Mascota* mascota, int* id);

int mascota_setNombre(Mascota* mascota, char* nombre);
int mascota_getNombre(Mascota* mascota, char* nombre);

int mascota_setEdad(Mascota* mascota, int edad);
int mascota_getEdad(Mascota* mascota, int* edad);

int cargarMascotas(char* path , LinkedList* pListaMascotas);
int bajaMascota(LinkedList* pListaMascotas);
int bajaMascotaGuardarElemento(LinkedList* pListaMascotas);
int modificarMascota(LinkedList* pListaMascotas);
int getIndexById(LinkedList* pListaMascotas, int id);
int buscarMascota(LinkedList* pListaMascotas);
int listaCincoMascotas(LinkedList* pListaMascotas);
void mostrarMascota(Mascota* mascota);
int mostrarMascotas(LinkedList* pListaMascotas);
int ordenarMascotasEdad(void* pElement1, void* pElement2);
int guardarMascotas(char* path , LinkedList* pListaMascotas);
