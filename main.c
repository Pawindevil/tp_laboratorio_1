#include <stdio.h>
#include <stdlib.h>

#include "operaciones.h"


int main()
{

    int opcion;
    int validacionA;
    int validacionB;
    int flag = 0;
    float a = 0;
    float b = 0;
    float suma;
    float resta;
    float producto;
    float division;
    int factoreoA;
    int factoreoB;



    do{
    // este es el menu, sus opciones e ingreso de opcion de usuario
    printf("**** Seleccione una opcion **** \n1. Ingresar primer operando (a=%.2f)\n2. Ingresar segundo operando (b=%.2f)\n",a,b);
    printf ("3. Calcular todas las operaciones \n");
    printf ("a) Calcular suma (a+b) \n");
    printf ("b) Calcular resta (a-b) \n");
    printf ("c) Calcular multiplicacion (a*b) \n");
    printf ("d) Calcular division (a/b) \n");
    printf ("e) Calcular factorial (a! y b!) \n");
    printf ("4. Informar resultados \n");
    printf ("5. Salir \n");

    opcion=menu ("Ingrese una opcion: ");

    switch (opcion){

case 1:             // Operando a
        a= getFloat("Ingrese operador a: ");
        validacionA=1;
        break;
case 2:             // Operando b
        b= getFloat("Ingrese operador b: ");
        validacionB=1;
        break;
case 3:         //Resolucion de cada operacion
    if(validacionA==1 && validacionB==1){ // Valida si se ingresaron los operandos para poder resolver las operaciones
        suma=opSuma(a,b);
        resta=opResta(a,b);
        producto=opMulti(a,b);
        division=opDiv(a,b);
        factoreoA=factorizacion(a);
        factoreoB=factorizacion(b);
        flag=1; //Valida si se realizaron las operaciones antes de mostrar resultados.
    }else{
    printf("Invalido, ingrese operadores");
    }
    break;
case 4:

        mostrarResultados(suma, resta, producto, division, flag, factoreoA, factoreoB);
        break;
case 5:
        printf("Fin de los calculos, hasta luego.\n");
        break;
default:
    printf("Opcion invalida.\n");

    }//Final del switch
    system ("pause");
    system ("cls"); //limpia la consola
    }while(opcion!=5); //Termina la iteracion

    return 0;
}
