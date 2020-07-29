#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicleta.h"
#include "Validaciones.h"


eBicicleta* bibicleta_new()
{
    eBicicleta* unaBici;

    return unaBici =(eBicicleta*)malloc(sizeof(eBicicleta));
}

eBicicleta* bicicleta_newParametros(char* idBk,char* nombre,char* tipo, char* tiempo)
{
    return bicicleta_newParametrosConvertido(atoi(idBk),nombre, tipo,atoi(tiempo));
}

eBicicleta* bicicleta_newParametrosConvertido(int id,char* nombre,char* tipo, int tiempo)
{
    eBicicleta* unaBici;
    unaBici = bibicleta_new();
    if(unaBici !=NULL)
    {
        if(!(bicicleta_setIdBike(unaBici, id)
                && bicicleta_setNombres(unaBici, nombre)
                && bicicleta_setTipo(unaBici, tipo)
                && bicicleta_setTiempo(unaBici, tiempo)))
        {
            free(unaBici);
            unaBici = NULL;
        }

    }
    return unaBici;
}


int bicicleta_setIdBike(eBicicleta* this,int idBK)
{
    int ret = 0;
    if(this!=NULL)
    {
        this->idBike = idBK;
        ret = 1;
    }
    return ret;
}



int bicicleta_setNombres(eBicicleta* this,char* nombre )
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        ret = 1;
    }
    return ret;
}


int bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(this->tipo,tipo);
        ret = 1;
    }
    return ret;
}


int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int ret = 0;
    if(this!=NULL)
    {
        this->tiempo = tiempo;
        ret = 1;
    }
    return ret;
}

int bicicleta_getIdBike(eBicicleta* this,int* idBk)
{
    int ret = 0;
    if(this!=NULL)
    {
        *idBk = this->idBike;
        ret = 1;
    }
    return ret;
}

int bicicleta_getNombre(eBicicleta* this,char* nombre)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        ret = 1;
    }
    return ret;
}

int bicicleta_getTipo(eBicicleta* this,char* tipo)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(tipo, this->tipo);
        ret = 1;
    }
    return ret;
}

int bicicleta_getTiempo(eBicicleta* this,int* tiempo)
{
    int ret = 0;
    if(this!=NULL)
    {
        *tiempo = this->tiempo;
        ret = 1;
    }
    return ret;
}

int bicicleta_mostrarUnaBici(eBicicleta* unaBici)
{
    int idBk;
    char nombre[50];
    char tipo[50];
    int tiempo;

    int retorno = -1;

    if(unaBici!=NULL)
    {
        bicicleta_getIdBike(unaBici,&idBk);
        bicicleta_getNombre(unaBici,nombre);
        bicicleta_getTipo(unaBici, tipo);
        bicicleta_getTiempo(unaBici, &tiempo);

        printf("%5d  %20s %15s %10d\n",idBk, nombre, tipo, tiempo);
        retorno = 1;
    }
    return retorno;
}

void* bicicleta_CargarDatos(void* unaBici)
{
    int aleatorio;

    eBicicleta* bici= NULL;

    bici = (eBicicleta*) unaBici;

    aleatorio = 50 + rand()%(121-50);

    bicicleta_setTiempo(bici, aleatorio);

    return bici;
}

int filtroPorTipo(void* unaBici)
{
    int auxReturn = 0;
    char tipo[50];
    char auxTipo[50];
    eBicicleta* aux = NULL;
    int retorno = 0;


    if(unaBici !=NULL)
    {
        aux = (eBicicleta*) unaBici;

        bicicleta_getTipo(aux, auxTipo);

        if(strcmp(tipo, auxTipo)== 0)
        {
            bicicleta_mostrarUnaBici(aux);
            retorno = 1;
        }
    }
    return retorno;
}

int bicicletas_OrdenarPorTipo(void* tipo1, void* tipo2)
{
    char bici1[128];
    char bici2[128];
    int ret = 0;
    int comparacion;

    if(tipo1 != NULL && tipo2 != NULL)
    {
        bicicleta_getTipo(tipo1, bici1);
        bicicleta_getTipo(tipo2, bici2);
        comparacion = strcmp(bici1, bici2);

        if(comparacion > 0)
        {
            ret = 1;
        }
        else if(comparacion < 0)
        {
            ret = -1;
        }
    }
    return ret;
}

int bicicletas_OrdenarPorTiempo(void* tiempo, void* tiempo2)
{
    int Bici1;
    int bici2;
    int ret = 0;

    if((tiempo != NULL) && (tiempo2 != NULL))
    {
        bicicleta_getTiempo(tiempo, &Bici1);
        bicicleta_getTiempo(tiempo2, &bici2);

        if(Bici1 > bici2)
        {
            ret = 1;
        }
        else if(Bici1 < bici2)
        {
            ret = -1;
        }
    }
    return ret;
}
int bicicleta_filtrarBMX(void* element)
{
    eBicicleta* bicicleta = NULL;
    char tipo[128];
    int retorno = -1;

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("BMX", tipo) == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}


int bicicleta_filtrarPlayera(void* element)
{
    eBicicleta* bicicleta = NULL;
    char tipo[128];
    int retorno = -1;

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("PLAYERA", tipo) == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int bicicleta_filtrarMTB(void* element)
{
    eBicicleta* bicicleta = NULL;
    char tipo[128];
    int retorno = -1;

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("MTB", tipo) == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int bicicleta_filtrarPaseo(void* element)
{
    eBicicleta* bicicleta = NULL;
    char tipo[128];
    int retorno = -1;

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("PASEO", tipo) == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

