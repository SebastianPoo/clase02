#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"
#include "persona.h"
#include "empleado.h"
#include <time.h>
#include "autoCargaEmpleado.h"

#include "listaEmpleados.h"
#include "listaDobleEmpleados.h"
#include "pilaEmpleado.h"

int main(int argc, char *argv[])
{
    int selected;
    char calles[1001][30];
    int vCalles;
    srand(time(NULL));
    stEmpleado empleado;
    nodo* lista = inicLista();
    nodo* nuevo = inicLista();
    nodoDoble* listaDoble = inicListaDoble();
    nodoDoble* nuevoDoble = inicListaDoble();
     char n[20];
    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            vCalles = csv2arreglo(30, "mocks/callesMarDelPlata.csv", calles, 1000);
            cargaArchivoEmpleados("archiAlumnos",100);
            archivoCreado("archiAlumnos");
            printf("\n");
            system("pause");
            break;
        case 2:
            muestraArchivoEmpleado("archiAlumnos");
            printf("\n");
            system("pause");
            break;
        case 3:
            nuevo=crearNodo(cargaUnEmpleado());
            lista=agregarAlPrincipio(lista,nuevo);
            printf("\n");
            system("pause");
            break;
        case 4:
            printf("\n Muestra lista");
            mostrarLista(lista);
            printf("\n");
            system("pause");
            break;
        case 5:
            printf ("\nIngrese un apellido a buscar\n");
            fflush(stdin);
            gets(n);
            nodo* nodoEmpleado = buscaEmpleado(lista,n);
            if (nodoEmpleado)
            {
                muestraUnNodo(nodoEmpleado);
            }
            else
            {
                printf("\tEl apellido no existe ");
            }

            printf("\n");
            system("pause");
            break;
        case 6:
            printf("\n\tDato del nodoEmpleado");

            if (nodoEmpleado!=NULL)
            {
                muestraUnEmpleado(nodoEmpleado->dato);
            }
            else
            {
                printf("\tEl apellido no existe ");
            }


            printf("\n");
            system("pause");
            break;
        case 7:
            nuevoDoble=crearNodoDoble(cargaUnEmpleado());
            listaDoble=agregarAlPrincipioDoble(listaDoble,nuevoDoble);
            printf("\n");
            system("pause");
            break;
        case 8:
           printf("\n Muestra lista Doble\n");
            mostrarListaDobleConPuntero(listaDoble);
            printf("\n");
            system("pause");
            break;
        case 9:
            funcion_x();
            break;
        case 10:
            funcion_x();
            break;
        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");

            break;
        }

    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}
int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-CREA ARCHIVO DE EMPLEADOS");
    printf("\n2-MUESTRA LOS EMPLEADOS DEL ARCHIVO");
    printf("\n3-CREA LISTA Y AGREGA AL PRINCIPIO");
    printf("\n4-MUESTRA LAS LISTA");
    printf("\n5-BUSCA NODO POR APELLIDO");
    printf("\n6-DATO DEL NODO BUSCADO");
    printf("\n7-CREA NODO DOBLE");
    printf("\n8-MUESTRA LISTA DOBLE");
    printf("\n9-Calcula promedio de una pila (usa funcion de suma, division y cuenta)");
    printf("\n10-Recibe pila con numeros de un digito y los transforma en un numero decimal");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}
funcion_x()
{
    system("cls");
    system("color 1E");
    printf("\n\naca deberia estar la funcion pedida en cada ejercicio de la practica\n");
    system("PAUSE");
}











