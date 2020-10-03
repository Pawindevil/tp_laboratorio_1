#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "EmployeesArrays.h"
#include "Funciones.h"

int main()
{
    int opcion;


    unEmpleado list[LEN];

    inItEmployees(list, LEN);



    do
    {

        printf ("----------------------------------------Menu de empleados----------------------------------------\n\n\n");
        printf ("1. Alta Empleado \n2. Modificar empleado\n3. Dar baja empleado\n4. Mostrar empleados\n5.Salir\n");
        opcion= menu("Ingrese opcion: \n");



        switch (opcion)
        {

        case 1:
            confirmarAlta(list);

            break;

        case 2:
        confirmarModificacion(list);


            break;

        case 3:
            confirmarBaja(list);
            break;

        case 4:
            ordenSectorSueldos(list);



            break;

        case 5:
                printf ("Sistema finalizado, hasta luego! \n");

            break;

        default:
            printf ("Opcion invalida!\n");

            break;

        }
        system ("cls");
        system ("pause"); // se limpia pantalla
    }while (opcion!=5 );  // termina la iteracion

        return 0;
}

