#include <stdio.h>
#include <stdlib.h>
#define TAM 50
typedef struct
{
    int isEmpty;
   int id;
   int orden;
   char apellido[51];
}ePersona;
void inicializarStruct(ePersona* persona, int cantidad);
int obtenerLibre(ePersona* persona, int cantidad);
void pedirDatos(ePersona* persona);

void ordenarFloat(float* flotante, int cantidad);
void swapFloat(float * numero, float * numeroDos);
void inicializarFloat(float* flotante, int cantidad);
void mostrarFloat(float* flotante, int cantidad);

void ordenar(int* enteros, int cantidad);
void swap(int * numero, int * numeroDos);
void inicializar(int* entero, int cantidad);
void mostrar(int* entero, int cantidad);
int main()
{
    int index;
    ePersona lista[50];
    int i=0, opcion;
    char continuar = 's';
    int padron[TAM];
    float numeroOrden[TAM];
    inicializarFloat(numeroOrden, TAM);
    inicializarStruct(lista, TAM);
    inicializar(padron, TAM);
    while(continuar == 's')
        {
            printf("que desea hacer??\n");
            printf("1_.ingresar datos\n");
            printf("NO HAY TANTAS OPCIONES CAPO, APURATE!!\n\n");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                index=obtenerLibre(lista, TAM);
                pedirDatos(lista + index);
                break;
            case 2:

            default:
                printf("HABIA UNA SOLA OPCION PAPA, COMO TE CONFUNDIS?, SALAME");
                break;
            }
            /*pedirDatos(lista, cantidad);
            printf("Ingrese un numero\n");
            scanf("%d", &padron[i]);
            printf("Ingrese un numero de orden\n");
            scanf("%f", &numeroOrden[i]);
            printf("Desea continuar??\n");
            fflush(stdin);
            scanf("%c", &continuar);
            i++;*////sirve
        }
            /*ordenar(padron, TAM);
            mostrar(padron, TAM);
            ordenarFloat(numeroOrden,TAM);
            mostrarFloat(numeroOrden,TAM);*////sirve
}


void ordenar(int* enteros, int cantidad)
{
    for(int i=0;i<cantidad-1;i++)
        {
            for(int j=i+1; j<cantidad; j++)
                {
                    if(*(enteros+i)>*(enteros+j))
                        {
                            swap(enteros + i, enteros + j);
                        }
                }
        }
}
void swap(int * numero, int * numeroDos)
{
    int auxiliar;
    auxiliar=*numero;
    *numero=*numeroDos;
    *numeroDos=auxiliar;
}
void inicializar(int* entero, int cantidad)
{
        for(int i=0;i<TAM;i++)
            {
                *(entero+i)=0;
            }
}
void mostrar(int* entero, int cantidad)
{
            for(int i=0;i<TAM;i++)
            {
                printf("%d\n", *(entero+i));
            }
}
void inicializarFloat(float* flotante, int cantidad)
{
        for(int i=0;i<TAM;i++)
            {
                *(flotante+i)=0;
            }
}
void mostrarFloat(float* flotante, int cantidad)
{
            for(int i=0;i<TAM;i++)
            {
                printf("%f\n", *(flotante+i));
            }
}
void ordenarFloat(float * flotante, int cantidad)
{
    for(int i=0;i<cantidad-1;i++)
        {
            for(int j=i+1; j<cantidad; j++)
                {
                    if(*(flotante+i)>*(flotante+j))
                        {
                            swapFloat(flotante + i, flotante + j);
                        }
                }
        }
}
void swapFloat(float * numero, float * numeroDos)
{
    float auxiliar;
    auxiliar=*numero;
    *numero=*numeroDos;
    *numeroDos=auxiliar;
}
void inicializarStruct(ePersona* persona, int cantidad)
{
        for(int i=0;i<TAM;i++)
            {
                (*(persona+i)).isEmpty=1;
                (*(persona+i)).id=-1;
            }
}
int obtenerLibre(ePersona* persona, int cantidad)
{
    int index;
    for(int i=0;i<cantidad;i++)
        {
            if((*(persona+i)).isEmpty==1)
                {
                    index=i;
                }
        }
        return index;
}
void pedirDatos(ePersona* persona)
{
    //int index;
    //(*(persona)).id;
    printf("Ingrese un numero de orden\n");
    scanf("%d", &(persona->orden));
    printf("Ingrese el apellido\n");
    fflush(stdin);
    gets((persona->apellido));
}
