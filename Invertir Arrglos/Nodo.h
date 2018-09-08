typedef struct Nodo{
    int dato;
    struct Nodo* next;
}Nodo;

Nodo* crearNodo();
Nodo* iniciarNodo(int dato);
