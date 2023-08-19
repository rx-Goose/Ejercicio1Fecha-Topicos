#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int d,m,a;
}Fecha;

Fecha sumarDiasAFecha(const Fecha *,int);
Fecha restarDiasAFecha(const Fecha *,int);
bool esBisiesto(int);
bool esFechaValida(Fecha *);
void mostrarFecha(const Fecha *);
void restaFechas(Fecha *, const Fecha *);
void ingresarFecha(Fecha *);
void queDiaEsFecha(int);
int cantDiaMes(int,int);
int ingresarEnteroPositivo();
int logicaDiaSemanal(const Fecha *);


//int cantidadAniosBis(const Fecha *);


#endif // FUNCIONES_H_INCLUDED
