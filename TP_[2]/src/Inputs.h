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

int getInt(char mensaje[]);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
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
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int onlyLetters(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[], char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetters(char mensaje[], char input[]);
