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
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED

void mostrarEmpleado(Employee* empleado);
int mostrarEmpleados(LinkedList* pArrayListEmployee);
int add_employee(LinkedList* listaEmpleados);
int adit_employee(LinkedList* listaEmpleados);
int remove_employee(LinkedList* listaEmpleados);
int getIndexById(LinkedList* listaEmpleados, int id);
int buscarMaxId(LinkedList* pArrayListEmployee);
int generarNuevoId(LinkedList* pArrayListEmployee);
int employee_OrdenarPorId(void* emp1, void* emp2);
int employee_OrdenarPorHorasTrabajadas(void* emp1, void* emp2);
int employee_OrdenarPorSueldo(void* emp1, void* emp2);
