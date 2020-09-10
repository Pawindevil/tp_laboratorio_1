#include <stdio.h>




float opSuma (float a, float b)
{


float resultado;

resultado= a    +   b  ;

return resultado;

}


float opResta (float a, float b)
{

float resultado;

resultado= a    -   b;


return resultado;
}

float opMulti(float a, float b)
{

float resultado;

resultado= a    *   b;


return resultado;

}

float opDiv (float a, float b)
{


float resultado;

if(b != 0){

resultado= a    /   b;
return resultado;

}
else
{

return 0;

}
}
long long int factorizacion (float a){


long long int factorial = 1;
if (a>0){

for(int i=1;i<=a;i++){
    factorial*=i;
}
return factorial;
}
else
{
return -1;
}
}

void mostrarResultados(float suma, float resta, float producto, float division, int flag, long long int factoreoA, long long int factoreoB){

if (flag == 1 ) // Se valida si se hicieron las operaciones
{
    printf ("La suma es: %.2f\n", suma);
    printf ("La resta es: %.2f\n", resta);
    printf ("El producto es: %.2f\n", producto);
    if(division!=0)
    {
        printf ("La division es: %.2f\n", division);
    }
    else{
        printf("No se puede dividir por 0\n");
    }
    if (factoreoA== -1){
        printf("No se puede factorizar un numero negativo\n");
    }else{
    printf("El factorial de a es: %lld\n");
    }
    if(factoreoB== -1){
        printf("No se puede factorizar un numero negativo\n");
    }else{
    printf("El factorial de b es: %lld\n");
    }
}
else{
    printf ("Calcule las operaciones primero.");
}


}

int menu(char mensaje[])
   {
       int opcion;


       printf ("%s", mensaje);
       scanf("%d", &opcion);

       return opcion;
   }

float getFloat (char mensaje[])
{
        float numero;
        printf("%s", mensaje);
        scanf("%f", &numero);

        return numero;
}

