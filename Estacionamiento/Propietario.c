#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Propietario.h"
#include "Input/inc/input.h"
#include "Fecha.h"
void showUsers(ePropietario persona[], int cantidad)
{
    int flag=0;
    printf("ID \t nombre \t\t Fecha de nacimiento\n");
    for(int i=0; i<cantidad;i++)
            {
                if(persona[i].isEmpty==0)
                    {
                        showUser(persona[i]);
                        flag=1;
                    }
            }
            if(flag==0)
                {
                    printf("No hay empleados para mostrar\n");
                }
}



void showUser(ePropietario persona)
{
    printf("%d\t %s\t %d \t %d \t %d\n",persona.idPropietario , persona.nombre, persona.fechaDeNac.dia, persona.fechaDeNac.mes, persona.fechaDeNac.anio);
}



void initUsers(ePropietario persona[], int cantidad)
{
    for(int i=0;i<cantidad;i++)
        {
           persona[i].isEmpty=1;
        }
}



int findFreeUser(ePropietario persona[], int cantidad)
{
    int index=-1;
    for(int i=0; i<cantidad; i++)
        {
            if(persona[i].isEmpty==1)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}




int addUser(ePropietario persona[], int cantidad)
{
    int reply=0;
    int index;
    index = findFreeUser(persona, cantidad);
    if(index!=-1)
        {
            persona[index].idPropietario =  index + 1;
            reply=getString(persona[index].nombre, "Ingrese su nombre\n", "Su nombre es demasiado corto o largo\n", 1, 50);
            reply=getDate(persona[index].fechaDeNac.anio, persona[index].fechaDeNac.mes, persona[index].fechaDeNac.dia, "nacimiento\n", 1900, 2015);
            persona[index].isEmpty=0;
        }else
        {
            printf("No hay espacio en el sistema\n");
            reply=1;
        }
        return reply;
}



int menu()
{
    int option;
    printf("Que desea hacer??\n");
    printf("1_. Dar de alta a un propietario\n");
    printf("2_. Dar de Baja a un propietario\n");
    printf("3_. modificar los datos de un propietario\n");
    printf("4_. mostrar propietarios\n");
    printf("5_. Ingresar un vehiculo\n");
    printf("6_. Mostrar vehiculos\n");
    printf("7_. ingresar hora de salida\n");
    printf("8_. salir\n");
    scanf("%d", &option);
    //printf("Dar de Baja a un propietario");
    return option;
}



int findArrayById(ePropietario persona[], int cantidad, int id)
{
    int index = -1;
    for(int i=0; i<cantidad; i++)
        {
            if(persona[i].idPropietario == id)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}



int removeUser(ePropietario persona[], int cantidad)
{
    char option;
    int idPropietario, index=0, reply=1;
    printf("ingrese el ID del propietario que desea darde baja\n");
    scanf("%d", &idPropietario);
    printf("%d\n", idPropietario);
    index = findArrayById(persona, cantidad, idPropietario);
    printf("%d\n", index);
    if(index==-1)
        {
            printf("no existe un usuario con ese ID\n");
            return reply;
        }else
        {
           showUser(persona[index]);
           printf("Desea dar de baja a este propietario??\n");
           fflush(stdin);
           scanf("%c", &option);
           if(option=='s')
            {
                persona[index].isEmpty = 1;
                reply=0;
            }
        }
        return reply;
}




int modifyUser(ePropietario persona[], int cantidad)
{
    char letra;
    int idDelPropietario, index, option, reply=1;
    printf("Introduzca el ID de la persona a modificar\n");
    scanf("%d", &idDelPropietario);
    index = findArrayById(persona, cantidad, idDelPropietario);
    if(index!=-1)
                {
                    showUser(persona[index]);
                    printf("Desea modificar este usuario??\n");
                    fflush(stdin);
                    scanf("%c", &letra);
                    if(letra=='s')
                        {
                            reply=0;
                            printf("que desea modificar??\n");
                            printf("1-Nombre\n");
                            printf("2-año de nacimiento\n");
                            printf("3-mes de nacimiento\n");
                            printf("4-dia de nacimiento\n");
                            scanf("%d",&option);
                            switch(option)
                            {
                            case 1:
                                printf("Ingrese el nuevo nombre\n");
                                fflush(stdin);
                                gets(persona[index].nombre);
                                break;
                            case 2:
                                printf("Reingrese el año de nacimiento\n");
                                scanf("%d", &persona[index].fechaDeNac.anio);
                                break;
                            case 3:
                                printf("Reingrese el mes de nacimiento\n");
                                scanf("%d", &persona[index].fechaDeNac.mes);
                                break;
                             case 4:
                                printf("Reingrese el dia de nacimiento\n");
                                scanf("%d", &persona[index].fechaDeNac.dia);
                                break;
                            }
                        }
                }else
                {
                    printf("No existe un propietario con ese id\n");
                }
                return reply;
}
