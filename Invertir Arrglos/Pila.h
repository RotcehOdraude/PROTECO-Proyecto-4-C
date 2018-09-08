#include "Nodo.c"
typedef struct Pila{
  Nodo *tope;
}Pila;
typedef enum boolean{false,true} Bool;

Pila* crearPila();
Bool push(Pila *pila, int dato);
int pop(Pila *pila);
Bool isEmpty(Pila *pila);
int tope(Pila *pila);
