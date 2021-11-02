#ifndef LISTADOBLEEMPLEADOS_H_INCLUDED
#define LISTADOBLEEMPLEADOS_H_INCLUDED
#include "persona.h"
#include "empleado.h"

typedef struct _nodoDoble
{
    stEmpleado dato;
    struct _nodoDoble*siguiente;
    struct _nodoDoble*anterior;
}nodoDoble;

nodoDoble* inicListaDoble();
nodoDoble* crearNodoDoble(stEmpleado e);
nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
void muestraUnNodoDoble(nodoDoble* nodo);
void mostrarListaDoble(nodoDoble* lista);
void mostrarListaDobleConPuntero(nodoDoble* lista);


#endif // LISTADOBLEEMPLEADOS_H_INCLUDED
