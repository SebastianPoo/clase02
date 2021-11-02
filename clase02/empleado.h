#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "persona.h"


typedef struct{
    int id;
    int legajo;
    char cargo[22];
    stPersona persona;
    stDomicilio domicilioLaboral;
}stEmpleado;

void muestraUnEmpleado(stEmpleado e);
stEmpleado cargaUnEmpleado();


#endif // EMPLEADO_H_INCLUDED
