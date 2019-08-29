#include <stdio.h>
#include <stdlib.h>
void saludar();
int pedirDatos();
void mostrar(float respuesta);
float promediar(int sumaAPromediar, int cantidadDeElementos);
float sumar(int numero1, int numero2);
float restar(int numero1, int numero2);
float multiplicar(int numero1, int numero2);
float dividir(int numero1, int numero2);
void calcular(int num1, int num2, int operacion);
int main()
{
    float promedio;
    int valor;
    int numeroUno;
    int numeroDos;
    int operacion;
    numeroUno=pedirDatos();
    numeroDos=pedirDatos();
    operacion=pedirDatos();
    saludar();
    valor=sumar(33,77);
    calcular(numeroUno, numeroDos, operacion);
    promedio = promediar(22,3);
    printf("suma %d\n %f", valor, promedio);
    return 0;
}
void saludar()
{
    printf("Hello world!\n");
}
float resta(int numero1, int numero2)
{
    return (float)numero1-numero2;
}
float multiplicar(int numero1, int numero2)
{
    return (float)numero1*numero2;
}
float sumar(int numero1, int numero2)
{
    return (float)numero1+numero2;
}
float dividir(int numero1, int numero2)
{
    return (float)numero1/numero2;
}
void calcular(int num1, int num2, int operacion)
{
    float resultado;
    switch(operacion)
    {
        case 1:
            resultado = sumar(num1, num2);
            break;
        case 2:
            resultado = resta(num1,num2);
            break;
        case 3:
            resultado = multiplicar(num1, num2);
            break;
        case 4:
            resultado = dividir(num1, num2);
            break;
        }
        mostrar(resultado);
}
float promediar(int sumaAPromediar, int cantidadDeElementos)
{
    float resultado;
    resultado=(float)sumaAPromediar/cantidadDeElementos;
    return resultado;
}
void mostrar(float respuesta)
{
    printf("\n %f \n", respuesta);
}
int pedirDatos()
{
    int numero;
    printf("Ingrese un numero\n");
    scanf("%d", &numero);
    return numero;
}
