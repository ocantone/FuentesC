#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int buscar (int nsc[], int suc);
void ordenar (int nsc[], float trc[]);

int main()
{
 int i, ns[TAM],suc,z,c,ns800[TAM];
 float tr[TAM], dinero;

 // Carga de datos
 for (i=0; i<TAM; i++)
  {
     printf ("Ingrese numero de sucursal:\n");
     scanf (" %d",& ns[i]);
     printf ("Ingrese Total recaudado:\n");
     scanf (" %f",& tr[i]);
  }
// Movimientos del día
 printf ("Ingrese Numero de Sucursal para operar: \n");
 scanf (" %d",& suc);
 while (suc != 0)
    {
     z = buscar(ns,suc);
     if (z == -1) printf ("Sucursal inexistente\n");
     else
        {
            printf ("Ingrese la cantidad de dinero recaudado: \n");
            scanf ("%f", & dinero);
            tr[z] += dinero;
        }
     printf ("Ingrese Numero de Sucursal para operar: \n");
     scanf ("%d", & suc);
     }
     //Generar el nuevo vector
     c=0;

    for (i=0; i<TAM; i++)
    { if(tr[i]>8000)
        {
         ns800[c]=ns[i];
         c++;
        }
    }
 if (c==0)printf("No se genero el vector de los Numero de sucursal que recaudaron mas de $8000\n");
 else
    for (i=0; i<c; i++)
     {
     printf ("Las sucursales que recaudaron mas de $8000 son:%d\n", ns800[i]);
     }
 ordenar (ns,tr);
 for (i=0; i<TAM; i++) printf ("La sucursal Numero:%d, recaudo:%.2f\n", ns[i], tr[i]);
 return 0;
}
//== CUERPO DE LAS FUNCIONES =====================================
int buscar (int nsc[], int suc)
{
 int k=0, i=0;
 while (k == 0 && i<TAM)
 {
     if (nsc[i] == suc)
     k = 1;
     else
     i ++;
 }
 if (k == 0) return -1;
 else return i;
}

void ordenar (int nsc[], float trc[])
{
 int i,k, x, aux;
 float aux1;
 k=0;
 x=TAM;
 while (k==0)
 {
     k=1;
     x--;
     for (i=0; i<x; i++)
     {
         if (nsc[i] < nsc[i+1])
            {
             k = 0;
             aux = nsc[i];
             nsc[i] = nsc[i+1];
             nsc[i+1] = aux;

             aux1 = trc[i];
             trc[i] = trc[i+1];
             trc[i+1] = aux1;
            }
    }
 }
}
