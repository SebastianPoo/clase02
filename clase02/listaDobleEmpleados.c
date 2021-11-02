#include "stdio.h"
#include "stdlib.h"
#include "listaDobleEmpleados.h"
#include "persona.h"
#include "empleado.h"


nodoDoble* inicListaDoble()
{
    return NULL;
}

void muestraUnNodoDoble(nodoDoble* nodo)
{
    muestraUnEmpleado (nodo->dato);
}

nodoDoble* crearNodoDoble(stEmpleado dato)
{
    nodoDoble* nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    nuevoNodo->siguiente = lista;

    return nuevoNodo;
}

void mostrarListaDoble(nodoDoble* lista)
{
    nodoDoble* seg = lista;
    while(seg!=NULL)
    {
        muestraUnEmpleado(seg->dato);
        seg = seg->siguiente;
    }
}

void mostrarListaDobleConPuntero(nodoDoble* lista)
{
    nodoDoble* seg = lista;
    while(seg!=NULL)
    {

        printf("\n<---anterior--->%p-<---Actual--->%p-<--Siguiente--->%p",seg->anterior,seg,seg->siguiente);

        seg = seg->siguiente;
    }
}
