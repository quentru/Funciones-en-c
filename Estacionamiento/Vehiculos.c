#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vehiculos.h"


int findFreeVehicle(eVehiculo vehiculo[], int cantidad)
{
    int index=-1;
    for(int i=0; i<cantidad; i++)
        {
            if(vehiculo[i].isEmpty==1)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}

int checkIn(eVehiculo vehiculo[], int cantidad)
{
    int reply=0;
    int index;
    index=findFreeVehicle(vehiculo, cantidad);
    if(index!=-1)
        {
            vehiculo[index].id =  index + 1;
            printf("Ingrese su patente\n");
            fflush(stdin);
            gets(vehiculo[index].patente);
            printf("Ingrese el id del propietario\n");
            scanf("%d", &vehiculo[index].idPropietario);
            printf("Ingrese el dia de ingreso\n");
            scanf("%d", &vehiculo[index].fechaDeIngreso.dia);
            printf("Ingrese el mes de ingreso\n");
            scanf("%d", &vehiculo[index].fechaDeIngreso.mes);
            printf("Ingrese el anio de ingreso\n");
            scanf("%d", &vehiculo[index].fechaDeIngreso.anio);
            printf("Ingrese ña hora de ingreso\n");
            scanf("%d", &vehiculo[index].horaIngreso);
            vehiculo[index].isEmpty=0;
        }else
        {
            printf("No hay espacio en el sistema\n");
            reply=1;
        }
        return reply;
}

void printVehicles(eVehiculo vehiculo[] ,ePropietario persona[], int cantidad)
{
    int flag=0;
    printf("ID  patente   Fecha ingreso  hora ingreso  hora salida  nombre del propietario \n");
    for(int i=0; i<cantidad;i++)
            {
                if(vehiculo[i].isEmpty==0)
                    {
                        printVehicle(vehiculo[i], persona, cantidad);
                        flag=1;
                    }
            }
            if(!flag)
                {
                    printf("No hay vehiculos que mostrar\n");
                }
}

void printVehicle(eVehiculo vehiculo ,ePropietario persona[], int cantidad)
{
        int index;
        int idDelDuenio=vehiculo.idPropietario;
        index=findArrayById(persona, cantidad, idDelDuenio);
        if(index!=-1 && vehiculo.horaSalida!=-1)
            {
                printf("%d\t  %s\t  %d/%d/%d/\t  %d\t  %d\t %s\n",vehiculo.id, vehiculo.patente, vehiculo.fechaDeIngreso.dia, vehiculo.fechaDeIngreso.mes, vehiculo.fechaDeIngreso.anio, vehiculo.horaIngreso, vehiculo.horaSalida,persona[index].nombre);
            }else if(index!=1 && vehiculo.horaSalida==-1)
            {
                printf("%d\t  %s\t  %d/%d/%d/\t  %d\t\t %s\n",vehiculo.id, vehiculo.patente, vehiculo.fechaDeIngreso.dia, vehiculo.fechaDeIngreso.mes, vehiculo.fechaDeIngreso.anio, vehiculo.horaIngreso,persona[index].nombre);
            }else
            {
                printf("No se ingreso ningun usuario con ese id\n");
            }
}

int checkOut(eVehiculo vehiculo[],ePropietario persona[], int cantidad)
{
    int reply=-1;
    char option;
    int index;
    char patente[50];
    printf("Ingrese la patente del auto a egresar\n");
    fflush(stdin);
    gets(patente);
    index = findVehicleByPatent(vehiculo, cantidad, patente);
    if(index>-1)
        {
            printf("Desea ingresar la hora de salida de este vehiculo??\n");
            printVehicle(vehiculo[index], persona, cantidad);
            fflush(stdin);
            scanf("%c", &option);
            if(option=='s')
                {
                    printf("Ingrese la hora de salida\n");
                    scanf("%d", &vehiculo[index].horaSalida);
                    reply=0;
                    return reply;
                }else
                {
                    return reply;
                }
            }else
            {
                printf("No existe ningun vehiculo con esa patente\n");

                return reply;
            }
}

int findVehicleByPatent(eVehiculo vehiculo[], int cantidad, char patente[])
{
    int index=-1;
    for(int i=0; i<cantidad; i++)
        {
            if(strcmp(vehiculo[i].patente, patente)==0)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}

void initVehicles(eVehiculo vehiculo[], int cantidad)
{
    for(int i=0;i<cantidad;i++)
        {
           vehiculo[i].isEmpty=1;
           vehiculo[i].horaSalida=-1;
        }
}
