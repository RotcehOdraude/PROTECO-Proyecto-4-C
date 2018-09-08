/*
Implementación de la calculadora estadística con memoria dinámica. (Valor: 25%).
En vez de trabajar sobre un arreglo de 10 elementos, que el usuario pueda elegir
el número de datos con el cual trabajar.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "compare.h"
//---------------------------------
float moda(float *arreglo,int tamanio);
float promedio(float *arreglo,int tamanio);
float varianza(float desviacion_estandar);
float desviacion_estandar(float *arreglo,int tamanio);
void mediana(float *arreglo,float *medi,int tamanio);
//---------------------------------
int main(int argc, char const *argv[]) {
  float median[2]={0,0};
  int opcion = 0,dimension = 0;
  printf("###### Esta es una calculadora que hace operaciones estadisticas #######\n" );
  printf("Por favor escriba la dimensiona del arreglo\n\t:", );
  scanf("%i",&dimension);
  float valores[dimension]={0,0,0,0,0,0,0,0,0,0};
  printf("Escriba los valores del arreglo:\n");
  for (size_t i = 0; i < 10; i++) {
    scanf("%f",&valores[i]);
  }
  system("clear");
  while (1) {
    printf("Por favor eliga una de las opciones: \n");
    printf("1) Moda\n2) Mediana\n3) Promedio\n4) Varianza\n5) Desviacion estandar\n6) Regresion lineal\n7) Salir\n\t:" );
    scanf("%i",&opcion);
    switch (opcion) {
      case 1://<
        system("clear");

        break;
      case 2://<--------------
        system("clear");
        mediana(valores,median,10);
        printf("La mediana es: {%.2f,%.2f} \n",median[0],median[1]);
        break;
      case 3://<--------------
        system("clear");
        printf("\tEl promedio es: %f \n",promedio(valores,10));
        break;
      case 4://<-------------
        system("clear");
        printf("\tLa varianza es: %f \n",varianza(desviacion_estandar(valores,10)));
        break;
      case 5://<-------------
        system("clear");
        printf("\tLa desviacion estandar es: %f \n",desviacion_estandar(valores,10));
        break;
      case 6://<

        break;
      case 7://<-------------
        return 0;
      default:
        printf("Opcion incorrecta" );

    }
  }

}
float promedio(float *arreglo,int tamanio){
  float suma = 0;
  for (size_t i = 0; i < tamanio; i++) {
    suma += arreglo[i];
  }
  return suma/tamanio;
}
void mediana(float *arreglo,float *medi,int tamanio){
  qsort(arreglo, 10, sizeof(float), (void *)compare );
  medi[0] = arreglo[4];
  medi[1] = arreglo[5];
}
float desviacion_estandar(float *arreglo,int tamanio){
  float x_ = promedio(arreglo,tamanio);
  float suma = 0;
  for (size_t i = 0; i < tamanio; i++) {
    suma = pow(arreglo[i]-x_,2) + suma;
  }
  return suma / (tamanio-1);
}
float varianza(float desviacion_estandar){
  return pow(desviacion_estandar,2);
}
float moda(float *arreglo,int tamanio){

}
