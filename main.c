#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
  int * elementos;
  int qtde;
  int cap;
} lista;



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

void aumentar (lista * l){
  int * aux = malloc(l->cap * 2 * sizeof(int));
  for (int i = 0; i < l->qtde; i++){
    aux[i] = l->elementos[i];
  }
  l->cap *= 2;
  free(l->elementos);
  l->elementos = aux;
}

void inserir (lista * l, int e){
  if (esta_cheia (l))
    aumentar(l);
  l->elementos[l->qtde] = e;
  l->qtde++;
}

void exibir (lista * l){
  printf ("**********************\n");
  printf ("Qtde: %d\n", l->qtde);
  printf ("Cap: %d\n", l->cap);
  for (int i = 0; i < l->qtde; i++){
    printf ("%d ", l->elementos[i]);
  }
  printf ("\n");
}



int main(void) {

  //data fixa: 23/02/2001
  //unidade de medida: dia

  //2
  srand(time(NULL));
  lista * uma_lista = obter_lista();
  for (int i = 0; i < 100; i++){
    int dado = rand() % 20 + 1;
    inserir (uma_lista, dado);
    exibir(uma_lista);
  }
  return 0;
}