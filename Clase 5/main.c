#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
typedef struct
{
    float dni;
    char nombre[50];
    char apellido[50];
    int estaVacio;
}ePersona;

void menu();
void initArray(ePersona alumno[], int cantidad);
int indexOfIsEmpty(ePersona alumno[], int cantidad);
void getArrayStruct(ePersona alumno[], int cantidad);
void showArrayStruct(ePersona alumno[], int cantidad);
void showStruct(ePersona alumno);
void modifyStruct(ePersona alumno[], int cantidad);
int validarDNI(ePersona alumno[], int auxDni, int cantidad);
void sortByDNI(ePersona alumno[], int cantidad);
void sortByNameAndLastName(ePersona alumno[], int cantidad);
int findByDNI(ePersona alumno[],int cantidad, int dni);
void removeStruct(ePersona alumno[], int cantidad);


int main()
{
    char continuar='s';
    int eleccion;
    ePersona alumno[TAM];
    initArray(alumno,TAM);
    while(continuar=='s')
        {
                menu();
                scanf("%d", &eleccion);
            switch(eleccion)
            {
                case 1:
                    getArrayStruct(alumno,TAM);
                    system("pause");
                    system("cls");
                break;
                case 2:
                    showArrayStruct(alumno,TAM);
                    system("pause");
                    system("cls");
                break;
                 case 3:
                    sortByDNI(alumno,TAM);
                    system("pause");
                    system("cls");
                break;
                case 4:
                    sortByNameAndLastName(alumno,TAM);
                    system("pause");
                    system("cls");
                break;
                case 5:
                    modifyStruct(alumno,TAM);
                    system("pause");
                    system("cls");
                break;
                case 6:
                    removeStruct(alumno,TAM);
                    system("pause");
                    system("cls");
                break;
                case 7:
                    continuar='n';
                break;
            }
        }
}
void getArrayStruct(ePersona alumno[], int cantidad)
{
    float auxDni;
    int index;
    index=indexOfIsEmpty(alumno, cantidad);
        if(index==-1)
            {
                printf("no hay espacio para otro alumno en el sistema\n");
            }
                else
            {
                printf("ingrese su DNI\n");
                scanf("%f", &auxDni);
                while(validarDNI(alumno, auxDni, cantidad))
                    {
                        printf("reingrese su DNI\n");
                        scanf("%f", &auxDni);
                    }
                alumno[index].dni = auxDni;
                printf("ingrese su Nombre\n");
                fflush(stdin);
                gets(alumno[index].nombre);
                printf("ingrese su Apellido\n");
                fflush(stdin);
                gets(alumno[index].apellido);
                alumno[index].estaVacio=0;
            }
}


void showArrayStruct(ePersona alumno[], int cantidad)
{
    int index;
    index=indexOfIsEmpty(alumno,cantidad);
    if(index == 0)
        {
            printf("No hay datos que mostrar\n");
        }
        else
        {
            for(int i=0;i<cantidad;i++)
                {
                    showStruct(alumno[i]);
                    //printf("su dni es %f\n su nombre es %s\n su apellido es %s\n", alumno[i].dni, alumno[i].nombre,alumno[i].apellido);
                }
        }
}
void initArray(ePersona alumno[], int cantidad)
{
    for(int i=0; i<cantidad;i++)
        {
            alumno[i].dni=0;
            strcpy(alumno[i].nombre,"");
            strcpy(alumno[i].apellido,"");
            alumno[i].estaVacio = 1;
        }
}

