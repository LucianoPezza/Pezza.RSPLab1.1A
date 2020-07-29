#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicleta.h"


int parser_BicicletaFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    eBicicleta* auxBici=NULL;
    int retorno = -1;
    char auxId[50];
    char auxNombre[128];
    char auxTipo[50];
    char auxTiempo[50];

    int r;

    if(pFile != NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxTipo, auxTiempo);
        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxTipo, auxTiempo);
            if(r == 4)
            {
                auxBici = bicicleta_newParametros(auxId, auxNombre, auxTipo, auxTiempo);
                if(auxBici!=NULL)
                {
                   ll_add(pArrayListEmployee, auxBici);
                    retorno = 1;
                }
            }else
            {
                break;
            }
        }
    }
    return retorno;
}
