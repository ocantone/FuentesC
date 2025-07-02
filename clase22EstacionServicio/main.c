/**
Realizar un programa que administre una estación de servicio.
Para ello se debe conocer de 300 ventas,
la siguiente información: tipo de combustible (nafta, diésel o GNC) y litros a cargar.
Dependiendo el tipo de combustible será el precio del litro a cobrar.
Para conocerlos, deberán solicitarse, mediante el uso de una función (llamada PrecioDiario),
los mismos al comenzar cada día.
Además, deberá almacenarse de cada carga el número de ventas que comenzará en 1 y se irá
incrementando y asignando automáticamente.
Se pide:

1.  Mediante el uso de una función, calcular el precio final de cada carga.
2.  Mediante el uso de una función, buscar un número de carga específico. Al
encontrarse devolver su posición y eliminar esa carga: se asignará 0 a toda su
información.
3.  Generar un vector para discriminar el número de carga de aquellas cuyo tipo
de combustible cargado es nafta.
4.  En caso de existir, mediante una función, ordenar dichos datos, por cantidad
de litros cargados, de menor a mayor con su respectivo número de carga.
Luego, en el main, informar.
5.  Al finalizar el día informar, toda la información asociada a cada carga realizada.

Nota: No hace falta validar ninguna
información. Siempre se da por supuesto el
ingreso correcto de datos.
Las salidas por pantalla deberán ser como
las siguientes:

*/
#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 300

int opcion(void);
void PrecioDiario( void);
void cargaVenta();
void calculaPrecioV();
void borraVenta(void);
void ventasNafta(void);
void muestraCargasNafta();

float cantCargada[CANT_MAX], precioVenta[CANT_MAX], precioLitro[CANT_MAX];
float precios[3] = {1200,1200,800};
int venNafta[CANT_MAX];
int numVenta=0, vN=0,tipoComb, ventaBorrar;


int main()
{

    printf("Estaci%cn de Servicio\n",162);
//Carga de datos
    do{
    printf("1. Actualiza precios\n");
    printf("2. Carga venta\n");
    printf("3. Borrar venta\n");
    printf("4. Mostrar cargas Nafta\n");
    printf("0. Salir\n");
    }while( opcion() );

    return 0;
}
int opcion (){
    int op;
    scanf(" %d", &op);
    if (op == 1) PrecioDiario();
    else if (op == 2) cargaVenta();
    else if (op == 3) borraVenta();
    else if (op == 4) muestraCargasNafta();
    return op;

}

void PrecioDiario(){
    printf("Precio Nafta: \n"); scanf(" %f", &precios[0]);
    printf("Precio Diesel: \n"); scanf(" %f", &precios[1]);
    printf("Precio GNC: \n"); scanf(" %f", &precios[2]);
}
//1.  Mediante el uso de una función, calcular el precio final de cada carga.
void cargaVenta(){
    numVenta++;
    printf("Ingrese tipo combustible(1.Nafta 2.Diesel 3.GNC: "); scanf(" %d",&tipoComb);
    printf("Ingrese cantidad: "); scanf(" %f", &cantCargada[numVenta]);
    precioLitro[numVenta] = precios[tipoComb-1];
    calculaPrecioV();
    if (tipoComb == 1) ventasNafta();
}

void calculaPrecioV(){
    precioVenta[numVenta] = cantCargada[numVenta] * precioLitro[numVenta];
}
/*2.  Mediante el uso de una función, buscar un número de carga específico. Al
encontrarse devolver su posición y eliminar esa carga: se asignará 0 a toda su
información.*/

void borraVenta(void){
    char confirma;
    printf("Ingrese venta a borrar: "); scanf(" %d", &ventaBorrar);
    printf (" Se eliminar%c la venta N%c %d  [Si/No]", 160,167, ventaBorrar);
    scanf(" %c", &confirma);
    if (confirma == 'S') {
        cantCargada[ventaBorrar] = 0;
        precioLitro[ventaBorrar] = 0;
        precioVenta[ventaBorrar] = 0;
    }
}
/** 3.  Generar un vector para discriminar el número de carga de aquellas cuyo tipo
de combustible cargado es nafta.
*/
void ventasNafta(){

    venNafta[vN] = numVenta;
    vN++;

}
/** 4.  En caso de existir, mediante una función, ordenar dichos datos, por cantidad
de litros cargados, de menor a mayor con su respectivo número de carga.
Luego, en el main, informar.
*/
void muestraCargasNafta(){
    int cambios =0;
    int auxVN;
    do{
        cambios = 0;
        for(int i=0; i< vN-1; i++){
            if( cantCargada[venNafta[i]] > cantCargada[venNafta[i+1]]){
                auxVN= venNafta[i];
                venNafta[i] = venNafta[i+1];
                venNafta[i+1] = auxVN;
                cambios++;
            }
        }
    }while (cambios);
    for (int i=0; i<vN; i++){
        printf("Venta N%c %d %.2f litros $%.2f/litro total:$%.2f \n", 167, venNafta[i],cantCargada[venNafta[i]], precioLitro[venNafta[i]], precioVenta[venNafta[i]]);
        }
        printf("\n");


}

