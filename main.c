#include "Funciones.h"

int main()
{
    Fecha fInicio,fDiaDeSemana,fSuma,fARestar,fResta,fFechaInicial,fRestado;

    puts("\n Punto Clase. \n");
    ingresarFecha(&fInicio);    //Manda direccion del struct

    int dias = ingresarEnteroPositivo();
    fSuma = sumarDiasAFecha(&fInicio,dias);

    mostrarFecha(&fSuma);

    puts("\n Punto 1. \n");

    ingresarFecha(&fARestar);
    ingresarFecha(&fResta);

    restaFechas(&fARestar, &fResta);


    puts("\n Punto 2. \n");

    ingresarFecha(&fDiaDeSemana);

    int diaSemana = logicaDiaSemanal(&fDiaDeSemana);

    queDiaEsFecha(diaSemana);

    puts("\n Punto 3. \n");

    ingresarFecha(&fFechaInicial);
    int diasARestar = ingresarEnteroPositivo();

    fRestado = restarDiasAFecha(&fFechaInicial,diasARestar);

    mostrarFecha(&fRestado);

    return 0;
}

