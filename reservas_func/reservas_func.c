#include <stdio.h>
#include <stdlib.h>

#define aacute  160
#define eacute  130
#define iacute  161
#define oacute  162
#define uacute  163

void mostrar_menu();
void calculaDescuentos();
void muestraReserva();
void muestraTotales();
void actualizaTotales();
void inicializaValores();
int nuevaReserva();
int calculaHabitaciones(int , int );

int dniTitular =0;
char formaPago =' ';
int cantidadDias =0;
int cantidadPersonas =0;
int cantidadHabitac  =0;
int numReserva =102;
int totalReservas =0;
int totalPersonas =0;
float reservaMasBarata =0;
float subTotal =0;
float recargos =0;
float descuentos =0;
float totalAPagar =0;
float totalRecaudado =0;

const int capacHabit =4;
const int precioHabit = 100000;
const int descuento2Personas = 15;
const int recargoTrajeta = 10;

int main()
{
    do{
        if ( nuevaReserva() ){
              inicializaValores();
              mostrar_menu();
              cantidadHabitac = calculaHabitaciones(cantidadPersonas, capacHabit);
              calculaDescuentos();
              actualizaTotales();
              muestraReserva();
              numReserva++;
        }
        else break;
    }while(1);

    muestraTotales();

    return 0;
}

void inicializaValores(){
    subTotal =0;
    cantidadDias =0;
    cantidadHabitac =0;
    cantidadPersonas =0;
    totalAPagar =0;
    descuentos =0;
    recargos =0;
}

void mostrar_menu(){
    printf("\n");
    printf("DNI del titular de la reserva: ");
    scanf(" %d",&dniTitular);
    printf("Forma de pago (E:efectivo T:tarjeta de cr%cdito): ", eacute);
    scanf(" %c",&formaPago);
    printf("Cantidad de d%cas que desean hospedarse: ", iacute);
    scanf(" %d",&cantidadDias);
    printf("Cantidad de personas: ");
    scanf(" %d",&cantidadPersonas);
}

int nuevaReserva(){
    char tecla =' ';
    printf("\n-----------------------------------------------------\nPresione una tecla para reservar, Z para salir: ");
    scanf(" %c",&tecla);
    if (tecla !='z' && tecla !='Z') return 1;
        else return 0;
}

void calculaDescuentos(){
    subTotal = cantidadHabitac * precioHabit * cantidadDias;
    if (cantidadPersonas <= 2 || (cantidadPersonas % capacHabit<0 && cantidadPersonas%capacHabit<=2) ) descuentos = precioHabit * descuento2Personas /100;
    if (formaPago == 't' || formaPago =='T') recargos = (subTotal - descuentos)*recargoTrajeta/100;
    totalAPagar = subTotal - descuentos + recargos;
}

int calculaHabitaciones(int _personas, int _capacidad){
    int cantidad;
    if(  _personas < _capacidad) return 1;
    else{
        cantidad =_personas / _capacidad;
        if (_personas % _capacidad) cantidad++;
        return cantidad;
    }
}

void muestraReserva(){

    printf("\n\nNro de reserva: %d\n", numReserva);
    printf("DNI del titular: %d\n", dniTitular );
    printf("Habitaciones: %d para %d personas\n", cantidadHabitac, cantidadPersonas);
    printf("D%cas reservados: %d\n", iacute, cantidadDias);
    printf("Forma de pago: ");
    if (formaPago =='e' || formaPago =='E') printf("efectivo\n");
    if (formaPago =='t' || formaPago =='T') printf("tarjeta de cr%cdito\n",eacute);
    printf("\nSubtotal: $%.2f\n", subTotal);
    printf("Recargo: $%.2f\n", recargos);
    printf("Descuentos: $%.2f\n", descuentos);
    printf("\nTotal a pagar: $%.2f\n", totalAPagar);
}

/*Al finalizar el programa, se debe informar la cantidad de reservas realizadas,
cantidad total de personas que desean alojarse y el total recaudado de todas las
reservas, así como también, cual fue la reserva más barata que se realizó y su total.
*/

void actualizaTotales(){
    totalReservas ++;
    totalPersonas += cantidadPersonas;
    totalRecaudado += totalAPagar;
    if(totalReservas==1) reservaMasBarata = totalAPagar;
        else if(totalAPagar<reservaMasBarata)reservaMasBarata = totalAPagar;

}

void muestraTotales(){
    printf("\n\nTotal reservas: %d\n", totalReservas);
    printf("Total personas alojadas: %d\n", totalPersonas);
    printf("Total recaudado: $%.2f\n", totalRecaudado);
    printf("Reserva menor valor: $%.2f\n", reservaMasBarata);

}


