#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Propietario.h"
#include "Vehiculos.h"
#define TAM 4

int main()
{
    char option;
    int reply;
    int continuar=1;
    eVehiculo vehiculo[TAM];
    ePropietario cliente[TAM];
    initVehicles(vehiculo, TAM);
    initUsers(cliente, TAM);
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
                                system("pause");
                                system("cls");
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
                                system("pause");
                                system("cls");
                                //continuar=0;
                            }
                            break;
                    case 4:
                        showUsers(cliente,TAM);
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        reply=checkIn(vehiculo, TAM);
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
                    case 6:
                        printVehicles(vehiculo, cliente, TAM);
                        system("pause");
                        system("cls");
                        break;
                    case 7:
                        reply = checkOut(vehiculo,cliente, TAM);
                        if(!reply)
                            {
                                printf("Se egreso el vehiculo\n");
                                system("pause");
                                system("cls");
                            }else
                            {
                                printf("no se egreso el vehiculo\n");
                                system("pause");
                                system("cls");
                            }
                            break;

                    case 8:
                        printf("Desea salir??\n");
                        fflush(stdin);
                        scanf("%c", &option);
                        if(option=='s')
                            {
                                continuar=0;
                            }else
                            {
                                system("cls");
                                break;
                            }
                    }
                }

    //hardcode(cliente, TAM);
    //showData(cliente,TAM);
    //hardcodeVehiculo(vehiculo,TAM);
    //showVehiculo(vehiculo,cliente,TAM);
    return 0;
}
