#include "EmployeesArrays.h"
#include "Funciones.h"

int inItEmployees (unEmpleado list[], int len)//Indicar que el vector esta vacio
{


    for (int i=0; i<len; i++)
    {
        list[i].isEmpty= 1;
    }
    return 0;
}

int buscarEspacio (unEmpleado list[], int len)
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

void mostrarEmpleado(unEmpleado list)
{

    printf ("%4d      %8s       %8s      %7.2f      %3d\n\n", list.id, list.name, list.lastName,list.salary, list.sector);

    printf ("********************************************************************\n");


}


int altaEmpleado(unEmpleado list[], int len, int espacio) //ingresar empleado
{


    getS("Ingrese nombre del empleado: \n",list[espacio].name );


    getS("Ingrese apellido del empleado: \n", list[espacio].lastName);


    printf ("Ingrese salario del empleado: \n");
    scanf ("%f", &list[espacio].salary);

    printf ("Ingrese sector del empleado: \n");
    scanf ("%d", &list[espacio].sector);

    list[espacio].id= generarID(list, len);

    list[espacio].isEmpty = 0;




    return espacio;
}

void confirmarAlta(unEmpleado list[])
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

int mostrarEmpleados(unEmpleado list[], int len)
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


int generarID(unEmpleado list[], int len)
{

    int aux=0;

    for (int i=0; i<len; i++)
    {

        if((i  ==  0 ||  list[i].id)  >  aux  &&  list[i].isEmpty!=1)
        {

            aux=list[i].id;

        }
    }
    return aux+1;
}

int validarId(unEmpleado list[], int len, int auxId)
{

    int valido=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && auxId == list[i].id)
        {
            valido=0;
        }
    }

    return valido;
}





int bajaEmpleado(unEmpleado list[], int len ) // Eliminar empleado
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

void confirmarBaja (unEmpleado list[])
{
    int espacio;


    mostrarEmpleados(list, LEN);// informo array empleados

    espacio = bajaEmpleado(list, LEN); //Elimina empleado


    confirmacion(espacio); //  ejecucion valida o erronea

}

int modificarEmpleado (unEmpleado list[], int len,int id,int opcion)
{

    int valido =-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && id == list[i].id)
        {
            switch (opcion)
            {
            case 0:
                getS ("Ingrese nuevo nombre de empleado: ",list[i].name);

                break;
            case 1:
                getS("Ingrese nuevo apellido del empleado: ", list[i].lastName);
                break;
            case 2:
                printf ("Ingrese nuevo salario del empleado: \n");
                scanf ("%f", &list[i].salary);
                break;
            case 3:
                printf ("Ingrese nuevo sector del empleado: \n");
                scanf ("%d", &list[i].sector);
                break;
            }
            valido=0;
        }
    }

    return valido;
}

void confirmarModificacion(unEmpleado list[])
{
    int opcion;
    int auxId;
    int valido=-1;



    mostrarEmpleados(list, LEN); // informo empleados

    // Pido ingreso de ID del empleado
    printf ("Ingrese Id del empleado a modificar: ");
    scanf ("%d", &auxId);


    valido=validarId(list,LEN,auxId); // si se encontro el id

    if (valido==0)
    {
        // Se pregunta al usuario quiere modificar
        opcion = intDeValidacion("\n0) Nombre\n1) Apellido\n2) Salario\n3) Sector\nIndique parametro a modificar: ", "Error.  (0-3): ", 0, 3);

        // Se modifica
        valido = modificarEmpleado(list, LEN, auxId, opcion);


        confirmacion(valido);// avisa si se realizo la modificacion
    }

    else
    {

        confirmacion(valido); // error de id
    }
}



void sueldoPromedioEmpleados(unEmpleado list[])
{

    float totalSueldos;
    float promedioSalarios;
    int masDelPromedio;

    // Operacion de suma para sacar total de sueldos
    totalSueldos= sumaSueldos(list, LEN);

    if (totalSueldos > 0)
    {
        system("pause");
        printf("La suma total de los sueldos es: %.2f", totalSueldos);

        promedioSalarios= promedioSueldos(list);//operacion para sacar promedio de los sueldos
        printf("El sueldo promedio es: %.2f\n", promedioSalarios);
        // Calcula la cantidad de empleados que ganan mas que el promedio
        masDelPromedio= masQueElPromedio(list, LEN, promedioSalarios);
        printf("Hay %d empleado/s que superan el salario promedio\n", masDelPromedio);
        system ("pause");
    }

    else
    {
        totalSueldos= -1;
        confirmacion(totalSueldos);
    }
}

void preguntarOrdenEmpleados(unEmpleado list[])
{

    int valido=-1;
    int criterio;

    criterio = intDeValidacion("Ingrese orden deseado\n1)Orden por sector descendente.\n2)Orden por sector ascendente.\n", "Opcion invalida, ingrese 1 o 2", 1, 2);//Se pide tipo de orden a ejecutar
    valido=ordenEmpleados(list, LEN, criterio);//ordenamiento

    confirmacion(valido);// valido si se puede ordenar

    if(valido == 0)
    {


        mostrarEmpleados(list, LEN);
        system("pause");
    }

}


int ordenEmpleados(unEmpleado list[], int len, int criterio) // Ordenamiento de vector (ascendente o descendente)
{

    unEmpleado aux;
    int valido=-1;

    for(int i=0; i<len-1; i++)
    {

        if(list[i].isEmpty!=0)
        {
            continue;
        }
        for(int j=i+1; i<len; j++)
        {
            if(list[j].isEmpty!=0)
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
                else
                {
                    if((list[i].sector == list[j].sector) && (strcmp (list[i].lastName, list[j].lastName)<0))   // ordeno por apellido en caso de que los sectores sean iguales
                    {

                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
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
                else
                {
                    if ((list[i].sector == list[j].sector) && (strcmp (list[i].lastName, list[j].lastName)>0))   // ordeno por apellido en caso de que los sectores sean iguales
                    {

                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
                valido=0;
                break;
            }

        }
    }




    return valido;
}


int informarEmpleados(unEmpleado list[], int len)      // Imprime vectores o arrays de forma encolumnada
{

    printf("*************************************************************************\n");
    printf("    Id       Nombre       Apellido       Salario        Sector   \n");
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

int cantidadEmpleados(unEmpleado list[], int len)
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

float sumaSueldos (unEmpleado list[], int len)
{



    float suma=0;

    for(int i=0; i<len; i++)
    {
        if (list[i].isEmpty!= 0)
        {
            continue;
        }

        suma=(float)(suma+list[i].salary);
    }
    printf ("%f",suma);
    return suma;

}

float promedioSueldos (unEmpleado list[])
{


    float promedio;
    float totalDeSueldos;
    int cantidad;

    totalDeSueldos = sumaSueldos(list, LEN);
    printf ("Total sueldos: %.2f\n", totalDeSueldos);
    cantidad = cantidadEmpleados(list, LEN);
    printf ("Cantdad empleados: %d\n", cantidadEmpleados);
    promedio = (float) (totalDeSueldos / cantidad);
    printf ("Promedio: %.2f\n",promedio);

    return promedio;

}

float masQueElPromedio(unEmpleado list[], int len, int promedio)
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

void ordenSectorSueldos(unEmpleado list[])
{
    int opcion;

    opcion = intDeValidacion("1) Mostrar empleados ordenados por sector\n"
                             "2)Suma total de sueldos y su promedio, y cuantos empleados superan este ultimo.\nIndique opcion deseada:  ",
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

