#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/input.h"
#define TAM 4

int main()
{
    int numeros[TAM];
    char numero[200];
    char email[52];
    int anio;
    int mes;
    int dia;
    char caracter;
    char genero;
    int edad=0;
    float precio;
    char continuar;
    char nombre[50];
    int r; // Respuesta


    hardcode(numeros,TAM);
    arraySortMinorToMajor(numeros,TAM);
    showArray(numeros,TAM);
   // EJEMPLO DE USO DE getInt
  // printf("Ingrese email\n");
   //fflush(stdin);
   //gets(email);
        /*r=isAlphanumeric(email);
        if(r==0)
            {
                printf("es alfanumerico\n");
            }else
            {
                printf("no es alfanumerico\n");
            }

        r=getString(email,  "Ingrese su Email",  "Error al validar compruebe el largo del Email", 0, 20 );
        if(!r)
            {
                printf("Joya1\n");
            }
         printf("Ingrese un carater\n");
         fflush(stdin);
         scanf("%c", &caracter);
         r=isChar(&caracter);
            if(r == 1){
            printf("\n CARACTER: %c\n", caracter);
            }else{
            printf("Hubo error\n");
            }
*/

    r = getInt(&edad,"¿Cual es tu edad?","Rango valido [0 - 100]",1,100);
    if(r == 0){
        printf("la edad es: %d\n", edad);
    }
   /* r=validateInt(&edad, );
    if(r==0)
        {
            printf("joya usted ingreso %d", edad);
        }else
        {
            printf("error");
        }*/
    getString(email,  "Ingrese su Email",  "Error al validar compruebe el largo del Email", 0, 51 );

    // EJEMPLO DE USO DE getFloat
    r = getFloat(&precio,"¿Cual es el precio?","Rango valido [0 - 10000]",1,10000);
    if(r == 0)
        printf("\nEl precio es: %0.2f\n",precio);


    // EJEMPLO DE USO DE getChar
    r = getChar(&continuar,"Ingrese Opcion [A][B][C]","Solo [A][B][C]",'a','c');
    if(r == 0)
        printf("\nContinuar: %c\n",continuar);



    // EJEMPLO DE USO DE getString
    r = getString(nombre,"Nombre: ","El largo debe ser entre 2 y 50", 2, 50);
    if(r == 0)
        printf("\nNombre: %s\n",nombre);


    r = getGenre(&genero , "Ingrese su sexo: ", "Su sexo debe ingresarse con los caracters m o f", 'm', 'f');
    if(r == 0)
        printf("\n genero: %c\n",genero);

/*        r = getDate(&anio,  &mes, &dia, "ingreso", 1930, 2019);
        if(r == 0)
        printf("\n genero: %d %d %d\n",anio,mes,dia);
*/


    return 0;
}

