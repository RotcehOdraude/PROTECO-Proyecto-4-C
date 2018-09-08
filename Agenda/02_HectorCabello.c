/* Esta es una agenda simple en lenguaje C.
  Permite:
    Almacenar datos personales de un número de personas dado por
    el usuario.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//--------------------------------------------------
typedef struct contacto{
  char nombre[20];
  char edad[20];
  char direccion[20];
  char telefono[20];
}Contacto;
Contacto* ingresar_contacto(Contacto *pointer);
void consultar_contacto(Contacto *pointer);
Contacto* modificar_contacto(Contacto *pointer);
void mostrar_contactos(Contacto *pointer);
void imprimirAgenda(Contacto* pointer);
void imprimirContacto(Contacto *pointer);
int numeroDeContactos = 0;
//--------------------------------------------------
int main(int argc, char const *argv[]) {
  Contacto* agenda = NULL;
  agenda = (Contacto*) realloc(agenda,sizeof(Contacto));
  int opcion = 0;
  while (1){
    printf("\t### MENU ###\n");
    printf("1)Ingresar\n2)Consultar\n3)Modificar\n4)Mostrar\n5)Salir\n");
    printf("\tEliga una opcion: " );
    scanf("%d",&opcion);
    switch (opcion) {
      case 1:
        //ingresar contactos
        system("clear");
        agenda = ingresar_contacto(agenda);
        break;
      case 2:
        // consultar contacto
        system("clear");
        consultar_contacto(agenda);
        break;
      case 3:
        // modificar contacto
        system("clear");
        agenda = modificar_contacto(agenda);
        break;
      case 4:
        // mostrar todos los contactos
        system("clear");
        mostrar_contactos(agenda);
        break;
      case 5:
        // salir
        return 0;
      default:
        printf("Opcion invalida\n");
    }
  }
}
//----------------------------------------------
Contacto* ingresar_contacto(Contacto *pointer) {
  int i = 0, limiteWhile = 0;
  printf("\t### INGRESAR ###\n");
  printf("Cuantos contactos va a ingresar: ");
  scanf("%i",&limiteWhile);
  if(pointer != NULL){
    do{
      printf("Escriba los siguientes datos del contacto:\n");
      printf("\tNombre: ");
      scanf("%s",pointer[i].nombre);
      printf("\tEdad: ");
      scanf("%s",pointer[i].edad);
      printf("\tDireccion: ");
      scanf("%s",pointer[i].direccion);
      printf("\tTelefono: ");
      scanf("%s",pointer[i].telefono);
      numeroDeContactos++;
      pointer = (Contacto*)realloc(pointer,(numeroDeContactos + 1) * sizeof(Contacto));
      i++;
    }while(i < limiteWhile && pointer!= NULL);
    //imprimirAgenda(pointer);
  }
  return pointer;
}
void consultar_contacto(Contacto *pointer){
  char telefono[20];
  printf("\t### CONSULTAR ###\n");
  printf("Escriba el numero de telefono del contacto.\n\t:");
  scanf("%s",telefono);
  for (int i = 0; i < numeroDeContactos; i++) {
    if(strcmp(pointer[i].telefono,telefono) == 0){
      imprimirContacto(pointer+i);
    }
  }
}

Contacto* modificar_contacto(Contacto *pointer){
  char telefono[20];
  printf("\t### MODIFICAR ###\n");
  printf("Escriba el numero de telefono del contacto.\n\t:");
  scanf("%s",telefono);
  for (int i = 0; i < numeroDeContactos; i++) {
    if(strcmp(pointer[i].telefono,telefono) == 0){
      printf("Escriba los siguientes datos del contacto:\n");
      printf("\tNombre: ");
      scanf("%s",pointer[i].nombre);
      printf("\tEdad: ");
      scanf("%s",pointer[i].edad);
      printf("\tDireccion: ");
      scanf("%s",pointer[i].direccion);
      printf("\tTelefono: ");
      scanf("%s",pointer[i].telefono);
    }
  }
  return pointer;
}
void mostrar_contactos(Contacto* pointer){
  for (int i = 0; i < numeroDeContactos; i++) {
    printf("·%s\n",pointer[i].nombre );
    printf("·%s\n",pointer[i].edad );
    printf("·%s\n",pointer[i].direccion );
    printf("·%s\n\n",pointer[i].telefono );
  }
}
void imprimirContacto(Contacto *pointer) {
  printf("·%s\n",pointer->nombre );
  printf("·%s\n",pointer->edad );
  printf("·%s\n",pointer->direccion );
  printf("·%s\n\n",pointer->telefono );
}
