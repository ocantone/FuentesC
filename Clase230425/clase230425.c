/***********************************************
Ingresar 10 números enteros.
Calcular e informar la cantidad de positivos,
la cantidad de negativos y la cantidad de ceros.
************************************************/

#include <stdio.h>

int main(){

    const int cantidad =5;                  //Declara e inicializa.
    int entero,positivos,negativos,ceros;   //Solo declara.

    entero=positivos=negativos=ceros=0;     //Inicializa.

    printf("Ingrese %d valores enteros \n", cantidad);
    switch(entero){
        float s;
        case 'a': s=2;
                    printf("aa");
                    break;

    }

    for( register int i=0; i<cantidad; i++){
        scanf("%d", &entero);           //Pide ingreso al usuario.
        if(entero >0){                  //¿es positivo?
            positivos++;                //incrementa "positivos" en uno.
        }
        else if(entero < 0){            //¿Es negativo?
            negativos++;                //Incrementa "negativos" en uno.
        }
        else{                           //Entonces es cero.
            ceros++;                    //Incrementa "ceros" en uno.
        }

    }
    //Informo las cantidades obtenidas:
    printf("La cantidad de positivos fue %d \n", positivos);
    printf("La cantidad de negativos fue %d \n", negativos);
    printf("La cantidad de ceros fue %d \n", ceros);

    return 0;       //Bye bye.
}
