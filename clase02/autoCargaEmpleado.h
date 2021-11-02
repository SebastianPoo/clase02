#ifndef AUTOCARGAEMPLEADO_H_INCLUDED
#define AUTOCARGAEMPLEADO_H_INCLUDED

#include "empleado.h"


int getId();
int getlegajo();
char* getCargo();
char *getNro ();
char *getNroDni ();
char *getNombresMascu();
char *getNombreArchivo();
char* getNombreFeme();
char *getApellidos();
char *getCalleBisArchivo();
char *getCalleArreglo(char arreglo[1001][30], int v);
char *getNombreArchivo();
char *getApellidoArchivo();
void archivoCreado(char archivo[]);
void muestraArchivoEmpleado( char archivo[]);
void cargaArchivoEmpleados( char archivo[], int cantidad);
int csv2arregloBis(int col, char archivo[], char n[][col], int dim);
int csv2arreglo(int col, char archivo[], char n[][col], int dim);


#endif // AUTOCARGAEMPLEADO_H_INCLUDED
