#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "autoCargaEmpleado.h"



int getId(){
    static int id=0;
    id++;
    return id;
}

int getlegajo(){
        static int legajo=1000;
        legajo++;
        return legajo;
}


char *getNro (){
    char *nro=(char*)malloc(sizeof(char)*5);
    itoa(rand()%10000,nro,10);
    return nro;
}

char *getNroDni (){
    char *nro=(char*)malloc(sizeof(char)*9);
    int dniAle=1;

    for (int i=0;i<7;i++)
    {
        if (i<2)
        {
        dniAle=dniAle+(rand()%2);
        dniAle=dniAle*10;
        }
        else
        {
          dniAle=dniAle+(rand()%9);
        dniAle=dniAle*10;
        }

    }
    itoa(dniAle,nro,10);
    return nro;
}

char *getCargo(){
        char *cargo= (char*)malloc(sizeof(char)*22);
        char cargos[][22]={"Developer","Developer Full Stack","Developer Front-End","Developer Java","Developer Back End","Developer C"};
        strcpy(cargo, cargos[rand()%(sizeof(cargos)/22)]);
        return cargo;
}

char *getNombresMascu(){
        char *nombre= (char*)malloc(sizeof(char)*30);
        char nombres[][30]={"Jorge","Sebastian","Javier","Leonel","Esteban","Gaspar","Jesus","Ramon","Cristian","Facundo","Omar","Marcelo","Tomas","Matias","Osvaldo","Enrrique","Carlos","Hernan","Miguel","Ruben", "Federico", "Gustavo","Fabian","Ezequiel","Rafael","Pablo"};
        strcpy(nombre, nombres [rand()%(sizeof(nombres)/30)]);
        return nombre;
}

char *getNombreFeme(){
        char *nombre= (char*)malloc(sizeof(char)*30);
        char nombres[][30]={"Cintia","Candela","Sophya","Rocio","Nansi","Florencia","Jorgelina","Ambar","Estela","Marcela","Nelida","Maria", "Vanesa","Soledad", "Paola", "Paula", "Patricia","Noelia","Adriana","Pilar","Romina", "Esmeralda", "Lorena", "Gabriela", "Alejandra"};
        strcpy(nombre, nombres [rand()%(sizeof(nombres)/30)]    );
        return nombre;
}


char *getApellidos(){
        char *apellido= (char*)malloc(sizeof(char)*30);
        char apellidos[][30]={"Palma","Messi","Roqueet","Montero","Fernadez","Piñero","Morales","Socorro","Govea","Morillo","Atencio","Bermudez","Cruz","Rincon","Lisboa","Rivera","Quivera","Avila","Bravo","Ramos","Taborda","lubo","Urdaneta","Landino","Garcia","Andrade","Vargas"};
        strcpy(apellido,apellidos[rand()%(sizeof(apellidos)/30)]);
        return apellido;
}

char *getCalle(){
    char *calle = (char*)malloc(sizeof(char)*30);
    char calles[][30]={"San Lorenzo","Rivadavia","Roca","Don Orione","Av. Constitucion","Av. Jara", "Av. Luro", "Av. Colon", "Alem"};

    strcpy(calle, calles[rand()%(sizeof(calles)/30)]);
    return calle;
}
char *getCalleArreglo(char arreglo[1001][30], int v){
    char *calle = (char*)malloc(sizeof(char)*30);
    strcpy(calle, arreglo[rand()%v]);

    return calle;
}

char *getCalleBisArchivo(){
    char *calle = (char*)malloc(sizeof(char)*30);
    char calles[1001][30];
    int v=0;

    v = csv2arreglo(30, "mocks/callesMarDelPlata.csv", calles, 1001);

    strcpy(calle, calles[rand()%v]);

    return calle;
}

char *getNombreArchivo(){
    char *nombre = (char*)malloc(sizeof(char)*30);
    char nombres[1000][30];
    int v=0;

    v = csv2arregloBis(30, "mocks/nombres.csv", nombres, 1000);

    strcpy(nombre, nombres[rand()%v]);

    return nombre;
}

char *getApellidoArchivo(){
    char *apellido = (char*)malloc(sizeof(char)*30);
    char apellidos[1001][30];
    int v=0;

    v = csv2arregloBis(30, "mocks/apellidos.csv", apellidos, 1000);

    strcpy(apellido, apellidos[rand()%v]);

    return apellido;
}

int csv2arreglo(int col, char archivo[], char n[][col], int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while(fgets(n[i], col, archi)){
            n[i][strlen(n[i])-1] = '\0';
            i++;
        }
        fclose(archi);
    }
    return i;
}

int csv2arregloBis(int col, char archivo[], char n[][col], int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while((fscanf(archi, "%s",&n[i])==1) && (i<dim)){
            i++;
        }
        fclose(archi);
    }
    return i;
}

void cargaArchivoEmpleados( char archivo[], int cantidad){
    stEmpleado e;
    int i=0;
     FILE *archi=fopen(archivo, "wb");
     if (archi){
        while(i<cantidad){
                e=cargaUnEmpleado();
                fwrite(&e,sizeof(stEmpleado),1,archi);
                i++;
        }
        fclose(archi);
     }
}

void muestraArchivoEmpleado( char archivo[]){
    stEmpleado e;
    FILE *archi=fopen(archivo,"rb");
    if(archi){
        while(fread(&e,sizeof(stEmpleado),1,archi)>0){
            muestraUnEmpleado(e);
        }
    }
}

void archivoCreado(char archivo[])
{
   stEmpleado e;
    FILE *archi=fopen(archivo,"rb");
    if(archi)
    {
        printf("\nArchivo creado exitosamente");
    }
}
/***int empleadosCsv2arrV2(char archivo[], stEmpleado e[]){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while(fscanf(archi, "%d,%[^,],%d,%d", &e[i].legajo, e[i].nombreApellido, &e[i].edad, &e[i].idDepartamento) == 4){
            muestraUnEmpleado(e[i]);
            i++;
        }
        fclose(archi);
    }
    return i;
}
*/

///ver cara que esta funcion//
int palindromo(char arr[],int val){
    int i=0;
    int ul=val-1;
    int flag=1;
    while(i<ul && flag==1){
        if(arr[ul]!=arr[i]){
            flag=0;
        }
        i++;
        ul--;
    }
    return flag;
}

int cuentaGenero(stEmpleado e[], int v, char genero){
    int i=0;
    int cant=0;
    for(i=0; i<v; i++){
        if(e[i].persona.genero==genero){
            cant++;
        }
    }
    return cant;
}

void arreglo2Arreglo (stEmpleado **z, int *k,stEmpleado e[],int v,char genero){
   int i=0;
   int cantGenero=cuentaGenero(e,v,genero);
    (*z)=(stEmpleado*)malloc(sizeof(stEmpleado)* cantGenero);
       while (i<v){
        if(e[i].persona.genero==genero){
            (*z)[*k]=e[i];
            (*z++);
        }
       }
}

int eliminoDatoArray(int a[], int v, int nro){
    for(int i=0; i<v; i++){
        if(a[i]==nro){
            for(int j=i; j<v; j++){
                a[j]=a[j+1];
            }
            v--;
        }
    }
    return v;
}


