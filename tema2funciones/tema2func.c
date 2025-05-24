/**  Resolución Tema 2 1° Parcial 15/5/25  */
#include <stdio.h>
#include <stdlib.h>

int cantParticipantes =0, numParticipante =0, edad =0, pruebasCompletadas =0, puntosAtleta =0;
char genero =0;
int puntosTotalBruto =0, puntosTotalNeto =0;
int atletasFemeninos =0, atletasMasculinos =0;
int bonifica =0, descuenta =0, totalBonos =0, totalDescuentos =0;
int numAtleta =0, puntajeMinimo =0, atletaMinPuntaje =0;

/*  Funciones  */
int bonificaPruebas(int, int);
int penalizaInactividad(int);
int bonificaEdad( int, int);
int ingresaAtleta();
void muestraTotales();

int main()
{
    while ( ingresaAtleta()){
        cantParticipantes++;
        if(genero =='f' || genero == 'F') atletasFemeninos++;
        if(genero =='m' || genero == 'M') atletasMasculinos++;

        bonifica += bonificaPruebas(pruebasCompletadas, puntosAtleta);
        bonifica += bonificaEdad(edad, pruebasCompletadas);
        descuenta += penalizaInactividad(pruebasCompletadas);
        totalBonos += bonifica;
        totalDescuentos += descuenta;

        puntosTotalBruto += puntosAtleta;
        puntosAtleta = puntosAtleta + bonifica - descuenta;
        puntosTotalNeto += puntosAtleta;


        if( (cantParticipantes == 1) || (puntosTotalNeto < puntajeMinimo)){
          puntajeMinimo = puntosAtleta;
          atletaMinPuntaje = numParticipante;
        }

        bonifica =0;
        descuenta =0;
    }
    muestraTotales();
    return 0;
}
int bonificaPruebas(int cant, int puntos){
    if(cant > 5 && puntos >80) return 10;
    else return 0;
}
int bonificaEdad(int _edad, int pruebas){
    if(_edad > 50 && pruebas >=4) return 5;
    else return 0;
}

int penalizaInactividad(int pruebas){
    if(pruebas < 2) return 15;
    else return 0;
}

void muestraTotales(){
    printf("\nPuntos totales sin bonificar: %d\n", puntosTotalBruto);
    printf("Puntos bonificados: %d\n", totalBonos);
    printf("Puntos descontados: %d\n", totalDescuentos);
    printf("Puntos totales: %d\n", puntosTotalNeto);
    printf("El menor puntaje fue el participante %d con %d puntos \n", atletaMinPuntaje, puntajeMinimo);


}

int ingresaAtleta(){
    printf("\nIngrese n%cmero participante: ",163); // 
    scanf(" %d", &numParticipante);
    if ( numParticipante ){
        printf("Ingrese genero [F][M]: ");
        scanf(" %c", &genero);
        printf("Ingrese edad: ");
        scanf(" %d", &edad);
        printf("Cantidad pruebas completadas: ");
        scanf(" %d", &pruebasCompletadas);
        printf("Puntos totales obtenidos: ");
        scanf(" %d", &puntosAtleta);

    }
    else return 0;
return 1;
}
