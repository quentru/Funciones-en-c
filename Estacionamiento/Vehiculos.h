#include "Fecha.h"
#include "Propietario.h"
#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED

typedef struct
{
    int id;
    char patente[50];
    eFecha fechaDeIngreso;
    int horaIngreso;
    int horaSalida;
    int idPropietario;
    int isEmpty;
}eVehiculo;

void initVehicles(eVehiculo vehiculo[], int cantidad);
int checkIn(eVehiculo vehiculo[], int cantidad);
int checkOut(eVehiculo vehiculo[],ePropietario persona[], int cantidad);
void printVehicles(eVehiculo vehiculo[] ,ePropietario persona[], int cantidad);
void printVehicle(eVehiculo vehiculo ,ePropietario persona[], int cantidad);
int findVehicleByPatent(eVehiculo vehiculo[], int cantidad, char patente[]);
int findFreeVehicle(eVehiculo vehiculo[], int cantidad);

#endif // VEHICULOS_H_INCLUDED
