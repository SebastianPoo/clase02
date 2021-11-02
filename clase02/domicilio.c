#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "domicilio.h"

void muestraUnDomicilio(stDomicilio d){
    printf("\nCalle y Numero...........: %s,%s", d.calle,d.nro);
    printf("\nCodigo Postal - Localidad: %s,%s", d.cpos,d.localidad);
    printf("\nProvincia................: %s", d.provincia);
    printf("\n---------------------------------------");
}



char* domicilioToString(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s, "\nId: %6d - Calle: %s - Nro: %s - Localidad: %s - Codigo Postal: %s - Provincia: %s", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
    return s;
}

char* domicilioToCsv(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s, "%6d; %s; %s; %s; %s; %s\n", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
    return s;
}

char* domicilioToJson(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s, "\n\t{\"id\":\"%6d\",\n\t\"Calle\":\"%s\",\n\t\"Nro\":\"%s\",\n\t\"Localidad\":\"%s\",\n\t\"Codigo Postal\":\"%s\",\n\t\"Provincia\":\"%s\"\n\t}", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
    return s;
}

stDomicilio addDomicilio(){
    static int id = 0;
    id++;
    stDomicilio d;
    d.id = id;
    strcpy(d.calle, "San Martin");
    strcpy(d.nro, "1256");
    strcpy(d.cpos, "7600");
    strcpy(d.localidad, "Mar del Plata");
    strcpy(d.provincia, "Buenos Aires");

    return d;
}
