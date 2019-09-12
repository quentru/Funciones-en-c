#include <stdio.h>
#include <stdlib.h>
#define TAM 4
void showArray(int arrayEdades[],char arrayNombres[], int cantidad);
void showMax(int arrayEdades[],char arrayNombres[], int cantidad);
int getIdMax(int arrayEdades[], int cantidad);
int obtainMax(int array[], int cantidad);
void hardcode(int array[], int cantidad);
void cargarCadenas(char array[][50], int cantidad);
int main()
{
    //int numero;
    //char nombreDelMenor[50];
    //int mayorEdad;
    int edades[TAM];
    char nombres[TAM][50];
    cargarCadenas(nombres,TAM);
    hardcode(edades,TAM);
    /*for(int i=0;i<3;i++)
        {
            printf("Ingrese su edad\n");
            scanf("%d", &edades[i]);
            printf("Ingrese su nombre\n");
            fflush(stdin);
            gets(nombres[i]);
            //edades[i]=numero;
        }*/
            //strcpy(nombres[i], nombre);
        //printf("la menor edad es %d y su nombre es %s",menorEdad, nombreDelMenor);
        //showArray(edades,nombres,TAM);
        showMax(edades,nombres,TAM);
    return 0;
}

void hardcode(int array[], int cantidad)
{
    int numerosParaHardcode[]={4,10,8,2};
    for (int i=0; i<cantidad; i++)
        {
            array[i] = numerosParaHardcode[i];
        }
}
void cargarCadenas(char array[][50], int cantidad)
{
    char nombresHardcode[][50]={"Alfredo","Rogelio","Julieta","pablo"};
    for (int i=0; i<cantidad; i++)
        {
            strcpy(array[i],nombresHardcode[i]);
        }
}
void showArray(int arrayEdades[],char arrayNombres[], int cantidad)
{
    for (int i=0;i<TAM;i++)
        {
            printf("su nombre es %s y su edad es %d\n", arrayNombres[i], arrayEdades[i]);
        }
}
int getIdMax(int arrayEdades[], int cantidad)
{
    int indice;
    int mayor;
    mayor = obtainMax(arrayEdades, cantidad);
    for(int i=0;i<cantidad;i++)
    {
        if(arrayEdades[i]==mayor);
        indice=i;
    }
    return indice;
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
void showMax(int arrayEdades[],char arrayNombres[], int cantidad)
{
    int indice;
    indice=getIdMax(arrayEdades,cantidad);
    printf("la nota mayor es %d y el nombre es %s", arrayEdades[indice], arrayNombres[indice]);
}


   /* for (int i=0; i<cantidad; i++)
        {
            printf("%d\n", array[i]);
        }*/

