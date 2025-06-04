#include <stdio.h>
#include <stdlib.h>
int main()
{
    int chasis, estado, usados=0, minchasis, band=0;
    float plista, desc=0.0, rec=0.0, imp=0.0, pfinal, recaudado=0.0, minpfinal;
    printf("NRO CHASIS: ");
    scanf("%d",&chasis);
    while(chasis!=0)
    {
        desc=0.0, rec=0.0, imp=0.0;
         printf("ESTADO: 1. Usado \t 2. Okm \n OPCION: ");
         scanf("%d",&estado);
         printf("PRECIO DE LISTA: ");
         scanf("%f",&plista);
         if(estado==1)
         {
            desc=plista*0.1;
            usados++;
         }
         else rec=plista*0.2;
         if(plista>5000000)imp=plista*0.3;
         printf("\n\nPRECIO DE LISTA: $%.2f", plista);
         printf("\nDESCUENTO: $%.2f", desc);
         printf("\nRECARGO: $%.2f", rec);
         printf("\nIMPUESTO: $%.2f", imp);
         pfinal=plista-desc+rec+imp;
         if(estado==2)recaudado+=pfinal;
         printf("\nPRECIO FINAL: $%.2f", pfinal);
         if(band==0)
         {
            band=1;
            minchasis=chasis;
            minpfinal=pfinal;
         }
         else
         if(pfinal<minpfinal)
         {
            minchasis=chasis;
            minpfinal=pfinal;
         }
         printf("\n\nNRO CHASIS: ");
         scanf("%d",&chasis);
      }
printf("\n\nUSADOS VENDIDOS: %d", usados);
printf("\nRECAUDADO EN 0KM: $%.2f", recaudado);
printf("\nEL CHASIS %d ES EL MAS BARATO: $%.2f", minchasis, minpfinal);
return 0;
}
