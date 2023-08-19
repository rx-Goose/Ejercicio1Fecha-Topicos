#include "Funciones.h"

void ingresarFecha(Fecha *x)
{
    puts("Ingrese una fecha (d/m/a).");
    scanf("%d/%d/%d",&x->d,&x->m,&x->a);
    while(!esFechaValida(x))
    {
        puts("Ingrese una fecha (d/m/a).");
        scanf("%d/%d/%d", &x->d, &x->m, &x->a);
    }
}

bool esFechaValida(Fecha *fecha) //"*" indica que va a ser un puntero.
{
    if(fecha->a>=1601 && (fecha->m>=1 && fecha->m<=12)&& (fecha->d>=1 && fecha->d<=cantDiaMes(fecha->m,fecha->a)))
            return true;
    return false;
}

bool esBisiesto(int anio)
{
    return anio % 4 == 0 && (anio % 100 != 0 ||  anio % 400 == 0);
}

int cantDiaMes(int m, int a)//08 2023
{
    int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && esBisiesto(a))
        return 29;
    return dm[m];
}

Fecha sumarDiasAFecha(const Fecha *f, int dias)
{
    int cdm;
    Fecha fechaFinal = *f;

    fechaFinal.d += dias;

    while(fechaFinal.d>(cdm = cantDiaMes(fechaFinal.m,fechaFinal.a)))
    {
        fechaFinal.d -= cdm;
        fechaFinal.m ++;

        if(fechaFinal.m>12)
        {
            fechaFinal.m=1;
            fechaFinal.a++;
        }
    }
    return fechaFinal;
}

int ingresarEnteroPositivo()
{
    int entero=1;
    do{
        if(entero<=0)
            puts("No es un ingreso valido.");
        puts("Ingrese un entero Positivo: ");
        scanf("%d",&entero);
    }while(entero<0);

    return entero;
}

void mostrarFecha(const Fecha *f)
{
    printf("\nLa Fecha final es: %d/%d/%d", f->d, f->m, f->a);
}

void restaFechas(Fecha *inicial,const Fecha *resta)
{

    inicial->d -= resta->d;
    inicial->m -= resta->m;
    inicial->a -= resta->a;

    if(inicial->a < 0)
    {
        inicial->a *= -1;
    }
    if(inicial->m < 0)
    {
        inicial->a--;
        inicial->m+=12;

    }
    if(inicial->d<0)
    {
        int m = inicial->m, a = inicial->a;

        int cdm = cantDiaMes(m,a);

        inicial->m--;

        inicial->d += cdm;
    }

    printf("\n La Diferencia en DD/MM/AA es: %d/%d/%d", inicial->d, inicial->m, inicial->a);
}


int logicaDiaSemanal(const Fecha *f)
{
    int a,y,m,dayOfTheWeek;
    a = (14 - f->m) / 12;
    y = f->a - a;
    m = f->m + 12 * a - 2;
    dayOfTheWeek = (f->d + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    return dayOfTheWeek;
}

void queDiaEsFecha(int numDia)
{
    switch (numDia)
    {

    case 1:
        puts("Ese dia es Lunes");
        break;

    case 2:
        puts("Ese dia es Martes");
        break;

    case 3:
        puts("Ese dia es Miercoles");
        break;

    case 4:
        puts("Ese dia es Jueves");
        break;

    case 5:
        puts("Ese dia es Viernes");
        break;

    case 6:
        puts("Ese dia es Sabado");
        break;

    case 7:
        puts("Ese dia es Domingo");
        break;
    }
}

Fecha restarDiasAFecha(const Fecha *f, int dias)
{
    int cdm;
    Fecha fechaFinal = *f;

    fechaFinal.d -= dias; 

    while(fechaFinal.d<1) 
    {
        cdm = cantDiaMes(fechaFinal.m,fechaFinal.a);
        fechaFinal.d += cdm;
        fechaFinal.m --;

        if(fechaFinal.m<1)
        {
            fechaFinal.m=12;
            fechaFinal.a--;
        }
    }
    return fechaFinal;
}