int indexOfIsEmpty(ePersona alumno[], int cantidad)
{
    int index=-1;
    for(int i=0;i<cantidad;i++)
        {
            if(alumno[i].estaVacio==1)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}


void menu()
{
    printf("***--ABM--***\n\n");
    printf("Que desea hacer ??\n");
    printf("1-- Agregar datos\n");
    printf("2-- mostrar todos\n");
    printf("3-- ordenar por DNI\n");
    printf("4-- ordenar por nombre y apellido\n");
    printf("5-- modificar datos\n");
    printf("6-- Dar de baja\n");
    printf("7-- salir\n");
}

int validarDNI(ePersona alumno[], int auxDni, int cantidad)
{
    int value=0;
        for(int i=0;i<cantidad;i++)
            {
                if(alumno[i].dni==auxDni)
                    {
                        value=1;
                        return value;
                    }
            }
            return value;
}

void sortByDNI(ePersona alumno[], int cantidad)
{
    ePersona auxiliar;
    for(int i=0;i<cantidad-1;i++)
        {
            for(int j=i+1;j<cantidad;j++)
                {
                    if(alumno[i].dni>alumno[j].dni)
                        {
                            auxiliar=alumno[i];
                            alumno[i]=alumno[j];
                            alumno[j]=auxiliar;
                        }
                }
        }
        showArrayStruct(alumno, cantidad);
}
void sortByNameAndLastName(ePersona alumno[], int cantidad)
{
     for(int i=0;i<cantidad-1;i++)
        {
            ePersona auxiliar;
            for(int j=i+1;j<cantidad;j++)
                {
                        if(strcmp(alumno[i].nombre,alumno[j].nombre)>0)
                        {
                            auxiliar=alumno[i];
                            alumno[i]=alumno[j];
                            alumno[j]=auxiliar;
                        }
                        if(strcmp(alumno[i].nombre,alumno[j].nombre)==0)
                            {
                                if(strcmp(alumno[i].apellido,alumno[j].apellido)>0)
                                    {
                                        auxiliar=alumno[i];
                                        alumno[i]=alumno[j];
                                        alumno[j]=auxiliar;
                                    }
                            }
                }
        }
        showArrayStruct(alumno,cantidad);
}

void showStruct(ePersona alumno)
{
    printf("su dni es %f\n su nombre es %s\n su apellido es %s\n", alumno.dni, alumno.nombre, alumno.apellido);
}


void modifyStruct(ePersona alumno[], int cantidad)
{
    float auxDni;
    char decision;
    int dni, index;
    printf("Ingrese el DNI del usuario a modificar\n");
    scanf("%d", &dni);
    index = findByDNI(alumno, cantidad, dni);
    if(index != -1)
        {
            printf("desea modificar este usuario??\n");
            showStruct(alumno[index]);
            fflush(stdin);
            scanf("%c", &decision);
            switch(decision)
            {
            case 's':
                printf("ingrese el nuevo DNI\n");
                scanf("%f", &auxDni);
                while(validarDNI(alumno, auxDni, cantidad))
                    {
                        printf("reingrese su DNI\n");
                        scanf("%f", &auxDni);
                    }
                alumno[index].dni = auxDni;
                printf("ingrese el nuevo Nombre\n");
                fflush(stdin);
                gets(alumno[index].nombre);
                printf("ingrese el nuevo Apellido\n");
                fflush(stdin);
                gets(alumno[index].apellido);
                alumno[index].estaVacio=0;
                printf("Sus datos se modificaron correctamente\n");
                break;
            case 'n':
                break;
            default:
                printf("Debe Ingresar 's' o 'n'\n");
                break;
            }
            }else
            {
                printf("no se encontro al usuario\n");
            }
        }



int findByDNI(ePersona alumno[],int cantidad, int dni)
{
    int index=-1;
    for(int i=0;i<cantidad;i++)
        {
            if(alumno[i].dni==dni)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}

void removeStruct(ePersona alumno[], int cantidad)
{
    char decision;
    int index, dni;
    printf("Ingrese el DNI del usuario a dar de baja\n");
    scanf("%d", &dni);
    index=findByDNI(alumno, cantidad, dni);
    printf("Desea darle de baja a este usuario??\n");
    showStruct(alumno[index]);
    fflush(stdin);
    scanf("%c", &decision);printf("6-- salir\n");
    if(index!=-1)
    {
        switch(decision)
        {
            case 's':
                alumno[index].estaVacio=1;
                printf("Se dio de baja correctamente al usuario");
                break;
            case 'n':
            break;
            default:
                printf("Debe Ingresar 's' o 'n'\n");
            break;
        }
    }else
    {
        printf("no se encontro al usuario\n");
    }

}
