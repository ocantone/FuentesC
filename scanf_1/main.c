#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   int x1,x2,y1,y2;
    float x,y;
    x=y=x1=x2=y1=y2=0;
    printf("Ingrese la coordenada de P1: ");
    scanf(" %d %*c %d",&x1,&y1);
    printf("Ingrese la coordenada de P2: ");
    scanf(" %d %*c %d",&x2,&y2);
    x=x2-x1;
    y=y2-y1;
    float modulo = sqrt(x*x + y*y);
    float angulo = 180*atan(y/x)/3.1415926536;

    printf("\nM%cdulo: %.2f\n",162, modulo);
    printf("Angulo: %.2f\n\n", angulo);



    return 0;
}
