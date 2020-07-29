#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Validaciones.h"
#include "Bicicleta.h"
#include <time.h>

int main()
{
    srand (time(NULL));
    int option;
    int opcionFiltrada;
    char input[50];
    LinkedList* listaSinDatos = ll_newLinkedList();
    LinkedList* listaConDatos = NULL;
    LinkedList* listaFiltrada = NULL;


    do
    {
        printf("\n1.Para cargar los datos por texto\n2.Mostrar Bicis(primero cargar los tiempos)\n3 Asignar Tiempo\n4.Filtrar por tipos\n5.Mostrar posiciones\n6.Guardar posiciones\n7.Salir\n");
        option = getInt("Ingrese una opcion: ","Error. Solo puede ingresar numeros: ");
        switch(option)
        {
        case 1:
            printf("Ingrese el archivo(bicicletas.csv): ");
            scanf("%s", input);
            controller_loadFromText(input,listaSinDatos);
            break;
        case 2:
            controller_ListBicis(listaSinDatos);
            system("pause");
            system("cls");
            break;

        case 3:
            listaConDatos = ll_map(listaSinDatos, bicicleta_CargarDatos);
            printf("Datos cargados.\n\n");
            controller_ListBicis(listaConDatos);
            system("pause");
            system("cls");
            break;
        case 4:
            printf("\n1.Para mostrar BMX\n2.para mostrar PLAYERA\n3 para mostrar MTB\n4.para mostrar PASEO\n");
            opcionFiltrada = getInt("Ingrese una opcion: ","Error. Solo puede ingresar numeros: ");
            switch(opcionFiltrada)
            {

            case 1:
                listaFiltrada = ll_filtrer(listaSinDatos,bicicleta_filtrarBMX);
                controller_ListBicis(listaFiltrada);
                controller_saveAsText("Bmx.csv", listaFiltrada);
                break;
            case 2:
                listaFiltrada = ll_filtrer(listaSinDatos,bicicleta_filtrarPlayera);
                controller_ListBicis(listaFiltrada);
                controller_saveAsText("Playera.csv", listaFiltrada);
                break;
            case 3:
                listaFiltrada = ll_filtrer(listaSinDatos,bicicleta_filtrarPaseo);
                controller_ListBicis(listaFiltrada);
                controller_saveAsText("Paseo.csv", listaFiltrada);
                break;
            case 4:
                listaFiltrada = ll_filtrer(listaSinDatos,bicicleta_filtrarMTB);
                controller_ListBicis(listaFiltrada);
                controller_saveAsText("MTB.csv", listaFiltrada);
                break;
            }
            break;
        case 5:
            ll_sort(listaConDatos, bicicletas_OrdenarPorTipo, 1);
            ll_sort(listaConDatos, bicicletas_OrdenarPorTiempo,1);
            controller_ListBicis(listaConDatos);
            system("pause");
            system("cls");
            break;
        case 6:
            controller_saveAsText("listaOrdenadaPorTipoYTiempo.csv", listaConDatos);
            break;
            case 7:
            option = 10;
            break;
        }

    }
    while(option != 10);

    return 0;
}
