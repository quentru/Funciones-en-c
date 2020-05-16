#include "Fecha.h"
#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

typedef struct
{
    int idPropietario;
    char nombre[50];
    eFecha fechaDeNac;
    int isEmpty;
}ePropietario;

void initUsers(ePropietario persona[], int cantidad);
void showUsers(ePropietario persona[], int cantidad);
void showUser(ePropietario persona);
int findFreeUser(ePropietario persona[], int cantidad);
int addUser(ePropietario persona[], int cantidad);
int menu();
int removeUser(ePropietario persona[], int cantidad);
int modifyUser(ePropietario persona[], int cantidad);
int findArrayById(ePropietario persona[], int cantidad, int id);

#endif // PROPIETARIO_H_INCLUDED
