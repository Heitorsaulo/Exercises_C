#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaEnc.h"

char compare(ITEM x, ITEM y) { return x > y ? 1 : (x < y ? -1 : 0); }

bool igual(ITEM x, ITEM y) { return compare(x, y) == 0; }

void inicializar(LISTA *l) {
  l->cabeca = NULL;
  l->cauda = NULL;
  l->tamanho = 0;
}

NO *criarNo(ITEM item, NO *prox) {
  NO *pNovo = (NO *)malloc(sizeof(NO));
  if (pNovo == NULL) {
    printf("Nao foi possivel alocar memoria para pNovo\n");
    exit(EXIT_FAILURE);
  }
  pNovo->item = item;
  pNovo->prox = prox;
  return pNovo;
}

int tamanho(LISTA *l) { return l->tamanho; }

bool cheia(LISTA *l) { return false; }

bool vazia(LISTA *l) { return l->cabeca == NULL; }

bool inserir(ITEM item, LISTA *l) {
  
  NO *no = criarNo(item, l->cabeca);
  NO *noAux = no;

  if (l->tamanho == 0) {
    l->cabeca = no;
    l->cauda = no;
    l->tamanho++;
    return true;
  }  
  else if (l->tamanho == 1) {
    if (item < l->cabeca->item) {
      noAux = l->cabeca;
      l->cabeca = no;
      l->cabeca->prox = noAux;
      l->tamanho++;
      return true;
    } else {
      NO* noFinal = criarNoFinal(item);
      l->cauda->prox = noFinal;
      l->cauda = noFinal;
      l->tamanho++;
      return true;
    }
  }
  else if(item > l->cauda->item){
    NO* noFinal = criarNoFinal(item);
    l->cauda->prox = noFinal;
    l->cauda = noFinal;
    l->tamanho++;
    return true;
  }

  else {
    NO *anterior = l->cabeca;
    NO *posterior = l->cabeca->prox;
    NO *cabeca = l->cabeca;

    while(cabeca != NULL){
      if (item > anterior->item && item < posterior->item) {
        anterior->prox = no;
        no->prox = posterior;
        l->tamanho++;
        return true;
      }
      anterior = cabeca;
      cabeca = cabeca->prox;
      posterior = cabeca;
    }
  }
  

  return false;
}

/*
    Objetivo: Retorna o endereco do No contido na posicao informada.
              Caso a posicao seja invalida (negativa ou maior ou igual
              ao tamanho da lista, retorna NULL.
*/
NO *noNaPosicao(int n, LISTA *l) {
  if (n < 0 || n >= tamanho(l))
    return NULL;

  NO *p = l->cabeca;
  for (int i = 0; i < n; i++)
    p = p->prox;
  return p; // existe um n-esimo e p aponta para ele
}

int buscar(ITEM item, LISTA *l) {
  NO *p = l->cabeca;
  int pos = 0;
  while (p) // p != NULL
  {
    if (igual(item, p->item))
      return pos;
    p = p->prox;
    pos++;
  }
  return -1; // Nao achou
}

ITEM enesimo(int n, LISTA *l) {
  NO *no = noNaPosicao(n, l);
  if (no)
    return no->item;
  else {
    printf("Posicao inexistente na lista (%d)\n", n);
    exit(EXIT_FAILURE);
  }
}

bool alterar(ITEM item, int pos, LISTA *l) {
  NO *no = noNaPosicao(pos, l);
  if (no) {
    no->item = item; // existe um n-esimo e p aponta para ele
    return true;
  } else
    return false;
}

bool inserirNaPos(ITEM item, int i, LISTA *l) {
  if (i < 0 || i > tamanho(l)) {
    printf("Posicao de insercao invalida (%d)\n", i);
    exit(EXIT_FAILURE);
  }

  if (i == 0) // insercao na cabeca da lista
  {
    l->cabeca = criarNo(item, l->cabeca);
  } else // insercao no meio ou final
  {
    NO *pAnterior = noNaPosicao(i - 1, l);
    pAnterior->prox = criarNo(item, pAnterior->prox);
  }
  l->tamanho++;
  return true;
}

void exibirItem(ITEM i) { printf("%d", i); }

void exibirLista(LISTA *l) {
  printf("[");
  NO *p = l->cabeca;
  while (p) // p != NULL
  {
    exibirItem(p->item);
    if (p->prox)
      printf(",");
    p = p->prox;
  }
  printf("]");
}

void limpar(LISTA *l) {
  NO *atual = l->cabeca;
  while (atual) {
    NO *prox = atual->prox; // guarda proxima posicao
    free(atual);            // libera memoria apontada por atual
    atual = prox;
  }
  l->cabeca = NULL; // ajusta inicio da lista (vazia)
  l->tamanho = 0;
}

void destruir(LISTA *l) { limpar(l); }

bool removerDaPos(ITEM item, int posicao, LISTA *lista) {
  NO *noAtual = lista->cabeca;
  NO *noAnterior = NULL;
  NO *noPosterior = noAtual->prox;

  int i = 0;
  if ((posicao > lista->tamanho) || (posicao < 0))
    return false;
  else if (posicao == 0){
    lista->cabeca = noPosterior;
    free(noAtual);
    }
  else {
    for (i = 0; i <= posicao; i++) {
      if (i == posicao) {
        noAnterior->prox = noPosterior;
        free(noAtual);
        lista->tamanho--;
        return true;
      }
      noAnterior = noAtual;
      noAtual = noAtual->prox;
      noPosterior = noPosterior->prox;
    }
  }
}

void inserirNoFinal(ITEM item, LISTA *lista) {
  NO *noNovo = criarNoFinal(item);
  lista->cauda->prox = noNovo;
  lista->cauda = noNovo;
}
// NO *retornaUltimoNo(LISTA *lista) {
//   NO *p = lista->cabeca;
//   while (p) {
//     p = p->prox;
//   }
//   return p;
// }

NO *criarNoFinal(ITEM item) {
  NO *pNovo = (NO *)malloc(sizeof(NO));
  if (pNovo == NULL) {
    printf("Nao foi possivel alocar memoria para pNovo\n");
    exit(EXIT_FAILURE);
  }
  pNovo->prox = NULL;
  pNovo->item = item;
  return pNovo;
}

void intercao(LISTA *l1, LISTA *l2, LISTA *l3){
  
  NO *auxL1 = l1->cabeca;
  NO *auxL2 = NULL;
  NO *noAux = NULL;

  while(auxL1 != NULL){
    auxL2 = l2->cabeca;
    while(auxL2 != NULL){
      if(auxL1->item == auxL2->item){
          if(l3->cabeca == NULL){
            l3->cabeca = criarNo(auxL1->item, NULL);
            l3->cauda = l3->cabeca;
          }
          else{
              l3->cauda->prox = criarNo(auxL1->item, NULL);
              l3->cauda = l3->cauda->prox;
          }
        }
        auxL2 = auxL2->prox;
      }
      auxL1 = auxL1->prox;
    }
    
  } 
 
  void inverter(LISTA *l){
    NO *auxAnt = NULL;
    NO *auxAtual = l->cabeca;
    NO *auxProx = NULL;

    
    while(auxAtual != NULL){
      auxProx = auxAtual -> prox;

      auxAtual->prox = auxAnt;
      auxAnt = auxAtual;
      auxAtual = auxProx;
    }

    l->cabeca = auxAnt;
  }