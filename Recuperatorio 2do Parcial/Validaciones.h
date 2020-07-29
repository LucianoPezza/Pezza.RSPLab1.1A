#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int getInti(char[]);
int getINT(int);
int getint(char[], char[]);
int getInt(char mensaje[], char mensajeError[]);
int getEdad();
int nombresValidos(char[]);
int nombresValidosFueraDeConsola(char*);
void getNombreArchivo(char [], char[] , char[]);
int letraValida(char);
char getLetra(char[], char[]);
void getnombre(char [],char [], char []);
int getSexo(char[]);
int getDia(char mensaje[], char mensajeError[]);
int getMes(char mensaje[], char mensajeError[]);
int getAnio(char mensaje[], char mensajeError[]);
void gotFecha(int*, int*, int*);
int getIdServicio();
int getIdTipo();
int getId();
int getIdMarca();
int getPrecio();
int getIdCliente();
float getFloat(char[]);

#endif // VALIDACIONES_H_INCLUDED
