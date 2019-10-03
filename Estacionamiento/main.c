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
    int idPropietario;
    char nombre[50];
    eFecha fechaDeNac;
    int isEmpty;
}ePropietario;

typedef struct
{
    int id;
    char patente[50];
    eFecha fechaDeIngreso;
    int horaIngreso;
    int horaSalida;
    int idPropietario;
}eVehiculo;
//void hardcode(ePropietario persona[], int cantidad);
int initUsers(ePropietario persona[], int cantidad);
void showUsers(ePropietario persona[], int cantidad);
void showUser(ePropietario persona);
void hardcodeVehiculo(eVehiculo vehiculo[], int cantidad);
void showVehiculo(eVehiculo vehiculo[],ePropietario persona[], int cantidad);
void obtainIndexUser(ePropietario persona[], int cantidad, int id);
int findArrayById(ePropietario persona[], int cantidad, int id);
int obtainIndexOfVoid(ePropietario persona[], int cantidad);
int addUser(ePropietario persona[], int cantidad);
int menu();
int removeUser(ePropietario persona[], int cantidad);
int modifyUser(ePropietario persona[], int cantidad);
//void addUser(ePropietario persona[], int cantidad);

int main()
{
    int reply;
    int continuar=1;
    eVehiculo vehiculo[TAM];
    ePropietario cliente[TAM];
    reply=initUsers(cliente, TAM);
    if(reply==0)
        {
            while(continuar)
                {
                    switch(menu())
                    {
                    case 1:
                        reply=addUser(cliente, TAM);
                        if(!reply)
                            {
                                printf("Se dio de alta\n");
                                system("pause");
                                system("cls");
                            }else
                            {
                                printf("hubo un error");
                                continuar=0;
                            }
                        break;
                    case 2:
                        reply=removeUser(cliente, TAM);
                        if(!reply)
                            {
                                printf("Se dio de baja correctamente\n");
                                system("pause");
                                system("cls");
                            }else
                            {
                                printf("No se pudo dar de baja\n");
                                //continuar=0;
                            }
                            break;
                    case 3:
                        reply = modifyUser(cliente, TAM);
                        if(!reply)
                            {
                                printf("Se modifico correctamente\n");
                                system("pause");
                                system("cls");
                            }else
                            {
                                printf("No se pudo modificar\n");
                                //continuar=0;
                            }
                    case 4:
                        showUsers(cliente,TAM);
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        continuar=0;
                    }
                }
        }else
        {
            printf("hubo un error al iniciar el sistema\n");
            return 0;
        }
    //hardcode(cliente, TAM);
    //showData(cliente,TAM);
    //hardcodeVehiculo(vehiculo,TAM);
    //showVehiculo(vehiculo,cliente,TAM);
    return 0;
}
void hardcode(ePropietario persona[], int cantidad)
{
    int anio[]={1990,1980,2000,1995};
    int mes[]={3,4,12,11};
    int dia[]={33,22,25,11};
    char nombre[][50]={"Maria","Ezequiel","German","Yanina"};
    for(int i=0;i<cantidad;i++)
        {
            persona[i].idPropietario = i+1;
            persona[i].fechaDeNac.anio = anio[i];
            persona[i].fechaDeNac.mes = mes[i];
            persona[i].fechaDeNac.dia = dia[i];
            strcpy(persona[i].nombre, nombre[i]);
        }
}
void showUsers(ePropietario persona[], int cantidad)
{
    for(int i=0; i<cantidad;i++)
            {
                printf("Su ID:%d\n", persona[i].idPropietario);
                printf("Nombre :%s\n", persona[i].nombre);
                printf("Fecha de nacimiento %d  %d  %d\n", persona[i].fechaDeNac.dia, persona[i].fechaDeNac.mes, persona[i].fechaDeNac.anio);
            }
}

