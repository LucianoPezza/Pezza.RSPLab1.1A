#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Validaciones.h"

int getInt(char mensaje[], char mensajeError[])
{
    char auxiliarChar[20];
    int enteroADevolver;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", auxiliarChar);
    enteroADevolver = atoi(auxiliarChar);

    while(getInti(auxiliarChar)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%s", auxiliarChar);
        enteroADevolver = atoi(auxiliarChar);
    }


    return enteroADevolver;
}

void getNombreArchivo(char mensaje[], char mensajeError[], char input [])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);

    strlwr(input);
    input[0] = toupper(input[0]);
    while(nombresValidos(input)!= 1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(input);
        input[0] = toupper(input[0]);
    }
    if(!(strcmp(input,"pandemia.csv")))
    {
        printf("Error. Reingrese el nombre del archivo (pandemia.csv)");
    }
}
int getInti(char str[])
{
    int retorno = 1;
    for(int i =0; str[i]!='\0'; i++)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getINT(int numerote)
{
    int retorno = -1;
    char* auxiliarCharr;

    for(int i =0; auxiliarCharr[i]!='\0'; i++)
    {
        if(auxiliarCharr[i]<'0' || auxiliarCharr[i]>'9')
        {
            numerote = atoi(auxiliarCharr);
            retorno = 0;
            break;
        }
    }
    return retorno;
}

void getnombre(char mensaje[],char mensajeError[], char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);

    strlwr(input);
    input[0] = toupper(input[0]);
    while(nombresValidos(input)!= 1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(input);
        input[0] = toupper(input[0]);
    }

}

int letraValida(char letra)
{
    int retorno = 1;
    if(letra <'A' || (letra>'Z' && letra<'a') || letra>'z')
    {
        retorno = 0;
    }
    return retorno;
}
char getLetra(char mensaje[], char mensajeError[])
{
    char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);

    while(letraValida(letra)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &letra);

    }
    return letra;
}

int nombresValidos(char str[])
{
    int retorno = 1;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]<'A' || (str[i]>'Z' && str[i]<'a') || str[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int nombresValidosFueraDeConsola(char* cadena)
{
    int retorno = 1;
    for(int i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]<'A' || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

float getFloat(char mensaje[])
{
    char auxiliarChar[10];
    float floatADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    floatADevolver = atof(auxiliarChar);

    while(floatADevolver == 0)
    {
        printf("%s", "Error. Ingrese un numero decimal valido\n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        floatADevolver = atof(auxiliarChar);
    }


    return floatADevolver;

}

int getSexo(char mensaje[])
{
    /*char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);
    while(!(isalpha(letra)))
    {
        printf("Error. Introduzca solo 1 caracter");
        scanf("%c", &letra);
    }*/
    char sexo;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &sexo);
    sexo = toupper(sexo);
    while(sexo != 'F' && sexo != 'M')
    {
        printf("Error. Introduzca los caracteres validos F/M: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = toupper(sexo);
    }
    return sexo;
}

int getEdad(char mensaje[], char mensajeError[])
{
    int edad;
    edad = getInt("Ingrese edad: ", "Error. Ingrese numeros: ");

    while(edad >= 100 || edad<= 0)
    {
        edad = getInt("Error. Ingrese una edad valida (entre 1 y 99 años): ","Solo numeros");
    }
    return edad;
}

void gotFecha(int* dia, int* mes, int* anio)
{
    *mes = getInt("Ingrese mes: ","Error. solo puede ingrese numeros: ");
    while(*mes < 1 || *mes > 12)
    {
        *mes = getInt("Error. Solo puede ingresar los meses validos 1-12: ","Error. solo puede ingrese numeros: ");
    }
    *dia =getInt("Ingrese dia: ", "Error. solo puede ingresar numeros: ");

    if(*mes == 1 || *mes ==3 || *mes == 5 || *mes ==7 || *mes ==8 || *mes == 10 || *mes == 12)
    {
    while(*dia < 1 || *dia > 31)
    {
        *dia = getInt("Error. Solo puede ingresar los dias validos 1-31: ","Error. Solo ingrese numeros: ");
    }
    }else if(*mes ==4 || *mes == 6 || *mes == 9 || *mes == 11)
    {
        while(*dia < 1 || *dia >30)
        {
            *dia = getInt("Error. Solo puede ingresar los dias validos 1-30: ","Error. Solo ingrese numeros: ");
        }
    }else
    {
        while(*dia < 1 || *dia >28)
        {
            *dia = getInt("Error. Solo puede ingresar los dias validos 1-28: ","Error. Solo ingrese numeros: ");
        }
    }
    *anio = getInt("Ingrese anio: ", "Error. Solo ingrese numeros: ");
    while(*anio < 1982 || *anio > 2020)
    {
        *anio = getInt("Error. Solo puede ingresar los anios validos 1982-2020): ","Error. Solo ingrese numeros: ");
    }

}
int getIdMarca()
{
    int idMarca;
    idMarca = getInt("Ingrese el id de la marca: ", "Error. solo numeros1");
    while(idMarca > 1003 || idMarca < 1000)
            {
                idMarca= getInt("Ingrese solo los ID correctos: 1000 a 1003: ","Error. Solo ingrese numeros: ");
            }
    return idMarca;
}
int getIdTipo()
{
    int tipoId;
   tipoId = getInt("Ingrese el id del tipo: ", "Error. Ingrese solo numeros: ");
      while(tipoId > 5003 || tipoId < 5000)
            {
                tipoId = getInt("Ingrese solo los ID correctos: 5000 a 5003: ", "Error. Solo ingrese numeros: ");
            }
    return tipoId;
}
int getId()
{
    int idx;
    idx =getInt("Ingrese Id: ","Error. Solo ingrese numeros: ");
        while(idx> 99 || idx < 1)
        {
            idx =getInt("Error. ingrese Id valida entre 1 y 100: ","Error. Solo ingrese numeros: ");
        }
     return idx;
}
int getPrecio()
{
    int precio;
    precio = getInt("Ingrese el precio: ", "Error. Ingrese solo numeros: ");
    while(precio > 80000 || precio < 5000)
    {
        precio = getInt("Ingrese un precio adecuado (Precio minimo: 5000 - Precio Maximo: 80000 )","Error. Solo ingrese numeros: ");
    }

    return precio;
}
int getIdServicio()
{
    int servicio;
    servicio = getInt("\nIngrese el id del servicio que quiera: ","Error. Solo ingrese numeros: ");
            while(servicio> 20003 || servicio < 20000)
            {
                servicio= getInt("\nIngrese solo los ID correctos: 20000 a 20003: ","Error. Solo ingrese numeros: ");
            }

    return servicio;
}
int getIdCliente()
{
    int idC;
    idC = getInt("Ingrese el IdCliente que desee: ", "Error. Ingrese solo numeros: ");
    while(idC > 703 || idC < 700)
    {
        idC = getInt("Ingrese el IdCliente adecuado Entre 700 y 703: ","Error. Solo ingrese numeros: ");
    }

    return idC;
}
