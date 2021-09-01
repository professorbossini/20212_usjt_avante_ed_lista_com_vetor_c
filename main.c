#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int * elementos;
  int qtde;
  int cap;
} lista;


void inserir (lista * l, int e){
 l->elementos[l->qtde] = e;
 l->qtde++;
}

int esta_cheia (lista * l){
  return l->qtde >= l->cap;
}


//snake case
lista * obter_lista (){
  lista * l = malloc(sizeof(lista));
  l->qtde = 0;
  l->cap = 4;
  l->elementos = malloc(l->cap * sizeof(int));
  return l;
}


int main(void) {
  printf("Hello World\n");
  return 0;
}