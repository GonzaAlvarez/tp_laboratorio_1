#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo);
void employee_delete(Employee* empleado);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED

int menu();

void mostrarEmpleado(Employee* empleado);
int mostrarEmpleados(LinkedList* pArrayListEmployee);

int validarLargoString(char string[], int tam);
int validarString(char string[]);
int validarSueldo(int sueldo);

int funcionCriterio(void* item1, void* item2);
