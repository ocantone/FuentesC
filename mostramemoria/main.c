#include <stdio.h>
#include <stdlib.h>

int main()
{

  int x[4] ={10,20,5,300};

    printf("La posicion %p contiene el dato %d \n", x, x[0]);
    printf("La posicion %p contiene el dato %d \n", &x[1], x[1]);
      printf("La posicion %p contiene el dato %d \n", &x[2], x[2]);
        printf("La posicion %p contiene el dato %d \n", &x[3], x[3]);
    return 0;
}
