#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Hello world!\n");
    do{
    c =getchar();
    printf("%c",c);
    }while(c != 27);
    return 0;
}
