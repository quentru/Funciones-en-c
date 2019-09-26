#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char nombre[50];
    eFecha fechaDeNac;
}ePersona;

typedef struct
{
    int id;
    char patente[50];
    eFecha fechaDeIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;

void hardcode(ePersona persona[], int cantidad);
void showUsers(ePersona persona[], int cantidad);
void hardcodeVehiculo(eVehiculo vehiculo[], int cantidad);
void showVehiculo(eVehiculo vehiculo[],ePersona persona[], int cantidad);
void obtainIndexUser(ePersona persona[], int cantidad, int id);

int main()
{
    eVehiculo vehiculo[TAM];
    ePersona cliente[TAM];
    hardcode(cliente, TAM);
    showData(cliente,TAM);
    hardcodeVehiculo(vehiculo,TAM);
    showVehiculo(vehiculo,cliente,TAM);
    return 0;
}
void hardcode(ePersona persona[], int cantidad)
{
    int anio[]={1990,1980,2000,1995};
    int mes[]={3,4,12,11};
    int dia[]={33,22,25,11};
    char nombre[][50]={"Maria","Ezequiel","German","Yanina"};
    for(int i=0;i<cantidad;i++)
        {
            persona[i].id = i+1;
            persona[i].fechaDeNac.anio = anio[i];
            persona[i].fechaDeNac.mes = mes[i];
            persona[i].fechaDeNac.dia = dia[i];
            strcpy(persona[i].nombre, nombre[i]);
        }
}
void showData(ePersona persona[], int cantidad)
{
    for(int i=0; i<cantidad;i++)
            {
                printf("Su ID:%d\n", persona[i].id);
                printf("Nombre :%s\n", persona[i].nombre);
                printf("Fecha de nacimiento %d  %d  %d\n", persona[i].fechaDeNac.dia, persona[i].fechaDeNac.mes, persona[i].fechaDeNac.anio);
            }
}

void hardcodeVehiculo(eVehiculo vehiculo[], int cantidad)
{
    int anio[]={1990,1980,2000,1995};
    int mes[]={3,4,12,11};
    int dia[]={33,22,25,11};
    int horaIngreso[]={10,9,8,11};
    int horaSalida[]={11,11,11,12};
    int idDuenio[]={1,2,2,4};
    char patente[][50]={"AAA111","BBB222","AA111BB","DJ222BB"};
    for(int i=0;i<cantidad;i++)
        {
            vehiculo[i].id = i+1;
            vehiculo[i].fechaDeIngreso.anio = anio[i];
            vehiculo[i].fechaDeIngreso.mes = mes[i];
            vehiculo[i].fechaDeIngreso.dia = dia[i];
            strcpy(vehiculo[i].patente, patente[i]);
            vehiculo[i].horaIngreso = horaIngreso[i];
            vehiculo[i].horaSalida = horaSalida[i];
            vehiculo[i].idDuenio = idDuenio[i];
        }
}
void showVehiculo(eVehiculo vehiculo[] ,ePersona persona[], int cantidad)
{
    int idDelDueño=0;
    for(int i=0; i<cantidad;i++)
            {
                printf("ID vehicular:%d\n", vehiculo[i].id);
                idDelDueño=vehiculo[i].idDuenio;
                obtainIndexUser(persona, cantidad, idDelDueño);
                printf("patente :%s\n", vehiculo[i].patente);
                printf("Fecha de ingreso %d  %d  %d\n", vehiculo[i].fechaDeIngreso.dia, vehiculo[i].fechaDeIngreso.mes, vehiculo[i].fechaDeIngreso.anio);
                printf("hora ingreso :%d\n", vehiculo[i].horaIngreso);
                printf("hora salida :%d\n", vehiculo[i].horaSalida);
            }
}
void obtainIndexUser(ePersona persona[], int cantidad, int id)
{
    for(int i=0;i<cantidad;i++)
        {
            if(persona[i].id == id)
                {
                printf("Su ID:%d\n", persona[i].id);
                printf("Nombre :%s\n", persona[i].nombre);
                printf("Fecha de nacimiento %d  %d  %d\n", persona[i].fechaDeNac.dia, persona[i].fechaDeNac.mes, persona[i].fechaDeNac.anio);
                }
        }
}