void showUser(ePropietario persona)
{
    printf("Su ID:%d\n", persona.idPropietario);
    printf("Nombre :%s\n", persona.nombre);
    printf("Fecha de nacimiento %d  %d  %d\n", persona.fechaDeNac.dia, persona.fechaDeNac.mes, persona.fechaDeNac.anio);

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
            vehiculo[i].idPropietario = idDuenio[i];
        }
}
void showVehiculo(eVehiculo vehiculo[] ,ePropietario persona[], int cantidad)
{
    int idDelDuenio=0;
    for(int i=0; i<cantidad;i++)
            {
                printf("ID vehicular:%d\t", vehiculo[i].id);
                idDelDuenio=vehiculo[i].idPropietario;
                obtainIndexUser(persona, cantidad, idDelDuenio);
                printf("patente :%s\t", vehiculo[i].patente);
                printf("Fecha de ingreso %d  %d  %d\t", vehiculo[i].fechaDeIngreso.dia, vehiculo[i].fechaDeIngreso.mes, vehiculo[i].fechaDeIngreso.anio);
                printf("hora ingreso :%d\t", vehiculo[i].horaIngreso);
                printf("hora salida :%d\n", vehiculo[i].horaSalida);
            }
}
void obtainIndexUser(ePropietario persona[], int cantidad, int id)
{
    for(int i=0;i<cantidad;i++)
        {
            if(persona[i].idPropietario == id)
                {
                printf("\n\n Su ID:%d \t ", persona[i].idPropietario);
                printf("Nombre :%s \n ", persona[i].nombre);
                printf("Fecha de nacimiento %d  %d  %d\t", persona[i].fechaDeNac.dia, persona[i].fechaDeNac.mes, persona[i].fechaDeNac.anio);
                }
        }
}
int initUsers(ePropietario persona[], int cantidad)
{
    int reply=-1;
    for(int i=0;i<cantidad;i++)
        {
           persona[i].isEmpty=1;
           persona[i].idPropietario=0;
           persona[i].fechaDeNac.anio=0;
           persona[i].fechaDeNac.mes=0;
           persona[i].fechaDeNac.dia=0;
           strcpy(persona[i].nombre,"");
           reply=0;
        }
        return reply;
}
int obtainIndexOfVoid(ePropietario persona[], int cantidad)
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
    index=obtainIndexOfVoid(persona, cantidad);
    if(index!=-1)
        {
            persona[index].idPropietario =  index + 1;
            printf("Ingrese sus nombre\n");
            fflush(stdin);
            gets(persona[index].nombre);
            printf("Ingrese su dia de nacimiento");
            scanf("%d", &persona[index].fechaDeNac.dia);
            printf("Ingrese su mes de nacimiento");
            scanf("%d", &persona[index].fechaDeNac.mes);
            printf("Ingrese su anio de nacimiento");
            scanf("%d", &persona[index].fechaDeNac.anio);
            persona[index].isEmpty=0;
        }else
        {
            printf("No hay espacio en el sistema");
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
    printf("5_. salir\n");
    scanf("%d", &option);
    //printf("Dar de Baja a un propietario");
    return option;
}
int removeUser(ePropietario persona[], int cantidad)
{
    char option;
    int idPropietario, index, reply=1;
    printf("ingrese el ID del propietario que desea darde baja\n");
    scanf("%d", &idPropietario);
    index = findArrayById(persona, cantidad, idPropietario);
    showUser(persona[index]);
    printf("Desea dar de baja a este propietario??\n");
    fflush(stdin);
    scanf("%c", &option);
    if (option=='s')
        {
            if(index!=-1)
                {
                    persona[index].isEmpty=1;
                    reply=0;
                }else
                {
                    printf("No existe un propietario con ese id\n");
                }
        }else
        {
            return reply;
        }
        return reply;
}

int findArrayById(ePropietario persona[], int cantidad, int id)
{
    int index=-1;
    for(int i=0; i<cantidad; i++)
        {
            if(persona[i].idPropietario==id)
                {
                    index=i;
                    return index;
                }
        }
        return index;
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
                                gets(persona[index].fechaDeNac.anio);
                                break;
                            case 3:
                                printf("Reingrese el mes de nacimiento\n");
                                gets(persona[index].fechaDeNac.mes);
                                break;
                             case 4:
                                printf("Reingrese el dia de nacimiento\n");
                                gets(persona[index].fechaDeNac.dia);
                                break;
                            }
                        }
                }else
                {
                    printf("No existe un propietario con ese id\n");
                }
                return reply;
}
