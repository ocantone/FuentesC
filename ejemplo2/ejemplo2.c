#include <stdio.h>
#include <stdlib.h>
void mostrarVector(int v[], int N);
void ordenar(int [], const int);

int main()
{
    const int N=4;
    int vec[4] = {3,2,4,1};
    printf("Vector sin ordenar: ");
    mostrarVector(vec, N);
    printf("Vector ordenado: ");
    ordenar(vec,N);
    mostrarVector(vec, N);
    return 0;
}

void mostrarVector(int v[], int N){
    for (register int i=0; i<N; i++ ){
        printf("%i  ", v[i]);
    }
    printf("\n\n");
}

void ordenar(int v[], const int N){
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[i]>v[j]){
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

}
