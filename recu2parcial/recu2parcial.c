/* se deberá almacenar: DNI, Número de Cuenta y Saldo. Realizar la carga de datos correspondiente. 
Al comenzar los movimientos del día, el cajero ingresará su número de empleado, el cual deberá ser ingresado cada 
vez que se realiza una operación, ya que distintos empleados pueden atender una misma caja. Cuando se ingrese el 
número de empleado 0, se hará el cierre del día, informando la cantidad de retiros y depósitos realizados. (1 pt.)
Para operar, el sistema solicitará el DNI del cliente y mostrará: Número de Cuenta, y Saldo Actual. Se podrá elegir 
entre realizar un depósito o una extracción indicando el monto. Tras la operación elegida, se generará un ticket con (1.5 pt.): 
 Número de empleado que atendió.
 Datos del cliente (DNI, Número de Cuenta).
 Saldo anterior, monto de la operación y saldo final.
Requerimientos adicionales:
1. Utilizar una función para buscar al cliente por DNI, para poder comenzar a operar con el mismo en el programa 
principal. (1.5 pt.)
2. Generar un vector con los números de cuenta que realizaron depósitos. (1.5 pt.)
3. Implementar una función para ordenar el vector generado de forma ascendente y mostrar el mismo en caso de 
existir. (1.5 pt.)
4. En una función, mostrar la lista ordenada de cuentas, con arrastre del saldo, al cierre del día. (1.5 pt.)
NOTA 1: Se asumen ingresos correctos siempre. No deben validarse valores.
NOTA 2: El resto del puntaje total del examen, se contempla en base a la lógica y sintaxis utilizada para el resto de los 
procesos.
Resolución:
*/
#include <stdio.h>
#include <stdlib.h>
#define T 3 // Cambiar a 250 en producción
// Prototipos
int buscar(int dni[], int buscado);
void ordenar(int cuentas[], float saldos[], int cantidad);
void mostrarDepositos(int cuentas[], float saldos[], int cantidad);
int main() {
    int i, dni[T], cuenta[T];
    float saldo[T];
    int cuentaDep[T]; // Vector para cuentas que realizaron depósitos
    float saldoDep[T]; // Arrastre del saldo correspondiente
    int dep = 0, ext = 0;
    int emp, op, buscado, pos;
    float monto;
 // ---------- CARGA DE CLIENTES ----------
    for (i = 0; i < T; i++) {
        printf("DNI: ");
        scanf("%d", &dni[i]);
        printf("Número de Cuenta: ");
        scanf("%d", &cuenta[i]);
        printf("Saldo: ");
        scanf("%f", &saldo[i]);
        printf("\n");
    } 
 // ---------- OPERACIONES DEL DÍA ----------
    printf("\nNúmero de Empleado (0 para finalizar): ");
    scanf("%d", &emp);
    while (emp != 0) {
        printf("DNI del cliente: ");
        scanf("%d", &buscado);
        pos = buscar(dni, buscado); // Buscar cliente por DNI
        if (pos == -1) {
           printf("Cliente no encontrado.\n");
        } else {
        printf("Cuenta: %d\tSaldo: %.2f\n", cuenta[pos], saldo[pos]);
        printf("1. Extracción 2. Depósito\nOpción: ");
        scanf("%d", &op);
        printf("Monto: ");
        scanf("%f", &monto);
        printf("\n--- TICKET DE MOVIMIENTO ---\n");
        printf("Empleado: %d\n", emp);
        printf("DNI: %d\n", dni[pos]);
        printf("Cuenta: %d\n", cuenta[pos]);
        printf("Saldo Anterior: %.2f\n", saldo[pos]);
        if (op == 2) {
        saldo[pos] += monto;
        cuentaDep[dep] = cuenta[pos];
        saldoDep[dep] = saldo[pos];
        dep++;
        printf("Monto depositado: %.2f\n", monto);
        } else {
        if(saldo[pos] >= monto){
        saldo[pos] -= monto;
        ext++;
        printf("Monto extraído: %.2f\n", monto);
        }
        else
        printf ("Saldo insuficiente\n");
        }
        printf("Saldo Actual: %.2f\n", saldo[pos]);
        }
        printf("\n-----------------------------\nNúmero de Empleado (0 para finalizar): ");
        scanf("%d", &emp);
    }
 // ---------- INFORME DE CUENTAS CON DEPÓSITO ----------
 if (dep > 0) {
 ordenar(cuentaDep, saldoDep, dep);
 mostrarDepositos(cuentaDep, saldoDep, dep);
 } else {
 printf("\nNo se generó el vector de cuentas con depósitos.\n");
 }
 // ---------- CIERRE DEL DÍA ----------
 printf("\nCantidad de Depósitos: %d", dep);
 printf("\nCantidad de Extracciones: %d\n", ext);
 return 0;

 }
// ---------- BUSCAR CLIENTE POR DNI ----------
int buscar(int dni[], int buscado) {
 int k = 0, i = 0;
 while (k == 0 && i < T) {
 if (buscado == dni[i])
 k = 1;
 else
 i++;
 }
 if (k == 0)
 return -1;
 else
 return i;
}
// ---------- ORDENAR CUENTAS (BURBUJEO con arrastre del saldo) ----------
void ordenar(int cuentas[], float saldos[], int cantidad) {
 int k = 0, x = cantidad, i, auxCuenta;
 float auxSaldo;
 while (k == 0) {
 k = 1;
 x--;
 for (i = 0; i < x; i++) {
 if (cuentas[i] > cuentas[i + 1]) {
 k = 0;
 // Intercambiar cuentas
 auxCuenta = cuentas[i];
 cuentas[i] = cuentas[i + 1];
 cuentas[i + 1] = auxCuenta;
 // Arrastrar saldos
 auxSaldo = saldos[i];
 saldos[i] = saldos[i + 1];
 saldos[i + 1] = auxSaldo;
 }
 }
 }
}
// ---------- MOSTRAR CUENTAS QUE REALIZARON DEPÓSITOS ----------
void mostrarDepositos(int cuentas[], float saldos[], int cantidad) {
 int i;
 printf("\n--- Cuentas que realizaron depósitos (ordenadas) ---\n");
 for (i = 0; i < cantidad; i++) {
 printf("Cuenta N° %d - Saldo: $%.2f\n", cuentas[i], saldos[i]);
 }
}