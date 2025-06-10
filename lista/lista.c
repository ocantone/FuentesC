#include <stdio.h>
#include <stdlib.h>

int opcion=0;
int menu();
void lista();
void agrega();
void borra();
struct usuario * nuevo();

struct usuario{
    char nombre[50];
    char apellido[50];
    int numUsuario;
    int saldo;
    struct usuario *sig;
};
struct usuario *inicio, *aux;

int main()
{
    inicio =NULL;
    aux =NULL;
    printf("LISTA\n");
    do{
    opcion = menu();
    switch (opcion){
        case 1: {
            lista();
            break;
        }
        case 2:{
            agrega();
            break;
        }
        case 3: {
            borra();
            break;
        }
        case 0: break;
    }

    }while(opcion);
return 0;
}

int menu(){
   int opc;
//   printf("\n");
   printf("1.Listar Usuarios\n");
   printf("2.Agregar usuario\n");
   printf("3.Borrar Usuario\n");
   printf("4.SALIR \n");
   printf("Opcion: ");
   scanf(" %d", &opc);
    if (opc == 4 )opc=0;
   return opc;
}
void lista(){
    if (inicio){
    aux=inicio;
    while(aux){
        printf("Nombre      : %s\n", aux->nombre);
        printf("Apellido    : %s\n", aux->apellido);
        printf("Num. usuario: %d\n", aux->numUsuario);
        printf("Saldo       : %d\n\n", aux->saldo);
        aux=aux->sig;
    }
    }
    else printf("\nNo hay usuarios en la lista\n");

}
void agrega(){
    if(inicio){
    aux=inicio;
    while(aux->sig)aux=aux->sig;
    aux->sig=nuevo();
    }
    else inicio = nuevo();
}

void borra(){
    int usuABorrar;
    struct usuario * anterior;
    printf("Ingrese num. usuario a borrar: ");
    scanf(" %d", &usuABorrar);
    aux=inicio;
    while(aux){
        if(aux->numUsuario==usuABorrar){
            if(aux==inicio){
                inicio=aux->sig;
                free(aux);
            }
            else{
                anterior->sig=aux->sig;
                free(aux);
            }
        }
     anterior=aux;
     aux=aux->sig;

    }
}

struct usuario * nuevo(){
    struct usuario *nuevoUsuario;
    nuevoUsuario=(struct usuario *)malloc(sizeof(struct usuario));
    printf("Alta nuevo usuario\n");
    printf("Ingrese nombre: ");
    scanf(" %s",nuevoUsuario->nombre);
    printf("Ingrese apellido: ");
    scanf(" %s",nuevoUsuario->apellido);
    printf("Ingrese num usuario: ");
    scanf(" %d", &nuevoUsuario->numUsuario);
    printf("Ingrese saldo: ");
    scanf(" %d",&nuevoUsuario->saldo);
    nuevoUsuario->sig=NULL;
    return nuevoUsuario;
}
