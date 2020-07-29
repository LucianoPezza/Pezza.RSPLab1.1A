#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Bicicleta.h"
#include "Validaciones.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE*pFile;
    int retorno = -1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_BicicletaFromText(pFile, pArrayListEmployee))
            {
                printf("\nArchivo cargado exitosamente\n");
                system("pause");
                system("cls");
                retorno = 1;
            }
            else
            {
                printf("\nNo se pudo asignar me moria para abrir el archivo.\n");
                system("pause");
                system("cls");
            }
        }
        else
        {
            printf("\nError al cargar el archivo");
        }
        fclose(pFile);
    }


    return retorno;
}

int controller_ListBicis(LinkedList* pArrayListEmployee)
{
    eBicicleta* unaBici;
    int tamanio;
    int flag = 0;
    int retorno = -1;

    if(pArrayListEmployee!=NULL)
    {
        tamanio = ll_len(pArrayListEmployee);
        printf(" IdBike----------------Nombre---------Tipo-------Tiempo\n");
        for(int i=0; i<tamanio; i++)
        {
            unaBici =(eBicicleta*) ll_get(pArrayListEmployee, i);
            if(unaBici !=NULL)
            {
                bicicleta_mostrarUnaBici(unaBici);
                flag = 1;
            }
        }
        retorno = 1;
        if(flag == 0)
        {
            printf("\nNo hay bicis cargados.\n");
        }
    }
    else
    {
        printf("\nLos datos no se pudieron mostrar\n");
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    eBicicleta* unaBici;
    FILE* pFile = fopen(path, "w");
    int tam = ll_len(pArrayListEmployee);
    int ret = -1;
    int idBIKE;
    char nombre[128];
    char tipo[128];
    int tiempo;


    if(pFile == NULL)
    {
        printf("\n\nError al guardar el archivo\n\n");
    }

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            fprintf(pFile, "id,nombre,tipo,tiempo\n");

            for(int i=0; i<tam; i++)
            {
                unaBici = (eBicicleta*)ll_get(pArrayListEmployee, i);

                bicicleta_getIdBike(unaBici,&idBIKE);
                bicicleta_getNombre(unaBici,nombre);
                bicicleta_getTipo(unaBici, tipo);
                bicicleta_getTiempo(unaBici,&tiempo);
                fprintf(pFile, "%d,%s,%s,%d \n",idBIKE,nombre,tipo,tiempo);
            }
            printf("\n\nArchivos exitosamente cargados\n\n");
        }
    }
    else
    {
        printf("\n\nNo se cargaron los datos\n\n");
    }
    fclose(pFile);

    return ret;
}

