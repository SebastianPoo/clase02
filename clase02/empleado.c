#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "empleado.h"

void muestraUnEmpleado(stEmpleado e)
{

    printf("\n\t\tId de empleado.......:%6d", e.id);
    printf("\nLegajo...............:%6d", e.legajo);
    printf("\nCargo................:%6s",e.cargo);
    printf("\n\n\tDatos personales\n");
    muestraUnaPersona(e.persona);
    printf("\n   \t     Domicilio Laboral\n");
    muestraUnDomicilio(e.domicilioLaboral);
    printf("\n-----------------------------------");
}

stEmpleado cargaUnEmpleado()
{
    stEmpleado e;
    static int id=0;
    id++;
    e.id = id;
    e.legajo = getlegajo();
    strcpy(e.cargo, getCargo());
    strcpy(e.persona.dni, getNroDni());
    e.persona.genero = rand()%2;
    if (e.persona.genero==0)
    {
        strcpy(e.persona.nombre, getNombresMascu());
    }
    else
    {
        strcpy(e.persona.nombre, getNombreFeme());
    }
    strcpy(e.persona.apellido, getApellidos());
    strcpy(e.persona.domicilio.calle, getCalle());
    strcpy(e.persona.domicilio.nro, getNro());
    strcpy(e.persona.domicilio.cpos, "7600");
    strcpy(e.persona.domicilio.localidad, "Mar del Plata");
    strcpy(e.persona.domicilio.provincia, "Buenos Aires");
    strcpy(e.domicilioLaboral.calle, getCalleBisArchivo());
    strcpy(e.domicilioLaboral.nro, getNro());
    strcpy(e.domicilioLaboral.cpos, "7600");
    strcpy(e.domicilioLaboral.localidad, "Mar del Plata");
    strcpy(e.domicilioLaboral.provincia, "Buenos Aires");

    return e;

}
