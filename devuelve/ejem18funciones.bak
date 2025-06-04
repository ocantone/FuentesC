#include <stdio.h>
#include <stdlib.h>

float calculaDesYBonif(float sueldo, float _porcAumento, int diasAusen);
float calculaNeto (float sueldo, float descYBonif);
float porciento(float, float);
void imprimeRecibo();
int ingresaDatos();

int _numEmpleado, _cantInasis;
float _sueldoBruto, _sueldoNeto, _descJubil, _descOSocial, _montoAumento;
float _descInasis, _porcAumento;


int main()
{   while(ingresaDatos())
    {
    _sueldoNeto =calculaNeto(_sueldoBruto, calculaDesYBonif(_sueldoBruto, _porcAumento,_cantInasis));
    imprimeRecibo();
    }
    printf("\nFINALIZADO\n");
    return 0;
}

/*=== CUERPOS DE LAS FUNCIONES  ===*/
int ingresaDatos(){
    int sigue;
    printf("\nIngrese Num. Empleado: ");
    scanf(" %d",&_numEmpleado);
    if (_numEmpleado){
        sigue =1;
        printf("Sueldo Bruto: ");
        scanf(" %f", &_sueldoBruto);
        printf("Porc. _porcAumento: ");
        scanf(" %f", &_porcAumento);
        printf("Dias Inasistencia: ");
        scanf(" %d", &_cantInasis);
    }
    else sigue =0;
    return sigue;
}

void imprimeRecibo()
{
    printf("\nNUMERO DE EMPLEADO:\t %d\n\n", _numEmpleado);
    printf("SUELDO BRUTO: \t %.2f\n\n", _sueldoBruto);
    printf("DESC. JUBILACION\t %.2f\n", _descJubil);
    printf("DESC. OBRA SOCIAL\t %.2f\n", _descOSocial);
    printf("AJUSTE POR INASISTENCIAS\t %.2f\n", _descInasis);
    printf("BONIFICACION\t %.2f\n\n", _montoAumento);

    printf("SUELDO NETO:\t %.2f\n", _sueldoNeto);
}

float calculaDesYBonif(float sueldo, float porcAum, int diasAusen)
{
    const float porcJubil =11;
    const float porOSocial =3;
    const float porAusen =8;

    _descJubil      = porciento(sueldo, porcJubil);
    _descOSocial    = porciento(sueldo, porOSocial);
    _descInasis     = porciento(sueldo, diasAusen*porAusen);
    _montoAumento   = porciento(sueldo, porcAum);
    return (sueldo-_descJubil-_descOSocial-_descInasis+_montoAumento);
}

float porciento(float valor, float porcentaje)
{
    return valor*porcentaje/100;
}

float calculaNeto (float sueldo, float descYBonif)
{
    return sueldo - descYBonif;
}

