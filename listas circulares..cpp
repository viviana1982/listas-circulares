#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
   int dato;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

// Funciones con listas:
void Insertar(Lista *l, int n);
void Borrar(Lista *l, int n);
void BorrarLista(Lista *);
void MostrarLista(Lista l);
void OrdenarLista(Lista *l, int);



int main() {
   Lista lista = NULL;
   pNodo p;
   pNodo nodo = lista;
   int dato, dato1, dato2, dato3, dato4;
   int aux;

   printf("ingrese un dato\n");
   scanf("%d",&dato1);
    Insertar(&lista, dato1);
    printf("ingrese un dato\n");
    scanf("%d",&dato2);
   Insertar(&lista, dato2);
   printf("ingrese un dato\n");
   scanf("%d",&dato3);
    Insertar(&lista, dato3);
    printf("ingrese un dato\n");
    scanf("%d",&dato4);
   Insertar(&lista, dato4);
   printf("mostrado la lista circular\n");
   MostrarLista(lista);

   Borrar(&lista, dato4);
   printf("\n");
   //OrdenarLista(lista, dato);

   MostrarLista(lista);
   printf("lista eliminada\n");
   BorrarLista(&lista);
   MostrarLista(lista);
   return 0;
}

void Insertar(Lista *lista, int n) {
   pNodo nodo;

   nodo = (pNodo)malloc(sizeof(tipoNodo));
   nodo->dato = n;

   if(*lista == NULL) *lista = nodo;
   else nodo->siguiente = (*lista)->siguiente;
   (*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int n) {
   pNodo nodo;

   nodo = *lista;

   do {
      if((*lista)->siguiente->dato != n) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->dato != n && *lista != nodo);
   if((*lista)->siguiente->dato == n) {
      if(*lista == (*lista)->siguiente) {
         free(*lista);
         *lista = NULL;
      }
      else {
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   while((*lista)->siguiente != *lista) {
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   free(*lista);
   *lista = NULL;
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   do {
      printf("%d", nodo->dato);
      nodo = nodo->siguiente;
   } while(nodo != lista);
   printf("\n");
}

void OrdenarLista(Lista lista, int n){
    pNodo nodo = lista;
    Lista  actual, dato;


    while(actual->siguiente != NULL){
            dato = actual->siguiente;

            while(dato != NULL){
             if(actual->dato> nodo ->siguiente->dato){
               n= nodo ->siguiente->dato;
               nodo->siguiente->dato= actual->dato;
               actual->dato = n;
            }
            nodo->siguiente = nodo->siguiente->siguiente;
            }
            printf("\n lista ordenada ");


    }


}
