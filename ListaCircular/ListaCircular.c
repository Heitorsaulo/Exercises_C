#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaCirc.h"

char compare(ITEM x, ITEM y) { return x > y ? 1 : (x < y ? -1 : 0); }

bool igual(ITEM x, ITEM y) { return compare(x, y) == 0; }

void inicializar(LISTA *l) {
  l->cabeca = (NO *)malloc(sizeof(NO));
  if (l->cabeca == NULL) {
    printf("Nao foi possivel alocar memoria para a cabeca\n");
    exit(EXIT_FAILURE);
  }
  l->cabeca->prox = l->cabeca; // faz a referencia circular
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

bool vazia(LISTA *l) { return tamanho(l) == 0; }

bool inserir(ITEM item, LISTA *l) {
  l->cabeca->prox = criarNo(item, l->cabeca->prox);
  l->tamanho++;
  return true;
}

/*
    Objetivo: Retorna o endereco do No contido na posicao informada.
              Caso a posicao seja invalida (negativa ou maior ou igual
              ao tamanho da lista, retorna NULL.
*/
NO *noNaPosicao(int n, LISTA *l) {
  if (n < 0 || n >= tamanho(l))
    return NULL;

  NO *p = l->cabeca->prox;
  for (int i = 0; i < n; i++)
    p = p->prox;
  return p; // existe um n-esimo e p aponta para ele
}

int buscar(ITEM item, LISTA *l) {
  NO *p = l->cabeca->prox;
  int pos = 0;
  while (p != l->cabeca) // enquanto nao deu a volta
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

  NO *pAnterior;
  if (i == 0) // insercaso na cabeca da lista
    pAnterior = l->cabeca;
  else // insercao no meio ou final da lista
    pAnterior = noNaPosicao(i - 1, l);

  pAnterior->prox = criarNo(item, pAnterior->prox);
  l->tamanho++;
  return true;
}

bool remover(ITEM item, LISTA *l) {
  NO *pAnterior = l->cabeca;

  // Percorre a lista ate encontrar um item com a chave procurada.
  // Remove o item e corrige o apontador do item anterior para
  // apontar para o proximo item
  while (pAnterior->prox != l->cabeca) {
    NO *pAtual = pAnterior->prox;

    if (igual(item, pAtual->item)) {
      pAnterior->prox = pAtual->prox;
      free(pAtual);
      l->tamanho--;
      return true;
    }

    pAnterior = pAtual;
  }
  return false; // Nao removeu
}

void limpar(LISTA *l) {
  NO *atual = l->cabeca->prox;
  while (atual != l->cabeca) // enquando nao deu a volta completa
  {
    NO *prox = atual->prox; // guarda proxima posicao
    free(atual);            // libera memoria apontada por atual
    atual = prox;
  }
  l->cabeca->prox = l->cabeca;
  l->tamanho = 0;
}

void destruir(LISTA *l) {
  limpar(l);
  free(l->cabeca);  // liberacao no No cabeca
  l->cabeca = NULL; // ajusta inicio da lista (vazia)
}

void exibirItem(ITEM i) { printf("%d", i); }

void exibirLista(LISTA *l) {
  printf("[");
  NO *p = l->cabeca->prox;
  while (p != l->cabeca) // enquando nao deu a volta completa
  {
    exibirItem(p->item);
    if (p->prox != l->cabeca)
      printf(",");
    p = p->prox;
  }
  printf("]");
}

void inserirNoFinal(ITEM item, LISTA *l) {
  NO *novoNo = criarNo(item, l->cabeca); // Cria um novo nó apontando para a cabeça
  
  if (vazia(l)) { // Se a lista estiver vazia, insere diretamente
    l->cabeca->prox = novoNo;
  } else {
    NO *ultimo = l->cabeca->prox; // Começa pelo primeiro nó

    // Encontra o último nó da lista
    while (ultimo->prox != l->cabeca) {
      ultimo = ultimo->prox;
    }

    // Atualiza o ponteiro do último nó para apontar para o novo nó
    ultimo->prox = novoNo;
  }

  l->tamanho++;
}

bool removerDaPos(ITEM *item, int i, LISTA *l) {
  NO *p = l->cabeca;
  NO *pAnterior;
  if (i >= l->tamanho || i < 0) {
    return false;
  }
  else if(i == 0){
    //l->cabeca = l->cabeca->prox;
    //free(p);
    remover(l->cabeca->item,l);
    return true;
  }
  else{
  for (int j = 0; j <= i; j++) {

    if (j == i) {
        item = &p->item;
        //pAnterior->prox = p->prox;
        //l->tamanho--;
        //free(p);
        remover(p->item, l);
        return true;
    } 
    else if(p->prox == l->cabeca){
        pAnterior->prox = l->cabeca;
        free(p);
        return true;
    }
    else {
      pAnterior = p;  
      p = p->prox;
    }
  }
  }
}

LISTA *clonar(LISTA *l) {
    LISTA *lClonada = (LISTA *)malloc(sizeof(LISTA) * l->tamanho);
    inicializar(lClonada); 

    NO *auxL = l->cabeca->prox;
    NO *auxLclonada = lClonada->cabeca;
    NO *novoNo = NULL;
    lClonada->cabeca->item = l->cabeca->item;
    while (auxL != l->cabeca) {
        novoNo = criarNo(auxL->item,lClonada->cabeca);
        auxLclonada->prox = novoNo;
        auxL = auxL -> prox;
        auxLclonada = auxLclonada->prox;
        lClonada->tamanho++;
    }

    return lClonada;
}

void inverter(LISTA *l){
  NO *auxAntes = l->cabeca;
  NO *auxAtual = l->cabeca->prox;
  NO *auxProx = NULL;
  while(auxAtual != l->cabeca){
    auxProx = auxAtual->prox;

    auxAtual->prox = auxAntes;
  
    auxAntes = auxAtual;
    auxAtual = auxProx;
  }
    
  
  auxProx = auxAtual->prox;
  auxAtual->prox = auxAntes;
  auxAntes =auxAtual;
  auxAtual = auxProx;
  auxAtual->prox = auxAntes;
  l->cabeca = auxAntes;
}

bool insercaoOrdenada(ITEM item, LISTA *l){
  NO* auxAnterior = l->cabeca;
  NO* auxAtual = l->cabeca->prox;

  NO* novoNo = criarNo(item,NULL);

  if(l->tamanho == 0){
    l->cabeca->prox = criarNo(item,l->cabeca);
    l->tamanho++;
    return true;
  }
  else{
    
    while(auxAtual!=l->cabeca){
        if(item<auxAtual->item){
          auxAnterior->prox = novoNo;
          novoNo->prox = auxAtual;
          l->tamanho++;
          return true;
        }
        else{
          auxAnterior = auxAnterior->prox;
          auxAtual = auxAtual->prox;
        }
      }

  }

  auxAnterior->prox = novoNo;
  novoNo->prox = auxAtual;
  l->tamanho++;
  return true;
}