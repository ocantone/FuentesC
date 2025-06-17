#include <stdio.h>
#include <stdlib.h>

#define CANT_ATLETAS 4

int numAtleta[CANT_ATLETAS], ciclismo720[CANT_ATLETAS], tTotal[CANT_ATLETAS];
int indice720=0;        //indice del vector de los que tardaron menos de 720 seg.
int segNatacion, segCiclismo, segPedestrismo;
int ganador, ultimo;

void calculaTotales(int, int, int, int);
void ordena(void);

int main()
{
    printf("Integrador Vectores #3\n");
    for(int i=0; i<CANT_ATLETAS ; i++){
        printf("Ingrese N%cmero Atleta: ", 163);
        scanf(" %d",&numAtleta[i]);
        printf("Ingrese tiempo nataci%cn: ",162);
        scanf(" %d",&segNatacion);
        printf("Ingrese tiempo ciclismo: ");
        scanf(" %d",&segCiclismo);
        printf("Ingrese tiempo pedestrismo: ");
        scanf(" %d",&segPedestrismo);
        printf("\n");

        if( segCiclismo < 720){
        ciclismo720[indice720] =numAtleta[i];
        indice720++;
        }

        calculaTotales(segNatacion, segCiclismo, segPedestrismo, i);

    }
    ordena();
    if(indice720){
        printf("\nAtletas que tradaron menos de 720 segundos: \n");
        for (int i=0; i<indice720; i++){
            printf("%3d.Atleta N%c%4d \n",i+1,167,ciclismo720[i]); //Muestra "1. Altena Nº203"
        }
    }
    else printf("\nNo hay atletas que tradaron menos de 720 segundos: \n");

    printf("\n\nOrdenados: \n");
    for(int i=0; i<CANT_ATLETAS; i++){
        printf("%3d. N%c%4d tiempo: %5d\n",i+1,167,numAtleta[i],tTotal[i]);
    }
    printf("\nGanador: Atleta N%c%4d",167, numAtleta[0]);
    printf("\nFinaliza: Atleta N%c%4d\n\n",167, numAtleta[CANT_ATLETAS-1]);

return 0;
}

void calculaTotales(int nat, int cic, int ped, int indice){
    tTotal[indice] =nat+cic+ped;
}
void ordena (){
    int cambios, aux;
    do{
        cambios =0;
        for (int i=0; i<(CANT_ATLETAS-1); i++){
            if(tTotal[i] > tTotal[i+1]){
                aux =tTotal[i+1];
                tTotal[i+1] =tTotal[i];
                tTotal[i] =aux;
                aux =numAtleta[i+1];
                numAtleta[i+1] =numAtleta[i];
                numAtleta[i] =aux;
                cambios++;
            }
        }
    }while(cambios);


}
