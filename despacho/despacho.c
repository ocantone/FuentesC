/** Despacho de palets**/
#include <stdio.h>
#include <stdlib.h>

/* Definimos caracteres con tilde */
#define aacute 160
#define eacute 130
#define iacute 161
#define oacute 162
#define uacute 163
#define ordinal 167




int numTicket =0, numPalet =0, pesoPalet =0, cantPalets =0, pesoDespacho =0;
const int capacidadCarga =6500, paletGrande =1000, paletChico =800;
unsigned char finalizarPrograma =0, pesoValido =0, despachoListo =0;
char charOpcion;

int main()
{
    /** Presento menú inicial**/
    printf("\nDespacho asistido de palets\n\n");

do{
    printf("- Para nuevo env%co presione [N] \n", iacute);
    printf("- Para finalizar presione [Q]\n");
    printf("Ingrese su opci%cn: ", oacute);

    scanf(" %c",&charOpcion);

    /** Si la opción fue N ó n procesa el ticket **/
    if( charOpcion == 'n' || charOpcion == 'N'){

        pesoDespacho =despachoListo =numPalet =cantPalets =0;

        printf("\nTicket N%c: %06d\n", ordinal,++numTicket);

        while ( !despachoListo){
            printf("Palet %02d (disponible %4dKg.): ",++numPalet, capacidadCarga-pesoDespacho);

            do{  //Verifica que el peso ingresado sea solo 1000 ú 800 Kg.
                scanf("%d",&pesoPalet);
                if(pesoPalet == paletGrande || pesoPalet == paletChico) pesoValido =1;
                        else{
                            pesoValido =0;
                            printf("Peso inv%clido\n", aacute);
                            printf("Palet %02d (disponible %4dKg.): ",numPalet, capacidadCarga-pesoDespacho);
                        }
                //Verificamos que no se supere la capacidad de carga.
                if(pesoPalet == paletGrande && (pesoDespacho+pesoPalet)>capacidadCarga){
                            pesoValido =0;
                            printf("Peso excesivo\n");
                            printf("Palet %02d (disponible %4dKg.): ",numPalet, capacidadCarga-pesoDespacho);

                }
               }while(!pesoValido);


            if ( (pesoDespacho + pesoPalet) <= capacidadCarga) {
                    pesoDespacho += pesoPalet;
                    //Si al sumar el menor supero la capacidad, finalizo ingreso.
                    if ((pesoDespacho + paletChico) > capacidadCarga) {
                        despachoListo =1;
                        cantPalets = numPalet;
                        printf("\nDespacho Listo\n");
                        printf("N%c: %06d\n",ordinal, numTicket);
                        printf("Cant. Palets: %2d\n",cantPalets);
                        printf("Peso: %4d Kg. \n\n",pesoDespacho);
                    }
            }
        }

    }
    else if (charOpcion == 'q' || charOpcion == 'Q'){
        finalizarPrograma =1;
    }
    else {
        finalizarPrograma =0;
        printf("Opcion inv%clida\nIngrese su opci%cn: ", aacute, oacute);

    }
}while ( !finalizarPrograma );
printf("\nFIN \n");
return 0;
}
