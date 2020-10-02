#include "EmployeesArrays.h"
#include "Funciones.h"

int initEmployees(Empleado list[], int len)//Indicar que el vector esta vacio
{
    int i;

    for (i=0; i<len; i++)
    {
        list[i].isEmpty= 1;
    }
    return 0;
}

int buscarEspacio (Empleado list[], int len)
{

    int espacio=0;

    for(int i=0; i<len; i++)
    {

        if(list[i].isEmpty==1)
        {
            espacio=i;
        }

    }
    return espacio;
}

void mostrarEmpleado(Empleado list)
{

    printf ("%4d      %8s       %8s      %7.2f      %3d\n\n", list.id, list.name, list.lastName,list.salary, list.sector);

    printf ("********************************************************************\n");


}


int altaEmpleado(Empleado list[], int len, int espacio) //ingresar empleado
{


    printf("Ingrese nombre del empleado: \n");
    fflush (stdin);
    scanf ("%s",  list[espacio].name);

    printf("Ingrese apellido del empleado: \n");
    fflush (stdin);
    scanf ("%s",   list[espacio].lastName);

    printf ("Ingrese salario del empleado: \n");
    scanf ("%f", &list[espacio].salary);

    printf ("Ingrese sector del empleado: \n");
    scanf ("%d", &list[espacio].sector);

    list[espacio].id= generarID(list, len);

    list[espacio].isEmpty = 0;




    return espacio;
}

void confirmarAlta(Empleado list[])
{
    int espacio;

    espacio = buscarEspacio(list, LEN); //verifica si hay lugar en el array

    if(espacio!=0)// hay lugar
    {
        altaEmpleado(list, LEN, espacio);
        espacio= 1;
    }

    confirmacion(espacio); // ejecucion con error o valida
}

int mostrarEmpleados(Empleado list[], int len)
{


    printf("*********************************************************************\n");
    printf("    Id      Nombre      Apellido      Salario       Sector   ");
    printf("*********************************************************************\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {

            mostrarEmpleado(list[i]);
        }
    }


    return 0;

}


int generarID(Empleado list[], int len)
{

    int aux;

    for (int i=0; i<len; i++)
    {

        if((i  ==  0 ||  list[i].id)  >  aux  &&  list[i].isEmpty!=1)
        {

            aux=list[i].id;

        }
    }
    return aux+1;
}





int bajaEmpleado(Empleado list[], int len ) // Eliminar empleado
{

    int aux ;
    int espacio= 0;

    printf("Ingresar ID de empleado a eliminar: "); // ingreso de id a eliminar
    scanf("%d", &aux);

    for(int i=0; i<len; i++)
    {
        if (list[i].isEmpty==0 && aux==list[i].id)
        {
            //Verifica si se encontro el ID
            list[i].isEmpty=1;
            espacio = 1;
            break;
        }
    }

    return espacio;
}

void confirmarBaja (Empleado list[])
{
   int espacio;


    mostrarEmpleados(list, LEN);// informo array empleados

    espacio = bajaEmpleado(list, LEN); //Elimina empleado


    confirmacion(espacio); //  ejecucion valida o erronea

}





void sueldoPromedioEmpleados(Empleado list[])
{

    float totalSueldos;
    float promedioSalarios;
    int masDelPromedio;

    // Operacion de suma para sacar total de sueldos
    totalSueldos= sumaSueldos(list, LEN);

    if (totalSueldos != 0)
    {
        printf("La suma total de los sueldos es: %.2f", totalSueldos);

        promedioSalarios= promedioSueldos(list);//operacion para sacar promedio de los sueldos
        printf("\nEl sueldo promedio es: %.2f", promedioSalarios);
        // Calcula la cantidad de empleados que ganan mas que el promedio
        masDelPromedio= masQueElPromedio(list, LEN, promedioSalarios);
        printf("\nHay %d empleado/s que superan el salario promedio\n", masDelPromedio);
    }

    else
    {
        totalSueldos= -1;
        confirmacion(totalSueldos);
    }
}

void preguntarOrdenEmpleados(Empleado list[])
{

    int valido=-1;
    int criterio;

    criterio = intDeValidacion("Ingrese orden deseado\n1)Orden por sector descendente.\n2)Orden por sector ascendente.", "Opcion invalida, ingrese 1 o 2", 1, 2);//Se pide tipo de orden a ejecutar
    valido=ordenEmpleados(list, LEN, criterio);//ordenamiento
    confirmacion(valido);// valido si se puede ordenar

    if(valido == 0)
    {

        mostrarEmpleados(list, LEN);
    }
}


int ordenEmpleados(Empleado list[], int len, int criterio) // Ordenamiento de vector (ascendente o descendente)
{
    int valido=-1;
    Empleado aux;

    for(int i=0; i<len-1; i++)
    {

        if(list[i].isEmpty==0)
        {
            continue;
        }
        for(int j=i+1; i<len; j++)
        {
            if(list[j].isEmpty==0)
            {
                continue;
            }
            switch (criterio)
            {

            case 1:  // ordenamiento descendente
                if(list[i].sector < list[j].sector)  // ordeno por sector
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                else if((list[i].sector = list[j].sector) && (strcmp (list[i].lastName, list[i].lastName)<0))   // ordeno por apellido en caso de que los sectores sean iguales
                {

                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                valido=0;
                       break;

            case 2: // ordenamiento ascendente


                if(list[i].sector > list[j].sector)  // ordeno por sector
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                else if((list[i].sector = list[j].sector) && (strcmp (list[i].lastName, list[i].lastName)>0))   // ordeno por apellido en caso de que los sectores sean iguales
                {

                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                valido=0;
                       break;
            }
        }
    }




    return valido;
}


int informarEmpleados(Empleado list[], int len)      // Imprime vectores o arrays de forma encolumnada
{

    printf("*************************************************************************\n");
    printf("    Id       Nombre       Apellido       Salario        Sector   ");
    printf("*************************************************************************\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            mostrarEmpleado(list[i]);
        }
    }

    return 0;
}

int cantidadEmpleados(Empleado list[], int len)
{

    int cantidad=0;

    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty!=0)
        {
            continue;
        }

        cantidad++;
    }

    return cantidad;
}

float sumaSueldos (Empleado list[], int len)
{



    float suma=0;

    for(int i=0; i<len; i++)
    {
        if (list[i].isEmpty!= 0)
        {
            continue;
        }

        suma=suma+list[i].salary;
    }

    return suma;

}

float promedioSueldos (Empleado list[])
{


    float promedio;
    float totalDeSueldos;
    int cantidad;

    totalDeSueldos = sumaSueldos(list, LEN);
    cantidad = cantidadEmpleados(list, LEN);
    promedio = totalDeSueldos / cantidad;

    return promedio;

}

float masQueElPromedio(Empleado list[], int len, int promedio)
{

    int mayor=0;

    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty!=0)
        {
            continue;
        }

        if (list[i].salary > promedio)
        {
            mayor++;
        }
    }

    return mayor;

}

void ordenSectorSueldos(Empleado list[])
{
    int opcion;

    opcion = intDeValidacion("1) Mostrar empleados ordenados por sector\n"
                             "2)Suma total de sueldos y su promedio, y cuántos empleados superan este ultimo.\nIndique opcion deseada:  ",
                             "Error. Reingrese opcion (1-2): ", 1, 2);

    switch (opcion)
    {
    case 1:
        preguntarOrdenEmpleados(list);
        break;
    case 2:
        promedioSueldos(list);
        break;
    }

}


