/*
 * Inputs.h
 *
 *  Created on: 26 nov. 2021
 *      Author: Alvarez Gonzalo
 */

#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */

/** \brief Crea el menu principal y lo muestra en pantalla
 *
 * \return int Retorna el valor de la opcion seleccionada
 *
 */
int menu();

/** \brief Crea el menu de la opcion modificar y lo muestra en pantalla
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Retorna el valor de la opcion seleccionada
 *
 */
int menuModify(Employee* list, int len, int id);

/** \brief Crea el menu de informes y lo muestra en pantalla
 *
 * \return int Retorna el valor de la opcion seleccionada
 *
 */
int menuInformes();

/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \return retorna el n�mero aleatorio generado
 *
 */
char getIdAleatorio(int desde , int hasta);

/** \brief Valida que los id no se repitan
 *
 * \param id int
 * \return int Retorna el valor del id ingresado, o un nuevo valor en caso de que sea repetido
 *
 */
int validarId(Employee* list, int len, int id);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[], char input[]);

/** \brief Verifica el largo de un string recibiendo como parametro un tama�o
 *
 * \param string[] char String a validar
 * \param tam int Tama�o del string
 * \return int Retorna: (0) = Si no supera el tama�o ingresado
 *                      (1) = Si supera el tama�o ingresado
 *
 */
int validarLargoString(char string[], int tam);

/** \brief Verifica que un string este compuesto unicamente de letras
 *
 * \param string[] char String a validar
 * \return int Retorna: (0) = Si esta compuesto de letras
 *                      (1) = Si no esta compuesto de letras
 *
 */
int validarString(char string[]);

int validarInt(char* num);
int validarFloat(char* num);
