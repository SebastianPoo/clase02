#include "stdio.h"
#include "stdlib.h"
#include "listaEmpleados.h"
#include "persona.h"
#include "empleado.h"


nodo* inicLista()
{
    return NULL;
}

void muestraUnNodo(nodo* nodo){
    muestraUnEmpleado(nodo->dato);
}

nodo* crearNodo(stEmpleado dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo)
{
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

void mostrarLista(nodo* lista)
{
    nodo* seg = lista;
    while(seg!=NULL)
    {
        muestraUnEmpleado(seg->dato);
        seg = seg->siguiente;
    }
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo* ultimo = buscaUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

nodo* buscaUltimo(nodo* lista)
{
    nodo* seg = lista;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg;
}

int cuentaLista(nodo* lista)
{
    int cont=0;
    nodo* seg = lista;
    while(seg!=NULL)
    {
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}


nodo* buscaEmpleado(nodo* lista, char apellido[])
{
    nodo* seg = lista;

    while(seg!=NULL && strcmp(seg->dato.persona.apellido,apellido)!=0)
    {
        seg = seg->siguiente;
    }

    return seg;
}

nodo* agregarEnOrdenPorLegajo(nodo* lista, nodo* nuevoNodo)
{
    if (!lista)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.legajo<lista->dato.legajo)
        {
            lista=agregarAlPrincipio(lista,nuevoNodo);
        }
        else
        {
            nodo* ante=lista;
            nodo* seg= lista->siguiente;
            while(seg!=NULL && nuevoNodo->dato.legajo>seg->dato.legajo)
            {
                ante=seg;
               seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }
    }
         return  lista;
}
