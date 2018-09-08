#include <stdio.h>
#include <stdlib.h>
#include "Pila.c"
//-------------------------------------------
int* crear_arreglo(int* aptArreglo,int num);
void llenar_arreglo(int* aptArreglo);
void invertir_arreglo(int* aptArreglo);
void imprimir_arreglo(int* aptArreglo);
int numElementosArreglo = 0;
//-------------------------------------------
int main(int argc, char const *argv[]) {
  int* arreglo = NULL;
  printf("####  INVIERTE ARREGLOS ####\n\n");
  printf("Por favor escriba el numero de elementos del arreglo: ");
  scanf("%i",&numElementosArreglo);
  arreglo = crear_arreglo(arreglo,numElementosArreglo);
  llenar_arreglo(arreglo);
  printf("Este es el arreglo original: \n");
  imprimir_arreglo(arreglo);
  invertir_arreglo(arreglo);
  printf("Este es el arreglo invertido: \n");
  imprimir_arreglo(arreglo);
  return 0;
}
//--------------------------------------------
int* crear_arreglo(int* aptArreglo,int num){
  aptArreglo = calloc(num,sizeof(int));
  if(aptArreglo == NULL){return NULL;}
  return aptArreglo;
}
void llenar_arreglo(int* aptArreglo){
  for (int i = 0; i < numElementosArreglo; i++) {
    printf("Elemento %i: ",i+1);
    scanf("%i",aptArreglo+i);
  }
}
void invertir_arreglo(int* aptArreglo){
  Pila* stack = crearPila();
  for (int i = 0; i < numElementosArreglo; i++) {
    push(stack,aptArreglo[i]);
  }
  for (int i = 0; i < numElementosArreglo; i++) {
    aptArreglo[i] = pop(stack);
  }
}
void imprimir_arreglo(int* aptArreglo){
  printf("[");
  for (int i = 0; i < numElementosArreglo; i++) {
    printf("%i ",aptArreglo[i]);
  }
  printf("]\n");
}
