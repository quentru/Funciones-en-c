#include <stdio.h>
#include <stdlib.h>
#define CANT 6

void showArray(int array[], int cantidad);
int obtainMax(int array[], int cantidad);
int obtainMin(int array[], int cantidad);
void initArray(int array[], int cantidad);
void secuentialChargeArray(int array[], int cantidad, char mensaje[]);
void arraySort(int array[], int cantidad);
float obtenerPromedio(int array[], int cantidad);
int main()
{
    int mayor;
    int numero;
    int listaDeNumeros[CANT];
        secuentialChargeArray(listaDeNumeros,CANT, "Ingrese un numero");
        showArray(listaDeNumeros, CANT);
        mayor = obtainMax(listaDeNumeros, CANT);
        obtenerPromedio(listaDeNumeros, CANT);
        printf("\n y el numero mayor es %d\n", mayor);
}
void showArray(int array[], int cantidad)
{
    for(int i=0; i<cantidad; i++)
        {
            printf("%d\n",array[i]);
        }
}
int obtainMax(int array[], int cantidad)
{
    int mayor;
   for(int i=0; i<cantidad; i++)
        {
          if(array[i]>mayor || i==0)
            {
                mayor=array[i];
            }
        }
        return mayor;
}
int obtainMin(int array[], int cantidad)
{
    int minimo;
    for(int i=0; i<cantidad; i++)
        {
          if(array[i]<minimo || i==0)
            {
               minimo=array[i];
            }
        }
        return minimo;
}
void initArray(int array[], int cantidad)
{
    for(int i=0; i<cantidad; i++)
       {
            array[i]=0;
       }
}
void secuentialChargeArray(int array[], int cantidad, char mensaje[])
{
    int numero;
    for(int i=0; i<cantidad;i++)
        {
            printf(mensaje);
            scanf("%d", &numero);
            array[i]=numero;
        }

}
float obtenerPromedio(int array[], int cantidad)
{
    float promedio;
    int suma;
    for(int i=0; i<cantidad; i++)
        {
            suma = suma+array[i];
        }
    promedio = (float)suma/cantidad;
    printf("El promedio es %f", promedio);
}
void arraySort(int array[], int cantidad)
{
    int aux;
    for(int i=0; i<cantidad;i++){}
}



    /*int numero;
    int listaDeNumeros[3];
    numero=33;
    //listaDeNumeros[0]=66;

    for(int i=0; i<3;i++)
        {
            listaDeNumeros[i]=0;
        }
    for(int i=0; i<3;i++)
        {
            printf("%d\n", listaDeNumeros[i]);
        }
    return 0;
*/
