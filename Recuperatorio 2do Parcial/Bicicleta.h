#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int idBike;
    char nombre[128];
    char tipo[128];
    int tiempo;

}eBicicleta;

eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametrosConvertido(int id,char* nombres,char* tipos, int tiempo);
eBicicleta* bicicleta_newParametros(char* idStr,char* nombres,char* tipos, char* tiempo);

int bicicleta_mostrarUnaBici(eBicicleta*);
void* bicicleta_CargarDatos(void*);
int filtroPorTipo(void*);
int bicicletas_OrdenarPorTipo(void* tipo1, void* tipo2);
int bicicletas_OrdenarPorTiempo(void* tiempo, void* tiempo2);
int bicicleta_filtrarBMX(void* element);
int bicicleta_filtrarPlayera(void* element);
int bicicleta_filtrarMTB(void* element);
int bicicleta_filtrarPaseo(void* element);

////////// setters
int bicicleta_setIdBike(eBicicleta* this,int);
int bicicleta_setNombres(eBicicleta* this,char*);
int bicicleta_setTipo(eBicicleta* this,char*);
int bicicleta_setTiempo(eBicicleta* this,int);

/////////// getters
int bicicleta_getIdBike(eBicicleta* this,int* );
int bicicleta_getNombre(eBicicleta* this,char* );
int bicicleta_getTipo(eBicicleta* this,char* );
int bicicleta_getTiempo(eBicicleta* this,int* );
////////////////////


#endif // BICICLETA_H_INCLUDED
